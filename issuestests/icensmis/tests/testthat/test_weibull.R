# HR <- c(1.5, 1.75, 2, 2.25, 2.5)
# pmiss <- c(0, 0.2, 0.4)
# power <- c(0.8, 0.9)
# 
# ssize <- function(x) {
#   icpower_weibull(x[1], 1, 1, 1, -log(0.4)/8, 1:8, 
#                   power = x[3], pmiss = x[2], pcensor = 0.025)$result$N
# }
# 
# parms <- expand.grid(power, pmiss, HR)[, 3:1]
# parms$sizes <- apply(parms, 1, ssize)
# papersizes <- strsplit("1.50 1.75 2.00 2.25 2.50
# 318 426 162 218 104 138
# 74 100 58 78
# 324 434 166 222 106 142
# 76 102 60 80
# 332 442 170 226 108 144
# 78 104 60 80", "[[:space:]]")[[1]]
# x <- as.numeric(papersizes)[-(1:5)]
# parms$papersizes <- unlist(split(x, rep(rep(1:5, each = 2), 3)))
# parms$diff_ratio <- with(parms, (sizes-papersizes)/papersizes)
# names(parms)[1:3] <- c("HR", "pmiss", "power")
# parms$diff_ratio <- round(parms$diff_ratio, 3)
