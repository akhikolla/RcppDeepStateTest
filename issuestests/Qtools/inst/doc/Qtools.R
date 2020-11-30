## ---- echo=FALSE, warning = FALSE---------------------------------------------
library(knitr)
#Determine the output format of the document
outputFormat   = opts_knit$get("rmarkdown.pandoc.to")

#Figure and Table Caption Numbering, for HTML do it manually
capTabNo = 1; capFigNo = 1;

#Function to add the Table Number
capTab = function(x){
  if(outputFormat == 'html'){
    x = paste0("Table ",capTabNo,". ",x)
    capTabNo <<- capTabNo + 1
  }; x
}

#Function to add the Figure Number
capFig = function(x){
  if(outputFormat == 'html'){
    x = paste0("Figure ",capFigNo,". ",x)
    capFigNo <<- capFigNo + 1
  }; x
}

## ----fig1, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.cap=capFig("Cumulative distribution (a) and quantile (b) functions for simulated Poisson data. The ordinary cumulative distribution function (CDF) and quantile function (QF) are represented by step-functions (grey lines), with the convention that, at the point of discontinuity or `jump', the function takes its value corresponding to the ordinate of the filled circle as opposed to that of the hollow circle. The mid-CDF and mid-QF are represented by filled squares, while the piecewise linear functions (dashed lines) connecting the squares represent continuous versions of, respectively, the ordinary CDF and QF.")----

library(Qtools)

cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1

set.seed(467)
y <- rpois(1000, 4)
pmid <- midecdf(y); xmid <- midquantile(y, probs = pmid$y)

par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))

plot(pmid, cex.main = cx.lab, cex.axis = cx.ax, cex.lab = cx.lab, xlab = "y", ylab = "CDF", main = "", cex.points = cx.p, jumps = TRUE)
points(pmid$x, pmid$y, pch = 15, cex = cx.p, col = 1)
mtext("(a)", 3, line = 0.5, cex = cx.lab)

plot(xmid, cex.main = cx.lab, cex.axis = cx.ax, cex.lab = cx.lab, xlab = "p", ylab = "Quantile", main = "", cex.points = cx.p, jumps = TRUE)
points(xmid$x, xmid$y, pch = 15, cex = cx.p, col = 1)
mtext("(b)", 3, line = 0.5, cex = cx.lab)


## ----fig2, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.cap=capFig("Estimated density (a) and empirical mid-quantile (b) functions of waiting time between eruptions in the Old Faithful Geyser data set.")----
library(Qtools)

gg_color_hue <- function(n) {
  hues = seq(15, 375, length=n+1)
  hcl(h=hues, l=65, c=100)[1:n]
}

y <- faithful$waiting
xl <- c(0,1)
yl <- c(40,100)
cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1
cc <- gg_color_hue(2)
p <- 1:19/20
xb <- "Waiting time (min)"
xmid <- midquantile(y, probs = p)

par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))
plot(density(y), main = "", xlab = xb, cex.lab = cx.lab, cex.axis = cx.ax, lwd = lw)
mtext("(a)", 3, line = 0.5, cex = cx.lab)

plot(xmid, xlim = xl, ylim = yl, main = "", xlab = "Probability p", ylab = xb, cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, pch = 15, lwd = lw, jumps = FALSE)
mtext("(b)", 3, line = 0.5, cex = cx.lab)


## ----fig3, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.cap=capFig("(a) Waiting times between eruptions against durations of eruptions (dashed vertical line drawn at $3$ minutes) in the Old Faithful Geyser data set. (b) Mid-CDF of waiting time by duration of eruption (solid line, shorter than 3 minutes; dashed line, longer than 3 minutes).")----
library(Qtools)

gg_color_hue <- function(n) {
  hues = seq(15, 375, length=n+1)
  hcl(h=hues, l=65, c=100)[1:n]
}

cutoff <- 3
x <- faithful$eruptions
y <- faithful$waiting
xl <- c(0,1)
yl <- c(40,100)
cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1
cc <- gg_color_hue(2)
p <- 1:19/20
f <- faithful$eruptions >= cutoff
xb <- "Waiting time (min)"
pmid0 <- midecdf(y[!f])
pmid1 <- midecdf(y[f])

xmid <- midquantile(y, probs = pmid$y)
cc <- gg_color_hue(2)

par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))

plot(waiting ~ eruptions, faithful, pch = 1, cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, ylab = xb, xlab = "Duration (min)")
mtext("(a)", 3, line = 0.5, cex = cx.lab)

points(x[!f], y[!f], col = cc[1], cex = cx.p)
points(x[f], y[f], col = cc[2], cex = cx.p)

abline(v = cutoff, lty = 2, col = grey(5/10))

plot(pmid0, xlim = yl, ylim = xl, xlab = xb, ylab = "CDF", main = "", cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, col.midline = cc[1], lty.midline = 1, lwd = lw)
plot(pmid1, xlim = yl, ylim = xl, xlab = xb, ylab = "CDF", cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, col.midline = cc[2], lwd = lw, add = TRUE)
mtext("(b)", 3, line = 0.5, cex = cx.lab)



