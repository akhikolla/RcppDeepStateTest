library(bsearchtools,quietly=TRUE)

####################################################################################
#                               HELPER FUNCTIONS                                   #
####################################################################################
assert <- function(msg,condition){
  if(!all(condition == TRUE)){
      msg <- paste(msg,": failed!",sep=" ")
      stop(msg)
  }
}
doesFail <- function(expr){
  return(try({expr;TRUE},silent=TRUE) != TRUE)
}
capitalizeFirstLetter <- function(s){
  paste(toupper(substring(s, 1,1)), substring(s, 2),sep="")
}
linearlb <- function(sorted,valueToSearch){
  if(is.na(valueToSearch))
    return(1L)
  valueToSearch <- as(valueToSearch,class(sorted))
  if(length(sorted) == 0 || valueToSearch > max(sorted))
    return(length(sorted)+1L)
  if(valueToSearch < min(sorted))
    return(1L)
  bools <- sorted >= valueToSearch  
  return(which(bools)[1])
}
linearub <- function(sorted,valueToSearch){
  if(is.na(valueToSearch))
    return(length(sorted)+1L)
  valueToSearch <- as(valueToSearch,class(sorted))
  if(length(sorted) == 0 || valueToSearch >= max(sorted))
    return(length(sorted)+1L)
  bools <- sorted > valueToSearch  
  return(which(bools)[1L])
}
linearindexesEqualTo <- function(sorted,valueToSearch,indexesRemap=NULL){
  if(!is.null(indexesRemap))
    return(indexesRemap[linearindexesEqualTo(sorted,valueToSearch,NULL)])
  if(is.na(valueToSearch))
    return(1:length(sorted))
  valueToSearch <- as(valueToSearch,class(sorted))
  return(which(sorted==valueToSearch))
}
linearindexesInRange <- function(sorted,from,to,indexesRemap=NULL){
  if(!is.null(indexesRemap))
    return(indexesRemap[linearindexesInRange(sorted,from,to,NULL)])
  from <- as(from,class(sorted))
  to <- as(to,class(sorted))
  if(!is.na(from) && !is.na(to))
    return(which(sorted>=from & sorted<=to))
  if(!is.na(to))
    return(which(sorted<=to))
  if(!is.na(from))
    return(which(sorted>=from))
  return(1:length(sorted))
}
getFunByName <- function(funName,className=""){
  bsearchFun <- get(paste(funName,capitalizeFirstLetter(className),sep=""))
  linearFun <- get(paste("linear",funName,sep=""))
  return(list(binsearch=bsearchFun,linearsearch=linearFun))
}
multiIdentical <- function(...){
  L <- list(...)
  all(sapply(L[2:length(L)], FUN = identical, L[[1]]))
}



####################################################################################
#                               CREATE SAMPLE OBJECT                               #
####################################################################################
DF <- data.frame(
                INT=c(9L,7L,2L,7L,1L,NA_integer_,4L,3L,7L,3L,NA_integer_,5L,8L),
                LGL=c(FALSE,TRUE,FALSE,as.logical(NA),TRUE,TRUE,FALSE,as.logical(NA),FALSE,FALSE,FALSE,TRUE,TRUE),
                CHR=c(NA_character_,"B","C","A","A","C","A",NA_character_,"A","B","D","E","F"),
                DBL=c(3.5, 4.7, 8.1, 9.5, 7.8, 1.1,5.3, 0.1, 9.9, 2.2, 7.7, NA_real_, NA_real_),
                stringsAsFactors = FALSE
                )

####################################################################################
#                               TEST DFI OBJECTS                                   #
####################################################################################
DFIobj1 <- DFI(DF)
DFIobj2 <- as.DFI(DF)

assert("DFI/as.DFI check", identical(DFIobj1, DFIobj2))  
assert("is.DFI check", c(is.DFI(DFIobj1),is.DFI(DFIobj2)))
assert("DFI.indexes check",identical(DFI.indexes(DFIobj1),c("INT","LGL","CHR","DBL")))
assert("DFI.unWrap",identical(DFI.unWrap(DFIobj1),DF))
assert("DFI.as.data.frame",identical(DFI.unWrap(DFIobj1),DF))
assert("DFI.as.matrix",identical(as.matrix(DFI.unWrap(DFIobj1)),as.matrix(DF)))

