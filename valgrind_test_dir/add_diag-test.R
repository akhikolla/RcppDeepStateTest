function (A, B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["add_diag"]][[length(e[["add_diag"]]) + 1]] <- list(A = A, 
        B = B)
    .Call("_hetGP_add_diag", PACKAGE = "hetGP", A, B)
}
