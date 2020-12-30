###            Qools: Utilities for quantiles
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License or
#  any later version.
#
#  This program is distributed without any warranty,
#
#  A copy of the GNU General Public License is available at
#  http://www.r-project.org/Licenses/
#

".onAttach" <- function(lib, pkg) {
    if(interactive() || getOption("verbose"))
	packageStartupMessage(sprintf("Package %s (%s) loaded. Type citation(\"%s\") on how to cite this package\n", pkg,
		packageDescription(pkg)$Version, pkg))
}

##################################################
### Generics
##################################################

# Marginal effects

maref <- function(object, namevec) UseMethod("maref")

# Sparsity

sparsity <- function(object, se = "nid", hs = TRUE) UseMethod("sparsity")

######################################################################
### Mid-distribution
######################################################################

# Sample mid-CDF and mid-QF

midecdf <- function(x, na.rm = FALSE){

if(!na.rm && any(is.na(x))) 
	return(NA)
if(na.rm && any(ii <- is.na(x))) 
	x <- x[!ii]
if(is.unsorted(x))
	x <- sort(x)

n <- length(x)
if (n < 1) 
	stop("'x' must have 1 or more non-missing values")
xo <- unique(x)

pmf <- as.numeric(table(x)/n)
val <- list()
val$call <- match.call()
val$x <- xo
val$y <- ecdf(x)(xo) - 0.5*pmf
val$fn <- approxfun(val$x, val$y, method = "linear", rule = 1)
val$data <- x
class(val) <- "midecdf"
return(val)

}

midquantile <- function(x, probs = 1:3/4, na.rm = FALSE){

if(!na.rm && any(is.na(x))) 
	return(NA)
if(na.rm && any(ii <- is.na(x))) 
	x <- x[!ii]
if(any(c(probs < 0, probs > 1)))
	stop("the probability must be between 0 and 1")
	
Fn <- midecdf(x)
Qn <- approxfun(Fn$y, Fn$x, method = "linear", rule = 2)
val <- list()
val$call <- match.call()
val$x <- probs
val$y <- Qn(probs)
val$fn <- Qn
val$data <- x
class(val) <- "midquantile"
return(val)
}

# Conditional mid-CDF and mid-QF

cmidecdf <- function(formula, data, ecdf_est = "npc", npc_args = list(), theta = NULL, subset, weights, na.action, contrasts = NULL){

cl <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf$drop.unused.levels <- TRUE
mf[[1L]] <- quote(stats::model.frame)
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")
intercept <- attr(terms.formula(formula, data = mf), "intercept") == 1
y <- model.response(mf, "numeric")
x <- model.matrix(mt, mf, contrasts)
w <- as.vector(model.weights(mf))
if (!is.null(w) && !is.numeric(w)) 
	stop("'weights' must be a numeric vector")

fit <- cmidecdf.fit(x = x, y = y, intercept = intercept, ecdf_est = ecdf_est, npc_args = npc_args, theta = theta)

return(fit)

}

cmidecdf.fit <- function(x, y, intercept, ecdf_est, npc_args = list(), theta = NULL){

	glm.ao <- function(x, y, theta){
	k <- length(theta)
	val <- rep(NA, k)
		for(i in 1:k){
			fit <- try(glm.fit(x, y, start = rep(0, ncol(x)), family = binomial(link = ao1(theta[i])))$deviance, silent = TRUE)
			if(!inherits(fit, "try-error")) val[i] <- fit
		}
	sel <- which.min(val)
	ans <- glm(y ~ x - 1, family = binomial(link = ao1(theta[sel])))
	ans$lambda <- theta[sel]
	return(ans)
	}

p <- ncol(x)
n <- length(y)
yo <- sort(unique(y))
K <- length(yo)
Z <- mapply(function(t, y) as.numeric(y <= t), yo, MoreArgs = list(y = y))
if(missing(intercept) & all(x[,1] == 1)) intercept <- TRUE

if(ecdf_est == "npc"){
	xnpc <- if(intercept) x[, 2:p, drop = FALSE] else x # remove intercept
	force_args <- list(xdat = xnpc, ydat = ordered(y), bandwidth.compute = is.null(npc_args$bws), oykertype = "wangvanryzin")
    npc_add <- setdiff(names(npc_args), names(force_args))
    npc_args <- c(force_args, npc_args[npc_add])
	bw <- try(fastDoCall(npcdistbw, npc_args), silent = TRUE)
	if(inherits(bw, "try-error")){
		ecdf_est <- "logit"
		warning("ecdf_est 'npc' failed, using 'logit' instead", "\n")
	} else {
		Fhat <- mapply(function(obj, x, y, n) npcdist(bws = obj, exdat = x, eydat = ordered(rep(y, n)))$condist, yo, MoreArgs = list(obj = bw, x = xnpc, n = n))
		Fse <- mapply(function(obj, x, y, n) npcdist(bws = obj, exdat = x, eydat = ordered(rep(y, n)))$conderr, yo, MoreArgs = list(obj = bw, x = xnpc, n = n))
	}
}

if(ecdf_est == "ao"){
	if(is.null(theta)) theta <- seq(0, 2, by = 0.05)
	fitbin <- apply(Z, 2, function(z, x, theta) suppressWarnings(glm.ao(x = x, y = z, theta = theta)), x = x, theta = theta)
	Fhat <- sapply(fitbin, predict, type = "response")
	Fse <- sapply(fitbin, function(x) predict(x, type = "response", se.fit = TRUE)$se.fit)
	bhat <- sapply(fitbin, coef) # p x K
	linkinv <- family(fitbin[[1]])$linkinv
}

if(ecdf_est %in% c("logit", "probit", "cloglog")){
	fitbin <- apply(Z, 2, function(z, x, link) suppressWarnings(glm(z ~ x - 1, family = binomial(link))), x = x, link = ecdf_est)
	Fhat <- sapply(fitbin, predict, type = "response")
	Fse <- sapply(fitbin, function(x) predict(x, type = "response", se.fit = TRUE)$se.fit)
	bhat <- sapply(fitbin, coef) # p x K
	linkinv <- family(fitbin[[1]])$linkinv
}

if(ecdf_est == "identity"){
	fitbin <- apply(Z, 2, function(z, x) suppressWarnings(lm(z ~ x - 1)), x = x)
	Fhat <- sapply(fitbin, predict, type = "response")
	Fse <- sapply(fitbin, function(x) predict(x, type = "response", se.fit = TRUE)$se.fit)
	bhat <- sapply(fitbin, coef) # p x K
	linkinv <- function(eta) eta
}

# rearrange if CDF is not monotone
for(j in 1:n){
	tmp <- Fhat[j,]
	if(any(diff(tmp) < 0)){
		sf <- rearrange(stepfun(yo, c(-Inf, tmp)))
		Fhat[j,] <- sf(yo)
	}
}


M <- apply(Fhat, 1, diff)
if(ncol(Fhat) > 2) M <- t(M)
G <- Fhat[,-1] - 0.5*M
G <- cbind(Fhat[,1]/2, G)
r <- c(max(G[,1]), min(G[,ncol(G)]))

attr(G, "range") <- r
ecdf_fit <- if(ecdf_est == "npc") bw else list(coef = bhat, linkinv = linkinv)

ans <- list(G = G, Fhat = Fhat, Fse = Fse, yo = yo, ecdf_fit = ecdf_fit, ecdf_est = ecdf_est)
class(ans) <- "cmidecdf"

return(ans)

}

midrqControl <- function(method = "Nelder-Mead", ecdf_est = "npc", npc_args = list()){

	list(method = method, ecdf_est = ecdf_est, npc_args = npc_args)

}

midrq <- function(formula, data, tau = 0.5, lambda = NULL, subset, weights, na.action, contrasts = NULL, offset, type = 1, midFit = NULL, control = list()){

cl <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action", 
	"offset"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf$drop.unused.levels <- TRUE
mf[[1L]] <- quote(stats::model.frame)
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")
intercept <- attr(terms.formula(formula, data = mf), "intercept") == 1
y <- model.response(mf, "numeric")
x <- model.matrix(mt, mf, contrasts)
w <- as.vector(model.weights(mf))
if (!is.null(w) && !is.numeric(w)) 
	stop("'weights' must be a numeric vector")
offset <- as.vector(model.offset(mf))
if (!is.null(offset)){
	if (length(offset) != NROW(y)) 
		stop(gettextf("number of offsets is %d, should equal %d (number of observations)", 
			length(offset), NROW(y)), domain = NA)
}

if (is.null(names(control))) 
	control <- midrqControl()
else {
	control_default <- midrqControl()
	control_names <- intersect(names(control), names(control_default))
	control_default[control_names] <- control[control_names]
	control <- control_default
}

nq <- length(tau)
n <- nrow(x)
p <- ncol(x)
if (is.null(offset)) offset <- rep(0, n)
#x <- normalize(x) * sqrt(n)

# is the response binary?
binary <- setequal(sort(unique(y)), c(0,1))
if(binary){
	cat("Binary response detected", "\n")
}

# response on the scale of linear predictor
if(!is.null(lambda)){
	if(binary){
		hy <- ao(y, lambda)
	} else {
		if(any(y <= 0)) stop("The response must be strictly positive")
		hy <- bc(y, lambda)
	}
} else {hy <- y}

# fit model
if(p == 1 & intercept){
	midFit <- midquantile(y, probs = tau)
	fit <- list()
	for (j in 1:nq) {
		fit[[j]] <- list(par = midFit$y[j])
	}	
} else {

	# Estimate mid-CDF if not provided
	if(is.null(midFit)){
		midFit <- cmidecdf.fit(x = x, y = y, intercept = intercept, ecdf_est = control$ecdf_est, npc_args = control$npc_args, theta = seq(0, 2, by = 0.05))
	} else {control$ecdf_est <- midFit$ecdf_est}
	if(type == 3){
		# allowed range for tau
		r <- attr(midFit$G, "range")
		if(any(tau < r[1]) | any(tau > r[2])) stop("tau is outside allowed range ", "[", round(r[1], 3), ", " , round(r[2], 3), "]")
	}
	fit <- list()
	for (j in 1:nq) {
		fit[[j]] <- midrq.fit(x = x, y = y, offset = offset, lambda = lambda, binary = binary, midFit = midFit, type = type, tau = tau[j], method = control$method)
	}

}

names(fit) <- tau
betahat <- matrix(sapply(fit, function(x) x$par), nrow = p, ncol = nq)
rownames(betahat) <- colnames(x)
colnames(betahat) <- tau

yhat <- x %*% betahat + offset
if(!is.null(lambda)){
	if(binary){
		Fitted <- apply(yhat, 2, invao, lambda = lambda)
	} else {
		Fitted <- apply(yhat, 2, invbc, lambda = lambda)
	}
} else {
	Fitted <- yhat
}

fit$call <- cl
#fit$mf <- mf
fit$formula <- formula
mf <- match.call(expand.dots = FALSE)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$x <- x
fit$y <- y
fit$hy <- hy
fit$weights <- w
fit$offset <- offset
fit$tau <- tau
fit$lambda <- lambda
fit$binary <- binary
fit$intercept <- intercept
fit$type <- type
fit$control <- control
fit$coefficients <- betahat
fit$fitted.values <- Fitted
fit$residuals <- y - Fitted
fit$midFit <- midFit
fit$levels <- .getXlevels(mt, mf)
fit$terms <- mt
fit$term.labels <- colnames(x)

class(fit) <- "midrq"
return(fit)
}

midrq.fit <- function(x, y, offset, lambda, binary, midFit, type, tau, method){

n <- nrow(x)
p <- ncol(x)

# transform response to get starting values on the scale of linear predictor
if(!is.null(lambda)){
	if(binary){
		z <- ao(y, lambda) - offset
	} else {
		if(any(y <= 0)) stop("The response must be strictly positive")
		z <- bc(y, lambda) - offset
	}
} else {z <- y - offset}

if(type %in% c(1,2)){
	# starting values for beta
	b0 <- lm.fit(x, z)$coefficients

	if(p == 1){
		if(is.null(lambda)){
			fit <- optim(par = b0, fn = C_midrqLoss, G = midFit$G, x = x, yo = midFit$yo, offset = offset, type = type, tau = tau, n = n, p = p, k = length(midFit$yo), method = "Brent", lower = -Inf, upper = Inf)
			warning("'type = 3' is more reliable when no-intercept model is fitted")
		} else {
			if(binary){
				fit <- optim(par = b0, fn = C_midrqLoss_ao, G = midFit$G, x = x, yo = midFit$yo, offset = offset, type = type, tau = tau, lambda = lambda, n = n, p = p, k = length(midFit$yo), method = "Brent", lower = -Inf, upper = Inf)
			} else {
				fit <- optim(par = b0, fn = C_midrqLoss_bc, G = midFit$G, x = x, yo = midFit$yo, offset = offset, type = type, tau = tau, lambda = lambda, n = n, p = p, k = length(midFit$yo), method = "Brent", lower = -Inf, upper = Inf)
			}
		}
	} else {
		if(is.null(lambda)){
			fit <- optim(par = b0, fn = C_midrqLoss, G = midFit$G, x = x, yo = midFit$yo, offset = offset, type = type, tau = tau, n = n, p = p, k = length(midFit$yo), method = method)
		} else {
			if(binary){
				fit <- optim(par = b0, fn = C_midrqLoss_ao, G = midFit$G, x = x, yo = midFit$yo, offset = offset, type = type, tau = tau, lambda = lambda, n = n, p = p, k = length(midFit$yo), method = method)
			} else {
				fit <- optim(par = b0, fn = C_midrqLoss_bc, G = midFit$G, x = x, yo = midFit$yo, offset = offset, type = type, tau = tau, lambda = lambda, n = n, p = p, k = length(midFit$yo), method = method)
			}
		}
	fit$pseudoy <- NULL
	}
	
	fit$InitialPar <- b0
	
	} else if(type == 3){
	
	up <- apply(tau - midFit$G, 1, function(x) which(x < 0)[1])
	low <- up - 1
	Z <- cbind(midFit$yo[low], midFit$yo[up])
	PI <- t(apply(midFit$G, 1, function(x, p){
		sel <- which(p - x < 0)[1]
		x[c(sel-1, sel)]
	}, p = tau))
	B <- (tau - PI[,1])/(PI[,2] - PI[,1])*(Z[,2] - Z[,1]) + Z[,1]
	if(!is.null(lambda)){
		if(binary){
			B <- ao(B, lambda) - offset
		} else {
			B <- bc(B, lambda) - offset
		}
	} else {B <- B - offset}
	
	fit <- list(par = qr.solve(x, B), pseudoy = B)
	}

return(fit)
}

fitted.midrq <- function(object, ...){

return(object$fitted.values)

}

residuals.midrq <- function(object, ...){

return(object$residuals)

}

predict.midrq <- function(object, newdata, offset, na.action = na.pass, type = "response", ...){

lambda <- object$lambda
if (!missing(newdata)) {
	mt <- terms(object)
	Terms <- delete.response(mt)
	m <- model.frame(Terms, newdata, na.action = na.action, 
		xlev = object$levels)
	if (!is.null(cl <- attr(Terms, "dataClasses"))) 
		.checkMFClasses(cl, m)
	object$x <- model.matrix(Terms, m, contrasts.arg = object$contrasts)
	if (missing(offset)) 
		object$offset <- rep(0, nrow(object$x))
	object$data <- newdata
}
linpred <- drop(object$x %*% object$coefficients) + object$offset
if (type == "link") {
	return(linpred)
}
if (type == "response") {
	if(!is.null(lambda)){
		Fitted <- apply(linpred, 2, invbc, lambda = lambda)
	} else {
		Fitted <- linpred
	}
	return(Fitted)
}

}

coef.midrq <- coefficients.midrq <- function(object, ...){

return(object$coefficients)

}

vcov.midrq <- function(object, numerical = FALSE, robust = FALSE, ...){

	phi <- function(xnz, Fvec, nonZero, Z, w, n, k, tau, yo, offset, binary, lambda = NULL){
		Fvec[nonZero] <- xnz 
		Fhat <- matrix(Fvec, n, k)
		M <- apply(Fhat, 1, diff)
		if(ncol(Fhat) > 2) M <- t(M)
		G <- Fhat[,-1] - 0.5*M
		G <- cbind(Fhat[,1]/2, G)
			
		PI <- t(apply(G, 1, function(x, p){
			sel <- which(p - x < 0)[1]
			x[c(sel-1, sel)]
			}, p = tau))
		B <- (tau - PI[,1])/(PI[,2] - PI[,1])*(Z[,2] - Z[,1]) + Z[,1]

		if(!is.null(lambda)){
		if(binary){
			B <- ao(B, lambda) - offset
		} else {
			B <- bc(B, lambda) - offset
		}
		} else {B <- B - offset}

		ans <- qr.solve(w, B)
		return(ans)
	}
	
	huber <- function(x, a = 1.645){
		ifelse(abs(x) <= a, 0.5*x^2, a*(abs(x) - 0.5*a))
	}
	
	f <- function(b, args) {
		args$b <- b
		do.call(C_midrqLoss, args = args)
	}

tau <- object$tau
nq <- length(tau)
x <- object$x
n <- length(object$y)
p <- ncol(x)
G <- object$midFit$G
Gvec <- as.vector(G)
yo <- object$midFit$yo
K <- length(yo)

if(object$intercept & p == 1){
	V <- as.list(attr(confint(object$midFit), "stderr")^2)
	names(V) <- tau
	return(V)
}

if(numerical){
	FIT_ARGS <- list(G = G, x = x, yo = yo, offset = object$offset, type = object$type, n = n, p = p, k = K)

	V <- list()
	for(j in 1:nq){
		FIT_ARGS$tau <- tau[j]
		H <- hessian(func = f, x = object$coefficients[,j], method = "Richardson", args = FIT_ARGS)
		ans <- MASS::ginv(H)
		V[[j]] <- ans/n
	}
} else {
	xb <- as.matrix(predict(object, type = "link")) # xb includes the offset
	xx <- solve(crossprod(x))
	rate <- if(object$midFit$ecdf_est == "npc") prod(object$midFit$ecdf_fit$xbw)*n else 1
	Fvec <- as.vector(object$midFit$Fhat)
	r <- attr(G, "range")

	# variance of Fhat
	J1 <- object$midFit$Fse^2

	V <- list()
	for(j in 1:nq){
		res <- if(robust) huber(object$hy - xb[,j]) else (object$hy - xb[,j])^2
		V1 <- xx %*% t(x) %*% Diagonal(x = res) %*% x %*% xx

		up <- apply(tau[j] - G, 1, function(x) which(x < 0)[1])
		low <- up - 1
		if(any(low == 0) | any(is.na(low))) stop("Something went wrong. Perhaps tau is outside allowed range ", "[", round(r[1], 3), ", " , round(r[2], 3), "]")
		nonZero <- c((low - 1)*n + 1:n, (up - 1)*n + 1:n)
		
		J2 <- jacobian(func = phi, x = Fvec[nonZero], Fvec = Fvec, nonZero = nonZero, Z = cbind(yo[low], yo[up]), method = "simple", w = x, n = n, k = K, tau = tau[j], yo = yo, offset = object$offset, binary = object$binary, lambda = object$lambda, method.args = list(eps = 1e-6))
		V2 <- J2 %*% Diagonal(x = J1[nonZero]) %*% t(J2)

		V[[j]] <- as.matrix(V1 + rate*V2)
	}
}

names(V) <- tau
return(V)
}