# check on the structure
for(idxName in DFI.indexes(DFIobj1)){
  expected <- list(idxs=order(DF[[idxName]],na.last=NA),
                   sorted=DF[[idxName]][order(DF[[idxName]],na.last=NA)],
                   naidxs=which(is.na(DF[[idxName]])))
  assert(paste("DFI.getIndex",idxName,"check",sep=" "), identical(DFI.getIndex(DFIobj1,idxName),expected))
}

# test filter operators creation 
# create a lot of expressions and put them in a list
allFilterExpr <- list(
  INT.eq7 = EQ("INT",7),
  INT.noteq7 = NOT(EQ("INT",7)),
  INT.eqNA = EQ("INT",NA),
  INT.rg4_8 = RG("INT",4,8),
  INT.rgNA_8 = RG("INT",NA,8),
  INT.rg4_NA = RG("INT",4,NA),
  INT.in3_7_9 = IN("INT",c(3,7,9)),
  INT.in3_NA_9 = IN("INT",c(3,NA,9)),
  INT.eqna = EQNA("INT"),
  
  DBL.eq0.1 = EQ("DBL",0.1),
  DBL.noteq0.1 = NOT(EQ("DBL",0.1)),
  DBL.eqNA = EQ("DBL",NA),
  DBL.rg3_5 = RG("DBL",3,5),
  DBL.rgNA_5 = RG("DBL",NA,5),
  DBL.rg3_NA = RG("DBL",3,NA),
  DBL.in4.7_9.5_0.1 = IN("DBL",c(4.7,9.5,0.1)),
  DBL.in4.7_NA_0.1 = IN("DBL",c(4.7,NA,0.1)),
  DBL.eqna = EQNA("DBL"),
  
  LGL.eqTRUE = EQ("LGL",TRUE),
  LGL.noteqTRUE = NOT(EQ("LGL",TRUE)),
  LGL.eqNA = EQ("LGL",NA),
  LGL.rgTRUE_FALSE = RG("LGL",TRUE,FALSE),
  LGL.rgFALSE_TRUE = RG("LGL",FALSE,TRUE),
  LGL.rgNA_TRUE = RG("LGL",NA,TRUE),
  LGL.rgFALSE_NA = RG("LGL",FALSE,NA),
  LGL.inTRUE_FALSE = IN("LGL",c(TRUE,FALSE)),
  LGL.inTRUE_NA_FALSE = IN("LGL",c(TRUE,NA,FALSE)),
  LGL.eqna = EQNA("LGL"),
  
  CHR.eqA = EQ("CHR","A"),
  CHR.noteqA = NOT(EQ("CHR","A")),
  CHR.eqNA = EQ("CHR",NA),
  CHR.rgB_D = RG("CHR","B","D"),
  CHR.rgNA_D = RG("CHR",NA,"D"),
  CHR.rgB_NA = RG("CHR","B",NA),
  CHR.inB_D_A = IN("CHR",c("B","D","A")),
  CHR.inB_NA_A = IN("CHR",c("B",NA,"A")),
  CHR.eqna = EQNA("CHR")
    
)

allFilterExpr$and.1 <- AND(allFilterExpr$INT.eq7, allFilterExpr$CHR.rgB_D)
allFilterExpr$or.1 <- OR(allFilterExpr$INT.eq7, allFilterExpr$DBL.eq0.1, allFilterExpr$CHR.rgB_D)


# compare DFI.subset with normal subsetting described by filter expression toString
for(nm in names(allFilterExpr)){
    fexpr <- allFilterExpr[[nm]]

    filterString <- toString.DFI.FEXPR(fexpr)
    selection <- with(DF, eval(parse(text=filterString)))
    if(is.null(selection)){
      selection <- rep.int(TRUE,nrow(DF))
    }
    selection[is.na(selection)] <- FALSE
    
    result1 <- DF[selection,]  
    result2 <- DFI.subset(DFIobj1,filter = fexpr)
    result2indexes <- DFI.subset(DFIobj1,filter = fexpr,return.indexes=TRUE)
    result2indexesUnordered  <- DFI.subset(DFIobj1,filter = fexpr,return.indexes=TRUE,sort.indexes=FALSE)
    
    assert(paste("DFI.subset: ",nm,"check subset",sep=" "),identical(result1,result2))
    
    assert(paste("DFI.subset: ",nm,"check indexes",sep=" "),identical(which(selection),result2indexes))
    
    assert(paste("DFI.subset: ",nm,"check unordered indexes",sep=" "),setequal(result2indexes,result2indexesUnordered) && length(result2indexes) == length(result2indexesUnordered))
}

