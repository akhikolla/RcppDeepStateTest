testlist <- list(lb = -2017731232L, M = structure(c(2.18732436412092e-300,  2.06395372529255e+301, 1.879761069896e+235, 6.49449396537558e-229,  3.41558563368343e-214), .Dim = c(5L, 1L)), n_clust = -394848050L,      s_fn = 1176913755L)
result <- do.call(HDLSSkST:::gMADD,testlist)
str(result)