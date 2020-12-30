context("Equality of algorithms for tridiagonal likelihood matrix")

test_that("Ryser and brute algorithms produce the same output", {
  expect_equal( max(abs(ryser(triA)-brute(triA)))<1e-10,TRUE )
})

test_that("Ryser and BG algorithms produce the same output", {
  expect_equal( max(abs(ryser(triA)-BG(triA)))<1e-10,TRUE )
})