####################################################################################
#                TEST LB/UB/indexesEqualTo/indexesInRange FUNCTIONS                #
####################################################################################

INT <- c(2L,3L,8L,9L,9L,11L,13L)
DBL <- c(2,3,8,9,9,11,13)
LGL <- c(FALSE,FALSE,TRUE,TRUE,TRUE,TRUE,TRUE)
CHR <- c("B","C","C","D","E","E","N")

# lb
assert('lb INT central', multiIdentical(lb(INT,9L), lbInteger(INT,9L), linearlb(INT,9L)))
assert('lb INT NA', multiIdentical(lb(INT,NA), lbInteger(INT,NA), linearlb(INT,NA)))
assert('lb INT less than first', multiIdentical(lb(INT,-3), lbInteger(INT,-3), linearlb(INT,-3)))
assert('lb INT greater than last', multiIdentical(lb(INT,1000), lbInteger(INT,1000), linearlb(INT,1000)))
               
assert('lb DBL central', multiIdentical(lb(DBL,9), lbNumeric(DBL,9), linearlb(DBL,9)))
assert('lb DBL NA', multiIdentical(lb(DBL,NA), lbNumeric(DBL,NA), linearlb(DBL,NA)))
assert('lb DBL less than first', multiIdentical(lb(DBL,-3), lbNumeric(DBL,-3), linearlb(DBL,-3)))
assert('lb DBL greater than last', multiIdentical(lb(DBL,1000), lbNumeric(DBL,1000), linearlb(DBL,1000)))
               
assert('lb LGL central', multiIdentical(lb(LGL,TRUE), lbLogical(LGL,TRUE), linearlb(LGL,TRUE)))
assert('lb LGL NA', multiIdentical(lb(LGL,NA), lbLogical(LGL,NA), linearlb(LGL,NA)))
assert('lb LGL less than first', multiIdentical(lb(TRUE,FALSE), lbLogical(TRUE,FALSE), linearlb(TRUE,FALSE)))
assert('lb LGL greater than last', multiIdentical(lb(FALSE,TRUE), lbLogical(FALSE,TRUE), linearlb(FALSE,TRUE)))
               
assert('lb CHR central', multiIdentical(lb(CHR,"E"), lbCharacter(CHR,"E"), linearlb(CHR,"E")))
assert('lb CHR NA', multiIdentical(lb(CHR,NA), lbCharacter(CHR,NA), linearlb(CHR,NA)))
assert('lb CHR less than first', multiIdentical(lb(CHR,"A"), lbCharacter(CHR,"A"), linearlb(CHR,"A")))
assert('lb CHR greater than last', multiIdentical(lb(CHR,"Z"), lbCharacter(CHR,"Z"), linearlb(CHR,"Z")))
               
# ub
assert('ub INT central', multiIdentical(ub(INT,9L), ubInteger(INT,9L), linearub(INT,9L)))
assert('ub INT NA', multiIdentical(ub(INT,NA), ubInteger(INT,NA), linearub(INT,NA)))
assert('ub INT less than first', multiIdentical(ub(INT,-3), ubInteger(INT,-3), linearub(INT,-3)))
assert('ub INT greater than last', multiIdentical(ub(INT,1000), ubInteger(INT,1000), linearub(INT,1000)))
               
assert('ub DBL central', multiIdentical(ub(DBL,9), ubNumeric(DBL,9), linearub(DBL,9)))
assert('ub DBL NA', multiIdentical(ub(DBL,NA), ubNumeric(DBL,NA), linearub(DBL,NA)))
assert('ub DBL less than first', multiIdentical(ub(DBL,-3), ubNumeric(DBL,-3), linearub(DBL,-3)))
assert('ub DBL greater than last', multiIdentical(ub(DBL,1000), ubNumeric(DBL,1000), linearub(DBL,1000)))
               
