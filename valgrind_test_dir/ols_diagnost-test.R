function (y, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ols_diagnost"]][[length(e[["ols_diagnost"]]) + 1]] <- list(y = y, 
        x = x)
    .Call("_lpirfs_ols_diagnost", y, x)
}
