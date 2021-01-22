function (From, breaks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Refine2d_"]][[length(e[["Refine2d_"]]) + 1]] <- list(From = From, 
        breaks = breaks)
    .Call("_icosa_Refine2d_", From, breaks)
}
