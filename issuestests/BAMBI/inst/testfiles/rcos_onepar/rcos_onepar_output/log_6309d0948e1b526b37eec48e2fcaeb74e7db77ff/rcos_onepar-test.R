testlist <- list(I_upper_bd = 906.214606645425, k1 = -1.78831874731819e-137,      k2 = 4.20569622367789e-267, k3 = -1.52388373525763e-89, mu1 = 1.29714655428018e-226,      mu2 = 3.15932230363837e+155, n = 1594427709L)
result <- do.call(BAMBI:::rcos_onepar,testlist)
str(result)