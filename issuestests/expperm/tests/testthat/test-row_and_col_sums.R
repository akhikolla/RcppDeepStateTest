context("Row- and column-sums are all one")

test_that("Ryser and brute algorithms produce the same output", {
  expect_equal( max(abs( rowSums(brute(A))-1 ),abs( colSums(brute(A))-1 ))<1e-10,TRUE )
})

test_that("Ryser and brute algorithms produce the same output", {
  expect_equal( max(abs( rowSums(ryser(A))-1 ),abs( colSums(ryser(A))-1 ))<1e-10,TRUE )
})

test_that("Ryser and brute algorithms produce the same output", {
  expect_equal( max(abs( rowSums(BG(triA))-1 ),abs( colSums(BG(triA))-1 ))<1e-10,TRUE )
})

