##' @title CleanTypes
##' @export
##' @description  clean datatypes
cleanType <- function(type.vec){
  if(length(type.vec)==0)return(type.vec)
  trans.list <- list(
    comments=function(x)gsub("/[*].*?[*]/", "", x),
    beginning=function(x)sub("^\\s+", "", x),
    end=function(x)sub("\\s+$", "", x),
    after.temp=function(x)gsub("([<>])\\s+", "\\1", x),
    before.temp=function(x)gsub("\\s+([<>])", "\\1", x),
    and=function(x)gsub("&", "", x),
    const=function(x)gsub("\\s*const\\s*", "", x),
    reps=function(x)gsub(" +", " ", x))
  for(fun in trans.list){
    type.vec <- fun(type.vec)
  }
  rep.dt <- unique(nc::capture_all_str(
    type.vec,
    namespace="\\b[^\\s:<]+?",
    "::",
    fun="[^<\\s]+?\\b")[!is.na(fun)])
  for(i in seq_along(rep.dt$fun)){
    rep.row <- rep.dt[i]
    pattern <- paste0("(?<!::)\\b", rep.row$fun, "\\b")
    replace <- rep.row[, paste0(namespace, "::", fun)]
    type.vec <- gsub(pattern, replace, type.vec, perl=TRUE)
  }
  type.vec
}

##' @title Package Details
##' @export
##' @description  Parse RcppExports file
parseRcppExports <- function(pkg.path){
  RcppExports.cpp <- normalizePath(file.path(
    pkg.path, "src", "RcppExports.cpp"),
    mustWork=TRUE)
  cpp.lines <- readLines(RcppExports.cpp)
  getParams <- function(line.vec){
    grep("Rcpp::traits::input_parameter", line.vec, value=TRUE)
  }
  all.param.lines <- getParams(cpp.lines)
  subject.vec <- gsub("/[*].*?[*]/", "", cpp.lines)
  include.lines <- grep("#include", subject.vec, value=TRUE)
  ns.dt <- nc::capture_all_str(
    subject.vec,
    "using namespace ",
    namespace="[^ ;]+")
  fun.dt <- nc::capture_all_str(
    subject.vec,
    "\n\\s*// ",
    commentName=".*",
    "\n",
    prototype=list(
      returnType=".*",
      " ",
      funName=".*?",
      "\\(",
      arguments=".*",
      "\\);\n"),
    SEXP=".*\n",
    "\\s*BEGIN_RCPP\\s*\n",
    code="(?:.*\n)*?",
    "\\s*END_RCPP")
  pkg.arg.dt <- if(nrow(fun.dt)==0){
    data.table::data.table()
  }else{
    fun.dt[, {
      code.vec <- strsplit(code, "\n")[[1]]
      no.comments <- sub("//.*", "", code.vec)
      input.vec <- getParams(no.comments)
      if(length(input.vec)==0){
        NULL
      }else{
        nc::capture_first_vec(
          input.vec, 
          "input_parameter< ",
          inside=".*",
          ">::type ",
          argument.name="[^(]+")
      }
    }, by=funName]
  } 
  pkg.lines.dt <- data.table::data.table(
    parameters=length(all.param.lines),
    parsed=nrow(pkg.arg.dt))
  list(
    lines=pkg.lines.dt,
    namespaces=ns.dt,
    includes=include.lines,
    prototypes=fun.dt[, .(funName, commentName, prototype)],
    arguments=pkg.arg.dt)
}

##' @title cleantypeallcalls
##' @export
##' @description  cleantypeall calls
deepstate_cleantype <- function(path){
  arg.dt.list <- list()
  pkg <- basename(path)
  package_path <- file.path(
    path,"src", "RcppExports.cpp")
  if(!file.exists(package_path)){
    stop("pkgdir must refer to the directory containing an R package")
  }else{
    result.list <- parseRcppExports(path)
    if(nrow(result.list$arguments)){
      arg.dt.list[[path]] <- data.table::data.table(
        pkg, result.list$arguments)
    }
    arg.dt <- do.call(rbind, arg.dt.list)
    arg.dt[,argument.type := cleanType(inside)]
    arg.dt[argument.type=="longint"]
    arg.dt[grepl(" ", funName)]
    return(data.table::data.table(funName=arg.dt$funName,argument.type=arg.dt$argument.type,argument.name=arg.dt$argument.name))
  }
}



