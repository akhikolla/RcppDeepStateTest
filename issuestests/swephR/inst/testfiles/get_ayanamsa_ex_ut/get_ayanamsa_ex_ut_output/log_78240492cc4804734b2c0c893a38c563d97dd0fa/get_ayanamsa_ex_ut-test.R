testlist <- list(iflag = -1053990400L, jd_ut = -2.43318023382663e-187)
result <- do.call(swephR:::get_ayanamsa_ex_ut,testlist)
str(result)