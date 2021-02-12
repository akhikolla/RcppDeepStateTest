
length(packages)
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
message(sprintf("count - %d\n %s\n",no.exists,paste(noexists.pkgs, collapse=", ")))

packages <- Sys.glob(file.path("~/Desktop/compileAttributes","*"))
packages <- packages[-c(8,82,88,90,108,114,115,128,129,130,136,148,152,176,178,179,286,298
                        ,327,334,336,337,345,363,388,395,431,435,448,463,527,609,611,623,
                        654,655,657,667,706,757,840,699,711,714,732,734,735,736,776,858,935,969)]


deepstate_datatype_check <- function(params.list){
  params.list <- gsub("const","",params.list)
  params.list <-gsub("Rcpp::","",params.list)
  params.list <-gsub(" ","",params.list)
  datatypes <- list("NumericVector","NumericMatrix" ,"arma::mat","double",
                    "std::string","CharacterVector","int","IntegerVector")
  for(pkg.i in seq_along(params.list)){
    #print(params.list[[pkg.i]])
    if(is.element(params.list[[pkg.i]], datatypes) =="FALSE"){
      return(0);
    }
    
  }
  return(1);
}


funs.count <- 0
datatypes <- list("NumericVector","NumericMatrix" ,"arma::mat","double",
                  "std::string","CharacterVector","int","IntegerVector")
pkg.datatype.count.list <- list()
fun.datatype.count.list <- list()
for(i in datatypes){
  pkg.datatype.count.list[[i]] <- 0
  fun.datatype.count.list[[i]] <- 0
}


for(pkg.i in packages){
  pkgs.list <- list()
  print(pkg.i)
  functions.list <-  deepstate_cleantype(pkg.i)
  if(!is.null(functions.list) && length(functions.list) > 1){
    fun_names <- unique(functions.list$funName)
    for(function_name.i in fun_names){
      unique.params <- list()
      functions.rows  <- functions.list [functions.list$funName == function_name.i,]
      params <- c(functions.rows$argument.type)
      params <- gsub("const","",params)
      params <-gsub("Rcpp::","",params)
      params <-gsub(" ","",params)
      #print(params)
      if(deepstate_datatype_check(params) == 1){
        funs.count <- funs.count + 1
        print(function_name.i)
        unique.params <- unique(params)
        for(p in unique.params){
          fun.datatype.count.list[[p]] <- fun.datatype.count.list[[p]] + 1 
        }
      }
      pkgs.list <- c(pkgs.list,unique.params)
    }
}
    pkgs.list <- unique(pkgs.list)
    for(p in pkgs.list){
      pkg.datatype.count.list[[p]] <- pkg.datatype.count.list[[p]] + 1 
    }
  }