summary.midrq <- function(object, alpha = 0.05, numerical = FALSE, robust = FALSE, ...){

tau <- object$tau
nq <- length(tau)
p <- ncol(object$x)
bhat <- object$coefficients

if(object$intercept & p == 1){
	tmp <- confint(object$midFit, level = 1 - alpha)
	SE <- matrix(attr(tmp, "stderr"), nrow = 1)
	lower <- matrix(tmp$lower, nrow = 1)
	upper <- matrix(tmp$upper, nrow = 1)
} else {
	SE <- sapply(vcov(object, numerical = numerical, robust = robust), function(x) sqrt(diag(x)))
	lower <- bhat - SE*qnorm(1 - alpha/2, 0, 1)
	upper <- bhat + SE*qnorm(1 - alpha/2, 0, 1)
}

if(nq == 1){
	tTable <- data.frame(bhat, SE, lower, upper)
	names(tTable) <- c("Estimate", "Std.Err", "Lower", "Upper")
} else {
	tTable <- list()
	for(i in 1:nq){
		tTable[[i]] <- data.frame(bhat[,i], SE[,i], lower[,i], upper[,i])
		dimnames(tTable[[i]]) <- list(object$term.labels, c("Estimate", "Std.Err", "Lower", "Upper"))
	}
	names(tTable) <- tau
}

object$tTable <- tTable
class(object) <- "summary.midrq"

return(object)

}

midq2q <- function(object, newdata, ...){

tau <- object$tau
nt <- length(tau)
ecdf_fit <- object$midFit$ecdf_fit
yo <- object$midFit$yo
x <- model.matrix(object$formula[-2], newdata)
n <- nrow(x)
p <- ncol(x)
xnpc <- if(object$intercept) x[, 2:p, drop = FALSE] else x
if(object$midFit$ecdf_est == "npc"){
	Fhat <- mapply(function(obj, x, y, n) npcdist(bws = obj, exdat = x, eydat = ordered(rep(y, n)))$condist, yo, MoreArgs = list(obj = ecdf_fit, x = xnpc, n = n))
} else {
	Fhat <- apply(x %*% ecdf_fit$coef, 2, ecdf_fit$linkinv)
}

# rearrange if CDF is not monotone
for(j in 1:n){
	tmp <- Fhat[j,]
	if(any(diff(tmp) < 0)){
		sf <- rearrange(stepfun(yo, c(-Inf, tmp)))
		Fhat[j,] <- sf(yo)
	}
}

M <- apply(Fhat, 1, diff)
if (ncol(Fhat) > 2) 
	M <- t(M)
Ghat <- Fhat[, -1] - 0.5 * M
Ghat <- cbind(Fhat[, 1]/2, Ghat)
Hhat <- predict(object, newdata = newdata)
csi <- tmp <- matrix(NA, n, nt)
for(j in 1:n){
	sel <- findInterval(Hhat[j,], yo, all.inside = TRUE)
	low <- yo[sel] 
	up <- yo[sel + 1] 
	gamma <- (Hhat[j,] - low)/(up - low)
	pstar <- as.numeric((1-gamma)*Ghat[j,sel] + gamma*Ghat[j,sel + 1])
	sel <- findInterval(pstar, Ghat[j,])
	csi[j,] <- ifelse(pstar > Fhat[j,sel], ceiling(Hhat[j,]), floor(Hhat[j,]))
	tmp[j,] <- Fhat[j,sel]
}
colnames(csi) <- tau
rownames(csi) <- rownames(x)
attr(csi, "Fhat") <- tmp
class(csi) <- "midq2q"

return(csi)

}


# Plot and print functions

plot.midq2q <- function(x, ..., xlab = "p", ylab = "Quantile", main = "Ordinary Quantile Function", sub = TRUE, verticals = TRUE, col.steps = "gray70", cex.points = 1, jumps = FALSE){

n <- nrow(x)
k <- ncol(x)
Fhat <- attr(x, "Fhat")

if(n > 1) par(mfrow = c(ceiling(n/3), min(c(2,n))))

for(j in 1:n){
	sf <- stepfun(Fhat[j,], c(x[j,], x[j,k]))
	subtext <- paste("id = ", j)
	plot.stepfun(sf, xlab = xlab, ylab = ylab, main = main, verticals = verticals, col = col.steps, cex.points = cex.points, col.points = col.steps, do.points = jumps, xlim = c(0,1), ...)
	if(sub) mtext(text = subtext, side = 3, line = 0.5, cex = 0.8)
}

}

plot.midecdf <- function(x, ..., ylab = "p", main = "Ordinary and Mid-ECDF", verticals = FALSE, col.01line = "gray70", col.steps = "gray70", col.midline ="black", cex.points = 1, lty.midline = 2, lwd = 1, jumps = FALSE){

z <- sort(x$data)
n <- length(z)
vals <- unique(z)
nv <- length(vals)
Fz <- c(0, cumsum(table(z)/n))

pch <- if(jumps) 19 else ""
plot.stepfun(ecdf(x$data), ylab = ylab, main = main, verticals = verticals, col = col.steps, pch = pch, cex.points = cex.points, col.points = col.steps, ...)

if(jumps){
	points(vals, Fz[-nv], cex = cex.points, col = col.steps)
}

lines(x$x, x$fn(x$x), lty = lty.midline, col = col.midline, lwd = lwd)
abline(h = c(0, 1), col = col.01line, lty = 2)

}

plot.midquantile <- function(x, ..., xlab = "p", ylab = "Quantile", main = "Ordinary and Mid-Quantiles", col.steps = "gray70", col.midline ="black", cex.points = 1, lty.midline = 2, lwd = 1, jumps = FALSE){

z <- sort(x$data)
n <- length(z)
vals <- unique(z)
nv <- length(vals)
Fz <- c(0, cumsum(table(z)/n))
plot(c(0,1), range(z), axes = TRUE, type = "n", xlab = xlab, ylab = ylab, main = main, ...)

segments(x0 = Fz[1:nv], y0 = vals, x1 = Fz[-1], y1 = vals, col = col.steps)
if(jumps){
	points(Fz[1:nv], vals, cex = cex.points, col = col.steps)
	points(1, vals[nv], cex = cex.points, col = col.steps)
	points(Fz[-c(1,nv+1)], vals[-nv], pch = 19, cex = cex.points, col = col.steps)
}

lines(x$x, x$fn(x$x), lty = lty.midline, col = col.midline, lwd = lwd)
}

print.midecdf <- function(x, ...){

cat("Empirical mid-ECDF", "\n")
if (!is.null(cl <- x$call)) {
        cat("Call:\n")
        dput(cl)
        cat("\n")
}

}

print.midquantile <- function(x, ...){

cat("Empirical mid-quantile function", "\n")
if (!is.null(cl <- x$call)) {
        cat("Call:\n")
        dput(cl)
        cat("\n")
}


}

print.cmidecdf <- function(x, ...){

ecdf_est <- switch(x$ecdf_est,
			npc = "Nonparametric (kernel)",
			ao = "Aranda-Ordaz",
			logit = "logit",
			probit = "probit",
			cloglog = "cloglog",
			identity = "linear")

cat("Empirical conditional mid-ECDF", "\n")
cat("Estimator:", ecdf_est)
cat("\n")
if (!is.null(cl <- x$call)) {
        cat("Call:\n")
        dput(cl)
        cat("\n")
}

}

print.midrq <- function(x, ...){

if (!is.null(cl <- x$call)) {
	cat("call:\n")
	dput(cl)
	cat("\n")
}

coef <- x$coefficients
cat("\nCoefficients linear predictor:\n")
print(coef, ...)
nobs <- length(x$y)
p <- ncol(x$x)
rdf <- nobs - p
cat("\nDegrees of freedom:", nobs, "total;", rdf, "residual\n")

}

print.summary.midrq <- function(x, ...){

if (!is.null(cl <- x$call)) {
	cat("call:\n")
	dput(cl)
	cat("\n")
}

cat("\nCoefficients linear predictor:\n")
print(x$tTable, ...)
nobs <- length(x$y)
p <- ncol(x$x)
rdf <- nobs - p
cat("\nDegrees of freedom:", nobs, "total;", rdf, "residual\n")

}

######################################################################
### Confidence intervals for unconditional quantiles
######################################################################

confint.midquantile <- function(object, parm = NULL, level = 0.95, ...){

x <- object$data
probs <- object$x

Fn <- midecdf(x, na.rm = TRUE)
k <- length(probs)
n <- length(x)
p <- table(x)/n
val <- dens <- rep(NA, k)
level <- level + (1-level)/2

for(i in 1:k){
	sel <- findInterval(probs[i], Fn$y)
	if(!sel %in% c(0, length(Fn$y))){
		lambda <- (Fn$y[sel+1] - probs[i])/(Fn$y[sel+1] - Fn$y[sel]);
		val[i] <- probs[i]*(1- probs[i]) - (1 - (lambda - 1)^2)*p[sel]/4 - (1 - lambda^2)*p[sel+1]/4
		dens[i] <- 0.5*(p[sel] + p[sel+1])/(Fn$x[sel+1] - Fn$x[sel])
	}
}
stderr <- sqrt(val/(n*dens^2))
LB <- object$y - qt(level, n - 1) * stderr
UB <- object$y + qt(level, n - 1) * stderr
val <- data.frame(midquantile = object$y, lower = LB, upper = UB)
rownames(val) <- paste0(probs*100, "%")
attr(val, "stderr") <- stderr
return(val)
}

######################################################################
### Q-based statistics
######################################################################

qlss <- function(...) UseMethod("qlss")

qlss.numeric <- function(x, probs = 0.1, ...){

if(any(!probs > 0) | any(!probs < 0.5)) stop("Quantile index out of range: probs must be > 0 and < 0.5")
if(any(duplicated(probs))) probs <- unique(probs)
call <- match.call()

nq <- length(probs)

vec3 <- as.numeric(do.call(what = quantile, args = list(x = x, probs = 1:3/4, ...)))
Me <- vec3[2]
IQR <- vec3[3] - vec3[1]

IPR <- Ap <- Tp <- rep(NA, nq)
for(i in 1:nq){
	vecp <- as.numeric(do.call(what = quantile, args = list(x = x, probs = probs[i], ...)))
	vecq <- as.numeric(do.call(what = quantile, args = list(x = x, probs = 1 - probs[i], ...)))

	IPR[i] <- vecq - vecp
	Ap[i] <- (vecq - 2*Me + vecp)/IPR[i]
	Tp[i] <- IPR[i]/IQR
}
names(IPR) <- names(Ap) <- names(Tp) <- probs

val <- list(location = list(median = Me), scale = list(IQR = IQR, IPR = IPR), shape = list(skewness = Ap, shape = Tp))
val$probs <- probs
val$call <- call
class(val) <- "qlss"
return(val)
}

qlss.default <- function(fun = "qnorm", probs = 0.1, ...){

if(any(!probs > 0) | any(!probs < 0.5)) stop("Quantile index out of range: probs must be > 0 and < 0.5")
if(any(duplicated(probs))) probs <- unique(probs)
call <- match.call()

nq <- length(probs)

vec3 <- as.numeric(do.call(what = match.fun(fun), args = list(p = 1:3/4, ...)))
Me <- vec3[2]
IQR <- vec3[3] - vec3[1]

IPR <- Ap <- Tp <- rep(NA, nq)
for(i in 1:nq){
	vecp <- as.numeric(do.call(what = match.fun(fun), args = list(p = probs[i], ...)))
	vecq <- as.numeric(do.call(what = match.fun(fun), args = list(p = 1 - probs[i], ...)))

	IPR[i] <- vecq - vecp
	Ap[i] <- (vecq - 2*Me + vecp)/IPR[i]
	Tp[i] <- IPR[i]/IQR
}
names(IPR) <- names(Ap) <- names(Tp) <- probs

val <- list(location = list(median = Me), scale = list(IQR = IQR, IPR = IPR), shape = list(skewness = Ap, shape = Tp))
val$probs <- probs
val$call <- call
class(val) <- "qlss"
return(val)
}

qlss.formula <- function(formula, probs = 0.1, data = sys.frame(sys.parent()), subset, weights, na.action, contrasts = NULL, method = "fn", type = "rq", tsf = "mcjI", symm = TRUE, dbounded = FALSE, lambda = NULL, conditional = FALSE, ...){

if(any(!probs > 0) | any(!probs < 0.5)) stop("Quantile index out of range: probs must be > 0 and < 0.5")
if(any(duplicated(probs))) probs <- unique(probs)
if(type == "rqt" && tsf == "mcjII") stop("'mcjII' not available for qlss")
if (!inherits(formula, "formula") || length(formula) != 3) {
	stop("\nFixed-effects model must be a formula of the form \"y ~ x\"")
}

call <- match.call()
mc <- match.call(expand.dots = TRUE)
fitLs <- names(mc)

mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
mf <- eval(mf, parent.frame())
if (method == "model.frame") 
        return(mf)

taus <- c(1:3/4, probs, 1-probs)
nq <- length(probs)

val <- list()
if(type == "rq"){
	fitLs <- as.list(mc[fitLs %in% names(formals(rq))])
	fitLs$data <- mf
	fitLs$tau <- taus
	val$fit <- do.call(rq, args = fitLs)
}

if(type == "rqt"){
	if(conditional & length(lambda) < length(taus)) stop(paste0("Length of 'lambda' must be ", length(taus), ". See details in '?qlss'"))
	fitLs <- as.list(mc[fitLs %in% names(formals(tsrq))])
	fitLs$data <- mf
	fitLs$tau <- taus
	val$fit <- do.call(tsrq, args = fitLs)
}

Fitted <- val$fit$fitted.values
vec3 <- Fitted[,1:3]
vecp <- Fitted[ , -c(1:3), drop = FALSE][ , 1:nq, drop = FALSE]
vecq <- Fitted[ , -c(1:3), drop = FALSE][ , (nq+1):(2*nq), drop = FALSE]
Me <- drop(Fitted[,2])
IQR <- drop(vec3[,3] - vec3[,1])
IPR <- vecq - vecp
Ap <- (vecq - 2 * Me + vecp)/IPR
Tp <- IPR/IQR
colnames(IPR) <- colnames(Ap) <- colnames(Tp) <- probs

val$location <- list(median = matrix(Me))
val$scale <- list(IQR = matrix(IQR), IPR = IPR)
val$shape <- list(skewness = Ap, shape = Tp)
val$call <- call
val$probs <- probs
val$type <- type
val$method <- method

class(val) <- "qlss"
return(val)

}

predict.qlss <- function(object, newdata, interval = FALSE, level = 0.95, R = 200, na.action = na.pass, trim = 0.05, ...){

type <- object$type
if(!length(type)) return(object)

val <- switch(type,
	rq = qlssPredRq(object = object, newdata = newdata, interval = interval, level = level, R = R, na.action = na.action, trim = trim),
	rqt = qlssPredRqt(object = object, newdata = newdata, interval = interval, level = level, R = R, na.action = na.action, trim = trim)
)

val$probs <- object$probs

class(val) <- "qlss"
return(val)

}

qlssPredRq <- function(object, newdata, interval, level, R, na.action, trim){

probs <- object$probs
nq <- length(probs)

fit <- object$fit
taus <- fit$tau

if(missing(newdata))
	{x <- fit$x}	else {
	mt <- terms(fit)
	Terms <- delete.response(mt)
	mf <- model.frame(Terms, newdata, na.action = na.action, xlev = fit$xlevels)
	if (!is.null(cl <- attr(Terms, "dataClasses"))) 
		.checkMFClasses(cl, mf)
	x <- model.matrix(Terms, mf, contrasts.arg = fit$contrasts)
}

Fitted <- x%*%fit$coefficients

vecp <- Fitted[ , -c(1:3), drop = FALSE][ , 1:nq, drop = FALSE]
vecq <- Fitted[ , -c(1:3), drop = FALSE][ , (nq+1):(2*nq), drop = FALSE]
Me <- drop(Fitted[,2])
IQR <- drop(Fitted[,3] - Fitted[,1])
IPR <- vecq - vecp
Ap <- (vecq - 2 * Me + vecp)/IPR
Tp <- IPR/IQR
colnames(IPR) <- colnames(Ap) <- colnames(Tp) <- probs
val <- list(location = list(median = matrix(Me)), scale = list(IQR = matrix(IQR), IPR = IPR), shape = list(skewness = Ap, shape = Tp))

if(interval){
	fit.s <- summary(fit, se = "boot", R = R, covariance = TRUE)
	B <- lapply(fit.s, function(x) x$B)
	
	Fitted <- lapply(B, function(b,x) x%*%t(b), x = x)

	sdtrim <- function(u, trim){
		sel1 <- u >= quantile(u, probs = trim/2, na.rm = TRUE)
		sel2 <- u <= quantile(u, probs = 1-trim/2, na.rm = TRUE)
		sd(u[sel1 & sel2])
	}
	
	level <- level + (1-level)/2

	vecp <- Fitted[-c(1:3)][1:nq]
	vecq <- Fitted[-c(1:3)][(nq+1):(2*nq)]

	tmp <- qt(level, R - 1) * apply(Fitted[[2]], 1, sdtrim, trim = trim)
	Me.ci <- cbind(Me - tmp, Me + tmp)
	tmp <- qt(level, R - 1) * apply(Fitted[[3]] - Fitted[[1]], 1, sdtrim, trim = trim)
	IQR.ci <- cbind(IQR - tmp, IQR + tmp)
	
	IPR.ci <- Ap.ci <- Tp.ci <- list()
	for(j in 1:nq){
		ipr <- vecq[[j]] - vecp[[j]]
		tmp <- qt(level, R - 1) * apply(ipr, 1, sdtrim, trim = trim)
		IPR.ci[[j]] <- cbind(IPR[,j] - tmp, IPR[,j] + tmp)
		ap <- (vecq[[j]] - 2 * Fitted[[2]] + vecp[[j]])/ipr
		tmp <- qt(level, R - 1) * apply(ap, 1, sdtrim, trim = trim)
		Ap.ci[[j]] <- cbind(Ap[,j] - tmp, Ap[,j] + tmp)
		tp <- ipr/(Fitted[[3]] - Fitted[[1]])
		tmp <- qt(level, R - 1) * apply(tp, 1, sdtrim, trim = trim)
		Tp.ci[[j]] <- cbind(Tp[,j] - tmp, Tp[,j] + tmp)
	}
	
	CI <- list(Me = Me.ci, IQR = IQR.ci, IPR = IPR.ci, Ap = Ap.ci, Tp = Tp.ci)
	names(CI$IPR) <- names(CI$Ap) <- names(CI$Tp) <- probs
	val$CI <- CI
}

return(val)
}

