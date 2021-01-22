function (VAR_Data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["var_one"]][[length(e[["var_one"]]) + 1]] <- list(VAR_Data = VAR_Data)
    .Call("_lpirfs_var_one", VAR_Data)
}
