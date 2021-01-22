function (urlpath) 
{
    e <- get("data.env", .GlobalEnv)
    e[["VSI_list"]][[length(e[["VSI_list"]]) + 1]] <- list(urlpath = urlpath)
    .Call("_vapour_VSI_list", PACKAGE = "vapour", urlpath)
}