##' @title Package Details
##' @return A list with all the relevant data in the RcppExrpots
##' @param path to the package with RcppExports file
##' @description Ths function takes the path to the test package and captures the argument specific data.
##' @import nc
##' @import data.table
##' @export
deepstate_get_package_details <- function(path){
  funs <- ""
  package_path <- file.path(
    path,"src", "RcppExports.cpp")
  if(!file.exists(package_path)){
    stop("pkgdir must refer to the directory containing an R package")
  }else{
    funs<- nc::capture_all_str(
      package_path,
      "\n\\s*// ",
      commentName=".*",
      "\n",
      prototype=list(
        returnType=".*",
        " ",
        funName=".*?",
        "\\(",
        arguments=".*",
        "\\);"),"\n",
      SEXP=".*\n","\\s*BEGIN_RCPP\\s*\n",
      code="(?:.*\n)*?",
      "\\s*END_RCPP")
  }
}

##' @title Function Details
##' @return A list with function names and arguments
##' @param package_path path to the test package
##' @examples
##' deepstate_get_function_body(system.file("testpkgs/testSAN", package = "RcppDeepState")) 
##' @export
deepstate_get_function_body<-function(package_path){
  funs <-  deepstate_cleantype(package_path) 
  function.list <-""
  if(nrow(funs) > 0){
    function.list <- funs[,{
      dt <- nc::capture_all_str(
        code,
        "input_parameter< ",
        argument.type=".*?",
        ">::type",
        argument.name="[^(]+")
    }, by=funName]
  }
  return(function.list)
}

##' @title Prototypes
##' @return prototypes list with function prototypes
##' @param package_path to the RcppExports file
##' @export
deepstate_get_prototype_calls <-function(package_path){
  funs <-  RcppDeepState::deepstate_get_package_details(package_path) 
  codes <- funs[,{nc::capture_all_str(code,"::wrap",calls ="(?:.*)")},by=funName]
  prototypes <-funs[,.(funName,prototype,calls=codes$calls)]
  return(prototypes)
}



