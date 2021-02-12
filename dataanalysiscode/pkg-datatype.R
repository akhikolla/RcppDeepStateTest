packages <- Sys.glob(file.path("/Users/akhilachowdarykolla/Desktop/underrdp","*"))

pkgs <- packages
noexists.pkgs <- list()
exists <- 0
no.exists <- 0
for(i in pkgs){
  RcppExports.cpp <- file.path(i, "src/RcppExports.cpp")
  if(file.exists(RcppExports.cpp)){
    exists <- exists + 1
    
  }else{
    no.exists <- no.exists + 1
    noexists.pkgs <- c(noexists.pkgs,basename(i))
    }
}
message(sprintf("%s\n",paste(noexists.pkgs, collapse=", ")))


funs.count <- 0
datatypes <- list("NumericVector","NumericMatrix" ,"arma::mat","double",
                  "std::string","CharacterVector","int","IntegerVector")
#datatype.count.list  <- vector(mode = "list", length=length(datatypes))
pkg.datatype.count.list <- list()
for(i in datatypes){
  pkg.datatype.count.list[[i]] <- 0
}
notestfiles <- list()
for(pkg.i in packages){
  testpath <- file.path(pkg.i,"inst/testfiles")
  if(!dir.exists(testpath)){
    notestfiles <- c(notestfiles,pkg.i)
  }
}

unique.params <- list()
for(pkg.i in notestfiles){
  testpath <- file.path(pkg.i,"inst/testfiles")
  #testfuns <- Sys.glob(file.path(testpath,"*"))
  functions.list <- deepstate_cleantype(pkg.i)  #RcppDeepState::deepstate_get_function_body(pkg.i)   
  #print(functions.list)
  functions.list$argument.type<-gsub("Rcpp::","",functions.list$argument.type)
  fun_names <- unique(functions.list$funName)
  for(fun.i in fun_names){
    functions.rows  <- functions.list [functions.list$funName == basename(fun.i),]
    params <- c(functions.rows$argument.type)
    if(deepstate_datatype_check(params) == 1){
      unique.params <- c(unique.params,basename(pkg.i))
    
  }
  }
  print(unique.params)
}
  message(sprintf("%s\n",paste(unique.params, collapse=", ")))

unique.params <- list()
for(pkg.i in packages){
  unique.params <- list()
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  funs.count <- funs.count + length(testfuns)
  functions.list <- deepstate_cleantype(pkg.i)  #RcppDeepState::deepstate_get_function_body(pkg.i)   
  functions.list$argument.type<-gsub("Rcpp::","",functions.list$argument.type)
  fun_names <- unique(functions.list$funName)
  for(fun.i in testfuns){
    functions.rows  <- functions.list [functions.list$funName == basename(fun.i),]
    params <- c(functions.rows$argument.type)
    for(i in params){
      #arg.type <- gsub(" ","",functions.rows [argument.i,argument.type])
      type.arg <- gsub(" ","",i)
      type.arg <- gsub("const","", type.arg)
      type.arg <-gsub("Rcpp::","",type.arg)
      type.arg <-gsub("std::","",type.arg)
      #print(type.arg)
      unique.params <- c(unique.params,type.arg)
    }
    
  }
  print(unique.params)
  unique.params <- unique(unique.params)
  print(unique.params)
  for(j in unique.params){
    pkg.datatype.count.list[[j]] <- pkg.datatype.count.list[[j]] + 1 
  }
  
}


for(pkg.i in packages){
  unique.params <- list()
functions.list <-  deepstate_cleantype(pkg.i)
if(!is.null(functions.list) && length(functions.list) > 1){
  fun_names <- unique(functions.list$funName)
  for(function_name.i in fun_names){
    functions.rows  <- functions.list [functions.list$funName == function_name.i,]
    params <- c(functions.rows$argument.type)
    params <- gsub("const","",params)
    params <-gsub("Rcpp::","",params)
    params <-gsub(" ","",params)
      if(deepstate_datatype_check(params) == 1){
        funs.count <- funs.count + 1
        unique.params <- c(unique.params,type.arg)
        for(p in unique.params){
          fun.datatype.count.list[[p]] <- fun.datatype.count.list[[p]] + 1 
        }
        pkgs.list <- c(pkgs.list,pkg.i)
      }
    
  }
  pkgs.list <- unique(pkgs.list)
  for(p in pkgs.list){
  fun.datatype.count.list[[p]] <- fun.datatype.count.list[[p]] + 1 
}
}