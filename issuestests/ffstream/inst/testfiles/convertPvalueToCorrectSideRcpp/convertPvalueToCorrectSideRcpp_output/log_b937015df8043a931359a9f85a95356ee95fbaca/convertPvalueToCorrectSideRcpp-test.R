testlist <- list(p_ = c(5.22411903275173e+30, -4.52120063878379e-113, Inf,  1.27525944966522e-281, 1.33073290442033e+122, -Inf, 0))
result <- do.call(ffstream:::convertPvalueToCorrectSideRcpp,testlist)
str(result)