##' @title TestHarness for the package
##' @param package_path path to the test package
##' @description Creates Testharness for all the functions in the package that you want to test
##' using RcppDeepState.
##' @examples 
##' path <- system.file("testpkgs/testSAN", package = "RcppDeepState")
##' harness.list <- deepstate_pkg_create(path)
##' print(harness.list)
##' @import RcppArmadillo
##' @return A character vector of TestHarness files that are generated
##' @export
deepstate_pkg_create<-function(package_path){
  package_path <-normalizePath(package_path, mustWork=TRUE)
  package_path <- sub("/$","",package_path)
  inst_path <- file.path(package_path, "inst")
  if(!dir.exists(inst_path)){
    dir.create(inst_path)
  }
  test_path <- file.path(inst_path,"testfiles")
  packagename <- basename(package_path)
  unlink(test_path, recursive = TRUE)
  if(!file.exists(file.path(package_path,"src/*.so"))){
    system(paste0("R CMD INSTALL ",package_path),intern = FALSE,ignore.stderr =TRUE,ignore.stdout = TRUE)
  }
  if(!(file.exists("~/.RcppDeepState/deepstate-master/build/libdeepstate32.a") &&
       file.exists("~/.RcppDeepState/deepstate-master/build/libdeepstate.a")))
  {
    RcppDeepState::deepstate_make_run()
  }
  dir.create(test_path,showWarnings = FALSE)
  #Rcpp::compileAttributes(package_path)
  harness <- list()
  failed.harness <- list()
  primitives <- list()
  functions.list <-  deepstate_cleantype(package_path)
  if(!is.null(functions.list) && length(functions.list) > 1){
    functions.list$argument.type<-gsub("Rcpp::","",functions.list$argument.type)
    print(functions.list$argument.type)
    prototypes_calls <-deepstate_get_prototype_calls(package_path)
    in_package <- paste0("RcppDeepState")
    match_count = 0
    mismatch_count = 0
    #dir.create(file.path(inst_path,"testfiles"))
    headers <-"#include <fstream>\n#include <RInside.h>\n#include <iostream>\n#include <RcppDeepState.h>\n#include <qs.h>\n#include <DeepState.hpp>\n"
    #include <-gsub("@","\"",includes)
    fun_names <- unique(functions.list$funName)
    for(function_name.i in fun_names){
      functions.rows  <- functions.list [functions.list$funName == function_name.i,]
      params <- c(functions.rows$argument.type)
      filepath <-deepstate_fun_create(package_path,function_name.i)
      filename <- paste0(function_name.i,"_DeepState_TestHarness",".cpp")
      if(!is.na(filepath) && basename(filepath) ==  filename ){
        match_count = match_count + 1
        harness <- c(harness,filename) 
      }
      else if(RcppDeepState::deepstate_datatype_check(params) == 0)
      {
        mismatch_count = mismatch_count + 1
        failed.harness <- c(failed.harness,function_name.i)
        #cat(sprintf("We can't test the function - %s - due to  datatypes fall out of the specified list\n", function_name.i))
      }
    }
    
    if(match_count > 0 && match_count == length(fun_names)){
      message(sprintf("Testharness created for %d functions in the package\n",match_count))
      return(as.character(harness))
    }
    else{
      if(mismatch_count < length(fun_names) && length(failed.harness) > 0 && match_count != 0){
        message(sprintf("Failed to create testharness for %d functions in the package - %s\n",mismatch_count,paste(failed.harness, collapse=", ")))
        message(sprintf("Testharness created for %d functions in the package\n",match_count))
        return(as.character(harness))
      }  
    }
    if(mismatch_count == length(fun_names)){
      stop("Testharnesses cannot be created for the package - datatypes fall out of specified list!!")
      return(as.character(failed.harness))
    }
  }
  else{
    stop("No Rcpp Functions to test in the package")
  }
}   




