testlist <- list(c = -621726556L, x = -293123844L, y = -555281357L, z = 1746767833L)
result <- do.call(imager:::getCc,testlist)
str(result)