qlssPredRqt <- function(object, newdata, interval, level, R, na.action, trim){

probs <- object$probs
nq <- length(probs)

fit <- object$fit
taus <- fit$tau
tsf <- fit$tsf
symm <- attributes(tsf)$symm
dbounded <- attributes(tsf)$dbounded
isBounded <- attributes(tsf)$isBounded
#conditional <- attributes(tsf)$conditional
conditional <- TRUE

if(missing(newdata))
	{x <- fit$x}	else {
	mt <- terms(fit)
	Terms <- delete.response(mt)
	mf <- model.frame(Terms, newdata, na.action = na.action, xlev = fit$xlevels)
	if (!is.null(cl <- attr(Terms, "dataClasses"))) 
		.checkMFClasses(cl, mf)
	x <- model.matrix(Terms, mf, contrasts.arg = fit$contrasts)
}

n <- nrow(x)

lambdahat <- fit$lambda
linpred <- x%*%fit$coefficients
Fitted <- matrix(NA, nrow(linpred), ncol(linpred))
for (j in 1:length(taus)) {
	Fitted[, j] <- switch(tsf, mcjI = invmcjI(linpred[, 
		j], lambdahat[j], symm, dbounded), bc = invbc(linpred[, 
		j], lambdahat[j]), ao = invao(linpred[, j], lambdahat[j], 
		symm))
}

if (isBounded) {
	Fitted <- apply(Fitted, 2, function(x, x.r) invmap(x, 
		x.r), x.r = range(fit$y))
}

vecp <- Fitted[ , -c(1:3), drop = FALSE][ , 1:nq, drop = FALSE]
vecq <- Fitted[ , -c(1:3), drop = FALSE][ , (nq+1):(2*nq), drop = FALSE]
Me <- drop(Fitted[,2])
IQR <- drop(Fitted[,3] - Fitted[,1])
IPR <- vecq - vecp
Ap <- (vecq - 2 * Me + vecp)/IPR
Tp <- IPR/IQR
colnames(IPR) <- colnames(Ap) <- colnames(Tp) <- probs
val <- list(location = list(median = matrix(Me)), scale = list(IQR = matrix(IQR), IPR = IPR), shape = list(skewness = Ap, shape = Tp))

if(interval){
	B <- summary(fit, se = "boot", R = R, conditional = conditional, covariance = TRUE)$B

	linpred <- lapply(B, function(b,x) x%*%t(b), x = x)
	Fitted <- list()
	for (j in 1:length(taus)) {
		Fitted[[j]] <- switch(tsf,
		mcjI = apply(linpred[[j]], 2, function(x,l,s,d) invmcjI(x,l,s,d), l = lambdahat[j], s = symm, d = dbounded),
		bc = apply(linpred[[j]], 2, function(x,l,s,d) invbc(x,l), l = lambdahat[j]),
		ao = apply(linpred[[j]], 2, function(x,l,s) ao(x,l,s), l = lambdahat[j], s = symm)
		)
		if (isBounded) {
			Fitted[[j]] <- apply(Fitted[[j]], 2, function(x, x.r) invmap(x, 
				x.r), x.r = range(fit$y))
		}
	}
}

if(interval){

	sdtrim <- function(u, trim){
		sel1 <- u >= quantile(u, probs = trim/2, na.rm = TRUE)
		sel2 <- u <= quantile(u, probs = 1-trim/2, na.rm = TRUE)
		sd(u[sel1 & sel2])
	}
	
	level <- level + (1-level)/2

	vecp <- Fitted[-c(1:3)][1:nq]
	vecq <- Fitted[-c(1:3)][(nq+1):(2*nq)]

	tmp <- qt(level, R - 1) * apply(Fitted[[2]], 1, sdtrim, trim = trim)
	Me.ci <- cbind(Me - tmp, Me + tmp)
	tmp <- qt(level, R - 1) * apply(Fitted[[3]] - Fitted[[1]], 1, sdtrim, trim = trim)
	IQR.ci <- cbind(IQR - tmp, IQR + tmp)
	
	IPR.ci <- Ap.ci <- Tp.ci <- list()
	for(j in 1:nq){
		ipr <- vecq[[j]] - vecp[[j]]
		tmp <- qt(level, R - 1) * apply(ipr, 1, sdtrim, trim = trim)
		IPR.ci[[j]] <- cbind(IPR[,j] - tmp, IPR[,j] + tmp)
		ap <- (vecq[[j]] - 2 * Fitted[[2]] + vecp[[j]])/ipr
		tmp <- qt(level, R - 1) * apply(ap, 1, sdtrim, trim = trim)
		Ap.ci[[j]] <- cbind(Ap[,j] - tmp, Ap[,j] + tmp)
		tp <- ipr/(Fitted[[3]] - Fitted[[1]])
		tmp <- qt(level, R - 1) * apply(tp, 1, sdtrim, trim = trim)
		Tp.ci[[j]] <- cbind(Tp[,j] - tmp, Tp[,j] + tmp)
	}
	
	CI <- list(Me = Me.ci, IQR = IQR.ci, IPR = IPR.ci, Ap = Ap.ci, Tp = Tp.ci)
	names(CI$IPR) <- names(CI$Ap) <- names(CI$Tp) <- probs
	val$CI <- CI
}

return(val)
}

plot.qlss <- function(x, z, whichp = NULL, interval = FALSE, type = "l", ...){

probs <- x$probs
if(!is.null(whichp)){
	if(length(whichp) > 1) stop(cat("Only one value for 'whichp' to choose from", probs, "\n"))
	sel <- which(whichp == probs)
	if(!(length(sel))) stop(cat("Choose 'whichp' from", probs, "\n"))
} else {
	sel <- 1
}

r <- order(z)
n <- length(z)
if(interval){
	if(is.null(x$CI)) stop("Use 'predict.qlss' with 'interval = TRUE' first.") else CI <- x$CI
}

if(interval){
	yl1 <- range(c(x$location$median,CI$Me))
	yl2 <- range(c(x$scale$IQR,CI$IQR))
	yl3 <- range(c(x$shape$skewness[,sel],CI$Ap[[sel]]))
	yl4 <- range(c(x$shape$shape[,sel],CI$Tp[[sel]]))
} else {
	yl1 <- range(c(x$location$median))
	yl2 <- range(c(x$scale$IQR))
	yl3 <- range(c(x$shape$skewness[,sel]))
	yl4 <- range(c(x$shape$shape[,sel]))
}

if(!all(is.finite(yl1))) yl1 <- NULL
if(!all(is.finite(yl2))) yl2 <- NULL
if(!all(is.finite(yl3))) yl3 <- NULL
if(!all(is.finite(yl4))) yl4 <- NULL

par(mfrow = c(2,2))
plot(z[r], x$location$median[r,], ylab = "Median", type = type, ylim = yl1, ...)
abline(h = 0, col = grey(.5))
if(interval){
lines(z[r], CI$Me[r,1], lty = 2, ...)
lines(z[r], CI$Me[r,2], lty = 2, ...)
}

plot(z[r], x$scale$IQR[r,], ylab = "IQR", type = type, ylim = yl2, ...)
abline(h = 0, col = grey(.5))
if(interval){
lines(z[r], CI$IQR[r,1], lty = 2, ...)
lines(z[r], CI$IQR[r,2], lty = 2, ...)
}

plot(z[r], x$shape$skewness[r,sel], ylab = "Skewness", type = type, ylim = yl3, ...)
abline(h = 0, col = grey(.5))
if(interval){
lines(z[r], CI$Ap[[sel]][r,1], lty = 2, ...)
lines(z[r], CI$Ap[[sel]][r,2], lty = 2, ...)
}

plot(z[r], x$shape$shape[r,sel], ylab = "Shape", type = type, ylim = yl4, ...)
abline(h = 0, col = grey(.5))
if(interval){
lines(z[r], CI$Tp[[sel]][r,1], lty = 2, ...)
lines(z[r], CI$Tp[[sel]][r,2], lty = 2, ...)
}

}

print.qlss <- function(x, ...){

if (!is.null(cl <- x$call)) {
        cat("call:\n")
        dput(cl)
        cat("\n")
}

n <- length(x$location$median)
txt <- if(n > 1) "Conditional Quantile-Based Location, Scale, and Shape" else "Unconditional Quantile-Based Location, Scale, and Shape"

if(n > 1){
cat(txt, "\n")
cat("-- Values are averaged over observations -- ", "\n")

cat("\n")

cat("** Location **", "\n")

cat("Median", "\n")
print(mean(x$location$median))

cat("** Scale **", "\n")

cat("Inter-quartile range (IQR)", "\n")
print(mean(x$scale$IQR))

cat("Inter-quantile range (IPR)", "\n")
print(colMeans(x$scale$IPR))

cat("**Shape**", "\n")

cat("Skewness index", "\n")
print(colMeans(x$shape$skewness))

cat("Shape index", "\n")
print(colMeans(x$shape$shape))

} else {

cat(txt, "\n")
cat("\n")

cat("** Location **", "\n")

cat("Median", "\n")
print(x$location$median)

cat("** Scale **", "\n")

cat("Inter-quartile range (IQR)", "\n")
print(x$scale$IQR)

cat("Inter-quantile range (IPR)", "\n")
print(x$scale$IPR)

cat("** Shape **", "\n")

cat("Skewness index", "\n")
print(x$shape$skewness)

cat("Shape index", "\n")
print(x$shape$shape)


}



}

######################################################################
### Transformation models
######################################################################

# base transformation functions

powerbase <- function(x, lambda){
(x^(lambda) - 1)/lambda
}

invpowerbase <- function(x, lambda, replace = TRUE){
sx <- if(replace) 0 else NA
val <- (lambda*x + 1)^(1/lambda)
val[(lambda*x + 1) <= 0] <- sx
return(val)
}

powrecbase <- function(x, lambda){
1/(2*lambda) * (x^lambda - x^(-lambda))
}

# Logit transformation
logit <- function(theta, omega = 0.001){
if(any(theta < 0) | any(theta > 1)) stop("theta outside interval")
theta[theta == 0] <- omega
theta[theta == 1] <- 1-omega
val <- log(theta/(1-theta))
return(val)
}

# Inverse logit transformation
invlogit <- function(x){
val <- exp(x)/(1 + exp(x))
val[val < 0] <- 0
val[val > 1] <- 1
return(val)
}

# c-log-log transformation
cloglog <- function(theta, omega = 0.001){
if(any(theta < 0) | any(theta > 1)) stop("theta outside interval")
theta[theta == 0] <- omega
theta[theta == 1] <- 1-omega
val <- log(-log(1 - theta))
return(val)
}

# inverse c-log-log transformation
invcloglog <- function(x){
val <- 1 - exp(-exp(x))
return(val)
}

# Proposal I (one parameter)

mcjI <- function(x, lambda, symm = TRUE, dbounded = FALSE, omega = 0.001){

if(dbounded){
	if(any(x < 0) | any(x > 1)) stop("x outside interval")
	x[x == 0] <- omega
	x[x == 1] <- 1 - omega
} else {
	if(any(x <= 0)) stop("x must be strictly positive")
}

if(dbounded){
	if(symm){
		x <- x/(1-x)
	} else {
		x <- -log(1-x)
	}
} else {
	if(!symm){
		x <- log(1+x)
	}
}

if(lambda != 0){
	val <-  powrecbase(x, lambda)
	} else {val <- log(x)}

return(val)

}

# Inverse proposal I (one parameter)

invmcjI <- function(x, lambda, symm = TRUE, dbounded = FALSE){

if(dbounded){
	if(symm){
		if(lambda != 0){
				x <- lambda*x
				y <- (x + sqrt(1 + x^2))^(1/lambda)
				val <- y/(1+y)
			} else {
			val <- invlogit(x)
		}
	} else {
		if(lambda != 0){
				x <- lambda*x
				val <- (x + sqrt(1 + x^2))^(1/lambda)
				val <- 1 - exp(-val)
			} else {
			val <- invcloglog(x)
		}
	}
}
else {
	if(lambda != 0){
		x <- lambda*x
		val <- (x + sqrt(1 + x^2))^(1/lambda)
	} else {val <- exp(x)}

	if(!symm){
		val <- exp(val) - 1
	}
}

return(val)
}

# Proposal II (two parameters)

mcjII <- function(x, lambda, delta, dbounded = FALSE, omega = 0.001){

if(dbounded){
	if(any(x < 0) | any(x > 1)) stop("x outside interval")
	x[x == 0] <- omega
	x[x == 1] <- 1 - omega
} else {
	if(any(x <= 0)) stop("x must be strictly positive")
}

if(lambda == 0){
	lambda <- 1e-10
}
if(delta == 0){
	delta <- 1e-10
}

if(dbounded){
	x <- ((1-x)^(-delta) - 1)/delta
	val <- powrecbase(x, lambda)
}
else {
	x <- x/(1+x)
	x <- ((1-x)^(-delta) - 1)/delta
	val <- powrecbase(x, lambda)
}


return(val)

}

# Inverse proposal II (two parameters)

invmcjII <- function(x, lambda, delta, dbounded = FALSE){

if(lambda == 0){
	lambda <- 1e-10
}
if(delta == 0){
	delta <- 1e-10
}

if(dbounded){
	x <- lambda*x
	val <- (x + sqrt(1 + x^2))^(1/lambda)
	val <- 1 - (val*delta + 1)^(-1/delta)
}
else {
	x <- lambda*x
	val <- (x + sqrt(1 + x^2))^(1/lambda)
	val <- 1 - (val*delta + 1)^(-1/delta)
	val <- val/(1-val)
}

return(val)
}

# Aranda-Ordaz transformation (symmetric and asymmetric)

ao <- function(theta, lambda, symm = TRUE, omega = 0.001){
if(any(theta < 0) | any(theta > 1)) stop("theta outside interval")
theta[theta == 0] <- omega
theta[theta == 1] <- 1 - omega

if(symm){
	if(lambda != 0){
	val <- (2/lambda)* ((theta^lambda) - (1-theta)^lambda)/((theta^lambda) + (1-theta)^lambda)
	} else {
	val <- logit(theta)
	}
} else {
	if(lambda != 0){
	val <- log(((1-theta)^(-lambda) - 1)/lambda)
	} else {
	val <- cloglog(theta)
	}
}


return(val)

}

# Inverse Aranda-Ordaz transformation (symmetric and asymmetric)

invao <- function(x, lambda, symm  = TRUE, replace = TRUE){
sx <- if(replace) 0 else NA
dx <- if(replace) 1 else NA

if(symm){
	if(lambda != 0){
		y <- (lambda*x/2)
		a <- (1 + y)^(1/lambda)
		b <- (1 - y)^(1/lambda)
		val <- rep(dx, length(x))
		val <- ifelse(abs(y) < 1, a/(a + b), val)
		val[y <= -1] <- sx
	} else {val <- invlogit(x)}
} else {
	if(lambda != 0){
		y <- lambda*exp(x)
		val <- ifelse(y > -1, 1 - (1 + y)^(-1/lambda), 1)
		
	} else {val <- invcloglog(x)}
}

return(as.numeric(val))
}

# Box-Cox transformation

bc <- function(x, lambda){
if(any(x <= 0)) stop("x must be strictly positive")
val <- if(lambda != 0) powerbase(x, lambda) else log(x)
return(val)
}

# Inverse Box-Cox transformation

invbc <- function(x, lambda, replace = TRUE){

val <- if(lambda != 0) invpowerbase(x, lambda, replace = replace) else exp(x)
return(val)
}

# Mapping from x.r[1],x.r[2] to 0,1

map <- function(x, x.r = NULL){
if(is.null(x.r)) x.r <- range(x, na.rm = TRUE)
theta <- (x - x.r[1])/(x.r[2] - x.r[1])
attr(theta, "range") <- x.r
return(theta)
}

# Mapping from 0,1 to x.r[1],x.r[2]

invmap <- function(x, x.r = NULL){

if(is.null(x.r)) x.r <- attr(x, "range")

(x.r[2] - x.r[1]) * x + x.r[1]

}

# L1-norm and residual cusum loss functions
l1Loss <- function(x, tau, weights){

ind <- ifelse(x < 0, 1, 0)
sum(weights * x * (tau - ind))/sum(weights)

}

rcLoss <- function(lambda, x, y, weights, tsf, symm = TRUE, dbounded = FALSE, tau = 0.5, method.rq = "fn"){

if(length(tau) > 1) stop("One quantile at a time")
n <- length(y)
out <- rep(NA, n)

z <- switch(tsf,
	mcjI = mcjI(y, lambda, symm, dbounded, omega = 0.001),
	bc = bc(y, lambda),
	ao = ao(y, lambda, symm, omega = 0.001)
	)

Rfun <- function(x, t, e) mean(apply(x, 1, function(xj,t) all(xj <= t), t = t) * e)

fit <- try(rq.wfit(x, z, tau = tau, weights = weights, method = method.rq), silent = T)

if(!inherits(fit, "try-error")){
	e <- as.numeric(fit$residuals <= 0)
	#out <- apply(x, 1, function(t, z, e) Rfun(z, t, e), z = x, e = tau - e)
	for(i in 1:n){
	#out[i] <- mean(apply(x, 1, function(x,t) all(x <= t), t = x[i,]) * (tau - e))
	out[i] <- mean(apply(t(x) <= x[i,], 2, function(x) all(x)) * (tau - e))	
	}
}

return(mean(out^2))

}

nlLoss <- function(theta, x, y, tau, tsf, symm = TRUE, dbounded = FALSE, smooth = FALSE, omicron = 0.001) {

if(any(is.na(theta))){
	ans <- Inf
	attr(ans, "grad") <- matrix(Inf, ncol(x))
	return(ans)
}

n <- length(y)
eta <- x %*% matrix(theta[-1])
res <- switch(tsf,
	bc = y - invbc(eta, lambda = theta[1]),
	ao = y - invao(eta, lambda = theta[1], symm = symm),
	mcjI = y - invmcjI(eta, lambda = theta[1], symm = symm, dbounded = dbounded)
)

d1 <- switch(tsf,
	bc = d1bc(eta, lambda = theta[1]),
	ao = d1ao(eta, lambda = theta[1], symm = symm),
	mcjI = d1mcjI(eta, lambda = theta[1], symm = symm, dbounded = dbounded)
)

d2 <- switch(tsf,
	bc = d2bc(eta, lambda = theta[1]),
	ao = d2ao(eta, lambda = theta[1], symm = symm),
	mcjI = d2mcjI(eta, lambda = theta[1], symm = symm, dbounded = dbounded)
)

if(smooth){
	s <- ifelse(res <= (tau - 1)*omicron, -1, ifelse(res >= tau*omicron, 1, 0))
	w <- as.numeric(1 - s^2)
	W <- diag(w, n, n)
	vs <- s*((2*tau - 1)*s + 1)/2
	cs <- sum(0.25*(1-2*tau)*omicron*s - 0.25*(1-2*tau+2*tau^2)*omicron*s^2)
	res <- matrix(res)
	ans <- as.numeric(0.5 * omicron * t(res) %*% W %*% res + t(vs) %*% res + cs)
	gradl <- -sum(1/omicron * W %*% (res * d2) + (vs * d2))
	gradb <- -t(x) %*% matrix(1/omicron * W %*% (res * d1) + (vs * d1))
	grad <- c(gradl, gradb)
	#hess <- 1/omicron * t(x) %*% (W * d1) %*% x
} else {
	ind <- tau - as.numeric(res < 0)
	ans <- as.numeric(sum(res*ind))
	grad <- c(-sum(ind*d2), -t(x) %*% (ind * d1))
	#hess <- matrix(0, ncol(x), ncol(x))
}

if(is.na(ans)){
	ans <- Inf
	grad <- matrix(Inf, ncol(x))
}

attr(ans, "grad") <- matrix(grad)

return(ans)
}

