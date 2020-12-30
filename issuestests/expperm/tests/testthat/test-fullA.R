context("Equality of algorithms for fully populated likelihood matrix")

test_that("Ryser and brute algorithms produce the same output", {
  expect_equal( max(abs(ryser(A)-brute(A)))<1e-10,TRUE )
})