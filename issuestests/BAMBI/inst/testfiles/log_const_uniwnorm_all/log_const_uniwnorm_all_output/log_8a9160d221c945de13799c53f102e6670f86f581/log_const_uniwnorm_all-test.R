testlist <- list(par_mat = c(1.6168e-156, 3.1282e+210, -1.6925e-32, 1.1932e-164,  -2.6257e-264, -1.3452e-226, 7.0065e-37, 2.6261e-130))
result <- do.call(BAMBI:::log_const_uniwnorm_all,testlist)
str(result)