## ----fig4, echo = FALSE, results='hide', message=FALSE, fig.width = 3, fig.cap=capFig("Predicted 10th (solid line), 50th (dashed line), and 90th (dot-dashed line) centiles of ozone conditional on solar radiation in the New York Air Quality data set.")----
library(Qtools)
library(quantreg)

cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1

dd <- airquality[complete.cases(airquality),]
dd <- dd[order(dd$Solar.R),]
x <- seq(min(dd$Solar.R), max(dd$Solar.R), length = 200)
yhat <- predict(rq(Ozone ~ Solar.R , tau = c(.1,.5,.9), data = dd), newdata = data.frame(Solar.R = x))

par(mar = c(4.1, 4.1, 2.1, 2.1))

plot(Ozone ~ Solar.R, data = dd, xlab = "Solar radiation (lang)", ylab = "Ozone (ppb)", cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p)
for(i in 1:3){
lines(x[-1], yhat[-1,i], lty = c(1,2,4)[i], lwd = lw)
}


## ----fig5, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.cap=capFig("Predicted 10th (solid line), 50th (dashed line), and 90th (dot-dashed line) centiles of ozone conditional on solar radiation (a) and corresponding estimated marginal effects (b) using the symmetric proposal I transformation in the New York Air Quality data set.")----
library(Qtools)

cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1

dd <- airquality[complete.cases(airquality),]
dd <- dd[order(dd$Solar.R),]
x <- seq(9, 334, length = 200)
set.seed(567)

par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))

# mcjI

fit.rqt <- tsrq(Ozone ~ Solar.R, tsf = "mcjI", lambda = seq(1,3,by=0.005), tau = c(.1,.5,.9), data = dd, symm = TRUE)
qhat <- predict(fit.rqt, newdata = data.frame(Solar.R = x), type = "response")

plot(Ozone ~ Solar.R, data = dd, xlab = "Solar radiation (Ly)", ylab = "Ozone (ppb)", cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, col = "gray70")
for(i in 1:3){lines(x, qhat[,i], lty = c(1,2,4)[i], lwd = lw)}
mtext("(a)", 3, line = 0.5, cex = cx.lab)

# marginal

dqhat <- predict(fit.rqt, newdata = data.frame(Solar.R = x), type = "maref", namevec = "Solar.R")
plot(range(x), range(dqhat), type = "n", xlab = "Solar radiation (Ly)", ylab = "Marginal effect", main = "", cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p)
for(i in 1:3){lines(x, dqhat[,i], lty = c(1,2,4)[i], lwd = lw)}
mtext("(b)", 3, line = 0.5, cex = cx.lab)



## ----fig6, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.cap=capFig("Predicted 90th centile of A-level scores conditional on GCSE scores (a) and corresponding estimated marginal effect (b) using the asymmetric Aranda-Ordaz transformation in the A-level Chemistry Scores data set.")----
library(Qtools)

cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1


data(Chemistry)
#fit.rqt <- tsrq(score ~ gcse, data = Chemistry, tsf = "ao", symm = FALSE, lambda = seq(0,2,by=0.01), tau = 0.9)

x <- seq(0, 8, length = 200)
#qhat <- predict(fit.rqt, newdata = data.frame(gcse = x), type = "response")
#dqhat <- predict(fit.rqt, newdata = data.frame(gcse = x), type = "maref", namevec = "gcse")

par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))

#with(Chemistry, plot(score ~ gcse, xlab = "GCSE score", ylab = "A-level Chemistry score", cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, pch = 1, col = "gray70"))
#lines(x, qhat, lty = 1, lwd = lw)
#mtext("(a)", 3, line = 0.5, cex = cx.lab)

# marginal

#plot(x, dqhat, type = "l", xlab = "GCSE score", ylab = "Marginal effect", cex.lab = cx.lab, cex.axis = cx.ax, lwd = lw)
#mtext("(b)", 3, line = 0.5, cex = cx.lab)



## ----fig7, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.height=6, fig.cap=capFig("Location, scale and shape of ozone levels conditional on solar radiation in the New York Air Quality data set. Dashed lines denote the bootstrapped $90%$ point-wise confidence intervals.")----
library(Qtools)

cx.lab <- 1
cx.ax <- 1
lw <- 1.5
cx.p <- 1

fit.qlss <- qlss(formula = Ozone ~ Solar.R, data = airquality, type = "rqt", tsf = "mcjI", symm = TRUE, dbounded = FALSE,  lambda = seq(1, 3, by = 0.005), probs = c(0.05, 0.1))
set.seed(567)
x <- seq(9, 334, length = 200)
qhat <- predict(fit.qlss, newdata = data.frame(Solar.R = x), interval = TRUE, level = 0.90, R = 500)

par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))

plot(qhat, z = x, whichp = 0.1, interval = TRUE, type = "l", xlab = "Solar radiation (lang)", lwd = lw, cex.lab = cx.lab, cex.axis = cx.ax)


