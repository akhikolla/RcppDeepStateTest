testlist <- list(flavor = -1053990400L, nx = 467495432L, ny = 1827680409L)
result <- do.call(BWStest::murakami_stat_perms,testlist)
str(result)