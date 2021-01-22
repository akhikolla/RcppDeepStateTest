function (x, margin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcsum"]][[length(e[["rcsum"]]) + 1]] <- list(x = x, margin = margin)
    .Call("_mixR_rcsum", x, margin)
}
