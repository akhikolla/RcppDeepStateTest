function (x, scal, xmin, ymin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rescaleImageCpp"]][[length(e[["rescaleImageCpp"]]) + 
        1]] <- list(x = x, scal = scal, xmin = xmin, ymin = ymin)
    .Call("_RStoolbox_rescaleImageCpp", PACKAGE = "RStoolbox", 
        x, scal, xmin, ymin)
}
