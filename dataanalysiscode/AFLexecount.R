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
        lib.dir <- file.path(fun.i, paste0("AFL_",basename(fun.i)))
        #lib.dir <- file.path(fun.i, paste0("libFuzzer_",basename(fun.i)))    
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
  

for(pkg in names(pkg.execlist)){
  funs <- pkg.execlist[[pkg]]
  path <- file.path("/home/akhila/fuzzer_packages/fuzzedpackages",pkg)
  if(!file.exists(file.path(path,"src/*.so"))){
    system(paste0("R CMD INSTALL ",path),intern = FALSE,ignore.stderr =TRUE,ignore.stdout = TRUE)
  }
  for(fun.i in funs){
    print(fun.i)
  deepstate_create_makefile(path,basename(fun.i))
}
}
  
testfuncs <- function(pkg){
#for(pkg in names(pkg.execlist)){
  insts.path <- normalizePath("~",mustWork=TRUE)
  deepstate <- file.path(insts.path,".RcppDeepState")
  deepstate.path <- file.path(deepstate,"deepstate-master")
  AFL_HOME = file.path(deepstate,"afl-2.52b")
  Sys.setenv(AFL_HOME=AFL_HOME)
  path <- file.path("/home/akhila/fuzzer_packages/fuzzedpackages",pkg)
  funs <- pkg.execlist[[pkg]]
  #deepstate_pkg_create_AFL(path)
  for(fun.i in funs){
    afl.fun.path <- file.path(fun.i,paste0("AFL_",basename(fun.i)))
    harness.path <-  file.path(afl.fun.path,paste0(basename(fun.i),"_DeepState_TestHarness.cpp"))
    makefile.path <- file.path(afl.fun.path,"Makefile")
    if(file.exists(harness.path) && file.exists(makefile.path) ){
      executable <- paste0(basename(fun.i),"_DeepState_TestHarness")#gsub(".cpp$","",afl.fun.path)
      #input_dir <- file.path(afl.fun.path,"afl_inputs")
      input_dir <- file.path(fun.i,"inputs")
      output_dir <- file.path(afl.fun.path,paste0("afl_",basename(fun.i),"_output"))
    }
    
    compile_line <-paste0("cd ",afl.fun.path," && rm -f *.o && make")
    execution_line <- paste0("cd ",afl.fun.path," && ${AFL_HOME}/afl-fuzz -i ", input_dir," -o ",output_dir," -d -m 150 -t 2000+ -- ./",basename(executable),
                             " --input_test_file @@ --no_fork")
    system(compile_line)
    system(execution_line)
    
  }
}

#/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils

y <- paste0("~/fuzzer_packages/fuzzedpackages/",names(pkg.execlist))
  future::plan("multiprocess", workers=12)
  future.apply::future_lapply(y, FUN=testfuncs)

  future::plan("multiprocess", workers=12)
  future.apply::future_lapply(y, FUN=deepstate_pkg_create_AFL)
  