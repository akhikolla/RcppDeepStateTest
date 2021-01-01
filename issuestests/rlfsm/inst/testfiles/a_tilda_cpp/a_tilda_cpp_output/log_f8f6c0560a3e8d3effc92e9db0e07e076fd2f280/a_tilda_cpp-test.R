testlist <- list(alpha = 3.76872630433678e+222, H = 2.17590117142795e+276,      m = 1827680409L, M = -1053990400L, N = 467495432L)
result <- do.call(rlfsm:::a_tilda_cpp,testlist)
str(result)