## ----fig8, echo = FALSE, results='hide', message=FALSE, fig.width = 6, fig.cap=capFig("Predicted quantiles of number of bindings conditional on esterase concentration using regression quantiles (a) and restricted regression quantiles (b) in the Esterase data set.")----
library(Qtools)
library(quantreg)

data(esterase)

cx.lab <- .75
cx.ax <- .75
lw <- 1
cx.p <- 1


par(mfrow = c(1,2), mar = c(4.1, 4.1, 2.1, 2.1))

fit <- quantreg::rq(Count ~ Esterase, data = esterase, tau = c(.1,.25,.5,.75,.9))
yhat <- fit$fitted.values
fitr <- rrq(Count ~ Esterase, data = esterase, tau = c(.1,.25,.5,.75,.9))
yhat2 <- predict(fitr)

# Plot regression quantiles
plot(Count ~ Esterase, data = esterase, cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, pch = 1, col = "gray70")
apply(yhat, 2, function(y,x,lw) lines(x,y,lwd = lw), x = esterase$Esterase, lw = lw)
mtext("(a)", 3, line = 0.5, cex = cx.lab)

# Plot restricted regression quantiles
plot(Count ~ Esterase, data = esterase, cex.lab = cx.lab, cex.axis = cx.ax, cex = cx.p, pch = 1, cex.main = cx.lab, col = "gray70")
apply(yhat2, 2, function(y,x,lw) lines(x,y,lwd = lw), x = esterase$Esterase, lw = lw)
mtext("(b)", 3, line = 0.5, cex = cx.lab)


## ----fig9, echo = FALSE, results='hide', message=FALSE, fig.width = 4, fig.cap=capFig("Predicted 10th, 50th, and 90th centiles of number of bindings conditional on esterase concentration using Poisson regression and distribution-free quantile regression (QR) based on jittering in the Esterase data set.")----

data("esterase")

gg_color_hue <- function(n) {
  hues = seq(15, 375, length=n+1)
  hcl(h=hues, l=65, c=100)[1:n]
}

# Plot quantiles 0.25, 0.5, 0.75
cc <- gg_color_hue(2)
lw <- 2
cx.lab <- .75
cx.ax <- .75

fit1 <- rq.counts(Count ~ Esterase, tau = 0.1, data = esterase, M = 50)
fit2 <- rq.counts(Count ~ Esterase, tau = 0.5, data = esterase, M = 50)
fit3 <- rq.counts(Count ~ Esterase, tau = 0.9, data = esterase, M = 50)
fit.glm <- glm(Count ~ Esterase, data = esterase, family = poisson())

par(mar = c(4.1, 4.1, 2.1, 2.1))

plot(Count ~ Esterase, data = esterase, xlab = "Esterase", ylab = "Count", cex.lab = cx.lab, cex.axis = cx.ax, cex = 1)

lambda <- fit.glm$fitted.values
yhat <- mapply(qpois, c(0.1,0.5,0.9), MoreArgs = list(lambda = lambda))
lines(esterase$Esterase, yhat[,1], lwd = lw, col = cc[1])
lines(esterase$Esterase, yhat[,2], lwd = lw, col = cc[1])
lines(esterase$Esterase, yhat[,3], lwd = lw, col = cc[1])

yhat <- cbind(fit1$fitted.values, fit2$fitted.values, fit3$fitted.values)
lines(esterase$Esterase, yhat[,1], lwd = lw, col = cc[2])
lines(esterase$Esterase, yhat[,2], lwd = lw, col = cc[2])
lines(esterase$Esterase, yhat[,3], lwd = lw, col = cc[2])

legend(5,1000, legend = c("Poisson","QR"), col = c(cc), lty = c(1,1), lwd = lw, cex = cx.lab)

## ----fig10, echo = FALSE, results='hide', message=FALSE, fig.width = 4, fig.cap=capFig("Predicted 50th and 90th centiles of number of bindings conditional on esterase concentration using Poisson regression and mid-quantile regression (mid-QR) in the Esterase data set.")----

data("esterase")

gg_color_hue <- function(n) {
  hues = seq(15, 375, length=n+1)
  hcl(h=hues, l=65, c=100)[1:n]
}

# Plot quantiles 0.5, 0.9
cc <- gg_color_hue(2)
lw <- 2
cx.lab <- .75
cx.ax <- .75

fit <- midrq(Count ~ Esterase, tau = c(0.5, 0.9), data = esterase, type = 1, lambda = 0)

par(mar = c(4.1, 4.1, 2.1, 2.1))

plot(Count ~ Esterase, data = esterase, xlab = "Esterase", ylab = "Count", cex.lab = cx.lab, cex.axis = cx.ax, cex = 1)

yhat <- predict(fit)
lines(esterase$Esterase, yhat[,1], lwd = lw, col = cc[2])
lines(esterase$Esterase, yhat[,2], lwd = lw, col = cc[2])


