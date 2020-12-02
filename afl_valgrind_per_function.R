library(qs)
relative <- commandArgs(trailingOnly=TRUE)
print(relative)
no.qs <- list()
 time <- basename(relative)
package_name <-gsub("/inst/testfiles.*","",relative)
#library(basename(package_name))
test_path <- file.path(package_name,"inst/testfiles")
function_path <- gsub(".*./inst/testfiles/","",relative)
fun.i <- gsub("/.*","",function_path)
functions.list <-  RcppDeepState::deepstate_get_function_body(package_name)
if(length(functions.list ) > 0){
  functions.rows  <- functions.list [functions.list$funName == fun.i,]
  test_list <- vector(mode = "list", length=length(functions.rows$argument.name))
  names(test_list) <- gsub(" ","",functions.rows$argument.name)
  afl.fun.path <- file.path(test_path,fun.i,paste0("AFL_",fun.i))
  afl.inputs <- Sys.glob(file.path(afl.fun.path,"afl_inputs/*"))
  afl.inputs.path <- file.path(afl.fun.path,"afl_inputs")
  time.args <- grep(time,basename(afl.inputs),value=TRUE)
  args.qs.files <- gsub(".*_","",time.args) 
    for(name in names(test_list)){
      qread.path <- file.path(afl.inputs.path,paste0(time,"_",name,".qs"))
      var <- qread(qread.path)
      test_list[[name]] <- var
  }
  print(names(test_list))
  print(test_list)
fun <- get(fun.i, getNamespace(basename(package_name)))
test_result <- do.call(fun,test_list)
str(test_result)
}


