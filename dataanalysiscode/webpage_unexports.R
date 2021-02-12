d <- data.frame(tail=c(12,11,32,0),
                legs=c(4,4,4,2),
                height=c(31,35,62,68))

export.list <- list()
unexport.list <- list()

PAutilities
adeba - 404
alphabetr
BalancedSampling
bsearchtools
castor
ClinicalTrialSummary
cgAUC
credsetmat 404
corrcoverage 
dslice 404
ESGtoolkit 404
FastGP
finity
graphlayouts - 404
kcpRS
kmer
meteoland
minimaxdesign - 404
multicool
mousetrap - no inputs
OwenQ
PanelMatch - 404
parzer
Phase12Compare
Rvoterdistance
RJafroc
Speedloop - 404
tidyxl
          


export.list <- c("accelerometry","BNSL","factorcpt","humaniformat",
                 "IntegratedMRF","jmotif","olctools","QuantTools","RcppDynProg","rhoR","TransPhylo")

names(export.list) <- c("accelerometry","BNSL","factorcpt","humaniformat",
                        "IntegratedMRF","jmotif","olctools","QuantTools",
                        "RcppDynProg","rhoR","TransPhylo")

unexport.list <- c("abcADM","accelerometry","AGread","ambient","amt","anytime",
                   "aphid","aricode","autothresholdr","backbone","BAMBI","BoostMLR",
                   "bsplinePsd","CARBayes","carSurv","castor",
                   "CatReg","clogitboost","clogitL1","CMF",
                   "cort","CPAT","dng","energy","equateMultiple","exceedProb","eseis","expperm",
         "factorcpt","fastAdaboost","fbroc","ffstream","flying","forecastSNSTS","grainscape"
                      ,"HDLSSkST","hetGP","hierarchicalSets",
                   "highfrequency","humaniformat","humanleague","humaniformat","iCellR",
                   "icensmis","icRSF","immer","imagerExtra","IntegratedMRF","ipft",
                   "LassoNet","lsbclust","lutz","metacart","metadynminer3d",
                   "mixR","mlr3proba","mobsim","ModelMetrics",
                   "mosum","mousetrap","MPBoost","NAM","NHMM","nmixgof","oce","offlineChange",
                   "olctools","padr","PanelCount","particles",
                   "PAutilities","pcIRT","Phase12Compare","phylobase","pinbasic",
                   "PLMIX","PP","PPRL","ProjectionBasedClustering","propr","Qtools",
                   "quantregRanger","QuantTools","rankdist","RcppDynProg","RGeode",
                   "rhoR","RMPSH","RJafroc","robFitConGraph","robmixglm","robustSingleCell",
                   "rrecsys","Rrelperm","rres","rbscCI","RTransferEntropy","Rvoterdistance",
                   "segmenTier","signalHsmm","signnet","simPop","simstudy","SpatialEpi",
                   "SpecsVerification","Speedloop","stocks","surveysd","tagcloud",
                   "timma","tidyxl","TransPhylo","Umatrix","windfarmGA","wk","wkutils")

names(unexport.list) <-c("abcADM","accelerometry","AGread","ambient","amt","anytime",
                   "aphid","aricode","autothresholdr","backbone","BAMBI","BoostMLR",
                   "bsplinePsd","CARBayes","carSurv","castor",
                   "CatReg","clogitboost","clogitL1","CMF",
                   "cort","CPAT","dng","energy","equateMultiple","exceedProb","eseis","expperm",
         "factorcpt","fastAdaboost","fbroc","ffstream","flying","forecastSNSTS","grainscape"
                      ,"HDLSSkST","hetGP","hierarchicalSets",
                   "highfrequency","humaniformat","humanleague","humaniformat","iCellR",
                   "icensmis","icRSF","immer","imagerExtra","IntegratedMRF","ipft",
                   "LassoNet","lsbclust","lutz","metacart","metadynminer3d",
                   "mixR","mlr3proba","mobsim","ModelMetrics",
                   "mosum","mousetrap","MPBoost","NAM","NHMM","nmixgof","oce","offlineChange",
                   "olctools","padr","PanelCount","particles",
                   "PAutilities","pcIRT","Phase12Compare","phylobase","pinbasic",
                   "PLMIX","PP","PPRL","ProjectionBasedClustering","propr","Qtools",
                   "quantregRanger","QuantTools","rankdist","RcppDynProg","RGeode",
                   "rhoR","RMPSH","RJafroc","robFitConGraph","robmixglm","robustSingleCell",
                   "rrecsys","Rrelperm","rres","rbscCI","RTransferEntropy","Rvoterdistance",
                   "segmenTier","signalHsmm","signnet","simPop","simstudy","SpatialEpi",
                   "SpecsVerification","Speedloop","stocks","surveysd","tagcloud",
                   "timma","tidyxl","TransPhylo","Umatrix","windfarmGA","wk","wkutils")
