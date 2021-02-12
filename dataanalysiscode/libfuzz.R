deepstate_pkg_create_LibFuzzer<-function(path){
  path <- normalizePath(path,mustWork=TRUE)
  insts.path <- normalizePath("~",mustWork=TRUE)
  deepstate <- file.path(insts.path,".RcppDeepState")
  deepstate.path <- file.path(deepstate,"deepstate-master")
  inst_path <- file.path(path, "inst")
  test_path <- file.path(inst_path,"testfiles")
  if(!(file.exists(file.path(insts.path,".RcppDeepState/deepstate-master/build/libdeepstate32.a")) &&
       file.exists(file.path(insts.path,"/.RcppDeepState/deepstate-master/build/libdeepstate.a")))){
    RcppDeepState::deepstate_make_run()
  }
  LF.a <- file.path(deepstate.path,"build_libfuzzer/libdeepstate_LF.a")
  if(!file.exists(LF.a)){
    deepstate_make_libFuzzer()
    #print("lib not exists")
  }
  exists_flag = 0
  if(!file.exists(file.path(path,"src/*.so"))){
    system(paste0("R CMD INSTALL ",path),intern = FALSE,ignore.stderr =TRUE,ignore.stdout = TRUE)
  }
  functions.list  <-  RcppDeepState::deepstate_get_function_body(path)
  fun_names <- unique(functions.list$funName)
  for(f in fun_names){
    libfuzzer.fun.path <- file.path(test_path,f,paste0("libFuzzer_",f))
    libfuzzer.harness.path <- file.path(libfuzzer.fun.path,paste0(f,"_DeepState_TestHarness"))
    input_dir <- file.path(libfuzzer.fun.path,"libfuzzer_inputs")
    inputs.list <- Sys.glob(file.path(input_dir,"*"))
    if(!dir.exists(libfuzzer.fun.path)){
      exists_flag = 1
      dir.create(libfuzzer.fun.path,showWarnings = FALSE)
    }
    function.path <- file.path(test_path,f)
    harness.path <-  file.path(function.path,paste0(f,"_DeepState_TestHarness.cpp"))
    makefile.path <- file.path(function.path,"Makefile")
    if(file.exists(harness.path) && file.exists(makefile.path) ){
      executable <- gsub(".cpp$","",harness.path)
      object <- gsub(".cpp$",".o",harness.path)
      o.logfile <- file.path(libfuzzer.fun.path,paste0("/",f,"_log"))
      logfile <-  file.path(libfuzzer.fun.path,paste0("/libfuzzer_",f,"_log"))
      output_dir <- file.path(libfuzzer.fun.path,paste0("/libfuzzer_",f,"_output"))
      if(!dir.exists(output_dir)) {
        dir.create(output_dir,showWarnings = FALSE)
      }
      
      if(!dir.exists(input_dir)) {
        dir.create(input_dir,showWarnings = FALSE)
      }
      #writing harness file
      harness_lines <- readLines(harness.path,warn=FALSE)
      harness_lines <- gsub("RInside R;","static int rinside_flag = 0;\n  if(rinside_flag == 0)\n  {\n    rinside_flag = 1;\n    RInside R;\n  } std::time_t current_timestamp = std::time(0);"
                            ,harness_lines,fixed=TRUE)
      k <- nc::capture_all_str(harness_lines,
                               "qs::c_qsave","\\(",
                               save=".*",",\"",l=".*","\"")
      for(i in seq_along(k$l)){
        harness_lines <- gsub(paste0("\"",k$l[i],"\""),paste0(gsub(".qs","",basename(k$l[i])),"_t"),harness_lines,fixed=TRUE)
        harness_lines <- gsub(paste0("qs::c_qsave(",gsub(".qs","",basename(k$l[i]))),paste0("std::string ",gsub(".qs","",basename(k$l[i])),"_t = ","\"",dirname(dirname(k$l[i])),
                                                                                            "/",basename(libfuzzer.fun.path),"/libfuzzer_inputs/\" + std::to_string(current_timestamp) +
          \"_",basename(k$l[i]),"\"",";\n  qs::c_qsave(",gsub(".qs","",basename(k$l[i]))),harness_lines,fixed=TRUE)
      }
      harness.libFuzz <- file.path(libfuzzer.fun.path,basename(harness.path))
      file.create(harness.libFuzz,recursive=TRUE)
      cat(harness_lines, file=harness.libFuzz, sep="\n")
      
      ##makefileupdate
      makefile_lines <- readLines(makefile.path,warn=FALSE)
      makefile_lines <- gsub(function.path,libfuzzer.fun.path,makefile_lines,fixed=TRUE)
      makefile_lines <- gsub("clang++ -g","clang++ -g -fsanitize=address,fuzzer",makefile_lines,fixed=TRUE)
      makefile_lines <- gsub("-ldeepstate","-ldeepstate -ldeepstate_LF",makefile_lines,fixed=TRUE)
      makefile_lines <- gsub("deepstate-master/build","deepstate-master/build_libfuzzer",makefile_lines,fixed=TRUE)
      makefile.libFuzz <- file.path(libfuzzer.fun.path,"Makefile")
      file.create(makefile.libFuzz,recursive=TRUE)
      cat(makefile_lines, file=makefile.libFuzz, sep="\n")
      compile_line <-paste0("rm -f *.o && make -f ",makefile.libFuzz)
      execution_line <- paste0("cd ",libfuzzer.fun.path," && ./",basename(executable)," -max_total_time=1800")
      if(exists_flag == 1){
        print(compile_line)
        system(compile_line)
        print(execution_line)
        system(execution_line)
      }
    }
  }
  
}

