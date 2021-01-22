function (r, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["durbin"]][[length(e[["durbin"]]) + 1]] <- list(r = r, 
        N = N)
    .Call("_FastGP_durbin", PACKAGE = "FastGP", r, N)
}
