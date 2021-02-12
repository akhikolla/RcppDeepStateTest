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
          name="[^(]+")
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

RcppExports.cpp.vec <- Sys.glob(file.path(
  "compileAttributes", "*", "src", "RcppExports.cpp"))
pkg.dir.vec <- dirname(dirname(RcppExports.cpp.vec))

arg.dt.list <- list()
lines.dt.list <- list()
ns.dt.list <- list()
includes.dt.list <- list()
for(pkg.dir in pkg.dir.vec){
  pkg <- basename(pkg.dir)
  result.list <- parseRcppExports(pkg.dir)
  lines.dt.list[[pkg.dir]] <- data.table::data.table(
    pkg, result.list$lines)
  includes.dt.list[[pkg.dir]] <- data.table::data.table(
    pkg, include=result.list$includes)
  if(nrow(result.list$arguments)){
    arg.dt.list[[pkg.dir]] <- data.table::data.table(
      pkg, result.list$arguments)
    ns.dt.list[[pkg.dir]] <- data.table::data.table(
      pkg, result.list$namespaces)
  }
}
lines.dt <- do.call(rbind, lines.dt.list)
arg.dt <- do.call(rbind, arg.dt.list)

## Our regex extracts all arguments and functions for the vast
## majority of RcppExports.cpp files:
lines.dt[parsed==parameters]

## The RcppExports.cpp files in these packages were not parsed
## completely (should be empty because we are calling
## compileAttributes to get a standard format file).
lines.dt[parsed<parameters]

## These packages do not use Rcpp attributes, so there is no
## information about the input parameters in the RcppExports.cpp file.
lines.dt[parameters==0]

arg.dt[, clean.type := cleanType(inside)]






print(names(table(arg.dt$clean.type)))
print(names(table(ns.dt$namespace)))
arg.dt[clean.type=="longint"]
arg.dt[grepl(" ", funName)]








## which ones used the recursive regex?
arg.dt[, n.inside := nchar(gsub("[^<]", "", inside))]
arg.dt[0<n.inside][order(n.inside)]
arg.dt[2==n.inside, unique(clean.type)]
arg.dt[grepl("Nullable", clean.type)][order(n.inside)]
## which packages have a range of different numbers of nesting?
## geojsonR is the most extreme (5 different numbers, from 0 to 4).
nested.templates <- arg.dt[, .(
  min=min(n.inside),
  max=max(n.inside),
  count=length(table(n.inside))
), by=pkg][min!=max][order(count)]
## which arguments have multi-parameter templates? rmdcev is the most
## extreme package (69 arguments with multi-parameter templates).
multi.param.templates <- arg.dt[
  grepl(",", clean.type)][nested.templates, on="pkg", nomatch=0L]
multi.param.templates[, .(args=.N), by=pkg]

arg.counts <- arg.dt[, .(
  args=.N
), by=.(pkg, funName)][arg.dt, on=.(pkg, funName)]
(top10 <- arg.counts[args==1, .(
  funs=.N,
  pkgs=length(unique(pkg))
), by=clean.type][order(-funs)][1:11])

(covered <- arg.counts[top10$clean.type, on="clean.type"][, .(
  top10args=.N
), by=.(pkg, funName, args)][args==top10args][order(-args)])
##covered[funName=="repel_boxes"] 
covered[, .(
  funs=.N,
  pkgs=length(unique(pkg))
)]

(some.types <- grep(
  "SEXP|List|Rcpp::XPtr<XPtrTorchTensor>", top10$clean.type, invert=TRUE, value=TRUE))
some.covered <- arg.counts[some.types, on="clean.type"][, .(
  top10args=.N
), by=.(pkg, funName, args)][args==top10args][order(-args)]
some.covered[, .(
  funs=.N,
  pkgs=length(unique(pkg))
)]