assert('ub LGL central', multiIdentical(ub(LGL,TRUE), ubLogical(LGL,TRUE), linearub(LGL,TRUE)))
assert('ub LGL NA', multiIdentical(ub(LGL,NA), ubLogical(LGL,NA), linearub(LGL,NA)))
assert('ub LGL less than first', multiIdentical(ub(TRUE,FALSE), ubLogical(TRUE,FALSE), linearub(TRUE,FALSE)))
assert('ub LGL greater than last', multiIdentical(ub(FALSE,TRUE), ubLogical(FALSE,TRUE), linearub(FALSE,TRUE)))
               
assert('ub CHR central', multiIdentical(ub(CHR,"E"), ubCharacter(CHR,"E"), linearub(CHR,"E")))
assert('ub CHR NA', multiIdentical(ub(CHR,NA), ubCharacter(CHR,NA), linearub(CHR,NA)))
assert('ub CHR less than first', multiIdentical(ub(CHR,"A"), ubCharacter(CHR,"A"), linearub(CHR,"A")))
assert('ub CHR greater than last', multiIdentical(ub(CHR,"Z"), ubCharacter(CHR,"Z"), linearub(CHR,"Z")))

# indexesEqualTo
for(remapEnabled in c(FALSE,TRUE)){

  remap <- NULL
  if(remapEnabled)
    remap <- as.integer(c(1,5,3,4,2,7,6))
   
  assert(paste('indexesEqualTo INT central indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(INT,9L,remap), indexesEqualToInteger(INT,9L,remap), linearindexesEqualTo(INT,9L,remap)))
  assert(paste('indexesEqualTo INT NA indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(INT,NA,remap), indexesEqualToInteger(INT,NA,remap), linearindexesEqualTo(INT,NA,remap)))
  assert(paste('indexesEqualTo INT less than first indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(INT,-3,remap), indexesEqualToInteger(INT,-3,remap), linearindexesEqualTo(INT,-3,remap)))
  assert(paste('indexesEqualTo INT greater than last indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(INT,1000,remap), indexesEqualToInteger(INT,1000,remap), linearindexesEqualTo(INT,1000,remap)))

  assert(paste('indexesEqualTo DBL central indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(DBL,9,remap), indexesEqualToNumeric(DBL,9,remap), linearindexesEqualTo(DBL,9,remap)))
  assert(paste('indexesEqualTo DBL NA indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(DBL,NA,remap), indexesEqualToNumeric(DBL,NA,remap), linearindexesEqualTo(DBL,NA,remap)))
  assert(paste('indexesEqualTo DBL less than first indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(DBL,-3,remap), indexesEqualToNumeric(DBL,-3,remap), linearindexesEqualTo(DBL,-3,remap)))
  assert(paste('indexesEqualTo DBL greater than last indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(DBL,1000,remap), indexesEqualToNumeric(DBL,1000,remap), linearindexesEqualTo(DBL,1000,remap)))

  assert(paste('indexesEqualTo LGL central indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(LGL,TRUE,remap), indexesEqualToLogical(LGL,TRUE,remap), linearindexesEqualTo(LGL,TRUE,remap)))
  assert(paste('indexesEqualTo LGL NA indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(LGL,NA,remap), indexesEqualToLogical(LGL,NA,remap), linearindexesEqualTo(LGL,NA,remap)))
  assert(paste('indexesEqualTo LGL less than first indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(TRUE,FALSE,remap), indexesEqualToLogical(TRUE,FALSE,remap), linearindexesEqualTo(TRUE,FALSE,remap)))
  assert(paste('indexesEqualTo LGL greater than last indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(FALSE,TRUE,remap), indexesEqualToLogical(FALSE,TRUE,remap), linearindexesEqualTo(FALSE,TRUE,remap)))

  assert(paste('indexesEqualTo CHR central indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(CHR,"E",remap), indexesEqualToCharacter(CHR,"E",remap), linearindexesEqualTo(CHR,"E",remap)))
  assert(paste('indexesEqualTo CHR NA indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(CHR,NA,remap), indexesEqualToCharacter(CHR,NA,remap), linearindexesEqualTo(CHR,NA,remap)))
  assert(paste('indexesEqualTo CHR less than first indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(CHR,"A",remap), indexesEqualToCharacter(CHR,"A",remap), linearindexesEqualTo(CHR,"A",remap)))
  assert(paste('indexesEqualTo CHR greater than last indexes-remap',remapEnabled), multiIdentical(indexesEqualTo(CHR,"Z",remap), indexesEqualToCharacter(CHR,"Z",remap), linearindexesEqualTo(CHR,"Z",remap)))

}

# indexesInRange
for(remapEnabled in c(FALSE,TRUE)){
  
  remap <- NULL
  if(remapEnabled)
    remap <- as.integer(c(1,5,3,4,2,7,6))
  
  assert(paste('indexesInRange INT central indexes-remap',remapEnabled), multiIdentical(indexesInRange(INT,3L,9L,remap), indexesInRangeInteger(INT,3L,9L,remap), linearindexesInRange(INT,3L,9L,remap)))
  assert(paste('indexesInRange INT NA-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(INT,NA,NA,remap), indexesInRangeInteger(INT,NA,NA,remap), linearindexesInRange(INT,NA,NA,remap)))
  assert(paste('indexesInRange INT from-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(INT,3L,NA,remap), indexesInRangeInteger(INT,3L,NA,remap), linearindexesInRange(INT,3L,NA,remap)))
  assert(paste('indexesInRange INT NA-to indexes-remap',remapEnabled), multiIdentical(indexesInRange(INT,NA,11L,remap), indexesInRangeInteger(INT,NA,11L,remap), linearindexesInRange(INT,NA,11L,remap)))
  assert(paste('indexesInRange INT full-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(INT,-3,1000,remap), indexesInRangeInteger(INT,-3,1000,remap), linearindexesInRange(INT,-3,1000,remap)))
  assert(paste('indexesInRange INT no-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(INT,4,5,remap), indexesInRangeInteger(INT,4,5,remap), linearindexesInRange(INT,4,5,remap)))

  assert(paste('indexesInRange DBL central indexes-remap',remapEnabled), multiIdentical(indexesInRange(DBL,3,9,remap), indexesInRangeNumeric(DBL,3,9,remap), linearindexesInRange(DBL,3,9,remap)))
  assert(paste('indexesInRange DBL NA-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(DBL,NA,NA,remap), indexesInRangeNumeric(DBL,NA,NA,remap), linearindexesInRange(DBL,NA,NA,remap)))
  assert(paste('indexesInRange DBL from-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(DBL,3,NA,remap), indexesInRangeNumeric(DBL,3,NA,remap), linearindexesInRange(DBL,3,NA,remap)))
  assert(paste('indexesInRange DBL NA-to indexes-remap',remapEnabled), multiIdentical(indexesInRange(DBL,NA,11,remap), indexesInRangeNumeric(DBL,NA,11,remap), linearindexesInRange(DBL,NA,11,remap)))
  assert(paste('indexesInRange DBL full-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(DBL,-3,1000,remap), indexesInRangeNumeric(DBL,-3,1000,remap), linearindexesInRange(DBL,-3,1000,remap)))
  assert(paste('indexesInRange DBL no-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(DBL,4,5,remap), indexesInRangeNumeric(DBL,4,5,remap), linearindexesInRange(DBL,4,5,remap)))
  
  assert(paste('indexesInRange LGL central indexes-remap',remapEnabled), multiIdentical(indexesInRange(LGL,TRUE,TRUE,remap), indexesInRangeLogical(LGL,TRUE,TRUE,remap), linearindexesInRange(LGL,TRUE,TRUE,remap)))
  assert(paste('indexesInRange LGL NA-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(LGL,NA,NA,remap), indexesInRangeLogical(LGL,NA,NA,remap), linearindexesInRange(LGL,NA,NA,remap)))
  assert(paste('indexesInRange LGL from-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(LGL,TRUE,NA,remap), indexesInRangeLogical(LGL,TRUE,NA,remap), linearindexesInRange(LGL,TRUE,NA,remap)))
  assert(paste('indexesInRange LGL NA-to indexes-remap',remapEnabled), multiIdentical(indexesInRange(LGL,NA,FALSE,remap), indexesInRangeLogical(LGL,NA,FALSE,remap), linearindexesInRange(LGL,NA,FALSE,remap)))
  assert(paste('indexesInRange LGL full-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(LGL,FALSE,TRUE,remap), indexesInRangeLogical(LGL,FALSE,TRUE,remap), linearindexesInRange(LGL,FALSE,TRUE,remap)))
  assert(paste('indexesInRange LGL no-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(LGL,TRUE,FALSE,remap), indexesInRangeLogical(LGL,TRUE,FALSE,remap), linearindexesInRange(LGL,TRUE,FALSE,remap)))
  
  assert(paste('indexesInRange CHR central indexes-remap',remapEnabled), multiIdentical(indexesInRange(CHR,"C","D",remap), indexesInRangeCharacter(CHR,"C","D",remap), linearindexesInRange(CHR,"C","D",remap)))
  assert(paste('indexesInRange CHR NA-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(CHR,NA,NA,remap), indexesInRangeCharacter(CHR,NA,NA,remap), linearindexesInRange(CHR,NA,NA,remap)))
  assert(paste('indexesInRange CHR from-NA indexes-remap',remapEnabled), multiIdentical(indexesInRange(CHR,"C",NA,remap), indexesInRangeCharacter(CHR,"C",NA,remap), linearindexesInRange(CHR,"C",NA,remap)))
  assert(paste('indexesInRange CHR NA-to indexes-remap',remapEnabled), multiIdentical(indexesInRange(CHR,NA,"D",remap), indexesInRangeCharacter(CHR,NA,"D",remap), linearindexesInRange(CHR,NA,"D",remap)))
  assert(paste('indexesInRange CHR full-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(CHR,"A","Z",remap), indexesInRangeCharacter(CHR,"A","Z",remap), linearindexesInRange(CHR,"A","Z",remap)))
  assert(paste('indexesInRange CHR no-range indexes-remap',remapEnabled), multiIdentical(indexesInRange(CHR,"F","H",remap), indexesInRangeCharacter(CHR,"F","H",remap), linearindexesInRange(CHR,"F","H",remap)))
  
}

####################################################################################
#              TEST unionIndexesList/intersectIndexesList FUNCTIONS                #
####################################################################################

indexesMergeTest <- list()
indexesMergeTest$indexes1 <- list(c(7L,2L,3L),c(3L,100L,2L,8L,10L),c(10L,4L,5L,2L))
indexesMergeTest$indexes2 <- list(c(7L,2L,3L),integer(),c(10L,4L))
indexesMergeTest$indexes3 <- list(c(7L,2L,3L))
indexesMergeTest$indexes4 <- list()
indexesMergeTest$indexes5 <- list(integer())

.unionListSorted <- function(lst){ if(length(lst) == 0) integer() else sort(unique(Reduce(f=union,x=lst))) }
.intersectListSorted <- function(lst){ if(length(lst) == 0) integer() else sort(unique(Reduce(f=intersect,x=lst))) }

for(nm in names(indexesMergeTest)){
  toTest <- indexesMergeTest[[nm]]
  assert( paste("unionIndexesList default",nm),     identical( unionIndexesList(toTest), .unionListSorted(toTest))  )
  assert( paste("unionIndexesList sorted",nm),      identical( unionIndexesList(toTest,sorted=TRUE), .unionListSorted(toTest))  )
  assert( paste("unionIndexesList unsorted",nm),    identical( sort(unionIndexesList(toTest,sorted=FALSE)), .unionListSorted(toTest))  )

  assert( paste("intersectIndexesList default",nm), identical( intersectIndexesList(toTest), .intersectListSorted(toTest))  )
  assert( paste("intersectIndexesList sorted",nm),  identical( intersectIndexesList(toTest,sorted=TRUE), .intersectListSorted(toTest))  )
  assert( paste("intersectIndexesList unsorted",nm),identical( sort(intersectIndexesList(toTest,sorted=FALSE)), .intersectListSorted(toTest))  )
}

####################################################################################
#              TEST verifiable issues                                              #    
####################################################################################

D <- DFI(data.frame(A=1:10,B=21:30))
M <- DFI(as.matrix(D))


assert("issue #2",!identical(DFI.subset(D,filter = NULL, return.indexes = FALSE),
                             DFI.subset(D,filter = NULL, return.indexes = TRUE)
))
assert("issue #3",!is.matrix(DFI.subset(M,filter = IN('A',5), return.indexes = FALSE, drop=TRUE)))

####################################################################################
#                                     END                                          #
####################################################################################
