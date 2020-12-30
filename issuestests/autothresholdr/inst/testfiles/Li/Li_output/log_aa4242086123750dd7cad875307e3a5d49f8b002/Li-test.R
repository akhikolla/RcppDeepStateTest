testlist <- list(data = c(-414427158L, -875321502L, 939493244L, 529873119L,  -1905553655L, -1935276176L, 1574970956L, NA, -740136546L, -1240464915L,  NA, 497159851L, 228439193L))
result <- do.call(autothresholdr:::Li,testlist)
str(result)