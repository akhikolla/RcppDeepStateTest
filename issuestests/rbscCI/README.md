
<!-- README.md is generated from README.Rmd. Please edit that file -->
rbscCI
======

<!-- badges: start -->
<!-- badges: end -->
This package is an R wrapper of the C++ implementaton of the Blyth-Still-Casella confidence interval <https://github.com/keithw/biostat>.

It requires C++11 and the boost C++ library: <https://www.boost.org/>. The original C++ code is wrapped with an R interface using Rcpp and the boost library depedency is handled by the BH R package.

Installation
------------

You can install the released version of rbscCI from [CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("rbscCI")
```

Example
-------

This is a basic example to find the 95% confidence interval of the probability of success when there are 25 success out of 100 coin flips:

``` r
library(rbscCI)
bscCI(100, 25, 0.95, digits = 3)
#> [1] 0.171 0.341
```
