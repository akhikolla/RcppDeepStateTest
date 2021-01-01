testlist <- list(c = -1704920159L, x = 1344097580L, y = -1433424706L, z = 1190349588L)
result <- do.call(imager:::getZc,testlist)
str(result)