#export.lis <- paste(sprintf('<li><a href="%s.html">%s</a></li>',gsub(" ", "_", names(export.list)),names(export.list)),collapse="\n")
export.lis <- paste(sprintf('<li><a href="%s.html">%s</a></li>',paste0(gsub(" ", "_", names(export.list)),"_exports"),names(export.list)),collapse="\n")

unexport.lis <- paste(sprintf('<li><a href="%s.html">%s</a></li>',gsub(" ", "_", names(unexport.list)),names(unexport.list)),collapse="\n")
    
index.template <- readLines("figure-common-index-template.html")

index <- sprintf(paste(index.template, collapse="\n"), paste("<br/>Packages with Issues in exported functions<br/>",export.lis,
"<br/>Packages with Issues in unexported functions<br/><br/>",unexport.lis))
cat(index, file=file.path("figure-common", "index.html"))

index <- sprintf(paste(index.template, collapse="\n"), unexport.lis)

major.lis <- paste(
  sprintf('%s<li><a href="%s.html">%s</a></li>',
"Packages with issue in Exported functions\n<\br>",gsub(" ", "_", names(export.list)),
    names(export.list),"Packages with issue in unexported functions\n<\br>",gsub(" ", "_", names(unexport.list)),names(unexport.list)),collapse="\n")



major.lis <- paste(
  sprintf(
    '<li><a href="%s.html">%s</a></li>',
    gsub(" ", "_", names(export.lis)),
    names(export.lis)),
  collapse="\n")



# list of packages with no testfiles
path <- "~/RcppDeepStateTest/issuestests"

#path <- "~/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests"
packages <- Sys.glob(file.path(path,"*"))
list.package.fun.issues(packages)
notestfiles <- list()
for(pkg.i in packages){
  testpath <- file.path(pkg.i,"inst/testfiles")
  testfuns <- Sys.glob(file.path(testpath,"*"))
  if(length(testfuns) <= 0){
    notestfiles <- c(notestfiles,basename(pkg.i))
  }
}
binary.files.extract <- function(bin.files){
  binary.files <- if(length(grep("log_",bin.files,value=TRUE)) > 0){
    log.files <- grep("log_",bin.files,value=TRUE)
    sort(c(log.files[!log.files%in%bin.files],bin.files[!bin.files%in%log.files]))
  }  
}
log.files.extract <- function(bin.files){
  log.files <- list()
  for(log.i in bin.files){
    log.files <- if(length(grep("log_",basename(log.i))) > 0){
    c(log.files,log.i)
  }  
  }
  return(log.files)
}

PackageURL <- function(pkg){
  ahref(pkg, paste0("https://github.com/akhikolla/RcppDeepStateTest/tree/master/issuestests/", pkg))
}
ahref <- function(content, u){
  sprintf('<a href="%s">%s</a>', u, content)
}
getNamespaceExports_fun <- function(pkg.i){
namespace.list <- list()
funnamespace = readLines(file.path(pkg.i,"NAMESPACE"),warn = FALSE)
namespace.list <- nc::capture_all_str(funnamespace,
                                      status=".*",
                                      "\\(",
                                      fun=".*",
                                      "\\)")
export_list <- namespace.list[status == "export", fun]
return(export_list)
}


outersect <- function(x, y) {
  sort(c(x[!x%in%y],
         y[!y%in%x]))
}

