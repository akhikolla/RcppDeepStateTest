valgrind_afl_test <- function(){
cA.dir <- file.path(system.file("extdata",package="RcppDeepState"),"compileAttributes")
root.path <- system.file("extdata",package="RcppDeepState")
packages <- Sys.glob(file.path(cA.dir,"*"))
for(pkg.i in seq_along(packages)){
  pkg.tar.gz <- packages[[pkg.i]]
  testfiles.vec <- Sys.glob(file.path(pkg.tar.gz,"inst/testfiles/*"))
  test_path <- file.path(pkg.tar.gz,"inst/testfiles")
  functions.list <-  RcppDeepState::deepstate_get_function_body(pkg.tar.gz)
  cat(sprintf("%4d - %s\n", pkg.i, pkg.tar.gz))
  if(length(testfiles.vec) > 0){
    for(fun in testfiles.vec){
    afl.fun.path <- file.path(test_path,basename(fun),paste0("AFL_",basename(fun)))
    afl.inputs <- Sys.glob(file.path(afl.fun.path,"afl_inputs/*"))
    afl.inputs.path <- file.path(afl.fun.path,"afl_inputs") 
    times <- unique(gsub("_.*","",basename(afl.inputs)))
    for(utime in times){
       run_line <- paste0("R -d valgrind --vanilla --args ",afl.inputs.path,"/",basename(utime)," < /home/akhila/RcppDeepStateTest/afl_valgrind_per_function.R")
       system(run_line)
     }
   }
  }
}
}