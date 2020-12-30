testlist <- list(df = -2.60623911537396e-78, ncp = -4.78951292661942e+215,      x = 2.10035737868214e+94)
result <- do.call(exceedProb::pnct,testlist)
str(result)