function (x, centers) 
{
    e <- get("data.env", .GlobalEnv)
    e[["predKmeansCpp"]][[length(e[["predKmeansCpp"]]) + 1]] <- list(x = x, 
        centers = centers)
    .Call("_RStoolbox_predKmeansCpp", PACKAGE = "RStoolbox", 
        x, centers)
}
