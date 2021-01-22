function (A, B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_diag"]][[length(e[["fast_diag"]]) + 1]] <- list(A = A, 
        B = B)
    .Call("_hetGP_fast_diag", PACKAGE = "hetGP", A, B)
}