######################################################################
# One-parameter transformations (MCJI, Box-Cox, Aranda-Ordaz)
######################################################################

# Two-stage estimator

tsrq <- function(formula, data = sys.frame(sys.parent()), tsf = "mcjI", symm = TRUE, dbounded = FALSE, lambda = NULL, conditional = FALSE, tau = 0.5, subset, weights, na.action, contrasts = NULL, method = "fn"){

if(any(tau <= 0) | any(tau >= 1)) stop("Quantile index out of range")

nq <- length(tau)

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
if (method == "model.frame") 
	return(mf)
mf$drop.unused.levels <- TRUE
mf[[1L]] <- as.name("model.frame")
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")
x <- model.matrix(mt, mf, contrasts)
y <-  y.old <- model.response(mf, "numeric")
w <- if (missing(weights)) rep(1, length(y)) else as.vector(model.weights(mf))

if(tsf == "mcjII") stop("For two-parameter transformations, see 'tsrq2' and 'nlrq2'")
if(!tsf %in% c("bc","ao","mcjI")) stop("'tsf' not recognized")

isBounded <- (tsf == "mcjI" && dbounded)
isBounded <- tsf == "ao" || isBounded
if(isBounded) y <- map(y)

if(is.null(lambda) && !conditional){
	lambda <- if(tsf == "ao" & symm == FALSE) seq(-2, 2, by = 0.005)
		else seq(0, 2, by = 0.005)
}
nl <- length(lambda)

n <- length(y)
p <- ncol(x)

zhat <- res <- array(NA, dim = c(n, nq, nl))
matLoss <- rejected <- matrix(NA, nq, nl)
Ind <- array(NA, dim = c(n, nq, nl))

if(!conditional){
	# estimate linear QR for a sequence of lambdas
	for(i in 1:nl){

	# transform response
	newresponse <- switch(tsf,
		mcjI = mcjI(y, lambda[i], symm, dbounded, omega = 0.001),
		bc = bc(y, lambda[i]),
		ao = ao(y, lambda[i], symm, omega = 0.001)
		)

	# estimate linear QR for different taus
		for(j in 1:nq){
			fit <- try(do.call(rq.wfit, args = list(x = x, y = newresponse, tau = tau[j], weights = w, method = method)), silent = TRUE)
			if(!inherits(fit, "try-error")){
			zhat[,j,i] <- drop(x %*% fit$coefficients)
			
			Fitted <- switch(tsf,
				mcjI = invmcjI(zhat[,j,i], lambda[i], symm, dbounded),
				bc = invbc(zhat[,j,i], lambda[i]),
				ao = invao(zhat[,j,i], lambda[i], symm),
			)
			
			res <- y - Fitted
			
			if(tsf == "bc"){
				FLAG <- lambda[i]*zhat[,j,i] + 1 > 0
				Ind[,j,i] <- FLAG
				rejected[j,i] <- mean(!FLAG)
				}

			if(tsf == "ao" & symm == TRUE){
				FLAG <- abs(lambda[i]*zhat[,j,i]/2) - 1 < 0
				Ind[,j,i] <- FLAG
				rejected[j,i] <- mean(!FLAG)
				}
			
			matLoss[j,i] <- l1Loss(res, tau = tau[j], weights = w)
			}
		}
	}
	if(all(is.na(matLoss))) return(list(call = call, y = y, x = x))
	# minimise for lambda
	lambdahat <- apply(matLoss, 1, function(x, lambda) lambda[which.min(x)], lambda = lambda)
} else {
	if(is.null(lambda)) stop("Must specify value for 'lambda' when 'conditional = TRUE'")
	if(length(lambda) != nq) stop("Length of 'lambda' must be the same as length of 'tau'")
	lambdahat <- lambda
}

betahat <- matrix(NA, p, nq)
colnames(betahat) <- tau
Fitted <- matrix(NA, n, nq)
colnames(Fitted) <- tau
fit <- list()
Rho <- function(u, tau) u * (tau - (u < 0))

for(j in 1:nq){
	# transform response with optimal lambda
	newresponse <- switch(tsf,
		mcjI = mcjI(y, lambdahat[j], symm, dbounded, omega = 0.001),
		bc = bc(y, lambdahat[j]),
		ao = ao(y, lambdahat[j], symm, omega = 0.001)
		)
	# fit final model
	z <- do.call(rq.wfit, args = list(x = x, y = newresponse, tau = tau[j], weights = w, method = method))

	betahat[,j] <- coefficients(z)
	tmp <- z$fitted.values
	Fitted[,j] <- switch(tsf,
		mcjI = invmcjI(tmp, lambdahat[j], symm, dbounded),
		bc = invbc(tmp, lambdahat[j]),
		ao = invao(tmp, lambdahat[j], symm)
	)
	class(z) <- "rq"
	z$na.action <- attr(mf, "na.action")
	z$formula <- stats::update(formula, newresponse ~ .)
	z$terms <- mt
	z$xlevels <- .getXlevels(mt, mf)
	z$call <- call
	z$tau <- tau[j]
	z$weights <- w
	z$residuals <- drop(z$residuals)
	z$rho <- sum(Rho(z$residuals, tau[j]))
	z$method <- method
	z$fitted.values <- drop(z$fitted.values)
	attr(z, "na.message") <- attr(m, "na.message")
	z$model <- mf
	fit[[j]] <- z
}

if(isBounded){
	Fitted <- apply(Fitted, 2, function(x,x.r) invmap(x, x.r), x.r = range(y.old))
}

dimnames(betahat) <- list(dimnames(x)[[2]], paste("tau =", format(round(tau, 3))))
names(lambdahat) <- paste("tau =", format(round(tau, 3)))

fit$call <- call
fit$method <- method
fit$mf <- mf
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$y <- y.old
if(isBounded) fit$theta <- y
fit$x <- x
fit$weights <- w
fit$tau <- tau
fit$lambda <- lambdahat
fit$lambda.grid <- if(conditional) NULL else lambda
fit$tsf <- tsf
attr(fit$tsf, "symm") <- symm
attr(fit$tsf, "dbounded") <- dbounded
attr(fit$tsf, "isBounded") <- isBounded
attr(fit$tsf, "npar") <- 1
attr(fit$tsf, "conditional") <- conditional
fit$objective <- matLoss
fit$optimum <- apply(matLoss, 1, function(x) x[which.min(x)])
fit$coefficients <- betahat
fit$fitted.values <- drop(Fitted)
fit$rejected <- rejected
fit$terms <- mt
fit$term.labels <- colnames(x)
fit$rdf <- n - p - 1
fit$fn <- "tsrq"
class(fit) <- "rqt"
return(fit)
}


# Cusum process estimator

rcrq <- function(formula, data = sys.frame(sys.parent()), tsf = "mcjI", symm = TRUE, dbounded = FALSE, lambda = NULL, tau = 0.5, subset, weights, na.action, contrasts = NULL, method = "fn"){

if(any(tau <= 0) | any(tau >= 1)) stop("Quantile index out of range")

nq <- length(tau)

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
if (method == "model.frame") 
	return(mf)
mf$drop.unused.levels <- TRUE
mf[[1L]] <- as.name("model.frame")
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")
x <- model.matrix(mt, mf, contrasts)
y <-  y.old <- model.response(mf, "numeric")
w <- if (missing(weights)) rep(1, length(y)) else as.vector(model.weights(mf))

if(tsf == "mcjII") stop("For two-parameter transformations, see 'tsrq2' and 'nlrq2'")
if(!tsf %in% c("bc","ao","mcjI")) stop("'tsf' not recognized")

isBounded <- (tsf == "mcjI" && dbounded)
isBounded <- tsf == "ao" || isBounded
if(isBounded) y <- map(y)

if(is.null(lambda)){
	lambda <- if(tsf == "ao" & symm == FALSE) seq(-2, 2, by = 0.05)
		else seq(0, 2, by = 0.05)
}

n <- length(y)
p <- ncol(x)
nl <- length(lambda)

matLoss <- rejected <- matrix(NA, nq, nl)

for(i in 1:nl){


# estimate linear QR for for sequence of lambdas

	for(j in 1:nq){
	matLoss[j,i] <- rcLoss(lambda[i], x, y, w, tsf, symm = symm, dbounded = dbounded, tau = tau[j], method.rq = method)
	}

}

if(all(is.na(matLoss))) return(list(call = call, y = y, x = x))

# minimise for lambda
lambdahat <- apply(matLoss, 1, function(x, lambda) lambda[which.min(x)], lambda = lambda)


betahat <- matrix(NA, p, nq)
colnames(betahat) <- tau
Fitted <- matrix(NA, n, nq)
colnames(Fitted) <- tau
fit <- list()
Rho <- function(u, tau) u * (tau - (u < 0))

for(j in 1:nq){
	# transform response with optimal lambda
	newresponse <- switch(tsf,
		mcjI = mcjI(y, lambdahat[j], symm, dbounded, omega = 0.001),
		bc = bc(y, lambdahat[j]),
		ao = ao(y, lambdahat[j], symm, omega = 0.001)
		)
	# fit final model
	z <- do.call(rq.wfit, args = list(x = x, y = newresponse, tau = tau[j], weights = w, method = method))

	betahat[,j] <- coefficients(z)
	tmp <- z$fitted.values
	Fitted[,j] <- switch(tsf,
		mcjI = invmcjI(tmp, lambdahat[j], symm, dbounded),
		bc = invbc(tmp, lambdahat[j]),
		ao = invao(tmp, lambdahat[j], symm)
	)
	class(z) <- "rq"
	z$na.action <- attr(mf, "na.action")
	z$formula <- stats::update(formula, newresponse ~ .)
	z$terms <- mt
	z$xlevels <- .getXlevels(mt, mf)
	z$call <- call
	z$tau <- tau[j]
	z$weights <- w
	z$residuals <- drop(z$residuals)
	z$rho <- sum(Rho(z$residuals, tau[j]))
	z$method <- method
	z$fitted.values <- drop(z$fitted.values)
	attr(z, "na.message") <- attr(m, "na.message")
	z$model <- mf
	fit[[j]] <- z
}

if(isBounded){
	Fitted <- apply(Fitted, 2, function(x,x.r) invmap(x, x.r), x.r = range(y.old))
}

dimnames(betahat) <- list(dimnames(x)[[2]], paste("tau =", format(round(tau, 3))))
names(lambdahat) <- paste("tau =", format(round(tau, 3)))

fit$call <- call
fit$method <- method
fit$mf <- mf
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$y <- y.old
if(isBounded) fit$theta <- y
fit$x <- x
fit$weights <- w
fit$tau <- tau
fit$lambda <- lambdahat
fit$lambda.grid <- lambda
fit$tsf <- tsf
attr(fit$tsf, "symm") <- symm
attr(fit$tsf, "dbounded") <- dbounded
attr(fit$tsf, "isBounded") <- isBounded
attr(fit$tsf, "npar") <- 1
attr(fit$tsf, "conditional") <- FALSE
fit$objective <- matLoss
fit$optimum <- apply(matLoss, 1, function(x) x[which.min(x)])
fit$coefficients <- betahat
fit$fitted.values <- drop(Fitted)
fit$rejected <- rejected
fit$terms <- mt
fit$term.labels <- colnames(x)
fit$rdf <- n - p - 1
fit$fn <- "rcrq"
class(fit) <- "rqt"
return(fit)

}

# Nonlinear estimator

switch_check <- function(l0, l1, tol_ll, t0, t1, tol_theta, rule = "1"){
    deltal <- abs(l1/l0 - 1)
    deltat <- max(abs(t1/t0 - 1))
    switch(rule, `1` = deltal < tol_ll, `2` = deltal < tol_ll && 
        deltat < tol_theta)
}

nlControl <- function(tol_ll = 1e-05, tol_theta = 0.001, check_theta = FALSE, step = NULL, beta = 0.5, gamma = 1.25, reset_step = FALSE, maxit = 1000, smooth = FALSE, omicron = 0.001, verbose = FALSE) 
{
    if (beta > 1 || beta < 0) 
        stop("Beta must be a decreasing factor in (0,1)")
    if (gamma < 1) 
        stop("Beta must be a nondecreasing factor >= 1")
    if (maxit < 0) 
        stop("Number of iterations cannot be negative")
    list(tol_ll = tol_ll, tol_theta = tol_theta, 
        check_theta = check_theta, step = step, beta = beta, 
        gamma = gamma, reset_step = reset_step, maxit = as.integer(maxit),
        smooth = smooth, omicron = omicron, verbose = verbose)
}

nl.fit.rqt <- function(theta, x, y, tau, tsf, symm = TRUE, dbounded = FALSE, control){

step <- control$step
maxit <- control$maxit

theta_0 <- theta
ll_0 <- nlLoss(theta = theta_0, x = x, y = y, tau = tau, tsf = tsf, symm = symm, dbounded = dbounded, smooth = control$smooth, omicron = control$omicron)
eps <- .Machine$double.eps

for(i in 1:maxit) {
	if(control$verbose) cat(paste0("  (", i, ") logLik = ", round(ll_0,12), "\n"))
	# line search
	theta_1 <- theta_0 - attributes(ll_0)$grad*step
	ll_1 <- nlLoss(theta = theta_1, x = x, y = y, tau = tau, tsf = tsf, symm = symm, dbounded = dbounded, smooth = control$smooth, omicron = control$omicron)

	if(ll_1 > ll_0){
		if(control$verbose) cat("  Decreasing step...\n")
		step <- step*control$beta
	} else {
		rule <- if(control$check_theta) "2" else "1"
		check <- switch_check(ll_0, ll_1, control$tol_ll, theta_0, theta_1, control$tol_theta, rule = rule)
		if(check) break
		theta_0 <- theta_1
		ll_0 <- ll_1
		step <- if(control$reset_step) control$loop_step else step*control$gamma
	} 
}

list(par = as.numeric(theta_1), grad = attributes(ll_1)$grad, optimum = as.numeric(ll_1), CONVERGE = if(i==maxit) -1 else i)

}

nlrq1 <- function(formula, data = sys.frame(sys.parent()), tsf = "mcjI", symm = TRUE, dbounded = FALSE, start = NULL, tau = 0.5, subset, weights, na.action, contrasts = NULL, control = list()){

if(any(tau <= 0) | any(tau >= 1)) stop("Quantile index out of range")

nq <- length(tau)

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf$drop.unused.levels <- TRUE
mf[[1L]] <- as.name("model.frame")
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")
x <- model.matrix(mt, mf, contrasts)
y <-  y.old <- model.response(mf, "numeric")
w <- if (missing(weights)) rep(1, length(y)) else as.vector(model.weights(mf))

if(tsf == "mcjII") stop("For two-parameter transformations, see 'tsrq2' and 'nlrq2'")
if(!tsf %in% c("bc","ao","mcjI")) stop("'tsf' not recognized")

isBounded <- (tsf == "mcjI" && dbounded)
isBounded <- tsf == "ao" || isBounded
if(isBounded) y <- map(y)

n <- length(y)
p <- ncol(x)

# starting values
lambda_0 <- if(is.null(start)) 0 else start[1]

newresponse <- switch(tsf,
	mcjI = mcjI(y, lambda = lambda_0, symm = symm, dbounded = dbounded, omega = 0.001),
	bc = bc(y, lambda = lambda_0),
	ao = ao(y, lambda = lambda_0, symm = symm, omega = 0.001)
)

if(is.null(start)){
	start <- c(lambda_0, rq.fit(x, newresponse, tau = 0.5)$coef)
} else {
	if(length(start) != (p + 1)) stop("Length of vector of starting values does not match number of parameters")
}


if (is.null(names(control))) 
	control <- nlControl()
else {
	control_default <- nlControl()
	control_names <- intersect(names(control), names(control_default))
	control_default[control_names] <- control[control_names]
	control <- control_default
}
if (is.null(control$step)) 
	control$step <- sd(as.numeric(y))

# estimate nonlinear QR using gradient search

fit <- list()
betahat <- matrix(NA, p, nq)
lambdahat <- rep(NA, nq)
Fitted <- matrix(NA, n, nq)

for(j in 1:nq){
	fit[[j]] <- try(nl.fit.rqt(theta = start, x = x, y = y, tau = tau[j], tsf = tsf, symm = symm, dbounded = dbounded, control = control))
	if(!inherits(fit[[j]],"try-error")){
		tmp <- x%*%matrix(fit[[j]]$par[-1])
		betahat[,j] <- fit[[j]]$par[-1]
		lambdahat[j] <- fit[[j]]$par[1]
		if(!is.na(lambdahat[j])){
		Fitted[,j] <- switch(tsf,
			mcjI = invmcjI(tmp, lambdahat[j], symm, dbounded),
			bc = invbc(tmp, lambdahat[j]),
			ao = invao(tmp, lambdahat[j], symm)
		)}
	}
}

if(isBounded){
	Fitted <- apply(Fitted, 2, function(x,x.r) invmap(x, x.r), x.r = range(y.old))
}

dimnames(betahat) <- list(dimnames(x)[[2]], paste("tau =", format(round(tau, 3))))
names(lambdahat) <- paste("tau =", format(round(tau, 3)))

fit$call <- call
fit$method <- "gradient-search"
fit$mf <- mf
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$y <- y.old
if(isBounded) fit$theta <- y
fit$x <- x
fit$weights <- w
fit$tau <- tau
fit$lambda <- lambdahat
fit$tsf <- tsf
attr(fit$tsf, "symm") <- symm
attr(fit$tsf, "dbounded") <- dbounded
attr(fit$tsf, "isBounded") <- isBounded
attr(fit$tsf, "npar") <- 1
attr(fit$tsf, "conditional") <- FALSE
fit$coefficients <- betahat
fit$fitted.values <- drop(Fitted)
fit$terms <- mt
fit$term.labels <- colnames(x)
fit$rdf <- n - p - 1
fit$fn <- "nlrq1"
fit$control <- control
class(fit) <- "rqt"
return(fit)
}

######################################################################
# Two-parameter transformations (MCJII)
######################################################################

# Two-stage estimator

tsrq2 <- function(formula, data = sys.frame(sys.parent()), dbounded = FALSE, lambda = NULL, delta = NULL, conditional = FALSE, tau = 0.5, subset, weights, na.action, contrasts = NULL, method = "fn"){

if(any(tau <= 0) | any(tau >= 1)) stop("Quantile index out of range")

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), 
	names(mf), 0)
mf <- mf[c(1, m)]
mf$drop.unused.levels <- TRUE
mf[[1]] <- as.name("model.frame")
mf <- eval.parent(mf)
if (method == "model.frame") 
	return(mf)
mt <- attr(mf, "terms")
x <- model.matrix(mt, mf, contrasts)
y <- y.old <- model.response(mf)
w <- if (missing(weights)) rep(1, length(y)) else as.vector(model.weights(mf))
if(dbounded) y <- map(y)

