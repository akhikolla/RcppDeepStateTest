testlist <- list(i1 = -656782726L, i2 = -1130113819L, X1 = structure(c(1.97886617794508e-301,  2.19659342025781e+52, 2.55503601177102e+116, 1.53223510746629e-108,  1.85029912773825e-207, 3.12844627163376e-116), .Dim = c(6L, 1L )))
result <- do.call(hetGP:::partial_d_dist_abs_dX_i1_i2,testlist)
str(result)