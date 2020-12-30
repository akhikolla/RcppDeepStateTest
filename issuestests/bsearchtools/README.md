# bsearchtools
## Binary search tools for R.

The `bsearchtools` package exposes the binary search based functions of the C++ standard library 
(`std::lower_bound`, `std::upper_bound`) plus other convenience functions, allowing faster lookups on sorted vectors.

It also includes `DFI`, a lightweight `data.frame`/`matrix` wrapper, which automatically creates indexes on the 
columns for faster lookups.

These functions are especially designed to be used in non-vectorized operations (e.g. inside loops).  
For vectorized operations the great `data.table` package already fullfills basically every R programmer needs.

### Installation

The package is available on CRAN : https://cran.r-project.org/package=bsearchtools

### Examples : 

- Get lower and upper bound indexes :

```R
sortedVec <- c(1,3,3,5,7,12,15,42)

lb(sortedVec,3) # returns 2
ub(sortedVec,3) # returns 4
```

- Get indexes of elements equal to a value / in a [from,to] range :

```R
sortedVec <- c(1,3,3,5,7,12,15,42)

indexesEqualTo(sortedVec,3) # returns c(2,3)
indexesInRange(sortedVec,5,15) # returns c(4,5,6,7)

```

- DFI data.frame wrapper

```R
DF <- data.frame(Name=c('John','Jennifer','John','Emily','Peter','Anna','Emily'), 
                 Age=c(30,50,15,27,25,35,70),
                 stringsAsFactors = FALSE)

# create a DFI object from a data.frame (you can also use as.DFI)
DFIobj <- DFI(DF)

# select rows with this filter : 
# (Name == 'John' | Name == 'Emily') & Age >= 25 & Age <= 60
res <- DFI.subset(DFIobj, AND(OR(EQ('Name','John'),EQ('Name','Emily')),RG('Age',25,60)))
# returns :
> res
   Name Age
1  John  30
4 Emily  27

```

### Benchmarks :


- Tested on :
```
R: 3.2.5 64bit   
OS: Window 10  
CPU: i5 6600K @3.5 Ghz  
RAM: 16 GB
```

- Get indexes of elements in range `[7000,7500]` of a random numeric vector of
  `1e6` elements :
  
```R
set.seed(123) # for reproducibility
sortedValues <- sort(sample(1:1e4,1e6,replace=TRUE))

# measure time difference doing same operation 500 times
tm1 <- system.time( for(i in 1:500) res1 <- which(sortedValues >= 7000 & sortedValues <= 7500))
tm2 <- system.time( for(i in 1:500) res2 <- indexesInRangeInteger(sortedValues,7000,7500))

> tm1
   user  system elapsed 
  10.87    2.72   13.61 

> tm2
   user  system elapsed 
   0.04    0.00    0.04


```


- Subset a data.frame with `1e6` rows, performing a range selection on a numeric column :

```R
set.seed(123) # for reproducibility
DF <- data.frame(LT=sample(LETTERS,1e6,replace=TRUE),
                 Values=sample(1:1e4,1e6,replace=TRUE),
                 stringsAsFactors = FALSE)
# we want to index only 'Values' column, by default all columns are indexed
DFIobj <- DFI(DF,indexes.col.names = 'Values') 

# measure time difference doing same operation 500 times
tm1 <- system.time( for(i in 1:500) res1 <- DF[DF$Values >= 4500 & DF$Values <= 5000, 'LT' ] )
tm2 <- system.time( for(i in 1:500) res2 <- DFI.subset(DFIobj,filter=RG('Values',4500,5000),colFilter='LT') )

# and if you're not interested in keeping the original row order : 
tm3 <- system.time( for(i in 1:500) res3 <- DFI.subset(DFIobj,filter=RG('Values',4500,5000),colFilter='LT', 
                                                       sort.indexes = FALSE) )

> tm1
   user  system elapsed 
  14.80    1.84   16.64 
> tm2
   user  system elapsed 
   1.86    0.00    1.86 
> tm3
   user  system elapsed 
   0.29    0.00    0.30

```

##### N.B.  
If the original vector/data.frame is small, or the size of the filtered result is very similar to original vector/data.frame size, 
the performance gain of bsearchtools functions will become negligible or possibly worse than base R. So, these functions should be used when appropriate and after testing carefully both the possibilities.


### License

GPL (>= 2)

### Possible improvements

- Accept a filter like 'A <= 3 & B == 5' etc. (a fast and reliable parser is needed)
- Improve DFI.subset function, in particular on complex filter
- Better NA support ?







