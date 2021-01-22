function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["u64tobin"]][[length(e[["u64tobin"]]) + 1]] <- list(x = x)
    .Call("_jiebaR_u64tobin", x)
}
