
RcppDeepState_test <- function(package){
zip.path<- "~/fuzzer_packages/fuzzedpackages"
pkg.name <- sub("_.*", "", basename(package))
untar(package,exdir=zip.path)
unlink(package)
RcppExports.cpp <- file.path(zip.path,pkg.name, "src/RcppExports.cpp")
    if(file.exists(RcppExports.cpp)){
      print(file.path(zip.path,pkg.name))
      RcppDeepState::deepstate_harness_compile_run(file.path(zip.path,pkg.name))
      result = RcppDeepState::deepstate_harness_analyze_pkg(file.path(zip.path,pkg.name))
      print(result$logtable)
    }else{
  print("No Rcpp Exports")
}
}
future::plan("multiprocess", workers=11)
future.apply::future_lapply(pkg.name,FUN=RcppDeepState_test)

testpackages <- "/home/akhila/fuzzer_packages/fuzzedpackages"
testpackages.list <- Sys.glob(file.path(testpackages,"*"))
RcppDeepState_test <- function(package){
zip.path<- "/home/akhila/fuzzer_packages/fuzzedpackages"
pkg.name <- basename(package)
RcppExports.cpp <- file.path(zip.path,pkg.name,"src/RcppExports.cpp")
    if(file.exists(RcppExports.cpp)){
      print(file.path(zip.path,pkg.name))
      RcppDeepState::deepstate_harness_compile_run(file.path(zip.path,pkg.name))
      result = RcppDeepState::deepstate_harness_analyze_pkg(file.path(zip.path,pkg.name))
      print(result$logtable)
    }else{
  print("No Rcpp Exports")
}
}