##' @title TestHarness for the function
##' @param package_path to the test package
##' @param function_name from the test package
##' @param sep infun default
##' @description The function creates Testharness for the provided function name.
##' @examples 
##' path <- system.file("testpkgs/testSAN", package = "RcppDeepState")
##' function_name <- "rcpp_read_out_of_bound"
##' function.harness <- deepstate_fun_create(path,function_name)
##' print(function.harness)
##' @return The TestHarness file that is generated
##' @export
deepstate_fun_create<-function(package_path,function_name,sep="infun"){
  inst_path <- file.path(package_path, "inst")
  test_path <- file.path(inst_path,"testfiles")
  if(!dir.exists(inst_path)){
    dir.create(inst_path,showWarnings = FALSE)
    dir.create(test_path,showWarnings = FALSE)
  }
  primitives <- list()
  packagename <- basename(package_path)
  functions.list <-deepstate_cleantype(package_path)
  functions.list$argument.type<-gsub("Rcpp::","",functions.list$argument.type)
  prototypes_calls <-RcppDeepState::deepstate_get_prototype_calls(package_path)
  if(sep=="generation" ||  sep == "checks"){ 
    if(is.null(functions.list) || length(functions.list) < 1){
      stop("No Rcpp Function to test in the package")
    }
  }
  headers <-"#include <fstream>\n#include <RInside.h>\n#include <iostream>\n#include <RcppDeepState.h>\n#include <qs.h>\n#include <DeepState.hpp>\n"
  write_to_file <- ""
  functions.rows  <- functions.list[functions.list$funName == function_name,]
  params <- c(functions.rows$argument.type)
  if(RcppDeepState::deepstate_datatype_check(params) == 1){
    pt <- prototypes_calls[prototypes_calls$funName == function_name,]
    fun_name <-function_name
    filename <- if(sep == "generation" || sep == "checks"){
      paste0(fun_name,"_DeepState_TestHarness_",sep,".cpp")
    }else{
      paste0(fun_name,"_DeepState_TestHarness.cpp")
    }
    fun_path <- file.path(test_path,fun_name)
    if(!dir.exists(fun_path)){
      dir.create(fun_path)
      #unlink(fun_path, recursive = TRUE)
    }
    
    if(sep == "generation" || sep == "checks"){
      gen.path <- file.path(fun_path,paste0(fun_name,"_DeepState_TestHarness_",sep,".cpp"))
      makesep.path <- file.path(fun_path,paste0(sep,".Makefile"))
      filename <- basename(gen.path)
      file_path <- file.path(fun_path,filename)
      file.create(file_path,recursive=TRUE)
      if(file.exists(file.path(fun_path,"Makefile"))){
        file.copy(file.path(fun_path,"Makefile"),makesep.path)
      }else{
        RcppDeepState::deepstate_create_makefile(package_path,fun_name)
        #file.copy(file.path(fun_path,"Makefile"),makegen.path)
      }
      makefile_lines <- readLines(file.path(fun_path,"Makefile"),warn=FALSE)
      makefile_lines <- gsub(file.path(fun_path,paste0(fun_name,"_DeepState_TestHarness")),
                             file.path(fun_path,paste0(fun_name,"_DeepState_TestHarness_",sep)),makefile_lines,fixed=TRUE)
      file.create(makesep.path,recursive=TRUE)
      cat(makefile_lines, file=makesep.path, sep="\n")
      unlink(file.path(fun_path,"Makefile"))
      #dir.create(file.path(testable_path,"inputs"),showWarnings = FALSE)
      dir.create(file.path(fun_path,paste0(fun_name,"_output","_",sep)),showWarnings = FALSE)
    }else{
      file_path <- file.path(fun_path,filename)
      file.create(file_path,recursive=TRUE)
      RcppDeepState::deepstate_create_makefile(package_path,fun_name)
    }
    comment <- paste0("// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT\n// ",
                      fun_name,"_DeepState_TestHarness_generation.cpp and ",fun_name,"_DeepState_TestHarness_checks.cpp\n\n")
    
    #write_to_file <-
    if(sep == "generation" || sep == "checks"){
      write(headers,file_path,append = TRUE)
    }else{
      write(paste0(write_to_file,comment,headers),file_path,append = TRUE)
    }
    write_to_file <-paste0(write_to_file,pt[1,pt$prototype],"\n")
    testname<-gsub(".","",paste0(function_name,"_test",sep=""))
    unittest<-gsub(".","",paste0(packagename,"_deepstate_test"))
    write_to_file <- paste0(write_to_file,"\n","TEST(",unittest,",",testname,")","{","\n")
    #obj <-gsub( "\\s+", " " ,paste(in_package,tolower(in_package),";","\n"))
    #write(obj,filename,append = TRUE)
    indent <- "  "
    write_to_file<-paste0(write_to_file,indent,"RInside R;\n",indent,"std::cout << #input starts# << std::endl;\n")
    proto_args <-""
    for(argument.i in 1:nrow(functions.rows)){
      arg.type <- gsub(" ","",functions.rows [argument.i,argument.type])
      arg.name <- gsub(" ","",functions.rows [argument.i,argument.name])
      type.arg <- gsub("const","", arg.type)
      type.arg <-gsub("Rcpp::","",type.arg)
      type.arg <-gsub("arma::","",type.arg)
      st_val <- if(sep == "generation"){
        paste0("= ","RcppDeepState_",(type.arg),"()","; //RANGE OF THE VECTOR CAN BE ADDED HERE\n")
      }else{
        paste0("= ","RcppDeepState_",(type.arg),"()",";\n")
      }
      inputs_path <- file.path(fun_path,"inputs")
      if(!dir.exists(inputs_path)){
        dir.create(inputs_path)
      }
      if(type.arg == "mat"){
        variable <- paste0(arg.type," ",arg.name)
        write_to_file<-paste0(write_to_file,indent,"std::ofstream ",
                              gsub(" ","",arg.name),"_stream",";\n")
        input.vals <- file.path(inputs_path,arg.name)
        file_open <- gsub("# ","\"",paste0(arg.name,"_stream.open(#",input.vals,"# );","\n",indent,
                                           arg.name,"_stream << ", 
                                           arg.name,";","\n",indent,
                                           "std::cout << ","#",arg.name,
                                           " values: ","#"," << ",arg.name,
                                           " << std::endl;","\n",indent,
                                           arg.name,"_stream.close();","\n"))
      }
      else{
        if(sep == "generation"){
          if(type.arg == "int"){
            variable <- paste0("IntegerVector ",arg.name,"(1);","\n",indent,"//RcppDeepState_",type.arg,"(low,high)","\n",indent,arg.name,"[0]")
            primitives <- c(primitives,arg.name)
          }
          else if(type.arg == "double") {
            variable <- paste0("NumericVector ",arg.name,"(1);","\n",indent,"//RcppDeepState_",type.arg,"(low,high)","\n",indent,arg.name,"[0]")
            primitives <- c(primitives,arg.name)
          }
          else if(type.arg == "std::string")
          {
            variable <- paste0("CharacterVector ",arg.name,"(1);","\n",indent,arg.name,"[0]")
            primitives <- c(primitives,arg.name)
          }
          else if(type.arg == "NumericVector" || type.arg == "IntegerVector"){
            variable <- paste0("//RcppDeepState_",type.arg,"(size,low,high)","\n",indent,arg.type," ",arg.name)
          }
          else if(type.arg == "NumericMatrix"){
            variable <- paste0("//RcppDeepState_",type.arg,"(row,column,low,high)","\n",indent,arg.type," ",arg.name)
          }
        }else{
          if(type.arg == "int"){
            variable <- paste0("IntegerVector ",arg.name,"(1);","\n",indent,arg.name,"[0]")
            primitives <- c(primitives,arg.name)
          }
          else if(type.arg == "double") {
            variable <- paste0("NumericVector ",arg.name,"(1);","\n",indent,arg.name,"[0]")
            primitives <- c(primitives,arg.name)
          }
          else if(type.arg == "std::string")
          {
            variable <- paste0("CharacterVector ",arg.name,"(1);","\n",indent,arg.name,"[0]")
            primitives <- c(primitives,arg.name)
          }else{
            variable <- paste0(arg.type," ",arg.name)
          }
        }
        variable <- gsub("const","",variable)
        arg.file <- paste0(arg.name,".qs")
        input.vals <- file.path(inputs_path,arg.file)
        file_open <- gsub("# ","\"",paste0("qs::c_qsave(",arg.name,",#",input.vals,"#,\n","\t\t#high#, #zstd#, 1, 15, true, 1);\n",indent,
                                           "std::cout << ","#",arg.name," values: ","#"," << ",arg.name,
                                           " << std::endl;","\n"))
      }
      proto_args <- gsub(" ","",paste0(proto_args,arg.name))
      if(argument.i <= nrow(functions.rows)) {
        if(type.arg == "int" || type.arg == "double" || type.arg == "std::string"){
          proto_args <- paste0(proto_args,"[0],")
        }else{
          proto_args <- paste0(proto_args,",")  
        }
      }
      write_to_file <- paste0(write_to_file,indent,paste0(variable,indent,st_val,indent,file_open))
    }
    write_to_file<-paste0(write_to_file,indent,"std::cout << #input ends# << std::endl;\n",indent,"try{\n")
    write_to_file<-paste0(write_to_file,indent,indent,fun_name,"(",gsub(",$","",proto_args),");\n")
    if(sep == "checks"){
      write_to_file<-paste0(write_to_file,indent,"//ASSERT CONDITIONS CAN BE ADDED HERE\n") 
    }
    write_to_file<-gsub("#","\"",paste0(write_to_file,indent,"}\n",indent,"catch(Rcpp::exception& e){\n",indent,indent,"std::cout<<#Exception Handled#<<std::endl;\n",indent,"}"))
    write_to_file<-paste0(write_to_file,"\n","}")
    write(write_to_file,file_path,append=TRUE)
    return(filename)
  } else if(RcppDeepState::deepstate_datatype_check(params) == 0){
    return(NA_character_)
  }
  
}