if(is.null(lambda) && !conditional){
	lambda <- seq(0, 2, by = 0.005)
}
if(is.null(delta) && !conditional){
	delta <- seq(0, 2, by = 0.005)
}
nl <- length(lambda)
nd <- length(delta)

n <- length(y)
p <- ncol(x)
nq <- length(tau)

matLoss <- array(NA, dim = c(nl, nd, nq), dimnames = list(lambda = 1:nl, delta = 1:nd, tau = tau))

if(!conditional){
	for(k in 1:nd){
		for(i in 1:nl){
		# transform response
		newresponse <- mcjII(y, lambda[i], delta[k], dbounded, omega = 0.001)
			for(j in 1:nq){
			fit <- try(do.call(rq.wfit, args = list(x = x, y = newresponse, tau = tau[j], weights = w, method = method)), silent = TRUE)
				
				if(!inherits(fit, "try-error")){
				Fitted <- invmcjII(drop(x %*% fit$coefficients), lambda[i], delta[k], dbounded)
				matLoss[i,k,j] <- l1Loss(y - Fitted, tau = tau[j], weights = w)
				}
			}
		}
	}
	if(all(is.na(matLoss))) return(list(call = call, y = y, x = x))

	# minimise for lambda
	parhat <- apply(matLoss, 3, function(x, lambda, delta){
	m <- which(x == min(x, na.rm = TRUE), arr.ind = TRUE)[1,];
	return(c(lambda[m[1]], delta[m[2]]))}, lambda = lambda, delta = delta)
} else {
	if(is.null(lambda)) stop("Must specify value for 'lambda' when 'conditional = TRUE'")
	if(length(lambda) != nq) stop("Length of 'lambda' must be the same as length of 'tau'")
	if(is.null(delta)) stop("Must specify value for 'delta' when 'conditional = TRUE'")
	if(length(delta) != nq) stop("Length of 'delta' must be the same as length of 'tau'")
	parhat <- matrix(c(lambda, delta), ncol = nq, byrow = TRUE)
}

betahat <- matrix(NA, p, nq)
Fitted <- matrix(NA, n, nq)
colnames(Fitted) <- tau
fit <- list()
Rho <- function(u, tau) u * (tau - (u < 0))

for(j in 1:nq){
	# transform response with optimal lambda
	newresponse <- mcjII(y, parhat[1,j], parhat[2,j], dbounded, omega = 0.001)
	
	# fit final model
	z <- do.call(rq.wfit, args = list(x = x, y = newresponse, tau = tau[j], weights = w, method = method))

	betahat[,j] <- coefficients(z)
	tmp <- z$fitted.values
	Fitted[,j] <- invmcjII(z$fitted.values, parhat[1,j], parhat[2,j], dbounded)
	class(z) <- "rq"
	z$na.action <- attr(mf, "na.action")
	z$formula <- stats::update(formula, newresponse ~ .)
	z$terms <- mt
	z$xlevels <- .getXlevels(mt, mf)
	z$call <- call
	z$tau <- tau[j]
	z$weights <- w
	z$residuals <- drop(z$residuals)
	z$rho <- sum(Rho(z$residuals, tau[j]))
	z$method <- method
	z$fitted.values <- drop(z$fitted.values)
	attr(z, "na.message") <- attr(m, "na.message")
	z$model <- mf
	fit[[j]] <- z
}

if(dbounded){
	Fitted <- apply(Fitted, 2, function(x,x.r) invmap(x, x.r), x.r = range(y.old))
}

dimnames(betahat) <- list(dimnames(x)[[2]], paste("tau =", format(round(tau, 3))))
dimnames(parhat) <- list(c("lambda","delta"), paste("tau =", format(round(tau, 3))))

fit$call <- call
fit$method <- method
fit$mf <- mf
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$y <- y.old
if(dbounded) fit$theta <- y
fit$x <- x
fit$weights <- w
fit$tau <- tau
fit$eta <- parhat
fit$lambda.grid <- if(conditional) NULL else lambda
fit$delta.grid <- if(conditional) NULL else delta
fit$tsf <- "mcjII"
attr(fit$tsf, "dbounded") <- dbounded
attr(fit$tsf, "isBounded") <- dbounded
attr(fit$tsf, "npar") <- 2
attr(fit$tsf, "conditional") <- conditional
fit$objective <- matLoss
fit$optimum <- if(conditional) NA else apply(matLoss, 3, function(x){m <- which(x == min(x, na.rm = TRUE), arr.ind = TRUE)[1,];return(x[m[1],m[2]])})
fit$coefficients <- betahat
fit$fitted.values <- drop(Fitted)
fit$terms <- mt
fit$term.labels <- colnames(x)
fit$rdf <- n - p - 2
fit$fn <- "tsrq2"
class(fit) <- "rqt"
return(fit)
}

# Nelder-Mead optimization (joint estimation)

nlrq2 <- function(formula, data = sys.frame(sys.parent()), dbounded = FALSE, start = NULL, tau = 0.5, subset, weights, na.action, contrasts = NULL){

if(any(tau <= 0) | any(tau >= 1)) stop("Quantile index out of range")

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), 
	names(mf), 0)
mf <- mf[c(1, m)]
mf$drop.unused.levels <- TRUE
mf[[1]] <- as.name("model.frame")
mf <- eval.parent(mf)
mt <- attr(mf, "terms")
x <- model.matrix(mt, mf, contrasts)
y <- y.old <- model.response(mf)
w <- if (missing(weights)) rep(1, length(y)) else as.vector(model.weights(mf))
if(dbounded) y <- map(y)

n <- length(y)
p <- ncol(x)
nq <- length(tau)

if(is.null(start)) start <- rep(0, p + 2)

f <- function(theta, dataLs){

	if(theta[2] < 0) return(Inf)
	Fitted <- invmcjII(dataLs$x %*% matrix(theta[-c(1:2)]), lambda = theta[1], delta = theta[2], dbounded = dataLs$dbounded)
	return(l1Loss(dataLs$y - Fitted, tau = dataLs$tau, weights = dataLs$weights))
}

fit <- list()
betahat <- matrix(NA, p, nq)
parhat <- matrix(NA, 2, nq)
Fitted <- matrix(NA, n, nq)

for(j in 1:nq){
	fit[[j]] <- try(optim(par = start, fn = f, method = "Nelder-Mead", dataLs = list(x = x, y = y, dbounded = dbounded, tau = tau[j], weights = w)), silent = T)

	if(!inherits(fit[[j]], "try-error")){
		betahat[,j] <- fit[[j]]$par[-c(1:2)]
		parhat[,j] <- c(fit[[j]]$par[1], fit[[j]]$par[2])
		Fitted[,j] <- invmcjII(x %*% matrix(betahat[,j]), parhat[1,j], parhat[2,j], dbounded)
	}
}

if(dbounded){
	Fitted <- apply(Fitted, 2, function(x,x.r) invmap(x, x.r), x.r = range(y.old))
}

dimnames(betahat) <- list(dimnames(x)[[2]], paste("tau =", format(round(tau, 3))))
dimnames(parhat) <- list(c("lambda","delta"), paste("tau =", format(round(tau, 3))))


fit$call <- call
fit$method <- "Nelder-Mead"
fit$mf <- mf
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$y <- y.old
if(dbounded) fit$theta <- y
fit$x <- x
fit$weights <- w
fit$tau <- tau
fit$eta <- parhat
fit$tsf <- "mcjII"
attr(fit$tsf, "dbounded") <- dbounded
attr(fit$tsf, "isBounded") <- dbounded
attr(fit$tsf, "npar") <- 2
attr(fit$tsf, "conditional") <- FALSE
fit$coefficients <- betahat
fit$fitted.values <- drop(Fitted)
fit$terms <- mt
fit$term.labels <- colnames(x)
fit$rdf <- n - p - 2
fit$fn <- "nlrq2"
class(fit) <- "rqt"
return(fit)
}

######################################################################
# Print, summary, bootstrap, predict, fitted for class rqt
######################################################################

print.rqt <- function(x, ...){

if (!is.null(cl <- x$call)) {
	cat("call:\n")
	dput(cl)
	cat("\n")
}
type <- if(attr(x$tsf, "isBounded")) "(doubly bounded response)" else "(singly bounded response)"
tsf <- switch(x$tsf,
	mcjI = "Proposal I",
	bc = "Box-Cox",
	ao = "Aranda-Ordaz",
	mcjII = "Proposal II")
if(x$tsf %in% c("mcjI", "ao")){
	tsf <- paste(tsf, if(attr(x$tsf, "symm"))
	"symmetric" else "asymmetric")
}
tsf <- paste(tsf, "transformation", type)

cat(tsf, "\n")
cat("\nOptimal transformation parameter:\n")
if(x$tsf == "mcjII") print(x$eta) else print(x$lambda)

coef <- x$coefficients
cat("\nCoefficients linear model (transformed scale):\n")
print(coef, ...)

nobs <- length(x$y)
p <- ncol(x$x)
rdf <- nobs - p
cat("\nDegrees of freedom:", nobs, "total;", rdf, "residual\n")
if (!is.null(attr(x, "na.message"))) 
	cat(attr(x, "na.message"), "\n")
invisible(x)
}

predict.rqt <- function(object, newdata, na.action = na.pass, type = "response", namevec = NULL, ...){

tau <- object$tau
nq <- length(tau)
tsf <- object$tsf
symm <- attributes(tsf)$symm
dbounded <- attributes(tsf)$dbounded
isBounded <- attributes(tsf)$isBounded

if(tsf == "mcjII"){
	etahat <- object$eta
} else {
	lambdahat <- object$lambda
}

if(!missing(newdata)) {
	mt <- terms(object)
	Terms <- delete.response(mt)
	object$mf <- model.frame(Terms, newdata, na.action = na.action, xlev = object$levels) # model frame
	if (!is.null(cl <- attr(Terms, "dataClasses")))
		.checkMFClasses(cl, object$mf)
	object$x <- model.matrix(Terms, object$mf, contrasts.arg = object$contrasts) # model matrix
	object$data <- newdata # input variables
}

linpred <- object$x %*% object$coefficients

Fitted <- matrix(NA, nrow(linpred), ncol(linpred))
if(type == "link"){
	return(linpred)
}

if(type == "response"){
	if(tsf == "mcjII"){
		for(j in 1:nq){
			Fitted[,j] <- invmcjII(x = linpred[,j], lambda = etahat['lambda',j], delta = etahat['delta',j], dbounded = dbounded)
		}
	} else {
		for(j in 1:nq){
			Fitted[,j] <- switch(tsf,
				mcjI = invmcjI(linpred[,j], lambdahat[j], symm, dbounded),
				bc = invbc(linpred[,j], lambdahat[j]),
				ao = invao(linpred[,j], lambdahat[j], symm))
		}
	}

	if(isBounded){
		Fitted <- apply(Fitted, 2, function(x,x.r) invmap(x, x.r), x.r = range(object$y))
	}
return(Fitted)
}

if(type == "maref"){
	if(is.null(namevec)) stop("When type = 'maref', the argument namevec must be provided")
	if(tsf == "mcjII") stop("Marginal effects not available for tsf = 'mcjII'")
	Fitted <- maref(object, namevec = namevec)
	return(Fitted)

}

}

terms2expr <- function(object){

if(!inherits(object, "terms")) stop("Only objects of class 'terms'")

Irm <- function(x){
	n <- nchar(x)
	flag <- substr(x, 1, 2) == "I(" & substr(x, n, n) == ")"
	if(flag) x <- substr(x, 2, n)
	return(x)
}

x <- object
variables <- as.list(attr(x, "variables"))[-1]
mt <- attr(x, "term.labels")
mt <- sapply(mt, Irm)
mt <- sub(":", "*", mt)
term.labels <- names(mt)

#coefs <- term.labels
#coefs <- gsub(pattern = "\\(", replacement = "", x = coefs)
#coefs <- gsub(pattern = "\\)", replacement = "", x = coefs)
#coefs <- gsub(pattern = "[[:punct:]]", replacement = "", x = coefs)
#coefs <- gsub(pattern = "[[:space:]]", replacement = "", x = coefs)
#coefs <- gsub(pattern = ":", replacement = "_", x = coefs)
#coefs <- paste0("beta.", coefs)
coefs <- paste0("beta", 1:length(term.labels))

val <- as.formula(paste(variables[1], "~", paste(paste(coefs, mt, sep = "*"), collapse = " + ")))
attr(val, "terms") <- as.vector(mt)
attr(val, "labels") <- term.labels
attr(val, "coefs") <- coefs
return(val)

}

maref.rqt <- function(object, namevec){

tau <- object$tau
nq <- length(tau)

tsf <- object$tsf
symm <- attributes(tsf)$symm
dbounded <- attributes(tsf)$dbounded

betahat <- object$coefficients
lambdahat <- object$lambda

# Model frames and matrices
mt <- terms(object)
all_vars <- get_all_vars(delete.response(mt), object$data)

# Work out expression of linear predictor for symbolic derivative
f <- terms2expr(mt)
var_labels <- all.vars(mt)[-1]
g <- parse(text = paste0("function(", paste(var_labels, collapse = ", "), ", ", paste(attr(f, "coefs"), collapse = ", "), "){}"))
d2 <- deriv(expr = f, namevec = as.character(namevec), function.arg = eval(g))
cat("The linear component of the marginal effect is calculated as derivative of", "\n", deparse(f), "\n with respect to", namevec, "\n")

# 

linpred <- object$x %*% betahat
n <- nrow(object$x)
dlinpred <- matrix(NA, n, nq)

for(j in 1:nq){
	argsLs <- as.list(betahat[attr(f, "labels"),j])
	names(argsLs) <- attr(f, "coefs")
	argsLs <- c(as.list(all_vars), argsLs)
	D <- do.call(d2, args = argsLs)
	dlinpred[,j] <- attr(D, "gradient")
}

val <- matrix(NA, n, nq)
for(j in 1:nq)(
val[,j] <- switch(tsf,
	mcjI = d1mcjI(linpred[,j], lambdahat[j], symm, dbounded),
	bc = d1bc(linpred[,j], lambdahat[j]),
	ao = d1ao(linpred[,j], lambdahat[j], symm),
	)*dlinpred[,j]
)

return(val)

}

boot.rqt <- function(data, inds, object){

tau <- object$tau
nq <- length(tau)
all.obs <- rownames(object$x)
n <- length(all.obs)
flag <- !object$tsf %in% c("mcjII")
nn <- if(flag) c(object$term.labels, "lambda") else c(object$term.labels, "lambda", "delta")

if(nq == 1){
	fit <- stats::update(object, data = data[inds,])
	val <- fit$coefficients
	val <- if(flag) c(val, fit$lambda) else c(val, fit$eta)
} else {
	fit <- stats::update(object, data = data[inds,])
	val <- fit$coefficients
	val <- if(flag) rbind(val, fit$lambda) else rbind(val, fit$eta)
}

val <- as.vector(val)
names(val) <- rep(nn, nq)
return(val)

}

summary.rqt <- function(object, alpha = 0.05, se = "boot", R = 50, sim = "ordinary", stype = "i", conditional = FALSE, ...){

call <- match.call(expand.dots = TRUE)

tau <- object$tau
nq <- length(tau)
mpar <- ncol(object$x)
ntot <- mpar + attr(object$tsf, "npar")
if(mpar == 1) object$mf$intercept <- 1

flag <- (!conditional) && (se %in% c("iid","nid"))

if(object$tsf == "mcjII" && flag)  stop("Summary not available. Change to 'se = boot'.")
if(object$fn == "rcrq" && flag) stop("Summary not available. Change to 'se = boot'.")
if(conditional && object$fn == "nlrq2") stop("Conditional inference not available for objects from 'nlrq2'. Change to 'conditional = FALSE'.")


if(attr(object$tsf, "conditional")){
	if(!conditional) warning("Main call 'conditional = TRUE'")
	conditional <- TRUE
}

if(conditional){
	ans <- B <- list()
	for(j in 1:nq){
		Args <- list()
		Args$object <- object[[j]]
		Args$se <- se
		if(se == "boot") Args$R <- R
		nn <- c("covariance","hs","bsmethod","mofn","iid")
		nn <- nn[pmatch(names(call), nn, duplicates.ok = FALSE)]
		nn <- nn[!is.na(nn)]
		if(length(nn) > 0) {tmp <- as.list(call[[nn]]); names(tmp) <- nn; Args <- c(Args, tmp)}
		tmp <- do.call(summary.rq, args = Args)
		ans[[j]] <- tmp$coefficients
		if(!is.null(tmp$B)) B[[j]] <- tmp$B
		if(object$tsf == "mcjII") {
			tmp <- matrix(NA, nrow = 2, ncol = ncol(ans[[j]]))
			tmp[,1] <- object$eta[,j]
			rownames(tmp) <- c("lambda","delta")
		} else {
			tmp <- matrix(c(object$lambda[j], rep(NA, ncol(ans[[j]]) - 1)), nrow = 1)
			rownames(tmp) <- "lambda"
		}
		ans[[j]] <- rbind(ans[[j]], tmp)
	}
	object$B <- B
} else {
	if(se == "boot"){
		Args <- list()
		Args$data <- object$mf
		Args$statistic <- boot.rqt
		Args$object <- object
		Args$R <- R
		Args$sim <- sim
		Args$stype <- stype
		nn <- c("strata","L","m","weights","ran.gen","mle","simple","parallel","ncpus","cl")
		nn <- nn[pmatch(names(call), nn, duplicates.ok = FALSE)]
		nn <- nn[!is.na(nn)]
		if(length(nn) > 0) {tmp <- as.list(call[[nn]]); names(tmp) <- nn; Args <- c(Args, tmp)}
		B <- do.call(boot, args = Args)
		ci <- mapply(boot.ci, index = 1:(ntot*nq), MoreArgs = list(boot.out = B, conf = 1 - alpha, type = "perc"))[4,]
		ci <- t(sapply(ci, function(x) x[4:5]))

		S <- cov(B$t, use = "complete.obs")
		val <- cbind(B$t0, apply(B$t, 2L, mean, na.rm=TRUE) - B$t0, sqrt(diag(S)), ci)
		nn <- c("Value", "Bias", "Std. Error", "Lower bound", "Upper bound")
		colnames(val) <- nn
		
		maxn <- seq(0, ntot*nq, by = ntot)[-1]
		minn <- seq(1, ntot*nq, by = ntot)
		ans <- list()
		for(j in 1:nq){
			ans[[j]] <- val[minn[j]:maxn[j], ]
		}
		names(ans) <- tau
		object$B <- B
	} else if(se %in% c("iid", "nid")) {
		ans <- list()
		S <- se.rqt(object, se = se)
		for(j in 1:nq){
			val <- c(object[[j]]$coefficients, lambda = object$lambda[j])
			val <- cbind(val, sqrt(diag(S[,,j])), val - sqrt(diag(S[,,j]))*qnorm(1-alpha/2), val + sqrt(diag(S[,,j]))*qnorm(1-alpha/2))
			nn <- c("Value", "Std. Error", "Lower bound", "Upper bound")
			colnames(val) <- nn
			ans[[j]] <- val
		}
		names(ans) <- tau
	} else ans <- NULL	
}

attr(ans, "conditional") <- conditional
object$coefficients <- ans
object$call <- call
class(object) <- c("summary.rqt", class(object))
return(object)

}

