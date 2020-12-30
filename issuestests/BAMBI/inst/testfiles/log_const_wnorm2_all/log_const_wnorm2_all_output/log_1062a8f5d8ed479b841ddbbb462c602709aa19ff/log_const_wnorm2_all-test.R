testlist <- list(par_mat = c(1599200, 1.0786e-249))
result <- do.call(BAMBI:::log_const_wnorm2_all,testlist)
str(result)