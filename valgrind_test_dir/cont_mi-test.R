function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cont_mi"]][[length(e[["cont_mi"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_BNSL_cont_mi", x, y)
}
