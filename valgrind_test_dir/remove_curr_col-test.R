function (predy, i) 
{
    e <- get("data.env", .GlobalEnv)
    e[["remove_curr_col"]][[length(e[["remove_curr_col"]]) + 
        1]] <- list(predy = predy, i = i)
    .Call("_bartBMA_remove_curr_col", predy, i)
}
