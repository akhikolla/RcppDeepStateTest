function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["logsum"]][[length(e[["logsum"]]) + 1]] <- list(x = x)
    .Call("_aphid_logsum", PACKAGE = "aphid", x)
}
