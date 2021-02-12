log <- "~/Desktop/liblog"
val <- readLines(log)
log.res <- gsub("Missing value\n","",val)
log.res <- gsub("Missing value","",val)
log.res <- gsub(" ",",",log.res)
writeLines(log.res,"~/Desktop/liblogupdate")

res <- nc::capture_all_str("~/Desktop/liblogupdate","input starts\n",inps="(?:.*\n)*?","input ends\n")
inputs <- res[1]
e.in <- gsub("values:","=c(",)
e.in

#testlist <- list(window = -2008914661L, x = c(-1193066448L, -1076894989L)
testlist <- list(xy1 =c( 3.31923e-115),xy2 =c( 1.06139e-314,3.21867e-57,nan,1.06139e-314,2.66194e-310,3.21867e-57,
0.00000,2.48876e-319,1.25987e-321,2.23339e-23,8.14846e-310,nan,4.94066e-324,3.21758e-310,
2.11371e-314,4.29746e-311,2.83782e-304,7.29112e-304,4.94066e-324,6.53817e+91),
radius1 =c( nan),radius2 =c( -nan),delta =c( -1.06974e+270))

result <- do.call(vennplot:::,testlist)
str(result)

vennplot/inst/testfiles/alldis_R/libFuzzer_alldis_R/libfuzzer_inputs