future.apply::future_lapply(tgz.vec,RcppDeepStateTools::run_AFL())
packages <- file.path(system.file("extdata",package="RcppDeepState"),"packages")
  cA.dir <- file.path(system.file("extdata",package="RcppDeepState"),"compileAttributes")
  root.path <- system.file("extdata",package="RcppDeepState")
  zip.path <- cA.dir
  tgz.vec <- Sys.glob(paste0(packages,"/*.tar.gz"))
 pkg.name <- sub("_.*", "", basename(tgz.vec))
    for(pkg.i in seq_along(tgz.vec)){
    pkg.tar.gz <- tgz.vec[[pkg.i]]


    cat(sprintf("%4d - %s\n", pkg.i, pkg.tar.gz))
    if(!dir.exists(untestable_pkgs)){
      dir.create(untestable_pkgs)
    }
    pkg.name <- sub("_.*", "", basename(pkg.tar.gz))
    print(pkg.name)

future.apply::future_lapply(pkg.tar.gz,FUN=valgrind_afl_test)

packages <- "~/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/packages"
  tgz.vec <- Sys.glob(paste0(packages,"/*.tar.gz"))
 pkg.name <- sub("_.*", "", basename(tgz.vec))
    for(pkg.i in pkg.name){
    pkg.tar.gz <- pkg.i
install.packages(setdiff(basename(pkg.tar.gz), rownames(installed.packages())))
}

installs <- function(pkg.tar.gz){
install.packages(setdiff(basename(pkg.tar.gz), rownames(installed.packages())))
}

future.apply::future_lapply(pkg.name,FUN=installs)

future.apply::future_lapply(names_check,FUN=RcppDeepState_IssuePkg)

future.apply::future_lapply(tgz.vec,)

function(package){
zip.path<- file.path(system.file("extdata",package="RcppDeepState"),"compileAttributes")
pkg.name <- sub("_.*", "", basename(package))
untar(package,exdir=zip.path)
unlink(package)
RcppExports.cpp <- file.path(zip.path,pkg.name, "src/RcppExports.cpp")
    if(file.exists(RcppExports.cpp)){
      print(file.path(zip.path,pkg.name))
      RcppDeepState::deepstate_harness_compile_run(file.path(zip.path,pkg.name))
      result = RcppDeepState::deepstate_harness_analyze_pkg(file.path(zip.path,pkg.name))
      print(result$logtable)
    }else{
  print("No Rcpp Exports")
}
}


run_AFL<-function(){
  result.afl <- list()
  packages <- file.path(system.file("extdata",package="RcppDeepState"),"packages")
  cA.dir <- file.path(system.file("extdata",package="RcppDeepState"),"compileAttributes")

  root.path <- system.file("extdata",package="RcppDeepState")
  packages <- Sys.glob(file.path(cA.dir,"*"))
packages <- packages[-c(149,134,102,89,52,62,73)]


issues.dir <- file.path(system.file("extdata",package="RcppDeepState"),"issuestests")
  packages <- Sys.glob(file.path(issues.dir,"*"))
  for(pkg.i in seq_along(packages)){
    pkg.tar.gz <- packages[[pkg.i]]
  testfiles.vec <- Sys.glob(file.path(pkg.tar.gz,"inst/testfiles/*"))  
  cat(sprintf("%4d - %s\n", pkg.i, pkg.tar.gz))
  if(length(testfiles.vec) > 0){
    result.afl <- c(result.afl, pkg.tar.gz)
  }
  }
}
funs.list <- list()
for(pkg.i in result.afl){
   testfiles.vec <- Sys.glob(file.path(pkg.i,"inst/testfiles/*")) 
    for(fun.i in testfiles.vec){
      libfuzz.path <- file.path(fun.i,paste0("libFuzzer_",basename(fun.i)))
      exec.path <- file.path(libfuzz.path,paste0(basename(fun.i),"_DeepState_TestHarness"))
      inputs.path <- file.path(libfuzz.path,"libfuzzer_inputs")
      inputs.list <- Sys.glob(file.path(inputs.path,"*"))
      print(head(inputs.list))
      if(file.exists(exec.path) && length(inputs.list) > 0){  
      funs.list <- c(funs.list,fun.i)
       }
   }  

}

RcppDeepStateTools::

future::plan("multiprocess", workers=9)
future.apply::future_lapply(packages, FUN=valgrind_afl_test)

future::plan("multiprocess", workers=10)
future.apply::future_lapply(result.afl, FUN=deepstate_pkg_create_HonggFuzz)


future.apply::future_lapply(tgz.vec,FUN=RcppDeepState_test)
future::plan("multiprocess", workers=10)
future.apply::future_lapply(result.afl, FUN=RcppDeepStateTools::deepstate_pkg_create_AFL)
future::plan("multicore", workers=10)
future.apply::future_lapply(result.afl, FUN=deepstate_pkg_create_LibFuzzer)

sink("/home/akhila/finalvalgrind_log.txt",append=T)
future::plan("multiprocess", workers=10)
future.apply::future_lapply(exports.list,FUN=RcppDeepState_IssuePkg)
future.apply::future_lapply(pkg.tar.gz,FUN=valgrind_afl_test)
future.apply::future_lapply(names_check,FUN=RcppDeepState_IssuePkg)


future::plan("multiprocess", workers=3)
future.apply::future_lapply(pkg.tar.gz,FUN=RcppDeepState_IssuePkg)

deepstate_compile_generate_fun(package_name,function_name)


if (!require(basename(pkg.tar.gz),character.only = TRUE))
  {
    install.packages(pkg.tar.gz,dep=TRUE)
  }
pkg.tar.gz <- "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/compileAttributes/BNSL"
valgrind_afl_test(pkg.tar.gz)

datatable - xtable converts R datable to a html table 
rows and columns to er pages and they can be links to other webpages

RcppDeepState_IssuePkg <- function(pkg.tar.gz){
final.list <- list()
cA.dir <- file.path(system.file("extdata",package="RcppDeepState"),"testremains")
pkg.name <- sub("_.*", "", basename(pkg.tar.gz))
untar(pkg.tar.gz,exdir=cA.dir)
RcppExports.cpp <- file.path(cA.dir,pkg.name, "src/RcppExports.cpp")
    if(file.exists(RcppExports.cpp)){
      print(file.path(cA.dir,pkg.name))
      deepstate_harness_compile_run(file.path(cA.dir,pkg.name))
      result = RcppDeepState::deepstate_harness_analyze_pkg(file.path(cA.dir,pkg.name))
      #print(result$logtable)
      final.list <- c(final.list,result$logtable)  
    }else{
      file.copy(file.path(cA.dir,pkg.name),untestable_pkgs,overwrite = TRUE, 
                recursive = TRUE, 
                copy.mode = TRUE)
      unlink(file.path(cA.dir,pkg.name), recursive = TRUE)
      print("Package cannot be tested using RcppDeepState!!")
}    
print("final list")
print(final.list)
}

pkg.name <- sub("_.*", "", basename(pkg.i))

exports.packages <- c("abcADM","accelerometry","adeba","AGread","alphabetr","ambient","amt","anytime",
"aphid","aricode","autothresholdr","backbone","BalancedSampling","BAMBI","BoostMLR",
"bsearchtools","bsplinePsd","CARBayes","carSurv","castor",
"CatReg","ClinicalTrialSummary","cgAUC","clogitboost","clogitL1","CMF",
"credsetmat","corrcoverage","cort","dslice","CPAT",
"dng","energy","equateMultiple","exceedProb","eseis","ESGtoolkit","expperm",
"factorcpt","fastAdaboost","fbroc","FastGP","ffstream","finity","flying","forecastSNSTS","grainscape","graphlayouts","HDLSSkST","hetGP","hierarchicalSets",
"highfrequency","humaniformat","humanleague","humaniformat","iCellR",
"icensmis","icRSF","immer","imagerExtra","IntegratedMRF","ipft",
"kcpRS","kmer","LassoNet","lsbclust","lutz","metacart","metadynminer3d",
"meteoland","minimaxdesign","mixR","mlr3proba","mobsim","ModelMetrics",
"mosum","mousetrap","multicool","MPBoost","NAM","NHMM","nmixgof","oce","offlineChange",
"olctools","OwenQ","padr","PanelCount","PanelMatch","particles","parzer",
"PAutilities","pcIRT","Phase12Compare","phylobase","pinbasic",
"PLMIX","PP","PPRL","ProjectionBasedClustering","propr","Qtools",
"quantregRanger","QuantTools","rankdist","RcppDynProg","RGeode",
"rhoR","RMPSH","RJafroc","robFitConGraph","robmixglm","robustSingleCell",
"rrecsys","Rrelperm","rres","rbscCI","RTransferEntropy","Rvoterdistance",
"segmenTier","signalHsmm","signnet","simPop","simstudy","SpatialEpi",
"SpecsVerification","Speedloop","stocks","surveysd","tagcloud",
"timma","tidyxl","TransPhylo","Umatrix","windfarmGA","wk","wkutils")
   
exports.packages <-c("accelerometry","BNSL","factorcpt","humaniformat",
"IntegratedMRF","jmotif","olctools","QuantTools",
"PAutilities","RcppDynProg","rhoR","TransPhylo")

exports.packages <- c("PAutilities","adeba","alphabetr","BalancedSampling","bsearchtools","castor","ClinicalTrialSummary",
"cgAUC","credsetmat","corrcoverage","dslice","ESGtoolkit","FastGP","finity","graphlayouts","kcpRS",
"kmer","meteoland","minimaxdesign","multicool","mousetrap","OwenQ","PanelMatch","parzer","Phase12Compare","Rvoterdistance","RJafroc","Speedloop","tidyxl") 

sofar_tests <- "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests"
packages.path <- "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/packages"
tar.gz.path <- Sys.glob(file.path(packages.path,"*"))
length(tar.gz.path)
exports.list <- list()
for(pkg.i in tar.gz.path){
if(sub("_.*", "", basename(pkg.i)) %in% exports.packages){
 exports.list <- c(exports.list,pkg.i)

}
}
print(exports.list)
sofar_tests <- "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests"
sofar.path <- Sys.glob(file.path(sofar_tests,"*"))
names_check <- list()
no_check <- list()
for(pkg.i in exports.list){
 if(paste0(sofar_tests,"/",sub("_.*", "", basename(pkg.i))) %in% sofar.path){
 no_check <- c(no_check,pkg.i)
 }
 else{names_check <- c(names_check,pkg.i)}
}




exports.packages <- c("abcADM","accelerometry","adeba","AGread","alphabetr","ambient","amt","anytime",
"aphid","aricode","autothresholdr","backbone","BalancedSampling","BAMBI","BoostMLR",
"bsearchtools","bsplinePsd","CARBayes","carSurv","castor",
"CatReg","ClinicalTrialSummary","cgAUC","clogitboost","clogitL1","CMF",
"credsetmat","corrcoverage","cort","dslice","CPAT",
"dng","energy","equateMultiple","exceedProb","eseis","ESGtoolkit","expperm",
"factorcpt","fastAdaboost","fbroc","FastGP","ffstream","finity","flying","forecastSNSTS","grainscape","graphlayouts","HDLSSkST","hetGP","hierarchicalSets",
"highfrequency","humaniformat","humanleague","humaniformat","iCellR",
"icensmis","icRSF","immer","imagerExtra","IntegratedMRF","ipft",
"kcpRS","kmer","LassoNet","lsbclust","lutz","metacart","metadynminer3d",
"meteoland","minimaxdesign","mixR","mlr3proba","mobsim","ModelMetrics",
"mosum","mousetrap","multicool","MPBoost","NAM","NHMM","nmixgof","oce","offlineChange",
"olctools","OwenQ","padr","PanelCount","PanelMatch","particles","parzer",
"PAutilities","pcIRT","Phase12Compare","phylobase","pinbasic",
"PLMIX","PP","PPRL","ProjectionBasedClustering","propr","Qtools",
"quantregRanger","QuantTools","rankdist","RcppDynProg","RGeode",
"rhoR","RMPSH","RJafroc","robFitConGraph","robmixglm","robustSingleCell",
"rrecsys","Rrelperm","rres","rbscCI","RTransferEntropy","Rvoterdistance",
"segmenTier","signalHsmm","signnet","simPop","simstudy","SpatialEpi",
"SpecsVerification","Speedloop","stocks","surveysd","tagcloud",
"timma","tidyxl","TransPhylo","Umatrix","windfarmGA","wk","wkutils")
   

length(pkg.name)
[1] 2170
intersect(pkg.name,exports.packages)
 [1] "BNSL"          "IntegratedMRF" "PAutilities"   "QuantTools"   
 [5] "RcppDynProg"   "TransPhylo"    "accelerometry" "factorcpt"    
 [9] "humaniformat"  "jmotif"        "olctools"      "rhoR"    


/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/umat/umat_DeepState_TestHarness.cpp:19:5: error: 
      reference to 'umat' is ambiguous
    umat(pi_inv);
    ^
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/umat/umat_DeepState_TestHarness.cpp:8:15: note: 
      candidate found by name lookup is 'umat'
NumericMatrix umat(NumericMatrix pi_inv);
              ^
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppArmadillo/include/armadillo_bits/typedef_mat.hpp:51:21: note: candidate found by name
      lookup is 'arma::umat'
typedef Mat <uword> umat;
                    ^
1 error generated.
make: *** [Makefile:8: /home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/umat/umat_DeepState_TestHarness.o] Error 1
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/dmat_DeepState_TestHarness.cpp:42:5: error: 
      reference to 'dmat' is ambiguous
    dmat(id,time,result,phi1[0],phi0[0],negpred[0]);
    ^
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/dmat_DeepState_TestHarness.cpp:8:15: note: 
      candidate found by name lookup is 'dmat'
NumericMatrix dmat(NumericVector id, NumericVector time, IntegerVector result, double phi1, double phi0, double negpred);
              ^
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppArmadillo/include/armadillo_bits/typedef_mat.hpp:69:22: note: candidate found by name
      lookup is 'arma::dmat'
typedef Mat <double> dmat;
                     ^
1 error generated.


c("Applied Computer Science","Computer Engineering",
"Computer Science","Cybersecurity","Electrical Engineering","Electrical Engineering Technology","Informatics")


major.lis <- paste(
  sprintf('<li><a href="%s.html">%s</a></li><li><a href="%s.html">%s</a></li>',paste0("Packages with issue in Exported functions\n<\br>",gsub(" ", "_", names(export.list))),
    names(export.list),paste0("Packages with issue in unexported functions\n<\br>",gsub(" ", "_", names(unexport.list))),names(unexport.list)),collapse="\n")


MDM - 

intune - 

for(pair.i in 1:nrow(pairs.dt)){
  print(pair.i)
  pair.row <- pairs.dt[pair.i]
  print(pair.row)
  pair.unsort <- pair.row[, names(degree.list)[c(i, j)] ]
  print(pair.unsort)
  pair.name <- make.pair(pair.unsort)
  print(pair.name)
}





major.lis <- paste(sprintf('<li><a href="%s.html">%s</a></li><li><a href="%s.html">%s</a></li>',
          gsub(" ", "_", names(export.list)),
          paste0("Packages with issue in Exported functions\n<\br>", names(export.list)),
          gsub(" ", "_", names(unexport.list)),paste0("Packages with issue in unexported functions\n<\br>",
                                                      names(unexport.list))),collapse="\n")


major.lis <- paste(
  sprintf(
    '<li><a href="%s.html">%s</a></li>',
    gsub(" ", "_", names(degree.list)),
    names(degree.list)),
  collapse="\n")

issues.table <- function(logtable.list){
logtable.list <- do.call(rbind, logtable.list)
logtable.list.unique <-unique(logtable.list, incomparables = FALSE)
}


${HONGGFUZZ_HOME}/honggfuzz -t 2000 -i /home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/testpkgs/testSAN/inst/testfiles/rcpp_read_out_of_bound/inputs -o /home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/testpkgs/testSAN/inst/testfiles/rcpp_read_out_of_bound/hongg_rcpp_read_out_of_bound_output -- /home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/testpkgs/testSAN/inst/testfiles/rcpp_read_out_of_bound/rcpp_read_out_of_bound_DeepState_TestHarness.hongg ___FILE___





for(ex in exports.list){
RcppDeepState_IssuePkg(ex)
}


/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/testremains/BalancedSampling/inst/testfiles/cube/cube_DeepState_TestHarness.cpp:26:5: error: 
      reference to 'cube' is ambiguous
    cube(prob,Xbal);
    ^
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/testremains/BalancedSampling/inst/testfiles/cube/cube_DeepState_TestHarness.cpp:11:15: note: 
      candidate found by name lookup is 'cube'
IntegerVector cube(NumericVector prob, NumericMatrix Xbal);
              ^
/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppArmadillo/include/armadillo_bits/typedef_mat.hpp:79:22: note: candidate found by name
      lookup is 'arma::cube'
typedef Cube<double> cube;
                     ^
list.package.fun.issues <- function(packages){final.package.list <- list()
for(pkg.i in packages){
  package.path <- file.path(path,basename(pkg.i))
  package.funs.list <- list()
  sprintf("Package name - %s\n",basename(pkg.i))
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  for(fun.i in testfuns){
   test_list <- list()
    fun_name <- basename(fun.i)
    fun_output <- file.path(fun.i,paste0(fun_name,"_output"))
    sprintf("fun_name - %s\n\n",fun_name)
    log.files <- log.files.extract(Sys.glob(file.path(fun_output,"*")))
    flag = 0
    log.path = ""
    for(log.i in log.files){
      valgrind_log <- file.path(log.i,"valgrind_log")
      data.result <- RcppDeepState::deepstate_read_valgrind_xml(valgrind_log)
      if(!is.null(data.result) && nrow(data.result) > 0){
        flag = 1
        log.path = log.i
        result = data.result;
      }
    }
    if(flag == 1){
      log.path.list <- Sys.glob(file.path(log.path,"*")) 
      valgrind.list <- c(file.path(log.path,"valgrind_log_text"),file.path(log.path,"valgrind_log"))  
fun.test.file <- file.path(log.i,paste0(fun_name,"-test.R"))
system(paste0("R -d valgrind --vanilla < ",fun.test.file))      
  




  

accelerometry
BNSL
factorcpt
humaniformat
IntegratedMRF
jmotif
olctools
QuantTools
rhoR
TransPhylo

exports <- file.path()

fuzzers <- "/home/akhila/fuzzer_packages/fuzzedpackages"
#for(pkg.tar.gz in exports.list){
testd <-function(pkg.tar.gz){
untar(pkg.tar.gz,exdir=fuzzers)
pkg.name <- sub("_.*", "", basename(pkg.tar.gz))
print(pkg.name)
install.packages(setdiff(basename(pkg.name), rownames(installed.packages())))
}
future.apply::future_lapply(exports.list, FUN=testd)
  