exported functions:
----------------------------------------------------------------
list.package.exported.fun.issues <- function(packages){
  final.package.list <- list()
  package.funs.list <- list()
  major.template <- readLines("figure-common-major-template.html")
   url <- "https://github.com/akhikolla/RcppDeepStateTest/tree/master/issuestests"
for(pkg.i in packages){
  #path <- system.file("issuestests", package = "RcppDeepStateTests")
  package.path <- file.path(path,basename(pkg.i))
  package.funs.list <- list()
  sprintf("Package name - %s\n",basename(pkg.i))
  testpath <- file.path(pkg.i,"inst/testfiles")
  #testfuns <- paste0(testpath,"/",getNamespaceExports_fun(pkg.i))
  testfuns <- Sys.glob(file.path(testpath,"*"))
  for(fun.i in testfuns){
    fun_name <- basename(fun.i)
    fun_output <- file.path(fun.i,paste0(fun_name,"_output"))
    sprintf("fun_name - %s\n\n",fun_name)
    log.files <- log.files.extract(Sys.glob(file.path(fun_output,"*")))
    flag = 0
    log.path = ""
    for(log.i in log.files){
      valgrind_log <- file.path(log.i,"valgrind_log")
      data.result <- deepstate_read_valgrind_xml(valgrind_log)
      if(!is.null(data.result) && nrow(data.result) > 0){
        flag = 1
        log.path = log.i
        result = data.result;
      }
    }
if(fun_name %in% getNamespaceExports_fun(pkg.i)){symbol <-"::"}else{symbol <-":::"} 
   if(flag == 1){
      inputs <- grep("*.qs",Sys.glob(file.path(log.path,"*")),value=TRUE)
      inputs.list<- list()
      for(input.i in inputs){
        inputs.list[[gsub("*.qs","",basename(input.i))]] <- paste0(url,"/",basename(pkg.i),"/inst/testfiles/",
                                                                   fun_name,"/",fun_name,"_output/",basename(log.i),"/",basename(input.i))
      }     
major.lis <- paste(
        sprintf(
          '<a href="%s">%s</a>',
          gsub(" ", "_", inputs.list),
          names(inputs.list)),
        collapse="\n")
      
valgrind.file <- paste0(url,"/",basename(pkg.i),"/inst/testfiles/",                                                        fun_name,"/",fun_name,"_output","/",basename(log.i),"/valgrind_log")

 valgrind.lis <- paste(
        sprintf(
          '<a href="%s">%s</a>',
          valgrind.file,
          "valgrind_log"),
        collapse="\n")
      #print(major.lis)

      package.funs.list[[paste0(basename(pkg.i),"-",fun_name)]] <- data.table(name=paste0(basename(pkg.i),symbol,fun_name), 
                                                  inputs=major.lis,
                                                  message = result$message[1],
                                                  file.line =result$file.line[1],
                                                  valgrind_log=valgrind.lis)
      }else{
      package.funs.list[[fun_name]] <-data.table(name=paste0(basename(pkg.i),symbol,fun_name),inputs=character(), message=character(), file.line=character(),valgrind_log=character())
    }
  }
  package.funs <- do.call(rbind, package.funs.list)
  xt <- xtable::xtable(package.funs)
  old.align <- xtable::align(xt)
  xtable::align(xt) <- rep("r", length(old.align))
  major.html <- print(
    xt,
    include.rownames=FALSE,
    type="html",
    sanitize.text.function=identity,
    file="/dev/null")
  major.under <- gsub(" ", "_", basename(pkg.i))
  major.under.html <- paste0(major.under, "_exports.html")
  major.template.filled <- gsub("PACKAGE", PackageURL(basename(pkg.i)), major.template)
  cat(major.template.filled,
      gsub("<td", '<td valign="top"', major.html), 
      file=file.path("package-html-folders", major.under.html))
}
  
}












