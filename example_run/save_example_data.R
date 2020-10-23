sink("/home/akolla/alloutput.txt",append=T)
relative <- commandArgs(trailingOnly=TRUE)
path <- normalizePath(relative, mustWork=TRUE)
Rcpp::compileAttributes(path)
RcppExports.R <- file.path(path, "R", "RcppExports.R")
fun.env <- new.env()
source(RcppExports.R, fun.env)
con <- file(RcppExports.R, "w")
fun.name.vec <- ls(fun.env)
for(fun.name in fun.name.vec){
  fun <- fun.env[[fun.name]]
  arg.list <- formals(fun)
  rhs <- as.call(c(substitute(list), sapply(names(arg.list), as.symbol)))
  code <- body(fun)
  call.line <- code[[2]]
  call.line[[2]] <- sub("`", "'", call.line[[2]])
  body(fun) <- substitute({
    e <- get("data.env", .GlobalEnv)
    e[[NAME]][[length(e[[NAME]])+1]] <- RHS
    CALL
  }, list(NAME=fun.name, RHS=rhs, CALL=call.line))
  writeLines(paste(fun.name, "<-"), con)
  dput(fun, con)
}
close(con) 
install.packages(path, repos=NULL)
pkg <- basename(relative)
data.env <- new.env()
library(pkg, character.only=TRUE)
export.vec <- getNamespaceExports(pkg)
for(obj.name in export.vec){
  example(obj.name, package=pkg, character.only = TRUE)
}
data.result <- data.frame(sapply(data.env, length))
export_list <- row.names(data.result)
cat(sprintf("Package name : %s\n ",path))
data.result <- cbind(exported.funs=row.names(data.result),example.calls=data.result[,1])
print(data.result)
outersect <- function(x, y) {
  sort(c(x[!x%in%y],
         y[!y%in%x]))
}
tests.list<- file.path(path, "inst/testfiles")
fun.lists <- Sys.glob(paste0(tests.list,"/*"))
fun.lists <-  basename(fun.lists)
if(length(intersect(export_list, fun.lists)) > 1){
cat(sprintf("\nMatched functions : %s\n ",list(intersect(export_list, fun.lists))))
cat(sprintf("Mismatced functions not used in examples: %s\n ",list(outersect(export_list, fun.lists))))
}else{
  cat(sprintf("\nMatched functions : %s\n ",list(intersect(export_list, fun.lists))))
  cat(sprintf("Mismatced functions not used in examples: %s\n ",list(outersect(export_list, fun.lists))))
}
print("list ends")
test.R.vec <- Sys.glob(file.path(path, "tests", "*.[Rr]"))
try(devtools::test(path))##testthat only.
for(test.R in test.R.vec)try(source(test.R))#non-testthat.
sapply(data.env, length)
saveRDS(as.list(data.env), paste0(path, "_inputs_all.rds"))
noerr.list <- list()
for(fun.name in ls(data.env)){
  fun.input.lists <- data.env[[fun.name]]
  fun <- get(fun.name, getNamespace(pkg))
  fun.noerr.lists <- list()
  for(input.list in fun.input.lists){
    result <- try(do.call(fun, input.list))
    if(!is(result, "try-error")){
      fun.noerr.lists[[length(fun.noerr.lists)+1]] <- input.list
    }
  }
  noerr.list[[fun.name]] <- fun.noerr.lists
}
sapply(noerr.list, length)
saveRDS(noerr.list, paste0(path, "_inputs_noerr.rds"))