print.summary.rqt <- function(x, ...){

if (!is.null(cl <- x$call)) {
	cat("call:\n")
	dput(cl)
	cat("\n")
}

tau <- x$tau
nq <- length(tau)
mpar <- ncol(x$x)

type <- if(attr(x$tsf, "isBounded")) "(doubly bounded response)" else "(singly bounded response)"
tsf <- switch(x$tsf,
	mcjI = "Proposal I",
	bc = "Box-Cox",
	ao = "Aranda-Ordaz",
	mcjII = "Proposal II")
if (x$tsf %in% c("mcjI", "ao")){ 
	tsf <- paste(tsf, if (attr(x$tsf, "symm")) 
		"symmetric"
	else "asymmetric")
}
tsf <- paste(tsf, "transformation", type)

cat(tsf, "\n")

conditional <- if(attr(x$coefficients, "conditional")) "conditional" else "unconditional"
cat("\nSummary for", conditional, "inference\n")

for(i in 1:nq){
cat("\ntau = ", tau[i], "\n")

cat("\nOptimal transformation parameter:\n")
print(x$coefficients[[i]][-c(1:mpar),], ...)

cat("\nCoefficients linear model (transformed scale):\n")
print(x$coefficients[[i]][1:mpar,], ...)
}

nobs <- length(x$y)
p <- ncol(x$x)
rdf <- nobs - p
cat("\nDegrees of freedom:", nobs, "total;", rdf, "residual\n")
if (!is.null(attr(x, "na.message"))) 
	cat(attr(x, "na.message"), "\n")
invisible(x)


}

fitted.rqt <- function(object, ...){

return(object$fitted.values)

}

residuals.rqt <- function(object, ...){

return(object$y - object$fitted.values)

}

coef.rqt <- coefficients.rqt <- function(object, all = FALSE, ...){

if(!inherits(object, "rqt")) stop("Class 'rqt' only")

tau <- object$tau
nq <- length(tau)
tsf <- object$tsf
nn <- object$term.labels

if(all){
	nn <- if(tsf %in% "mcjII") c(nn, "lambda", "delta") else c(nn, "lambda")
}

tpar <- if(tsf %in% "mcjII") object$eta else object$lambda

if(!all){
	ans <- object$coefficients
} else {
	ans <- if(nq == 1) c(object$coefficients, tpar)
		else rbind(object$coefficients, tpar)
}

if(nq == 1){
	names(ans) <- nn
} else {
	rownames(ans) <- nn
	colnames(ans) <- paste("tau =", tau)
}

return(ans)

}

##################################################
### Asymptotics
##################################################

d1bc <- function(x, lambda){
zero <- rep(0, length(x))
g1 <- deriv(~ (lambda*x + 1)^(1/lambda), "x", func = function(x,lambda){})
g2 <- deriv(~ exp(x), "x", func = function(x){})
    if (lambda != 0) {
        val <- as.numeric(attributes(g1(x, lambda))$gradient)
		val <- ifelse(lambda * x + 1 > 0, val, zero)
    }
    else {
        val <- as.numeric(attributes(g2(x))$gradient)
    }
    return(val)
}

d2bc <- function(x, lambda){
g1 <- deriv(~ (lambda*x + 1)^(1/lambda), "lambda", func = function(lambda,x){})
    if (lambda != 0) {
        val <- as.numeric(attributes(g1(lambda,x))$gradient)
    }
    else {
        val <- as.numeric(attributes(g1(0.00001,x))$gradient)
    }
    return(val)
}

d1mcjI <- function(x, lambda, symm, dbounded){

if(dbounded){
	if(symm){
	g1 <- deriv(~ (lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)/(1 + (lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)), "x", func = function(x, lambda){})
	g2 <- deriv(~ exp(x)/(1+exp(x)), "x", func = function(x){})
		if(lambda != 0){
			val <- as.numeric(attributes(g1(x, lambda))$gradient)
		} else {
			val <- as.numeric(attributes(g2(x))$gradient)
		}
	} else {
	g1 <- deriv(~ 1 - exp(-(lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)), "x", func = function(x, lambda){})
	g2 <- deriv(~ 1 - exp(-exp(x)), "x", func = function(x){})
		if(lambda != 0){
			val <- as.numeric(attributes(g1(x, lambda))$gradient)
		} else {
			val <- as.numeric(attributes(g2(x))$gradient)
		}
	}
} else {
	if(symm){
	g1 <- deriv(~ (lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda), "x", func = function(x, lambda){})
	g2 <- deriv(~ exp(x), "x", func = function(x){})
		if (lambda != 0) {
			val <- as.numeric(attributes(g1(x, lambda))$gradient)
		} else {
			val <- as.numeric(attributes(g2(x))$gradient)
		}
	} else {
	g1 <- deriv(~ exp((lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)) - 1, "x", func = function(x, lambda){})
	g2 <- deriv(~ exp(exp(x)) - 1, "x", func = function(x){})
		if (lambda != 0) {
			val <- as.numeric(attributes(g1(x, lambda))$gradient)
		} else {
			val <- as.numeric(attributes(g2(x))$gradient)
		}
	}
}

return(val)

}

d2mcjI <- function(x, lambda, symm, dbounded){

if(dbounded){
	if(symm){
	g1 <- deriv(~ (lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)/(1 + (lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)), "lambda", func = function(lambda, x){})
		if(lambda != 0){
			val <- as.numeric(attributes(g1(lambda, x))$gradient)
		} else {
			val <- as.numeric(attributes(g1(0.00001,x))$gradient)
		}
	} else {
	g1 <- deriv(~ 1 - exp(-(lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)), "lambda", func = function(lambda, x){})
		if(lambda != 0){
			val <- as.numeric(attributes(g1(lambda, x))$gradient)
		} else {
			val <- as.numeric(attributes(g1(0.00001,x))$gradient)
		}
	}
} else {
	if(symm){
	g1 <- deriv(~ (lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda), "lambda", func = function(lambda, x){})
		if (lambda != 0) {
			val <- as.numeric(attributes(g1(lambda, x))$gradient)
		} else {
			val <- as.numeric(attributes(g1(0.00001,x))$gradient)
		}
	} else {
	g1 <- deriv(~ exp((lambda*x + sqrt(1 + (lambda*x)^2))^(1/lambda)) - 1, "lambda", func = function(lambda, x){})
		if (lambda != 0) {
			val <- as.numeric(attributes(g1(lambda, x))$gradient)
		} else {
			val <- as.numeric(attributes(g1(0.00001,x))$gradient)
		}
	}
}

return(val)

}

d1ao <- function(x, lambda, symm){
zero <- rep(0, length(x))
if(symm){
g1 <- deriv(~ (1 + lambda*x/2)^(1/lambda)/((1 + lambda*x/2)^(1/lambda) + (1 - lambda*x/2)^(1/lambda)), "x", func = function(x, lambda){})
g2 <- deriv(~ exp(x)/(1+exp(x)), "x", func = function(x){})
	if(lambda != 0){
		val <- as.numeric(attributes(g1(x, lambda))$gradient)
		val <- ifelse(abs(lambda * x/2) < 1, val, zero)
	} else {
		val <- as.numeric(attributes(g2(x))$gradient)
	}
} else {
g1 <- deriv(~ 1 - (1 + lambda*exp(x))^(-1/lambda), "x", func = function(x, lambda){})
g2 <- deriv(~ 1 - exp(-exp(x)), "x", func = function(x){})
	if(lambda != 0){
		val <- as.numeric(attributes(g1(x, lambda))$gradient)
		val <- ifelse(lambda * exp(x) > -1, val, zero)
		} else {
		val <- as.numeric(attributes(g2(x))$gradient)
	}
}

return(val)

}

d2ao <- function(x, lambda, symm){
zero <- rep(0, length(x))
if(symm){
g1 <- deriv(~ (1 + lambda*x/2)^(1/lambda)/((1 + lambda*x/2)^(1/lambda) + (1 - lambda*x/2)^(1/lambda)), "lambda", func = function(lambda, x){})
	if(lambda != 0){
		val <- as.numeric(attributes(g1(lambda, x))$gradient)
		val <- ifelse(abs(lambda * x/2) < 1, val, zero)
	} else {
		val <- as.numeric(attributes(g1(0.00001,x))$gradient)
	}
} else {
g1 <- deriv(~ 1 - (1 + lambda*exp(x))^(-1/lambda), "lambda", func = function(lambda, x){})
	if(lambda != 0){
		val <- as.numeric(attributes(g1(lambda, x))$gradient)
		val <- ifelse(lambda * exp(x) > -1, val, zero)
		} else {
		val <- as.numeric(attributes(g1(0.00001,x))$gradient)
	}
}

return(val)

}

se.rqt <- function(object, se = "nid"){


tau <- object$tau
nq <- length(tau)
tsf <- object$tsf
symm <- attributes(tsf)$symm
dbounded <- attributes(tsf)$dbounded
isBounded <- attributes(tsf)$isBounded
lambdahat <- object$lambda

betahat <- as.matrix(object$coefficients)
linpred <- predict(object, type = "link")
fis <- sparsity.rqt(object, se = se)$density # density of 'u = y - hinv(xb)' 

x <- object$x
n <- nrow(x)
p <- ncol(x)

g1 <- g2 <- matrix(NA, n, nq)
dbl <- matrix(NA, p, nq)
V <- array(NA, dim = c(p + 1, p + 1, nq))

for(j in 1:nq){
	g1[,j] <- switch(tsf,
		mcjI = d1mcjI(linpred[,j], lambdahat[j], symm, dbounded),
		bc = d1bc(linpred[,j], lambdahat[j]),
		ao = d1ao(linpred[,j],lambdahat[j], symm)
		)

	g2[,j] <- switch(tsf,
		mcjI = d2mcjI(linpred[,j], lambdahat[j], symm, dbounded),
		bc = d2bc(linpred[,j], lambdahat[j]),
		ao = d2ao(linpred[,j], lambdahat[j], symm)
		)
	f0 <- fis[,j]
	
	dbl[,j] <- - solve(crossprod(sqrt(f0 * g1[,j]) * x)/n) %*% matrix(colMeans((f0 * g2[,j] * x)))

	A <- rbind(cbind(diag(p), matrix(0, p, p), rep(0, p)),
		c(rep(0,p),dbl[,j],1))

	d2 <- cbind(g1[,j] * x, g2[,j])
	d <- cbind(x,d2)
	H <- A %*% (t(f0*d) %*% d2)/n
	Hinv <- try(chol2inv(chol(H)), silent = TRUE)
	if(inherits(Hinv, "try-error")) Hinv <- try(solve(H), silent = TRUE)
	if(inherits(Hinv, "try-error")){
		Hinv <- matrix(NA, p + 1, p + 1)
		warning("Singular 'H' matrix")
	}
	L <- tau[j] * (1 - tau[j]) * A %*% (crossprod(d)/n) %*% t(A)

	V[,,j] <- Hinv %*% L %*% t(Hinv)/n
}

return(V)

}

sparsity.rqt <- function(object, se = "nid", hs = TRUE){
    mt <- terms(object)
    m <- model.frame(object)
    y <- model.response(m)
    x <- model.matrix(mt, m, contrasts = object$contrasts)
    wt <- model.weights(object$model)
    taus <- object$tau
    nt <- length(taus)
    eps <- .Machine$double.eps^(2/3)

    vnames <- dimnames(x)[[2]]
    residm <- sweep(- predict(object, type = "response"), 1, y, FUN = "+")
    n <- length(y)
    p <- length(coefficients(object, all = TRUE))
    rdf <- n - p
    if (!is.null(wt)) {
        residm <- residm * wt
        x <- x * wt
        y <- y * wt
    }
    if (is.null(se)) {
		se <- "nid"
    }

spar <- dens <- matrix(NA, n, nt)
for(i in 1:nt){

tau <- taus[i]

    if (se == "iid") {
		resid <- residm[,i]
        pz <- sum(abs(resid) < eps)
        h <- max(p + 1, ceiling(n * bandwidth.rq(tau, n, hs = hs)))
        ir <- (pz + 1):(h + pz + 1)
        ord.resid <- sort(resid[order(abs(resid))][ir])
        xt <- ir/(n - p)
        spar[,i] <- rq(ord.resid ~ xt)$coef[2]
        dens[,i] <- 1/spar[,i]
    }
    else if (se == "nid") {
        h <- bandwidth.rq(tau, n, hs = hs)
        if (tau + h > 1) 
            stop("tau + h > 1:  error in summary.rq")
        if (tau - h < 0) 
            stop("tau - h < 0:  error in summary.rq")
		call <- getCall(object)
		call$tau <- tau + h
		bhi <- eval(call, attr(terms(object), ".Environment"), parent.frame())
		call$tau <- tau - h
        blo <- eval(call, attr(terms(object), ".Environment"), parent.frame())
        dyhat <- predict(bhi, type = "response") - predict(blo, type = "response")
        if (any(dyhat <= 0)) 
            warning(paste(sum(dyhat <= 0), "non-positive fis"))
        f <- pmax(0, (2 * h)/(dyhat - eps))
        dens[,i] <- f
		spar[,i] <- 1/f
    }
    else if (se == "ker") {
        h <- bandwidth.rq(tau, n, hs = hs)
        if (tau + h > 1) 
            stop("tau + h > 1:  error in summary.rq")
        if (tau - h < 0) 
            stop("tau - h < 0:  error in summary.rq")
        uhat <- c(residm[,i])
        h <- (qnorm(tau + h) - qnorm(tau - h)) * min(sqrt(var(uhat)), 
            (quantile(uhat, 0.75) - quantile(uhat, 0.25))/1.34)
        f <- dnorm(uhat/h)/h
        dens[,i] <- f
		spar[,i] <- 1/f
    }
}# loop i

	colnames(dens) <- colnames(spar) <- taus
    return(list(density = dens, sparsity = spar, bandwidth = h))
}

sparsity.rq <- sparsity.rqs <-function(object, se = "nid", hs = TRUE){
    mt <- terms(object)
    m <- model.frame(object)
    y <- model.response(m)
    x <- model.matrix(mt, m, contrasts = object$contrasts)
    wt <- model.weights(object$model)
    taus <- object$tau
    nq <- length(taus)
    eps <- .Machine$double.eps^(2/3)

    vnames <- dimnames(x)[[2]]
    residm <- as.matrix(object$residuals)
    n <- length(y)
    p <- nrow(as.matrix(object$coef))
    rdf <- n - p
    if (!is.null(wt)) {
        residm <- residm * wt
        x <- x * wt
        y <- y * wt
    }
    if (is.null(se)) {
		se <- "nid"
    }

spar <- dens <- matrix(NA, n, nq)
for(i in 1:nq){

tau <- taus[i]

    if (se == "iid") {
		resid <- residm[,i]
		pz <- sum(abs(resid) < eps)
        h <- max(p + 1, ceiling(n * bandwidth.rq(tau, n, hs = hs)))
        ir <- (pz + 1):(h + pz + 1)
        ord.resid <- sort(resid[order(abs(resid))][ir])
        xt <- ir/(n - p)
        spar[,i] <- rq(ord.resid ~ xt)$coef[2]
        dens[,i] <- 1/spar[,i]
    }
    else if (se == "nid") {
        h <- bandwidth.rq(tau, n, hs = hs)
        if (tau + h > 1) 
            stop("tau + h > 1:  error in summary.rq")
        if (tau - h < 0) 
            stop("tau - h < 0:  error in summary.rq")
        bhi <- rq.fit.fnb(x, y, tau = tau + h)$coef
        blo <- rq.fit.fnb(x, y, tau = tau - h)$coef
        dyhat <- x %*% (bhi - blo)
        if (any(dyhat <= 0)) 
            warning(paste(sum(dyhat <= 0), "non-positive fis"))
        f <- pmax(0, (2 * h)/(dyhat - eps))
        dens[,i] <- f
	  spar[,i] <- 1/f
    }
    else if (se == "ker") {
        h <- bandwidth.rq(tau, n, hs = hs)
        if (tau + h > 1) 
            stop("tau + h > 1:  error in summary.rq")
        if (tau - h < 0) 
            stop("tau - h < 0:  error in summary.rq")
        uhat <- c(residm[,i])
        h <- (qnorm(tau + h) - qnorm(tau - h)) * min(sqrt(var(uhat)), 
            (quantile(uhat, 0.75) - quantile(uhat, 0.25))/1.34)
        f <- dnorm(uhat/h)/h
        dens[,i] <- f
	  spar[,i] <- 1/f
    }
}# loop i

	colnames(dens) <- colnames(spar) <- taus
    return(list(density = dens, sparsity = spar, bandwidth = h))
}


##################################################
### Restricted quantiles
##################################################

rrq <- function(formula, tau, data, subset, weights, na.action, method = "fn", model = TRUE, contrasts = NULL, ...){

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0)
mf <- mf[c(1, m)]
mf$drop.unused.levels <- TRUE
mf[[1]] <- as.name("model.frame")
mf <- eval.parent(mf)
if (method == "model.frame")
	return(mf)
mt <- attr(mf, "terms")
weights <- as.vector(model.weights(mf))
y <- model.response(mf)
x <- model.matrix(mt, mf, contrasts)

eps <- .Machine$double.eps^(2/3)
nq <- length(tau)

if (nq > 1) {
        if (any(tau < 0) || any(tau > 1)) 
            stop("invalid tau:  taus should be >= 0 and <= 1")
        if (any(tau == 0)) 
            tau[tau == 0] <- eps
        if (any(tau == 1)) 
            tau[tau == 1] <- 1 - eps
}

fit.lad <- {
if (length(weights)) 
	rq.wfit(x, y, tau = 0.5, weights, method, ...)
	else rq.fit(x, y, tau = 0.5, method, ...)
}
r.lad <- fit.lad$residuals
r.abs <- abs(fit.lad$residuals)
beta <- fit.lad$coefficients

#fit.lad <- rq(formula, tau = 0.5, data = data, method = method)
#data$r.lad <- fit.lad$residuals
#data$r.abs <- abs(fit.lad$residuals)
#beta <- fit.lad$coefficients

fit.lad <- {
if (length(weights)) 
	rq.wfit(x, r.abs, tau = 0.5, weights, method, ...)
	else rq.fit(x, r.abs, tau = 0.5, method, ...)
}
s.lad <- fit.lad$fitted.values
gamma <- fit.lad$coefficients

#fit.lad <- rq(stats::update.formula(formula, r.abs ~ .), tau = 0.5, data = data, method = method)
#data$s.lad <- fit.lad$fitted
#gamma <- fit.lad$coefficients

zeta <- rep(0, nq)
for (i in 1:nq) {
	zeta[i] <- {
	if (length(weights)) 
		rq.wfit(matrix(s.lad), matrix(r.lad), tau = tau[i], weights, method, ...)$coefficients
		else rq.fit(matrix(s.lad), matrix(r.lad), tau = tau[i], method, ...)$coefficients
	}
}

#zeta <- rq(r.lad ~ s.lad - 1, tau = tau, data = data, method = method)$coefficients

