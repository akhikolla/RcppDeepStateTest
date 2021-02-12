packages <- Sys.glob(file.path("~/fuzzer_packages/fuzzedpackages","*"))
funs.count <- 0
datatypes <- list("NumericVector","NumericMatrix" ,"arma::mat","double",
                               "string","CharacterVector","int","IntegerVector")
#datatype.count.list  <- vector(mode = "list", length=length(datatypes))
datatype.count.list <- list()
for(i in datatypes){
  datatype.count.list[[i]] <- 0
}
#print(datatype.count.list) 
#packages <- Sys.glob(file.path("~/fuzzer_packages/fuzzedchangedpackages","*"))
for(pkg.i in packages){
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  funs.count <- funs.count + length(testfuns)
  functions.list <-  RcppDeepState::deepstate_get_function_body(pkg.i)   
  functions.list$argument.type<-gsub("Rcpp::","",functions.list$argument.type)
  fun_names <- unique(functions.list$funName)
      for(fun.i in testfuns){
      functions.rows  <- functions.list [functions.list$funName == basename(fun.i),]
      #print(functions.rows)
      params <- c(functions.rows$argument.type)
      print(params)
      print(basename(pkg.i))
      for(i in params){
        #arg.type <- gsub(" ","",functions.rows [argument.i,argument.type])
        type.arg <- gsub(" ","",i)
        type.arg <- gsub("const","", type.arg)
        type.arg <-gsub("Rcpp::","",type.arg)
        type.arg <-gsub("std::","",type.arg)
      #print(type.arg)
         datatype.count.list[[type.arg]] <- datatype.count.list[[type.arg]] + 1
      }
      
      }
}
