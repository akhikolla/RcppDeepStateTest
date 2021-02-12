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
#packages <- packages[-c(46,47,99,100)]
#packages <- packages[-c(72,73)]
#for(pkg.i in packages){
#packages <- Sys.glob(file.path("~/fuzzer_packages/fuzzedpackages","*"))
valgrind_libfuzz_test <- function(pkg.i){
  afl.res.list<- list()
  package.path <- pkg.i 
  sprintf("Package name - %s\n",basename(pkg.i))
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  for(fun.i in testfuns){
    fun <- basename(fun.i)
    afl.fun.path <- file.path(testpath,fun,paste0("libFuzzer_",fun))
    afl.inputs <- Sys.glob(file.path(afl.fun.path,"libfuzzer_inputs/*"))
    afl.inputs.path <- file.path(afl.fun.path,"libfuzzer_inputs") 
    times <- unique(gsub("_.*","",basename(afl.inputs)))
    output_folder <- paste0(afl.fun.path,paste0("/",fun,"_timely_output"))
    val_folder <- paste0(afl.fun.path,paste0("/",fun,"_valgrind_files"))
    unlink(output_folder)
    unlink(val_folder)
    if(!dir.exists(output_folder) && !dir.exists(val_folder)){
      
      dir.create(output_folder)
      dir.create(val_folder)
    }
    for(utime in times){
      test_list <- list()
      time.args <- grep(utime,basename(afl.inputs),value=TRUE)
      test_list <- vector(mode = "list", length=length(time.args))
      args.qs.files <- gsub(".*_","",time.args) 
      names(test_list) <- gsub(".qs","",args.qs.files)
      args.times<- grep(utime,afl.inputs,value=TRUE)
      for(arg in args.times){
        var <-if(length(grep(".qs",arg,value=TRUE)) > 0){
          qread(arg)
          print(qread(arg))
        }else{
          scan(arg,quiet=TRUE)
          print(scan(arg,quiet=TRUE))
        }
        test_list[[gsub(paste0(utime,"_"),"",gsub("*.qs","",basename(arg)))]] <- var
      }
      
      fun.test.file <- file.path(val_folder,paste0(utime,"-test.R"))
      if(file.exists(fun.test.file))
      {
        file.remove(fun.test.file)
      }
      file.create(fun.test.file)
      dput(test_list,fun.test.file)
      d_lines <- readLines(fun.test.file,warn=FALSE)
      d_lines <- gsub("list","testlist <- list",d_lines,fixed=TRUE)
      file.create(fun.test.file)
      cat(d_lines,file=fun.test.file,append=TRUE) 
      xml_file <- paste0(output_folder,"/",utime,"_xml") 
      if(fun %in% getNamespaceExports_fun(pkg.i)){symbol <-"::"}else{symbol <-":::"}
      cat(paste0("\nresult <- do.call(",basename(pkg.i),symbol,fun,",testlist)\nstr(result)"),file=fun.test.file,append=TRUE)      
      
      system(paste0("R -d \"valgrind --tool=memcheck --leak-check=full --xml=yes --xml-file=",xml_file,"\""," --vanilla < ",fun.test.file))
      print(paste0("R -d \"valgrind --tool=memcheck --leak-check=full --xml=yes --xml-file=",xml_file,"\""," --vanilla < ",fun.test.file))
      res = RcppDeepState::deepstate_read_valgrind_xml(xml_file) 
      print(res)
    }
  }
}


y <- paste0("/home/akhila/fuzzer_packages/fuzzedpackages/",names(pkg.unexlist))
future::plan("multiprocess", workers=12)
future.apply::future_lapply(y, FUN=valgrind_libfuzz_test)

packages <- Sys.glob(file.path("/home/akhila/fuzzer_packages/fuzzedpackages","*"))
pkg.list <- list()
for(pkg.i in packages){
  sprintf("Package name - %s\n",basename(pkg.i))
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  fun.list <- list()
  for(fun.i in testfuns){
    fun <- basename(fun.i)
    afl.fun.path <- file.path(testpath,fun,paste0("AFL_",fun))
    afl.inputs <- Sys.glob(file.path(afl.fun.path,"afl_inputs/*"))
    afl.inputs.path <- file.path(afl.fun.path,"afl_inputs") 
    times <- unique(gsub("_.*","",basename(afl.inputs)))
    output_folder <- paste0(afl.fun.path,paste0("/",fun,"_timely_output"))
    val_folder <- paste0(afl.fun.path,paste0("/",fun,"_valgrind_files"))
    if(dir.exists(output_folder) && dir.exists(val_folder)){
      val_folder_list <- Sys.glob(file.path("/home/akhila/fuzzer_packages/fuzzedpackages","*"))
      if(length(times) == length(val_folder_list)){
        fun.list <- c(fun.list,fun)
      }
    }
  }
  pkg.list[[basename(pkg.i)]] <- fun.list
}
