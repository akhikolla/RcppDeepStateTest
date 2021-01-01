testlist <- list(rmax = 1344097580L)
result <- do.call(Lmoments::shiftedlegendre,testlist)
str(result)