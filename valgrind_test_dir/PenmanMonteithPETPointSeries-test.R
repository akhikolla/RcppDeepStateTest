function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["PenmanMonteithPETPointSeries"]][[length(e[["PenmanMonteithPETPointSeries"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
