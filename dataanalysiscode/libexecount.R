pkg.execlist <- list() 
pkg.unexlist <- list()
pkgs <- Sys.glob(file.path("~/fuzzer_packages/fuzzedpackages","*"))
for(pkg.i in pkgs){
  exelist <- list()
  unexelist <- list()
  testfiles <- file.path(pkg.i,"inst/testfiles")
  fun.count <- Sys.glob(file.path(testfiles,"*"))
  if(length(fun.count) > 0){
    for(fun.i in fun.count){
      #lib.dir <- file.path(fun.i, paste0("AFL_",basename(fun.i)))
      lib.dir <- file.path(fun.i, paste0("libFuzzer_",basename(fun.i)))    
      lib.dir.exec <- file.path(lib.dir,paste0(basename(fun.i),"_DeepState_TestHarness"))
      #!dir.exists(lib.dir) && 
      if(!file.exists(lib.dir.exec)){                
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
  future.apply::future_lapply(y,FUN=deepstate_pkg_create_LibFuzzer)
  
  future.apply::future_lapply(y,FUN=deepstate_pkg_create_AFL)
  
  testfuncs.libfuzz <- function(pkg){
    insts.path <- normalizePath("~",mustWork=TRUE)
    deepstate <- file.path(insts.path,".RcppDeepState")
    deepstate.path <- file.path(deepstate,"deepstate-master")
    path <- file.path("/home/akhila/fuzzer_packages/fuzzedpackages",pkg)
    funs <- pkg.execlist[[pkg]]
    for(fun.i in funs){
      libfuzzer.fun.path <- file.path(fun.i,paste0("libFuzzer_",basename(fun.i)))
      harness.path <-  file.path(libfuzzer.fun.path,paste0(basename(fun.i),"_DeepState_TestHarness.cpp"))
      makefile.path <- file.path(libfuzzer.fun.path,"Makefile")
      if(file.exists(harness.path) && file.exists(makefile.path) ){
        executable <- paste0(basename(fun.i),"_DeepState_TestHarness")
      }
      compile_line <-paste0("rm -f *.o && make -f ",makefile.path)
      execution_line <- paste0("cd ",libfuzzer.fun.path," && ./",basename(executable)," -max_total_time=1800")
        print(compile_line)
        system(compile_line)
        print(execution_line)
        system(execution_line)
    }
  }  
  future::plan("multicore", workers=12)
  future.apply::future_lapply(z,FUN=testfuncs.libfuzz)
  