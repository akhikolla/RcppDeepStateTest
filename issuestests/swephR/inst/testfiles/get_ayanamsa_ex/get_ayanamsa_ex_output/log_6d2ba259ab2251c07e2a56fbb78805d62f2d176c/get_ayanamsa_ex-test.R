testlist <- list(iflag = -1053990400L, jd_et = -2.43318023382663e-187)
result <- do.call(swephR:::get_ayanamsa_ex,testlist)
str(result)