deepstate_getRcpppackages <- function(){
  packages <- "/Users/akhilachowdarykolla/Desktop/packages"
    #file.path(system.file("extdata",package="RcppDeepState"),"packages")
  Rcpp.LinkingTo.pkgs <- devtools::revdep("Rcpp", "LinkingTo")
  dir.create(packages)
  download.packages(Rcpp.LinkingTo.pkgs, packages, type="source")
}

tot_avail_packages <- list()
fuzzed <- gsub(" ","",fuzzed)
fuzzed_no <- gsub(" ","",fuzzed_no)
fuzzed_yes <- gsub(" ","",fuzzed_yes)
print(fuzzed)
print(fuzzed_no)
print(fuzzed_yes)
tot_avail_packages <- gsub(" ","",c(fuzzed,fuzzed_no,fuzzed_yes))
length(tot_avail_packages) # 1748
#print(tot_avail_packages)
#print(head(Rcpp.LinkingTo.pkgs))
print(length(intersect(tot_avail_packages,basename(expackages))))
packages <- Sys.glob(file.path("/Users/akhilachowdarykolla/Desktop/packages","*"))
folder <- "/Users/akhilachowdarykolla/Desktop/expackages"
for(pkg.i in packages){
  untar(pkg.i,exdir=folder)
  unlink(pkg.i)
}

expackages <- Sys.glob(file.path("/Users/akhilachowdarykolla/Desktop/expackages","*"))
length(expackages)

NoRcppExports <- list()
NoRcppExports_Count <- 0
for(i in expackages){
  RcppExports.cpp <- file.path(i, "src/RcppExports.cpp")
   if(!file.exists(RcppExports.cpp)){
    NoRcppExports <- c(NoRcppExports,basename(i))
   }else{
     NoRcppExports_Count <- NoRcppExports_Count + 1
   }
}