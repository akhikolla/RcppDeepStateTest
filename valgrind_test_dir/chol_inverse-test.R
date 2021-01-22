function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["chol_inverse"]][[length(e[["chol_inverse"]]) + 1]] <- list(X = X)
    .Call("_MM4LMM_chol_inverse", PACKAGE = "MM4LMM", X)
}