if (nq > 1){
	coef <- apply(outer(matrix(gamma, nrow = 1), zeta, "*"), 3, function(x, b) x + b, b = beta)
	taulabs <- paste0("tau = ", format(round(tau, 3)))
	dimnames(coef) <- list(dimnames(x)[[2]], taulabs)
} else {
	coef <- as.numeric(beta + zeta * gamma)
}


fit <- list(coefficients = coef, zeta = zeta, beta = beta, gamma = gamma, tau = tau)
fit$na.action <- attr(mf, "na.action")
fit$formula <- formula
fit$terms <- mt
fit$xlevels <- .getXlevels(mt, mf)
fit$call <- call
fit$weights <- weights
fit$method <- method
fit$x <- x
fit$y <- y
fit$fitted.values <- drop(x %*% coef)
fit$residuals <- drop(y - x %*% coef)
attr(fit, "na.message") <- attr(m, "na.message")
if (model)
	fit$model <- mf
class(fit) <- "rrq"
return(fit)
}

rrq.fit <- function(x, y, tau, method = "fn", ...){

if(length(tau) > 1) stop("only one quantile")

fit.lad <- rq.fit(x, y, tau = 0.5, method = method, ...)
r.lad <- fit.lad$residuals
r.abs <- abs(fit.lad$residuals)
beta <- fit.lad$coefficients

fit.lad <- rq.fit(x, r.abs, tau = 0.5, method = method, ...)
s.lad <- fit.lad$fitted.values
gamma <- fit.lad$coefficients

zeta <- rq.fit(s.lad, r.lad, tau = tau, method = method, ...)$coefficients

val <- beta + zeta * gamma

return(list(coefficients = val, zeta = zeta, beta = beta, gamma = gamma, tau = tau))
}

rrq.wfit <- function(x, y, tau, weights, method = "fn", ...){

if(length(tau) > 1) stop("only one quantile")

fit.lad <- rq.wfit(x, y, tau = 0.5, weights, method = method, ...)
r.lad <- fit.lad$residuals
r.abs <- abs(fit.lad$residuals)
beta <- fit.lad$coefficients

fit.lad <- rq.wfit(x, r.abs, tau = 0.5, weights, method = method, ...)
s.lad <- fit.lad$fitted.values
gamma <- fit.lad$coefficients

zeta <- rq.wfit(s.lad, r.lad, tau = tau, weights, method = method, ...)$coefficients

val <- beta + zeta * gamma

return(list(coefficients = val, zeta = zeta, beta = beta, gamma = gamma, tau = tau, weights = weights))
}

boot.rrq <- function(data, inds, object){

tau <- object$tau
nq <- length(tau)
all.obs <- rownames(object$x)
n <- length(all.obs)
nn <- dimnames(object$coefficients)[[1]]

fit <- stats::update(object, data = data[inds,])
val <- fit$coefficients

val <- as.vector(val)
names(val) <- rep(nn, nq)
return(val)

}

summary.rrq <- function(object, alpha = 0.05, se = "boot", R = 50, sim = "ordinary", stype = "i", ...){

call <- match.call(expand.dots = TRUE)

tau <- object$tau
nq <- length(tau)
ntot <- ncol(object$x)

if(se == "boot"){
	Args <- list()
	Args$data <- object$model
	Args$statistic <- boot.rrq
	Args$object <- object
	Args$R <- R
	Args$sim <- sim
	Args$stype <- stype
	nn <- c("strata","L","m","weights","ran.gen","mle","simple","parallel","ncpus","cl")
	nn <- nn[pmatch(names(call), nn, duplicates.ok = FALSE)]
	nn <- nn[!is.na(nn)]
	if(length(nn) > 0) {tmp <- as.list(call[[nn]]); names(tmp) <- nn; Args <- c(Args, tmp)}
	B <- do.call(boot, args = Args)
	ci <- mapply(boot.ci, index = 1:(ntot*nq), MoreArgs = list(boot.out = B, conf = 1 - alpha, type = "perc"))[4,]
	ci <- t(sapply(ci, function(x) x[4:5]))

	S <- cov(B$t, use = "complete.obs")
	val <- cbind(B$t0, apply(B$t, 2L, mean, na.rm=TRUE) - B$t0, sqrt(diag(S)), ci)
	nn <- c("Value", "Bias", "Std. Error", "Lower bound", "Upper bound")
	colnames(val) <- nn
	
	maxn <- seq(0, ntot*nq, by = ntot)[-1]
	minn <- seq(1, ntot*nq, by = ntot)
	ans <- list()
	for(j in 1:nq){
		ans[[j]] <- val[minn[j]:maxn[j], ]
	}
	names(ans) <- tau
	object$B <- B
} else {ans <- NULL}


object$coefficients <- ans
object$call <- call
class(object) <- c("summary.rrq", class(object))
return(object)

}

predict.rrq <- function(object, newdata, na.action = na.pass, ...){


tau <- object$tau
nq <- length(tau)
betahat <- object$coefficients

if(missing(newdata)) {x <- object$x} else {
	objt <- terms(object)
	Terms <- delete.response(objt)
	m <- model.frame(Terms, newdata, na.action = na.action, 
		xlev = object$levels)
	if (!is.null(cl <- attr(Terms, "dataClasses"))) 
		.checkMFClasses(cl, m)
	x <- model.matrix(Terms, m, contrasts.arg = object$contrasts)
}

return(x %*% betahat)

}

print.rrq <- function(x, ...){

class(x) <- "rqs"
print.rqs(x, ...)

}

print.summary.rrq <- function(x, ...){

if (!is.null(cl <- x$call)) {
	cat("call:\n")
	dput(cl)
	cat("\n")
}

tau <- x$tau
nq <- length(tau)
mpar <- ncol(x$x)

cat("\nSummary for restricted regression quantiles\n")

for(i in 1:nq){
cat("\ntau = ", tau[i], "\n")

cat("\nCoefficients linear model:\n")
print(x$coefficients[[i]][1:mpar,], ...)
}

nobs <- length(x$y)
p <- ncol(x$x)
rdf <- nobs - p
cat("\nDegrees of freedom:", nobs, "total;", rdf, "residual\n")
if (!is.null(attr(x, "na.message"))) 
	cat(attr(x, "na.message"), "\n")
invisible(x)

}

##################################################
### Multiple imputation
##################################################

mice.impute.rq <- function (y, ry, x, tsf = "none", symm = TRUE, dbounded = FALSE, lambda = NULL, x.r = NULL, par = NULL, conditional = TRUE, epsilon = 0.001, method.rq = "fn", ...) {

	if(!tsf %in% c("none", "mcjI", "bc", "ao")) stop(paste("Transformation"), tsf, "not available")
	if(is.null(x.r)) x.r <- range(y, na.rm = TRUE)
    isDbounded <- (tsf == "mcjI" && dbounded)
    isDbounded <- tsf == "ao" || isDbounded

    y.old <- y
	x <- cbind(1, as.matrix(x))

	m <- sum(ry)
	n <- sum(!ry)
    p <- ncol(x)
	sel <- sample(1:m, m, replace = TRUE)
	
    xobs <- x[ry, ]
	xobs <- xobs[sel,]
    xmis <- x[!ry, ]
	u <- round(runif(n, epsilon, 1 - epsilon) * 1000)
	u <- ifelse(u %in% c(1:4, 996:999), u/1000, (u - u%%5)/1000)
	taus <- unique(u)
	nt <- length(taus)
	if(tsf == "none") conditional <- TRUE
	
	if(conditional){
		if (is.null(lambda)) lambda <- 0
		if (tsf %in% c("mcjI", "bc", "ao")) {
			if (isDbounded) y <- map(y, x.r = x.r)
			z <- switch(tsf, mcjI = mcjI(y, lambda, symm, dbounded, 
            omega = 0.001), bc = bc(y, lambda), ao = ao(y, lambda, 
            symm, omega = 0.001))
		} else if(tsf == "none"){
        z <- y
		}
		yobs <- z[ry]
		yobs <- yobs[sel]
		fit <- matrix(NA, p, nt)
		for (j in 1:nt) {
			fit[, j] <- as.numeric(rq.fit(xobs, yobs, tau = taus[j], 
				method = method.rq)$coefficients)
		}
		ypred <- xmis %*% fit
		ypred <- diag(ypred[, match(u, taus), drop = FALSE])
		if(tsf %in% c("mcjI", "bc", "ao")) {
			val <- switch(tsf, mcjI = invmcjI(ypred, lambda, symm, 
				dbounded), bc = invbc(ypred, lambda), ao = invao(ypred, 
				lambda, symm))
			if (isDbounded) val <- invmap(val, x.r)
		} else {val <- ypred}
	} else {
		yobs <- y.old[ry]
		yobs <- yobs[sel]
		ypred <- matrix(NA, n, nt)
		fit <- nlrq1(yobs ~ xobs - 1, tsf = tsf, symm = symm, dbounded = dbounded, tau = taus)
		lambda <- fit$lambda
		lambda[is.na(lambda)] <- 0
		fit <- tsrq(yobs ~ xobs - 1, tsf = tsf, symm = symm, dbounded = dbounded, tau = taus, conditional = TRUE, lambda = lambda, method = method.rq)
		for(j in 1:nt) {
			ypred[,j] <- invmcjI(xmis%*%fit$coef[ , j, drop = FALSE], lambda = lambda[j], symm = symm, dbounded = dbounded)
		} # for
		val <- diag(ypred[, match(u, taus), drop = FALSE])
		if (isDbounded) val <- invmap(val, x.r)
	} # else

return(val)

}

# Impute using restricted quantiles

mice.impute.rrq <- function (y, ry, x, tsf = "none", symm = TRUE, dbounded = FALSE, lambda = NULL, epsilon = 0.001, method.rq = "fn", ...) 
{
    x <- cbind(1, as.matrix(x))
	y.old <- y
	isDbounded <- (tsf == "mcjI" && dbounded)
	isDbounded <- tsf == "ao" || isDbounded

	if(is.null(lambda))
		lambda <- 0

	if(tsf %in% c("mcjI","bc","ao")){
		if(isDbounded) y <- map(y)
		z <- switch(tsf,
			mcjI = mcjI(y, lambda, symm, dbounded, omega = 0.001),
			bc = bc(y, lambda),
			ao = ao(y, lambda, symm, omega = 0.001)
			)
	} else {z <- y}

	m <- sum(ry)
	n <- sum(!ry)
	p <- ncol(x)
	sel <- sample(1:m, m, replace = TRUE)

	xobs <- x[ry, ]
	xobs <- xobs[sel,]
	xmis <- x[!ry,]
	yobs <- z[ry]
	yobs <- yobs[sel]

	u <- round(runif(n, epsilon, 1 - epsilon)*1e3)
	u <- ifelse(u %in% c(1:4,996:999), u/1e3, (u - u %% 5)/1e3)
	taus <- unique(u)
	nt <- length(taus)

	fit <- matrix(NA, p, nt)
	for(j in 1:nt){
		fit[,j] <- as.numeric(rrq.fit(xobs, yobs, tau = taus[j], method = method.rq)$coef)
	}
	# n times nt matrix
	ypred <- xmis%*%fit
	# diagonal of n times n matrix
	ypred <- diag(ypred[, match(u, taus), drop = FALSE])
	
	if(tsf %in% c("mcjI","bc","ao")){
		val <- switch(tsf,
			mcjI = invmcjI(ypred, lambda, symm, dbounded),
			bc = invbc(ypred, lambda),
			ao = invao(ypred, lambda, symm));
		if(isDbounded) val <- invmap(val, range(y.old))
	} else {val <- ypred}

    return(val)
}


##################################################
### QR for counts (Machado and Santos Silva)
##################################################

rq.counts <- function(formula, data = sys.frame(sys.parent()), tau = 0.5, subset, weights, na.action, contrasts = NULL, offset = NULL, method = "fn", M = 50, zeta = 1e-5, B = 0.999, cn = NULL, alpha = 0.05) 
{

# log-linear model
tsf <- "bc"
symm <- TRUE
dbounded <- FALSE
lambda <- 0 

nq <- length(tau)
if (nq > 1) 
	stop("One quantile at a time")

call <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action", "offset"), names(mf), 0L)
mf <- mf[c(1L, m)]
if (method == "model.frame")
	return(mf)
mf$drop.unused.levels <- TRUE
mf[[1L]] <- as.name("model.frame")
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")

x <- model.matrix(mt, mf, contrasts)
y <- model.response(mf, "numeric")

p <- ncol(x)
n <- nrow(x)
term.labels <- colnames(x)

offset <- model.offset(mf)
if(is.null(offset)) offset <- rep(0, n)
w <- as.vector(model.weights(mf))
if(is.null(w)) w <- rep(1, n)

Fn <- function(x, cn){
	xf <- floor(x)
	df <- x - xf
	if(df < cn & x >= 1){
		val <- xf - 0.5 + df/(2*cn)
	}
	if(any(cn <= df & df < (1 - cn), x < 1)){
		val <- xf
	}

	if(df >= (1 - cn)){
		val <- xf + 0.5 + (df - 1)/(2*cn)
	}

	return(val)
}

Fvec <- Vectorize(Fn)

# Add noise
Z <- replicate(M, addnoise(y, centered = FALSE, B = B))

# Transform Z
TZ <- apply(Z, 2, function(x, off, tsf, symm, lambda, tau, zeta){
	z <- ifelse((x - tau) > zeta, x - tau, zeta);
	switch(tsf,
		mcjI = mcjI(z, lambda, symm, dbounded = dbounded, omega = 0.001),
		bc = bc(z, lambda)) - off
	}, off = offset, tsf = tsf, symm = symm, lambda = lambda, tau = tau, zeta = zeta)

# Fit linear QR on TZ
fit <- apply(TZ, 2, function(y, x, weights, tau, method) 
	rq.wfit(x = x, y = y, tau = tau, weights = weights, method = method), x = x, tau = tau, weights = w, method = method)
	
# predicted values
yhat <- sapply(fit, function(obj, x) x %*% obj$coefficients, x = x)
yhat <- as.matrix(yhat)

# sweep offset back in
linpred <- sweep(yhat, 1, offset, "+")

# back-transform + offset tau
zhat <- matrix(NA, n, M)
for(i in 1:M){
zhat[,i] <- tau + switch(tsf,
	mcjI = invmcjI(linpred[,i], lambda, symm, dbounded = dbounded),
	bc = invbc(linpred[,i], lambda))
}
	
# covariance matrix
if(is.null(cn)) cn <- 0.5 * log(log(n))/sqrt(n)
F <- apply(zhat, 2, Fvec, cn = cn)
Fp <- apply(zhat + 1, 2, Fvec, cn = cn)

multiplier <- (tau - (TZ <= yhat))^2
a <- array(NA, dim = c(p, p, M))
for (i in 1:M) a[, , i] <- t(x * multiplier[, i]) %*% x/n

multiplier <- tau^2 + (1 - 2 * tau) * (y <= (zhat - 1)) + 
	((zhat - y) * (zhat - 1 < y & y <= zhat)) * (zhat - y - 
		2 * tau)
b <- array(NA, dim = c(p, p, M))
for (i in 1:M) b[, , i] <- t(x * multiplier[, i]) %*% x/n

multiplier <- (zhat - tau) * (F <= Z & Z < Fp)
d <- array(NA, dim = c(p, p, M))
sel <- rep(TRUE, M)
for (i in 1:M) {
	tmpInv <- try(solve(t(x * multiplier[, i]) %*% x/n), 
		silent = TRUE)
	if (!inherits(tmpInv, "try-error"))
		{d[, , i] <- tmpInv}
	else {sel[i] <- FALSE}
}
    
dad <- 0
dbd <- 0
for (i in (1:M)[sel]) {
	dad <- dad + d[, , i] %*% a[, , i] %*% d[, , i]
	dbd <- dbd + d[, , i] %*% b[, , i] %*% d[, , i]
}
    
m.n <- sum(sel)
if (m.n != 0) {
	V <- dad/(m.n^2) + (1 - 1/m.n) * dbd * 1/m.n
	V <- V/n ## CHECK V AND WEIGHTS
	stds <- sqrt(diag(V))
	} else {
	stds <- NA
	warning("Standard error not available")
	}

betahat <- sapply(fit, function(x) x$coefficients)
betahat <- if (p == 1) mean(betahat) else rowMeans(betahat)

linpred <- if (p == 1) {
	mean(linpred[1, ])
} else {
	rowMeans(linpred)
}

Fitted <- tau + switch(tsf,
	mcjI = invmcjI(linpred, lambda, symm, dbounded = dbounded),
	bc = invbc(linpred, lambda))

lower <- betahat + qt(alpha/2, n - p) * stds
upper <- betahat + qt(1 - alpha/2, n - p) * stds
tP <- 2 * pt(-abs(betahat/stds), n - p)

ans <- cbind(betahat, stds, lower, upper, tP)
colnames(ans) <- c("Value", "Std. Error", "lower bound", "upper bound", "Pr(>|t|)")
rownames(ans) <- names(betahat) <- term.labels

fit <- list()
fit$call <- call
fit$method <- method
fit$mf <- mf
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf[[1L]] <- as.name("get_all_vars")
fit$data <- eval(mf, parent.frame())
fit$x <- x
fit$y <- y
fit$weights <- w
fit$offset <- offset
fit$tau <- tau
fit$lambda <- lambda
fit$tsf <- tsf
attr(fit$tsf, "symm") <- symm
fit$coefficients <- betahat
fit$M <- M
fit$Mn <- m.n
fit$fitted.values <- Fitted
fit$tTable <- ans
fit$Cov <- V
fit$levels <- .getXlevels(mt, mf)
fit$terms <- mt
fit$term.labels <- term.labels
fit$rdf <- n - p

class(fit) <- "rq.counts"
	
return(fit)
}

coef.rq.counts <- coefficients.rq.counts <- function(object, ...){

tau <- object$tau
nq <- length(tau)
ans <- object$coefficients

if(nq == 1){
  names(ans) <- object$term.labels
}

return(ans)

}

fitted.rq.counts <- function(object, ...){

return(object$fitted.values)

}

predict.rq.counts <- function(object, newdata, offset, na.action = na.pass, type = "response", namevec = NULL, ...) 
{

tsf <- object$tsf
symm <- attributes(tsf)$symm
lambda <- object$lambda

if(!missing(newdata)){
	mt <- terms(object)
	Terms <- delete.response(mt)
	m <- object$mf <- model.frame(Terms, newdata, na.action = na.action, xlev = object$levels)
	if (!is.null(cl <- attr(Terms, "dataClasses"))) .checkMFClasses(cl, m)
	object$x <- model.matrix(Terms, m, contrasts.arg = object$contrasts)
	if(missing(offset)) object$offset <- rep(0, nrow(object$x))
	object$data <- newdata
}

linpred <- drop(object$x %*% object$coefficients) + object$offset

if(type == "link"){
	return(linpred)
}

if(type == "response"){
	Fitted <- object$tau + switch(tsf, mcjI = invmcjI(linpred, lambda, symm, dbounded =FALSE), bc = invbc(linpred, lambda))
	return(Fitted)
}

if(type == "maref"){
	if(is.null(namevec)) stop("When type = 'maref', the argument namevec must be provided")
	Fitted <- maref(object, namevec = namevec)
	return(Fitted)
}
 
}

