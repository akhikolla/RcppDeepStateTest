deepstate_pkg_create_AFL<-function(path){
  path <- normalizePath(path,mustWork=TRUE)
  #$AFL_HOME/afl-fuzz -i foo -o afl_Runlen -- ./Runlen_AFL --input_test_file @@ --no_fork --abort_on_fail
  insts.path <- normalizePath("~",mustWork=TRUE)
  deepstate <- file.path(insts.path,".RcppDeepState")
  deepstate.path <- file.path(deepstate,"deepstate-master")
  inst_path <- file.path(path, "inst")
  test_path <- file.path(inst_path,"testfiles")
  if(!(file.exists(file.path(insts.path,".RcppDeepState/deepstate-master/build/libdeepstate32.a")) &&
       file.exists(file.path(insts.path,".RcppDeepState/deepstate-master/build/libdeepstate.a")))){
    #RcppDeepState::deepstate_make_run()
  }
  AFL.a <- file.path(deepstate.path,"build_afl/libdeepstate_AFL.a")
  if(!file.exists(AFL.a)){
    #deepstate_make_afl()
  }
  exists_flag = 0
  functions.list  <-  RcppDeepState::deepstate_get_function_body(path)
  fun_names <- unique(functions.list$funName)
  for(f in fun_names){
    function.path <- file.path(test_path,f)
    afl.fun.path <- file.path(test_path,f,paste0("AFL_",f))
    afl.harness.path <- file.path(afl.fun.path,paste0(f,"_DeepState_TestHarness"))
    #unlink(afl.fun.path, recursive=TRUE)
    if(!dir.exists(afl.fun.path)){
      exists_flag = 1
      dir.create(afl.fun.path,showWarnings = FALSE)
    }
    harness.path <-  file.path(function.path,paste0(f,"_DeepState_TestHarness.cpp"))
    makefile.path <- file.path(function.path,"Makefile")
    if(file.exists(harness.path) && file.exists(makefile.path) ){
      executable <- gsub(".cpp$","",harness.path)
      object <- gsub(".cpp$",".o",harness.path)
      o.logfile <- file.path(afl.fun.path,paste0(f,"_log"))
      logfile <-  file.path(afl.fun.path,paste0("afl_",f,"_log"))
      output_dir <- file.path(afl.fun.path,paste0("afl_",f,"_output"))
      if(!dir.exists(output_dir)) {
        dir.create(output_dir,showWarnings = FALSE)
      }
      input_dir <- file.path(afl.fun.path,"afl_inputs")
      if(!dir.exists(input_dir)) {
        dir.create(input_dir,showWarnings = FALSE)
      }
      #writing harness file
      harness_lines <- readLines(harness.path,warn=FALSE)
      harness_lines <- gsub("#include <fstream>","#include <fstream>\n#include <ctime>",harness_lines,fixed=TRUE)
      harness_lines <- gsub("RInside R;","RInside R;\n  std::time_t t = std::time(0);",harness_lines,fixed=TRUE)
      k <- nc::capture_all_str(harness_lines,
                               "qs::c_qsave","\\(",
                               save=".*",",\"",l=".*","\"")
      for(i in seq_along(k$l)){
        harness_lines <- gsub(paste0("\"",k$l[i],"\""),paste0(gsub(".qs","",basename(k$l[i])),"_t"),harness_lines,fixed=TRUE)
        harness_lines <- gsub(paste0("qs::c_qsave(",gsub(".qs","",basename(k$l[i]))),paste0("std::string ",gsub(".qs","",basename(k$l[i])),"_t = ","\"",dirname(dirname(k$l[i])),
                                                                                            "/",basename(afl.fun.path),"/afl_inputs/\" + std::to_string(t) + \"_",basename(k$l[i]),"\"",";\n  qs::c_qsave(",gsub(".qs","",basename(k$l[i]))),harness_lines,fixed=TRUE)
      }
      print(afl.fun.path)
      ##makefileupdate
      harness.afl <- file.path(afl.fun.path,basename(harness.path))
      file.create(harness.afl,recursive=TRUE)
      cat(harness_lines, file=harness.afl, sep="\n")
      makefile_lines <- readLines(makefile.path,warn=FALSE)
      makefile_lines <- gsub(o.logfile,logfile,makefile_lines,fixed=TRUE)
      makefile_lines <- gsub(function.path,afl.fun.path,makefile_lines,fixed=TRUE)
      makefile_lines <- gsub(paste0("clang++ -g -o ",afl.fun.path,basename(executable)),paste0("clang++ -g -o ",afl.harness.path,".afl"),makefile_lines,fixed=TRUE)
      makefile_lines <- gsub("clang++","$(CXX)",makefile_lines,fixed=TRUE)
      makefile_lines <- gsub("-ldeepstate","-ldeepstate_AFL",makefile_lines,fixed=TRUE)
      makefile_lines <- gsub("deepstate-master/build","deepstate-master/build_afl",makefile_lines,fixed=TRUE)
      AFL_HOME = file.path(deepstate,"afl-2.52b")
      Sys.setenv(AFL_HOME=AFL_HOME)
      input_dir <- file.path(function.path,"inputs")
      makefile_lines <- gsub("R_HOME=",paste0("export AFL_HOME=",AFL_HOME,"\nCXX=${AFL_HOME}/afl-clang++\nAFL_FUZZ=${AFL_HOME}/afl-fuzz\nR_HOME="),makefile_lines,fixed=TRUE)
      makefile_lines <- gsub(".afl.cpp",".cpp",makefile_lines,fixed=TRUE)
      makefile.afl <- file.path(afl.fun.path,"Makefile")
      file.create(makefile.afl,recursive=TRUE)
      cat(makefile_lines, file=makefile.afl, sep="\n")
      compile_line <-paste0("cd ",afl.fun.path," && rm -f *.o && make")
      
      execution_line <- paste0("cd ",afl.fun.path," && ${AFL_HOME}/afl-fuzz -i ", input_dir," -o ",output_dir," -m 150 -t 2000+ -- ./",basename(executable),
                               " --input_test_file @@ --no_fork")
      print(compile_line)
      print(execution_line)
      if(exists_flag == 1){
        #system(compile_line)
        #system(execution_line)
      }
    }
  }
}
