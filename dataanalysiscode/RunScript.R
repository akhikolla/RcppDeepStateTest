RcppDeepState_test <- function(package){
  zip.path<- "/home/akhila/fuzzer_packages/fuzzedpackages"
  pkg.name <- sub("_.*", "", basename(package))
  RcppExports.cpp <- file.path(zip.path,pkg.name, "src/RcppExports.cpp")
  if(file.exists(RcppExports.cpp)){
    #print(file.path(zip.path,pkg.name))
    deepstate_harness_compile_run(file.path(zip.path,pkg.name))
    result = RcppDeepState::deepstate_harness_analyze_pkg(file.path(zip.path,pkg.name))
    print(result$logtable)
  }else{
    print("No Rcpp Exports")
  }
}

val <- Sys.glob(file.path("/home/akhila/fuzzer_packages/fuzzedpackages","*"))

path <- Sys.glob(file.path("~/fuzzer_packages/fuzzedpackages","*"))
nlist <- list()
for(i in path){
  valid <- file.path(i,"inst/testfiles")
  val.len <- Sys.glob(file.path(valid,"*"))
  if(length(val.len)  < 1){
    nlist <- c(nlist,i)
  }
}

nlist <- do.call(rbind,nlist)
y <- nlist[,1]
parallel::mclapply(y[50:100],FUN=RcppDeepState_test,mc.cores = 12)
