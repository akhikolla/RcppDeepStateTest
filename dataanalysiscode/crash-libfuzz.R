getNamespaceExports_fun <- function(pkg.i){
  namespace.list <- list()
  funnamespace = readLines(file.path(pkg.i,"NAMESPACE"),warn = FALSE)
  namespace.list <- nc::capture_all_str(funnamespace,
                                        status=".*",
                                        "\\(",
                                        fun=".*",
                                        "\\)")
  export_list <- namespace.list[status == "export", fun]
  return(export_list)
}


  pkg.execlist <- list() 
  pkg.unexlist <- list()
  #pkgs <- Sys.glob(file.path("~/testpackages/testfolders","*"))
  #pkgs <- Sys.glob(file.path("/home/akhila/fuzzer_packages/fuzzedpackages","*"))
  pkgs <- Sys.glob(file.path("/Users/akhilachowdarykolla/Desktop/TestedPackages-NoIssues","*"))
  #pkgs <- Sys.glob(file.path("/Users/akhilachowdarykolla/Desktop/RcppDeepStateTest/issuestests","*")) - 76
  #pkgs <- Sys.glob(file.path("/Users/akhilachowdarykolla/Desktop/updateddatatypeslist/","*"))
  #pkgs <- y
  for(pkg.i in pkgs){
    exelist <- list()
    unexelist <- list()
    testfiles <- file.path(pkg.i,"inst/testfiles")
    fun.count <- Sys.glob(file.path(testfiles,"*"))
    if(length(fun.count) > 0){
      for(fun.i in fun.count){
        #lib.dir <- file.path(fun.i, paste0("AFL_",basename(fun.i)))
        lib.dir.path <- file.path(fun.i,paste0("libFuzzer_",basename(fun.i)))
        lib.dir <- Sys.glob(file.path(fun.i,paste0("libFuzzer_",basename(fun.i)),"*"))
        libdir.inputs <- Sys.glob(file.path(lib.dir.path,"libfuzzer_inputs","*"))
        if(length(grep("crash-*",lib.dir,value=TRUE)) == 1){#&& length(libdir.inputs) >= 1
          exelist<- c(exelist,fun.i)
        }
        else{
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
  y <- paste0("/home/akhila/fuzzer_packages/fuzzedpackages/",names(pkg.execlist))
#y <- paste0("~/fuzzer_packages/fuzzedpackages/",names(pkg.execlist))
length(y)
#/home/akhila/fuzzer_packages/fuzzedpackages/Benchmarking 
#"/home/akhila/fuzzer_packages/fuzzedpackages/Luminescence"  
# "/home/akhila/fuzzer_packages/fuzzedpackages/PoissonBinomial"
#"/home/akhila/fuzzer_packages/fuzzedpackages/RI2by2" ,SeqNet   
#- 2,8
#crash.list <- list()
for(pks in y){
  pk <- pkg.execlist[[basename(pks)]]
  pkg.path <- file.path("/home/akhila/fuzzer_packages/fuzzedpackages",basename(pks))
  if(!file.exists(file.path(pkg.path,"src/*.so"))){
    system(paste0("R CMD INSTALL ",pkg.path),intern = FALSE,ignore.stderr =TRUE,ignore.stdout = TRUE)
  }
  for(j in pk){
    test_list <- list()
    j.base <- basename(j)
    fun_name <- j.base
    libfuzz.logs <- file.path(j,paste0("libFuzzer_",j.base),"libfuzzer_logs")
    if(!dir.exists(libfuzz.logs)){
      dir.create(libfuzz.logs,showWarnings = TRUE)
    }
    libfuzz.crash.path <- file.path(j,paste0("libFuzzer_",j.base),"libfuzzer_inputs")
    libfuzz.crash.check <- Sys.glob(file.path(libfuzz.crash.path,"*"))
    utime <- gsub("_.*","",basename(libfuzz.crash.check[length(libfuzz.crash.check)]))
    print(utime)
    #print(basename(libfuzz.crash.check))
    time.args <- grep(utime,basename(libfuzz.crash.check),value=TRUE)
    args.qs.files <- gsub(".*_","",time.args)
    fun.log <- file.path(libfuzz.logs,paste0(utime,"-log"))
    fun.log.inps <- file.path(libfuzz.logs,paste0(utime,"-inps.R"))
    inputs <- paste0(libfuzz.crash.path,"/",utime,"_",args.qs.files)
    deepstate_test_list <- vector(mode = "list", length=length(args.qs.files))
    for(inps in inputs){ 
      var <-if(length(grep(".qs",inps,value=TRUE)) > 0){
        qread(inps)
      }else{
        scan(inps,quiet=TRUE)
      }
      test_list[[gsub(".qs","",gsub(".*_","",basename(inps)))]] <- var
    }
    if(fun_name %in% getNamespaceExports_fun(paste0("/home/akhila/fuzzer_packages/fuzzedpackages/",basename(pks)))){
      symbol <-"::"
      exported = TRUE
    }else{
      symbol <-":::"
      exported = FALSE
    }
    if(file.exists(fun.log.inps))
    {
      file.remove(fun.log.inps)
    }
    file.create(fun.log.inps)
    dput(test_list,fun.log.inps)
    d_lines <- readLines(fun.log.inps,warn=FALSE)
    d_lines <- gsub("list","testlist <- list",d_lines,fixed=TRUE)
    cat(d_lines,file=fun.log.inps,append=TRUE) 
    run_line <- paste0("R -d \"valgrind --tool=memcheck --leak-check=full --xml=yes --xml-file=",
                       fun.log,"\""," --vanilla < ", fun.log.inps )
   print(run_line)
  system(run_line)
  data.result <- RcppDeepState::deepstate_read_valgrind_xml(fun.log)
  if(!is.null(data.result) && nrow(data.result) > 0){
   print("Here")
     crash.list[[fun_name]] <- data.table(pkg.name= pks,
                                         fun.name = fun_name,
     libfuzz.issue = paste0(data.result$message[1]," : ",data.result$file.line[1]))
  }
  }
  
}    
message(sprintf("%s\n",paste(basename(y), collapse=", ")))

