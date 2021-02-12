#pkgs <- Sys.glob(file.path("~/testpackages/testpackages/fuzzedpackages","*"))
pkgs <- Sys.glob(file.path("~/testpackages/RcppDeepStateTest/issuestests","*"))
exists.pkgs <- list()
exists <- 0
no.exists <- 0
for(i in pkgs){
RcppExports.cpp <- file.path(i, "src/RcppExports.cpp")
if(file.exists(RcppExports.cpp)){
  exists <- exists + 1
  exists.pkgs <- c(exists.pkgs,i)
}else{
  no.exists <- no.exists + 1
}
}

funs.count <- 0
for(pkg.i in exists.pkgs){
  functions.list <-  RcppDeepState::deepstate_get_function_body(pkg.i)   
  if(!is.null(functions.list) && length(functions.list) > 1){
  fun_names <- unique(functions.list$funName)
  funs.count <- funs.count + length(fun_names)
  }
}

##output 4073
funs.count <- 0
for(pkg.i in pkgs){
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  funs.count <- funs.count + length(testfuns)
}