##' @title Harness compilation for the package
##' @param package_path to the test package
##' @param time.limit.seconds duration to run the testharness, defaulted to 5 seconds
##' @description Compiles all the generated function-specific testharness in the package.
##' @examples
##' path <- system.file("testpkgs/testSAN", package = "RcppDeepState")
##' compiled.harness.list <- deepstate_harness_compile_run(path)
##' print(compiled.harness.list)
##' @return A character vector of compiled functions.
##' @export
deepstate_harness_compile_run <- function(package_path,time.limit.seconds=5){
  if(time.limit.seconds <= 0){
    stop("time.limit.seconds should always be greater than zero")
  }
  package_path <- normalizePath(package_path, mustWork=TRUE)
  package_path <- sub("/$","",package_path)
  inst_path <- file.path(package_path, "inst")
  test_path <- file.path(inst_path,"testfiles")
  uncompiled.code <- list()
  compiled.code <- list()
  testharness<-deepstate_pkg_create(package_path)
  testharness <- gsub("_DeepState_TestHarness.cpp","",testharness)
  functions.list <- Sys.glob(file.path(test_path,"*"))
  #no harness created
  if(length(functions.list)){
    if(length(testharness) == length(basename(functions.list)) && 
       length(intersect(basename(functions.list),testharness)) == length(testharness)){
      uncompiled_count = 0
      log_count = 0
      for(fun.path in functions.list){
        compile.res <- RcppDeepState::deepstate_fuzz_fun(package_path,basename(fun.path),time.limit.seconds)
        if(!is.na(compile.res) && compile.res == basename(fun.path)){
          compiled.code <-c(compiled.code,compile.res)
        }
        else{
          uncompiled.code <- c(uncompiled.code,basename(fun.path))
        }
      }
      if(length(uncompiled.code) > 0)
        message(sprintf("Uncompiled functions : %s\n",paste(uncompiled.code, collapse=", ")))
      return(as.character(compiled.code))
    }
  }
  else{
    stop("TestHarness are not created for all the function that are returned by pkg create")
  }
}

