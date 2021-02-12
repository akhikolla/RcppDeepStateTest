example.valid.test <- function(){
  packages <- Sys.glob(file.path("~/fuzzer_packages/fuzzedpackages","*"))
  example.res.list<- list()
  packages <- packages[-c(46,47,99,100)]
  
  packages <- packages[-c(72,73)]
  for(pkg.i in packages){
   package.path <- pkg.i 
  sprintf("Package name - %s\n",basename(pkg.i))
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  relative <- pkg.i
  path <- normalizePath(relative, mustWork=TRUE)
  #Rcpp::compileAttributes(path)
  RcppExports.R <- file.path(path, "R", "RcppExports.R")
  #fun.name.vecs <- ls(fun.env)
  fun.env <- new.env()
  #fun.name.vec <- intersect(fun.name.vecs,basename(testfuns))
  for(fun.i in testfuns){
    source(RcppExports.R, fun.env)
    test_list <- list()
    fun.name <- basename(fun.i)
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
  con <- file.path("/home/akhila/fuzzer_packages/valgrind_test_dir",paste0(basename(fun.name),"-test.R"))
  writeLines(paste(fun.name, "<-"), con)
  dput(fun, con)
example.issue = "None"
output_folder <- paste0("home/akhila/fuzzer_packages/fuzzedpackages/",basename(pkg.i),"/inst/testfiles/",basename(fun.name),"/",basename(fun.name),"_output/")
if(dir.exists(output_folder)){
xml_file <- paste0("/home/akhila/fuzzer_packages/fuzzedpackages/",basename(pkg.i),"/inst/testfiles/",basename(fun.name),"/",basename(fun.name),"_output/",basename(pkg.i),"-",basename(fun.name),"-example")  
}else{
  xml_file <- paste0("/home/akhila/fuzzer_packages/fuzzedpackages/",basename(pkg.i),"/inst/testfiles/",basename(fun.name),"/",basename(pkg.i),"-",basename(fun.name),"-example")  
  
}

system(paste0("R -d \"valgrind --tool=memcheck --leak-check=full --xml=yes --xml-file=",xml_file,"\""," --vanilla < ","~/fuzzer_packages/valgrind_test_dir/",basename(fun.name),"-test.R"))
print(paste0("R -d \"valgrind --tool=memcheck --leak-check=full --xml=yes --xml-file=",xml_file,"\""," --vanilla < ","~/fuzzer_packages/valgrind_test_dir/",basename(fun.name),"-test.R"))

res.example = RcppDeepState::deepstate_read_valgrind_xml(xml_file)
if(nrow(res.example) > 0){
  example.issue=paste0(res.example$message[1]," : ",res.example$file.line[1])
}
fun_output <- file.path(fun.i,paste0(fun.name,"_output"))
sprintf("fun.name - %s\n\n",fun.name)
log.files <- log.files.extract(Sys.glob(file.path(fun_output,"*")))
flag = 0
log.path = ""
rcppdeepstate.issue="None"
for(log.i in log.files){
  valgrind_log <- file.path(log.i,"valgrind_log")
  data.result <- RcppDeepState::deepstate_read_valgrind_xml(valgrind_log)
  if(!is.null(data.result) && nrow(data.result) > 0){
    flag = 1
    log.path = log.i
    rcppdeepstate.issue = paste0(data.result$message[1]," : ",data.result$file.line[1])
    print(rcppdeepstate.issue)
  }else{
    rcppdeepstate.issue = "None"
  }
}

if(is.null(nrow(res.example)) && nrow(data.result) > 0){
  no.issue = TRUE
}else{
  no.issue = FALSE
}

if(rcppdeepstate.issue == example.issue && example.issue != "None"){
  same.issue = example.issue
}else{
  same.issue = "None"
}
if(fun.name %in% getNamespaceExports_fun(pkg.i)){
  symbol <-"::"
  exported = TRUE
}else{
  symbol <-":::"
  exported = FALSE
}
different.issue="None"
if(rcppdeepstate.issue != example.issue && example.issue != "None" && rcppdeepstate.issue != "None"){
  different.issue=paste0(example.issue,"- ",rcppdeepstate.issue)
}
example.res.list[[fun.name]]<- data.table(pkg=basename(pkg.i), func.name=fun.name, exported = exported,
           example.issue= example.issue,
           same.issue = same.issue ,
           rcppdeepstate.issue=rcppdeepstate.issue,
           different.issue=different.issue,
           no.issue=no.issue)


  }
  ex.res <- do.call(rbind,example.res.list)
  write.csv(ex.res,"~/fuzzer_packages/RcppDeepStateTest/example-valid-checks.csv")
  }
ex.res <- do.call(rbind,example.res.list)
return(ex.res)
}