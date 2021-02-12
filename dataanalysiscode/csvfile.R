list.package.fun.issues <- function(packages){
    final.package.list <- list()
    package.funs.list <- list()
    test_list <- list()
  for(pkg.i in packages){
      package.path <- pkg.i
      sprintf("Package name - %s\n",basename(pkg.i))
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
          data.result <- RcppDeepState::deepstate_read_valgrind_xml(valgrind_log)
          if(!is.null(data.result) && nrow(data.result) > 0){
            flag = 1
            log.path = log.i
            result = data.result;
          }
        }
        if(flag == 1){
          log.path.list <- Sys.glob(file.path(log.path,"*")) 
          valgrind.list <- c(file.path(log.path,"valgrind_log_text"),file.path(log.path,"valgrind_log"))  
          inputs <- outersect(log.path.list,valgrind.list)
          inputs <- outersect(inputs,grep("-test.R",inputs,value=TRUE))
          deepstate_test_list <- vector(mode = "list", length=length(inputs))
          for(inps in inputs){
            var <-if(length(grep(".qs",inps,value=TRUE)) > 0){
              qread(inps)
            }else{
              scan(inps,quiet=TRUE)
            }
            test_list[[gsub("*.qs","",basename(inps))]] <- var
          }
         
          if(fun_name %in% getNamespaceExports_fun(pkg.i)){
            symbol <-"::"
            exported = TRUE
          }else{
          symbol <-":::"
          exported = FALSE
          }
          fun.test.file <- file.path(paste0("~/inputs","-test.R"))
          if(file.exists(fun.test.file))
          {
            file.remove(fun.test.file)
          }
          file.create(fun.test.file)
          dput(test_list,fun.test.file)
          d_lines <- readLines(fun.test.file,warn=FALSE)
    
  package.funs.list[[paste0(basename(pkg.i),"-",fun_name)]] <- data.table(Package=paste0(basename(pkg.i)),#symbol,fun_name), 
                                                                          Function = fun_name,        
                                                                        Inputs=paste0("inputs <-",list(d_lines)),
                                                                          Valgrind_Issue = result$message[1],
                                                                          Issued_Files = result$file.line[1],
                                                                          exported = exported)
          
  }
      }
      #print(package.funs.list)
      package.funs <- do.call(rbind, package.funs.list)
    }
    print(package.funs)
    
  }
#  xc <- list.package.fun.issues(es)
test <- list.package.fun.issues(ks) 