
context("compare results with outputs from StatXact")

# load testdata and space pre-allocation
dat <- read.csv("TESTDATA.csv")
n_test <- nrow(dat)
sas <- matrix(NA, n_test,2)
v1 <- matrix(NA, n_test,2)

# load sas result from .lst file
sas_lst <- readLines("bscCI_test.lst")
offset_bscline <- 20
counter <- 1
ii <- 1
while (counter < length(sas_lst)) {
  txt <- sas_lst[counter]
  if (grepl("I=",txt)) {
    txt_bsc <- sas_lst[counter+offset_bscline]
    txt_bsc <- sub("\\(Blyth-Still-Casella\\)  = \\(", "", txt_bsc)
    txt_bsc <- sub("\\)", "", txt_bsc)
    txt_bsc <- strsplit(txt_bsc, ",")[[1]]
    txt_bsc <- trimws(txt_bsc)
    sas[ii,] <- as.numeric(txt_bsc)
    ii <- ii+1
    counter <- counter+offset_bscline
  }
  else {
    counter <- counter+1
  }
}

# R results
system.time(
  for (ii in 1:n_test) {
    v1[ii,] <- bscCI(dat$n[ii], dat$x[ii], 0.95, digits = )
  }
)

expect_equal(sas[,1], v1[,1], tolerance = 1e-4)
expect_equal(sas[,2], v1[,2], tolerance = 1e-4)
