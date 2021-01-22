function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["half2mat"]][[length(e[["half2mat"]]) + 1]] <- list(X = X)
    .Call("_propr_half2mat", X)
}