unexported functions:
------------------------------------------------------------------
list.package.fun.issues <- function(packages){
  final.package.list <- list()
  package.funs.list <- list()
  test_list <- list()
  major.template <- readLines("figure-common-major-template.html")
   url <- "https://github.com/akhikolla/RcppDeepStateTest/tree/master/issuestests"
   rawurl <- "https://raw.githubusercontent.com/akhikolla/RcppDeepStateTest/master/issuestests"
for(pkg.i in packages){
  #path <- system.file("issuestests", package = "RcppDeepStateTests")
  package.path <- pkg.i #file.path(path,basename(pkg.i))
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
      #outersect(log.path.list,valgrind.list)     
      #inputs <- grep("*.qs",Sys.glob(file.path(log.path,"*")),value=TRUE)
      
      inputs <- outersect(log.path.list,valgrind.list)
       inputs <- outersect(inputs,grep("-test.R",inputs,value=TRUE))
       deepstate_test_list <- vector(mode = "list", length=length(inputs))
      #names(test_list) <- gsub("*.qs","",basename(inputs))
      for(inps in inputs){
        var <-if(length(grep(".qs",inps,value=TRUE)) > 0){
	qread(inps)
        }else{
         scan(inps,quiet=TRUE)
        }
        test_list[[gsub("*.qs","",basename(inps))]] <- var
      }
        fun.test.file <- file.path(log.i,paste0(fun_name,"-test.R"))
        if(file.exists(fun.test.file))
       {
          file.remove(fun.test.file)
       }
        file.create(fun.test.file)
        dput(test_list,fun.test.file)
        d_lines <- readLines(fun.test.file,warn=FALSE)
        d_lines <- gsub("list","testlist <- list",d_lines,fixed=TRUE)
        file.create(fun.test.file)
        cat(d_lines,file=fun.test.file,append=TRUE) 
      inputs.list<- list()
      for(input.i in inputs){
        inputs.list[[gsub("*.qs","",basename(input.i))]] <- paste0(url,"/",basename(pkg.i),"/inst/testfiles/",
                                                                   fun_name,"/",fun_name,"_output/",basename(log.i),"/",basename(input.i))
      }

 if(fun_name %in% getNamespaceExports_fun(pkg.i)){symbol <-"::"}else{symbol <-":::"}
      major.lis <- paste(
        sprintf(
          '<a href="%s">%s</a>',
          gsub(" ", "_", inputs.list),
          names(inputs.list)),
        collapse="\n")
      
valgrind.file <- paste0(url,"/",basename(pkg.i),"/inst/testfiles/",                                                        fun_name,"/",fun_name,"_output","/",basename(log.i),"/valgrind_log")
print(valgrind.file)

fun.test.url.file <- paste0(rawurl,"/",basename(pkg.i),"/inst/testfiles/",                                                        fun_name,"/",fun_name,"_output","/",basename(log.i),"/",fun_name,"-test.R")

print(fun.test.url.file)
 valgrind.lis <- paste(
        sprintf(
          '<a href="%s">%s</a>',
          valgrind.file,
          "valgrind_log"),
        collapse="\n")
      #print(major.lis)

exec.lis <- paste( sprintf(
          '<a href="%s">%s</a>',
          fun.test.url.file,
          "executable-test-file"),
        collapse="\n")
print(exec.lis)

 cat(paste0("\nresult <- do.call(",basename(pkg.i),symbol,fun_name,",testlist)\nstr(result)"),file=fun.test.file,append=TRUE)      
package.funs.list[[paste0(basename(pkg.i),"-",fun_name)]] <- data.table(name=paste0(basename(pkg.i),symbol,fun_name), 
                                                  inputs=major.lis,
                                                  message = result$message[1],
                                                  file.line =result$file.line[1],
                                                  valgrind_log=valgrind.lis,
                                                  executable.file=exec.lis)
      
      }else{
        if(fun_name %in% getNamespaceExports_fun(pkg.i)){symbol <-"::"}else{symbol <-":::"}
      package.funs.list[[fun_name]] <-data.table(name=paste0(basename(pkg.i),symbol,fun_name),inputs=character(), message=character(), file.line=character(),valgrind_log=character(),executable.file=character())
    }
  }
  #print("before")
  print(package.funs.list)
  package.funs <- do.call(rbind, package.funs.list)
  xt <- xtable::xtable(package.funs)
  old.align <- xtable::align(xt)
  xtable::align(xt) <- rep("r", length(old.align))
  major.html <- print(
    xt,
    include.rownames=FALSE,
    type="html",
    sanitize.text.function=identity,
    file="/dev/null")
  major.under <- gsub(" ", "_", basename(pkg.i))
  major.under.html <- paste0(major.under, ".html")
  major.template.filled <- gsub("PACKAGE", PackageURL(basename(pkg.i)), major.template)
  cat(major.template.filled,
      gsub("<td", '<td valign="top"', major.html), 
      file=file.path("packages-folders", major.under.html))
  #line.num.dt<-unique(line.num.dt, incomparables = FALSE)
  #print("after")
  #print(package.funs.list)
}
  #final.package.list[[pkg.i]] <- package.funs.list
   #print("final package list")
   #print(final.package.list)
  
}
list.package.fun.issues(es)
future.apply::future_lapply(es, FUN=valgrind_checks)

-----------------------------------------------------------------------
future.apply::future_lapply(exports.packages, FUN=valgrind_checks)
  valgrind_checks <- function(pkg.i){
   path <- "~/fuzzer_packages/fuzzedpackages"
  #for(pkg.i in packages){
    package.path <- file.path(path,basename(pkg.i))
    testpath <- file.path(pkg.i,"inst/testfiles")
    testfuns <- Sys.glob(file.path(testpath,"*"))
    for(fun.i in testfuns){
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
      }
    } 
  }
}      
    
    
   
