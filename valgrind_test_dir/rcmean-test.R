function (x, margin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcmean"]][[length(e[["rcmean"]]) + 1]] <- list(x = x, 
        margin = margin)
    .Call("_mixR_rcmean", x, margin)
}
