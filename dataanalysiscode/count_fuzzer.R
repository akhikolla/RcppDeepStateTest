
  pkg.execlist <- list() 
  pkg.unexlist <- list()
  #pkgs <- Sys.glob(file.path("~/testpackages/testfolders","*"))
  pkgs <- Sys.glob(file.path("~/fuzzer_packages/fuzzedpackages","*"))
for(pkg.i in pkgs){
  exelist <- list()
  unexelist <- list()
  testfiles <- file.path(pkg.i,"inst/testfiles")
  fun.count <- Sys.glob(file.path(testfiles,"*"))
  if(length(fun.count) > 0){
    for(fun.i in fun.count){
      #lib.dir <- file.path(fun.i, paste0("libFuzzer_",basename(fun.i)))
      lib.dir <- file.path(fun.i, paste0("AFL_",basename(fun.i)))
       #lib.dir <- Sys.glob(file.path(fun.i,paste0("libFuzzer_",basename(fun.i)),"*"))
      if(!dir.exists(lib.dir)){                
        exelist<- c(exelist,fun.i)
      }else{
        unexelist<-c(unexelist,fun.i)
      }
    }
  }
  if(length(exelist) > 0)
    pkg.execlist[[basename(pkg.i)]] <-exelist
  if(length(unexelist) > 0)
    pkg.unexlist[[basename(pkg.i)]] <-unexelist
}


print("Executed package:\n")
print(head(pkg.execlist))
print("Unexecuted package:\n")
print(head(pkg.unexlist))

y <- paste0("~/fuzzer_packages/fuzzedpackages/",names(pkg.execlist))
future::plan("multicore", workers=12)
future.apply::future_lapply( y,FUN=deepstate_pkg_create_HonggFuzz)
future::plan("multicore", workers=12)
future.apply::future_lapply( y,FUN=deepstate_pkg_create_LibFuzzer)
future::plan("multicore", workers=7)
future.apply::future_lapply(y, FUN=deepstate_pkg_create_AFL)
future::plan("multicore", workers=12)
future.apply::future_lapply(y, FUN=deepstate_pkg_create_AFL)

