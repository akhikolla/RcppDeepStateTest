context("Equality of implementations in R and C++")

test_that("R Ryser and C++ Ryser algorithms produce the same output", {
  expect_equal( max(abs(ryser(A)-ryser_cpp(A)))<1e-10,TRUE )
})

test_that("R brute and C++ brute algorithms produce the same output", {
  expect_equal( max(abs(brute(A)-brute_cpp(A)))<1e-10,TRUE )
})

test_that("R BG and C++ BG algorithms produce the same output", {
  expect_equal( max(abs(BG(triA)-BG_cpp(triA)))<1e-10,TRUE )
})