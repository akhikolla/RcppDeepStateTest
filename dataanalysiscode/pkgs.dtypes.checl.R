deepstate_datatype_check <- function(params.list){
  params.list <- gsub("const","",params.list)
  params.list <-gsub("Rcpp::","",params.list)
  params.list <-gsub(" ","",params.list)
  datatypes <- list("NumericVector","NumericMatrix" ,"arma::mat","double",
                    "std::string","CharacterVector","int","IntegerVector")
  for(pkg.i in seq_along(params.list)){
    #print(params.list[[pkg.i]])
    if(is.element(params.list[[pkg.i]], datatypes) =="FALSE"){
      return(0);
    }
    
  }
  return(1);
}

datatypes <- list()
d.list <- c("NumericVector","NumericMatrix" ,"arma::mat","double",
            "std::string","CharacterVector","int","IntegerVector")

for(i in d.list){
  datatypes[[i]] <- 0
}

pkgs.list <- list()
fun.count <- 0
pkgs.unique <- unique(arg.dt$pkg)
for(pkg.i in pkgs.unique){
  pkgs.rows  <- arg.dt [arg.dt$pkg == pkg.i,]
  funs.names <- unique(pkgs.rows$funName)
  for(fun.i in funs.names){
    function.rows <- pkgs.rows[pkgs.rows$funName == fun.i]
    params <- c(function.rows$clean.type)
   #if(length(grep("std::string",params)) > 1){
  #  print(params)
   # }
    if(deepstate_datatype_check(params) == 1){
      fun.count <- fun.count + 1
      params <- gsub("const","",params)
      params <-gsub("Rcpp::","",params)
      params <-gsub(" ","",params)
      #print(params)
     # for(p in params){
      #  datatypes[[p]] <- datatypes[[p]] + 1
      #}
      pkgs.list <- c(pkgs.list,pkg.i)
      
    }
  }  
  
}

outersect <- function(x, y) {
  sort(c(x[!x%in%y],
         y[!y%in%x]))
}


final.list <- unique(pkgs.list)
length(final.list)
res <- do.call(rbind,final.list)
res.lst <- res[,1]
length(res.lst)
fuzzed_yes <- unique(fuzzed_yes)
fuzzed <- unique(fuzzed)
length(fuzzed_yes)
length(fuzzed)
new.lst <- c(fuzzed_yes,fuzzed)   #752
res_issued <- intersect(new.lst,res.lst) 
print(res_issued)
length(res_issued) #744
#1185-752 = 433
y <- (outersect(new.lst,res.lst)) #449

message(sprintf("%s\n",paste(y, collapse=", ")))


message(sprintf("%s\n",paste(noexists.pkgs, collapse=", ")))

for(i in noexists.pkgs){
  print(i)
  system(paste0("mv ","/Users/akhilachowdarykolla/Desktop/compileAttributes/",i," /Users/akhilachowdarykolla/Desktop/NoRcppExports"))
}

