pkg.datatypes<- function(pkg.list){
    pkg.dtypes <- list()
    for(pkg.i in pkg.list){
      RcppExports.cpp <- file.path(pkg.i, "src", "RcppExports.cpp")
        if(file.exists(RcppExports.cpp)){
          functions.list <- RcppDeepState::deepstate_get_function_body(pkg.i)
           if(!is.null(functions.list) && length(functions.list) > 1){
              functions.list$argument.type<-gsub("Rcpp::","",functions.list$argument.type)
               fun_names <- unique(functions.list$funName)
        for(fun.i in fun_names){
          functions.rows  <- functions.list [functions.list$funName == fun.i,]
          params <- c(functions.rows$argument.type)
          params.names <- c(functions.rows$argument.name)
          pkg.dtypes[[basename(fun.i)]] <- data.table(pkg.name= basename(pkg.i),
                                            fun.name = basename(fun.i),
                                            arg.types = paste0(list(params)),
                                            arg.names = paste0(list(params.names)))
           
        }
          }
        }
    }
    return(pkg.dtypes)
}

  pkgs.ex <-0
  no.ex <- 0
for(pkg.i in pkgs){
  RcppExports.cpp <- file.path(pkg.i, "src", "RcppExports.cpp")
  if(file.exists(RcppExports.cpp)){
    pkgs.ex <- pkgs.ex + 1
  }else{
    no.ex <- no.ex + 1
  }
}
  
  
 #count functions :
   
  fun.var <- 0
  for(pkg.i in pkgs){
    package.path <- pkg.i 
    sprintf("Package name - %s\n",basename(pkg.i))
    testpath <- file.path(pkg.i,"inst/testfiles")
    testfuns <- Sys.glob(file.path(testpath,"*"))
    for(i in testfuns)
    fun.var <- fun.var + length(testfuns)
  }
  
  #count Issued functions:
  
  err.fun.var <- 0
  pkgs <- pkgs[-c(74,75,177,178)]
  for(pkg.i in pkgs){
    package.path <- pkg.i
    testpath <- file.path(pkg.i,"inst/testfiles")
    testfuns <- Sys.glob(file.path(testpath,"*"))
    for(fun.i in testfuns){
      test_list <- list()
      fun_name <- basename(fun.i)
      fun_output <- file.path(fun.i,paste0(fun_name,"_output"))
      sprintf("fun_name - %s\n\n",fun_name)
      log.files <- log.files.extract(Sys.glob(file.path(fun_output,"*")))
      flag = 0
      log.path = ""
      for(log.i in log.files){
        valgrind_log <- file.path(log.i,"valgrind_log")
        if(file.exists(valgrind_log)){
        data.result <- RcppDeepState::deepstate_read_valgrind_xml(valgrind_log)
        print(basename(pkg.i))
        print(data.result)
        }
        if(!is.null(data.result) && nrow(data.result) > 0){
          flag = 1
          log.path = log.i
          result = data.result;
        }
      }
      if(flag == 1){
        err.fun.var = err.fun.var + 1
      }
    }
  }