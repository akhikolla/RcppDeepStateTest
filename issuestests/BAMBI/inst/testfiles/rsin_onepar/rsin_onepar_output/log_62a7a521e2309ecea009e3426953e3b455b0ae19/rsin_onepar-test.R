testlist <- list(I_upper_bd = -3.90273034706978e-168, k1 = 8.84251824152281e+255,      k2 = 2.68341701906964e+247, k3 = -3.9921407005713e-193, mu1 = 1.36529474157211e-291,      mu2 = 2.56830748759861e-90, n = 1283839064L)
result <- do.call(BAMBI:::rsin_onepar,testlist)
str(result)