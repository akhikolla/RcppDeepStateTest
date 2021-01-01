testlist <- list(a = -3.59872877491565e+296, b = 9.11343224192607e-239, ct = 393718998L,      t = -2.94034311491954e-89)
result <- do.call(activegp:::Ikk_cpp,testlist)
str(result)