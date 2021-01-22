function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BESSI0_C"]][[length(e[["BESSI0_C"]]) + 1]] <- list(x = x)
    .Call("_BAMBI_BESSI0_C", x)
}