residuals.rq.counts <- function(object, ...){

ans <- drop(object$y) - predict(object, type = "response", ...)
return(ans)

}

print.rq.counts <- function (x, digits = max(3, getOption("digits") - 3), ...) 
{
    tau <- x$tau
    nq <- length(tau)
    cat("Call: ")
    dput(x$call)
    cat("\n")
    if (nq == 1) {
        cat(paste("Quantile", tau, "\n"))
        cat("\n")
        cat("Fixed effects:\n")
        printCoefmat(x$tTable, signif.stars = TRUE, P.values = TRUE)
    }
    else {
    NULL
	}
}

maref.rq.counts <- function(object, namevec){

tau <- object$tau
nq <- length(tau)

tsf <- object$tsf
symm <- attributes(tsf)$symm
dbounded <- attributes(tsf)$dbounded

betahat <- as.matrix(object$coefficients)
lambda <- object$lambda

# Model frames and matrices
mt <- terms(object)
all_vars <- get_all_vars(delete.response(mt), object$data)

# Work out expression of linear predictor for symbolic derivative
f <- terms2expr(mt)
var_labels <- all.vars(mt)[-1]
g <- parse(text = paste0("function(", paste(var_labels, collapse = ", "), ", ", paste(attr(f, "coefs"), collapse = ", "), "){}"))
d2 <- deriv(expr = f, namevec = as.character(namevec), function.arg = eval(g))
cat("The linear component of the marginal effect is calculated as derivative of", "\n", deparse(f), "\n with respect to", namevec, "\n")

# 

linpred <- object$x %*% betahat
n <- nrow(object$x)
dlinpred <- matrix(NA, n, nq)

for(j in 1:nq){
        argsLs <- as.list(betahat[attr(f, "labels"),j])
        names(argsLs) <- attr(f, "coefs")
        argsLs <- c(as.list(all_vars), argsLs)
        D <- do.call(d2, args = argsLs)
        dlinpred[,j] <- attr(D, "gradient")
}

val <- matrix(NA, n, nq)
for(j in 1:nq)(
val[,j] <- switch(tsf,
        mcjI = d1mcjI(linpred[,j], lambda, symm, dbounded),
        bc = d1bc(linpred[,j], lambda)
        )*dlinpred[,j]
)

return(val)

}

addnoise <- function(x, centered = TRUE, B = 0.999) 
{

	n <- length(x)
    if (centered) 
        z <- x + runif(n, -B/2, B/2)
    else z <- x + runif(n, 0, B)
	
    return(z)
}

######################################################################
# Directional quantile classification
######################################################################

dqcControl <- function(tau.range = c(0.001, 0.999), nt = 10, ndir = 50, seed = NULL){

list(tau.range = tau.range, nt = nt, ndir = ndir, seed = seed)

}

dqc <- function(formula, data, df.test, subset, weights, na.action, control = list(), fit = TRUE){

cl <- match.call()
mf <- match.call(expand.dots = FALSE)
m <- match(c("formula", "data", "subset", "weights", "na.action"), names(mf), 0L)
mf <- mf[c(1L, m)]
mf$drop.unused.levels <- TRUE
mf[[1L]] <- quote(stats::model.frame)
mf <- eval(mf, parent.frame())
mt <- attr(mf, "terms")
intercept <- attr(terms.formula(formula, data = mf), "intercept") == 1

# train dataset
y <- model.response(mf)
x <- model.matrix(mt, mf)
w <- as.vector(model.weights(mf))
if (!is.null(w) && !is.numeric(w)) 
	stop("'weights' must be a numeric vector")
if(intercept){
	x <- x[,-c(1),drop = FALSE]
}

# test dataset
if(!is.null(df.test)){
	z <- model.matrix(formula[-2], df.test)
	if(intercept){
		z <- z[,-c(1),drop = FALSE]
	}
} else {
	z <- NULL
}

if(is.null(names(control)))
	control <- dqcControl()
else {
	control_default <- dqcControl()
	control_names <- intersect(names(control), names(control_default))
	control_default[control_names] <- control[control_names]
	control <- control_default
}

FIT_ARGS <- list(x = x, z = z, y = y, control = control)

if(!fit) return(FIT_ARGS)

res <- do.call(dqc.fit, FIT_ARGS)

res$call <- cl
res$nx <- nrow(x)
res$nz <- nrow(z)
res$p <- ncol(x)
res$control <- control
res$terms <- mt
res$term.labels <- colnames(x)
class(res) <- "dqc"
return(res)

}

dqc.fit <- function(x, z, y, control){

.checkfn <- function(x, p) x*(p - (x < 0))

if(!is.null(control$seed)) set.seed(control$seed)

y <- as.factor(y)
nx <- nrow(x)
nz <- nrow(z)
p <- ncol(x)

ndir <- control$ndir
nt <- control$nt
groups <- sort(levels(y))
ng <- length(groups)

if(is.null(row.names(x))) row.names(x) <- 1:nx
if(is.null(row.names(z))) row.names(z) <- 1:nz

# generate grid of taus
tau.range <- control$tau.range
if(any(is.na(tau.range))){
	stop("tau.range must not have NAs")
}
if(length(tau.range) == 1){
	taus <- tau.range
	nt <- 1
}
if(length(tau.range) == 2){
	tau.range <- sort(tau.range)
	taus <- seq(tau.range[1], tau.range[2], length = nt)
}
if(!length(tau.range) %in% c(1,2)){
	stop("I cannot understand 'tau.range'. It must be of length 1 or 2.")
}
if(any(taus <= 0) | any(taus >= 1)){
	stop("taus must be strictly in the unit interval (0,1)")
}

# order data
ord <- order(y)
x <- x[ord,]
y <- y[ord]
idx <- row.names(x)
idz <- row.names(z)

# marginal quantiles
csi <- lapply(split(data.frame(x), y), function(z, taus) apply(z, 2, quantile, probs = taus), taus = taus)
# element-wise signs for all combinations
c_groups <- gtools::combinations(n = ng, r = 2, v = groups, repeats.allowed = FALSE)
nc <- nrow(c_groups)
dir.sgn <- apply(c_groups, 1, function(i, x) sign(x[i][[1]] - x[i][[2]]), x = csi) # (nt x p) x nc

xu <- array(NA, dim = c(nx, ndir, nt), dimnames = list(obs = idx, dir = 1:ndir, tau = taus))
zu <- array(NA, dim = c(nz, ndir, nt), dimnames = list(obs = idz, dir = 1:ndir, tau = taus))

for (j in 1:nt) {
	# generate grid of directions uniformly over the p-dimensional unit sphere
	#theta <- matrix(runif(ndir * (p-1), 0, 2*pi), nrow = ndir, ncol = (p-1))
	#u <- mvmesh::Polar2Rectangular(r = rep(1, ndir), theta = theta) # ndir x p
	sgn.sel <- dir.sgn[seq(j, nt*p, by = nt),sample(1:nc, 1)]
	out <- C_projfun(x, z, sgn.sel, nx, nz, p, ndir)
	xu[,,j] <- out$xu
	zu[,,j] <- out$zu
}

B <- ndir*nt
xu <- matrix(as.numeric(xu), nrow = nx) # nx x B
zu <- matrix(as.numeric(zu), nrow = nz) # nx x B

ns <- as.integer(table(y))
minn <- c(0, cumsum(ns[-ng]))
maxn <- cumsum(ns)

Phi <- C_phifun(xu, zu, nx, nz, B, ndir, ng, taus, minn, maxn)

w <- colSums(Phi$out)
w <- -w/sqrt(sum(w^2))

dist.z <- matrix(0, nz, ng)
for (i in 1:ng){
	ss <- seq(i, ng*B, by = ng)
	dist.z[,i] <- Phi$Phi_z[, ss, drop = FALSE]%*%w
}
index <- apply(dist.z, 1, which.min)

ans <- data.frame(obs = idz, groups = factor(groups[index], levels = groups, labels = groups), value = apply(dist.z, 1, min))
list(ans = ans, groups = groups)

}

print.dqc <- function(x, ...){

z <- table(x$ans$groups)/x$nz*100

cat("Directional quantile classification", "\n")
if (!is.null(cl <- x$call)) {
	cat("Call:\n")
	dput(cl)
	cat("\n")
	cat("Classification proportions (%) by class:\n")
	print(z)
	cat("\n")
}


}

##################################################
### Khmaladze and other tests
##################################################

KhmaladzeFormat <- function(object, epsilon){

if(!inherits(object, "KhmaladzeTest")) stop("class(object) must be 'KhmaladzeTest'")
tt <- get("KhmaladzeTable")
if(!(epsilon %in% unique(tt$epsilon))) stop("'epsilon' must be in c(0.05,0.10,0.15,0.20,0.25,0.30)")

p <- length(object$THn)
ans <- matrix(NA, p + 1, 2)
colnames(ans) <- c("Value", "Pr")

sel <- tt[tt$p == p & tt$epsilon == epsilon,3:5]
alpha <- c(0.01,0.05,0.1)

ans[1,1] <- object$Tn
ans[1,2] <- min(c(1,alpha[object$Tn > sel]))
ans[2:(p+1),1] <- object$THn

sig <- c("significant at 1% level", "significant at 5% level", "significant at 10% level", "not significant at 10% level")
null <- if(object$nullH == "location") "location-shift hypothesis" else "location-scale-shift hypothesis"

sel <- tt[tt$p == 1 & tt$epsilon == epsilon,3:5]
if(p==1){val <- min(c(1,alpha[object$THn > sel]))} else
{val <- rep(0,p); for(i in 1:p) val[i] <- min(c(1,alpha[object$THn[i] > sel]))}
ans[2:(p+1),2] <- val

mm <- match(ans[1,2], c(alpha,1))
nn <- match(ans[2:(p+1),2], c(alpha,1))

cat("Khmaladze test for the", null, "\n")
cat("Joint test is", sig[mm], "\n")
cat("Test(s) for individual slopes:", "\n")
for(i in 1:p){
cat(names(object$THn)[i], sig[nn][i], "\n")
}
invisible(ans)

}

normalize <- function(x){

n <- nrow(x)
p <- ncol(x)

if(p < 2 | n < p) stop("Provide n x p matrix with n > p > 1")

xx <- x

for (i in 2:p) {
	H <- c(crossprod(x[, i], xx[, 1:(i - 1)]))/diag(crossprod(xx[,1:(i - 1)]))
	xx[, i] <- x[, i] - matrix(xx[, 1:(i - 1)], nrow = n) %*% 
		matrix(H, nrow = i - 1)
}
H <- 1/sqrt(diag(crossprod(xx)))
xx <- t(t(xx) * H)

return(xx)

}

rcTest <- function(object, alpha = 0.05, B = 100, seed = NULL){

taus <- object$tau
nq <- length(taus)

x <- if(is.null(object[['x']])){
		do.call(model.matrix, args = list(object = as.formula(object$formula), data = object$model))
	} else {object[['x']]}
n <- nrow(x)
p <- ncol(x)
x <- normalize(x)*sqrt(n)
Rmat <- as.matrix(residuals(object))
if(!is.null(seed)) set.seed(seed)


Tn <- Tc <- pval <- vector()
for(j in 1:nq){
	tau <- taus[j]
	psi <- (Rmat[,j] > 0) * tau + (Rmat[,j] <= 0) * (tau - 1)
	omega <- replicate(B, sample(c(tau, -tau, 1-tau, tau-1), size = n, replace = TRUE, prob = c((1-tau)/2, (1-tau)/2, tau/2, tau/2)))

	ans <- C_rcTest(x, psi, omega, n, p, B)

	Tstar <- apply(ans$outstar, 3, function(x, n) eigen(x/n)$values[1], n = n)
	Tc[j] <- quantile(Tstar, 1 - alpha)
	Tn[j] <- eigen(ans$out/n)$values[1]
	pval[j] <- 1 - ecdf(Tstar)(Tn[j])
}

names(Tn) <- names(Tc) <- names(pval) <- taus

val <- list(Tn = Tn, Tcrit = Tc, p.value = pval, tau = taus)
class(val) <- "rcTest"
attr(val, "seed") <- if(!is.null(seed)) seed else NA
return(val)

}

GOFTest <- function(object, type = "cusum", alpha = 0.05, B = 100, seed = NULL){


val <- list()

val[[1]] <- switch(type,
	cusum = rcTest(object = object, alpha = alpha, B = B, seed = seed))

attr(val, "type") <- type
class(val) <- "GOFTest"
return(val)

}

print.GOFTest <- function (x, digits = max(3, getOption("digits") - 3), ...){

nt <- length(x)
type <- attributes(x)$type
txt <- vector()
txt[1] <- "Goodness-of-fit test for quantile regression based on the cusum process"
tau <- x[[1]]$tau
nq <- length(tau)

if(type == "cusum"){
	x <- x[[1]]
	cat(txt[1], "\n")
	cat("A large test statistic (small p-value) is evidence of lack of fit", "\n")
	for (j in 1:nq) {
		cat(paste0("Quantile ", tau[j], ": "))
		cat(paste0("Test statistic = ", round(x$Tn[j], digits), "; p-value = ", round(x$p.value[j],digits)), "\n")
	}
}

}

KhmaladzeTable <- structure(list(p = c(1L, 2L, 3L, 4L, 5L, 6L, 7L, 8L, 9L, 10L, 
11L, 12L, 13L, 14L, 15L, 16L, 17L, 18L, 19L, 20L, 1L, 2L, 3L, 
4L, 5L, 6L, 7L, 8L, 9L, 10L, 11L, 12L, 13L, 14L, 15L, 16L, 17L, 
18L, 19L, 20L, 1L, 2L, 3L, 4L, 5L, 6L, 7L, 8L, 9L, 10L, 11L, 
12L, 13L, 14L, 15L, 16L, 17L, 18L, 19L, 20L, 1L, 2L, 3L, 4L, 
5L, 6L, 7L, 8L, 9L, 10L, 11L, 12L, 13L, 14L, 15L, 16L, 17L, 18L, 
19L, 20L, 1L, 2L, 3L, 4L, 5L, 6L, 7L, 8L, 9L, 10L, 11L, 12L, 
13L, 14L, 15L, 16L, 17L, 18L, 19L, 20L, 1L, 2L, 3L, 4L, 5L, 6L, 
7L, 8L, 9L, 10L, 11L, 12L, 13L, 14L, 15L, 16L, 17L, 18L, 19L, 
20L), epsilon = c(0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 
0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 
0.05, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 
0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.15, 0.15, 0.15, 
0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 
0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.2, 0.2, 0.2, 0.2, 0.2, 
0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 
0.2, 0.2, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 
0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3), alpha01 = c(2.721, 4.119, 
5.35, 6.548, 7.644, 8.736, 9.876, 10.79, 11.81, 12.91, 14.03, 
15, 15.93, 16.92, 17.93, 18.85, 19.68, 20.63, 21.59, 22.54, 2.64, 
4.034, 5.267, 6.34, 7.421, 8.559, 9.573, 10.53, 11.55, 12.54, 
13.58, 14.65, 15.59, 16.52, 17.53, 18.46, 19.24, 20.21, 21.06, 
22.02, 2.573, 3.908, 5.074, 6.148, 7.247, 8.355, 9.335, 10.35, 
11.22, 12.19, 13.27, 14.26, 15.22, 16.12, 17.01, 17.88, 18.78, 
19.7, 20.53, 21.42, 2.483, 3.742, 4.893, 6.023, 6.985, 8.147, 
9.094, 10.03, 10.9, 11.89, 12.85, 13.95, 14.86, 15.69, 16.55, 
17.41, 18.19, 19.05, 19.96, 20.81, 2.42, 3.633, 4.737, 5.818, 
6.791, 7.922, 8.856, 9.685, 10.61, 11.48, 12.48, 13.54, 14.34, 
15.26, 16, 16.81, 17.59, 18.49, 19.4, 20.14, 2.32, 3.529, 4.599, 
5.599, 6.577, 7.579, 8.542, 9.413, 10.27, 11.15, 12.06, 12.96, 
13.82, 14.64, 15.46, 16.25, 17.04, 17.85, 18.78, 19.48), alpha05 = c(2.14, 
3.393, 4.523, 5.56, 6.642, 7.624, 8.578, 9.552, 10.53, 11.46, 
12.41, 13.34, 14.32, 15.14, 16.11, 16.98, 17.9, 18.83, 19.72, 
20.58, 2.102, 3.287, 4.384, 5.43, 6.465, 7.412, 8.368, 9.287, 
10.26, 11.17, 12.1, 13, 13.9, 14.73, 15.67, 16.56, 17.44, 18.32, 
19.24, 20.11, 2.048, 3.199, 4.269, 5.284, 6.264, 7.197, 8.125, 
9.044, 9.963, 10.85, 11.77, 12.61, 13.48, 14.34, 15.24, 16.06, 
16.93, 17.8, 18.68, 19.52, 1.986, 3.1, 4.133, 5.091, 6.07, 6.985, 
7.887, 8.775, 9.672, 10.52, 11.35, 12.22, 13.09, 13.92, 14.77, 
15.58, 16.43, 17.3, 18.09, 18.95, 1.923, 3, 4.018, 4.948, 5.853, 
6.76, 7.611, 8.51, 9.346, 10.17, 10.99, 11.82, 12.66, 13.46, 
14.33, 15.09, 15.95, 16.78, 17.5, 18.3, 1.849, 2.904, 3.883, 
4.807, 5.654, 6.539, 7.357, 8.211, 9.007, 9.832, 10.62, 11.43, 
12.24, 13.03, 13.85, 14.61, 15.39, 16.14, 16.94, 17.74), alpha1 = c(1.872, 
3.011, 4.091, 5.104, 6.089, 7.047, 7.95, 8.89, 9.82, 10.72, 11.59, 
12.52, 13.37, 14.28, 15.19, 16.06, 16.97, 17.84, 18.73, 19.62, 
1.833, 2.946, 3.984, 4.971, 5.931, 6.852, 7.77, 8.662, 9.571, 
10.43, 11.29, 12.2, 13.03, 13.89, 14.76, 15.65, 16.53, 17.38, 
18.24, 19.11, 1.772, 2.866, 3.871, 4.838, 5.758, 6.673, 7.536, 
8.412, 9.303, 10.14, 10.98, 11.86, 12.69, 13.48, 14.36, 15.22, 
16.02, 16.86, 17.7, 18.52, 1.73, 2.781, 3.749, 4.684, 5.594, 
6.464, 7.299, 8.169, 9.018, 9.843, 10.66, 11.48, 12.31, 13.11, 
13.91, 14.74, 15.58, 16.37, 17.17, 17.97, 1.664, 2.693, 3.632, 
4.525, 5.406, 6.241, 7.064, 7.894, 8.737, 9.517, 10.28, 11.11, 
11.93, 12.67, 13.47, 14.26, 15.06, 15.83, 16.64, 17.38, 1.602, 
2.602, 3.529, 4.365, 5.217, 6.024, 6.832, 7.633, 8.4, 9.192, 
9.929, 10.74, 11.51, 12.28, 13.05, 13.78, 14.54, 15.3, 16.05, 
16.79)), .Names = c("p", "epsilon", "alpha01", "alpha05", "alpha1"
), class = "data.frame", row.names = c(NA, -120L))