##' @title Harness compilation for the function
##' @param fun_path path of the function to compile
##' @param sep default to infun
##' @description Compiles the function-specific testharness in the package.
##' @examples
##' path <- system.file("testpkgs/testSAN", package = "RcppDeepState")
##' compiled.harness <- deepstate_compile_fun(path)
##' print(compiled.harness)
##' @export
deepstate_compile_fun<-function(fun_path,sep="infun"){
  if(sep == "infun"){
    harness.file <- file.path(fun_path,paste0(basename(fun_path),"_DeepState_TestHarness.cpp"))
    make.file <- file.path(fun_path,"Makefile")
    compile_line <-paste0("cd ",fun_path," && rm -f *.o && make\n")
  }else if(sep == "generation"){
    harness.file <- file.path(fun_path,paste0(basename(fun_path),"_DeepState_TestHarness_generation.cpp"))
    make.file <- file.path(fun_path,"generation.Makefile")
    compile_line <-paste0("cd ",fun_path," && rm -f *.o && make -f generation.Makefile\n")
  }else if(sep == "checks"){
    harness.file <- file.path(fun_path,paste0(basename(fun_path),"_DeepState_TestHarness_checks.cpp"))
    make.file <- file.path(fun_path,"checks.Makefile")
    compile_line <-paste0("cd ",fun_path," && rm -f *.o && make -f checks.Makefile\n")
  }
  if(file.exists(harness.file) && 
     file.exists(make.file)){
    cat(sprintf("compiling .. \n%s\n",compile_line))
    system(compile_line)
  }else{
    stop("TestHarness and makefile doesn't exists. Please use deepstate_pkg_create() to create them")
  }
}

