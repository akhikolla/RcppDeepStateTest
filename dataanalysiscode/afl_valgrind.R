library(qs)
  relative <- commandArgs(trailingOnly=TRUE)
  print(relative)
  #path <- normalizePath(relative, mustWork=TRUE)
  no.qs <- list()
  time <- basename(relative)
  cA.dir <- file.path(system.file("extdata",package="RcppDeepState"),"compileAttributes")
  root.path <- system.file("extdata",package="RcppDeepState")
  packages <- Sys.glob(file.path(cA.dir,"*"))
  for(pkg.i in seq_along(packages)){
  pkg.tar.gz <- packages[[pkg.i]]
  #pkg.tar.gz <- "~/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/compileAttributes/AGread"
  #export.vec <- getNamespaceExports(pkg.tar.gz)
  testfiles.vec <- Sys.glob(file.path(pkg.tar.gz,"inst/testfiles/*"))
  test_path <- file.path(pkg.tar.gz,"inst/testfiles")
  functions.list <-  RcppDeepState::deepstate_get_function_body(pkg.tar.gz)
  cat(sprintf("%4d - %s\n", pkg.i, pkg.tar.gz))
  if(length(testfiles.vec) > 0){
    bases_fun <- basename(testfiles.vec)
    for(fun.i in bases_fun){
        functions.rows  <- functions.list [functions.list$funName == fun.i,]
       my_list <- vector(mode = "list", length=length(functions.rows$argument.name))
       names(my_list) <- gsub(" ","",functions.rows$argument.name)
       afl.fun.path <- file.path(test_path,fun.i,paste0("AFL_",fun.i))
       afl.inputs <- Sys.glob(file.path(afl.fun.path,"afl_inputs/*"))
       afl.inputs.path <- file.path(afl.fun.path,"afl_inputs")
       time.args <- grep(time,basename(afl.inputs),value=TRUE)
       args.qs.files <- gsub(".*_","",time.args)
         for(args in args.qs.files){
         no.qs <- c(no.qs,gsub(".qs","",args))
         #qread.path <- file.path(afl.inputs.path,paste0(time,"_",args))
         #print(qread(qread.path))
         #input.list <- c(input.list,qread(qread.path))
         #assign(no.qs,qread(qread.path))
         #print(no.qs)      
         }      
       print(no.qs)
      print(names(my_list))
       if(length(intersect(no.qs,names(my_list))) == length(names(my_list)))
      {  for(name in names(my_list)){
         qread.path <- file.path(afl.inputs.path,paste0(time,"_",name,".qs"))
           my_list[name] <- qread(qread.path)
      }
}
         print(my_list)       
      #print(class(names(my_list)))    
      #input.lists<- as.call(c(substitute(list), sapply(input.list, as.symbol)))
      #print(input.list[1])
       funnamespace = readLines(file.path(pkg.tar.gz,"NAMESPACE"),warn = FALSE)
    namespace.list <- nc::capture_all_str(funnamespace,
                                          status=".*",
                                          "\\(",
                                          fun=".*",
                                          "\\)")
    export_list <- namespace.list[status == "export", fun]
       fun <- if(fun.i %in% export_list){
        paste0(pkg.tar.gz,"::",fun.i)
      }else{
         paste0(pkg.tar.gz,":::",fun.i)
       }
     result <- do.call(fun,my_list)
     print(result)
}
}
