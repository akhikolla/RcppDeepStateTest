function (ycenter, xcol, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["maxLambda_a1_C_single"]][[length(e[["maxLambda_a1_C_single"]]) + 
        1]] <- list(ycenter = ycenter, xcol = xcol, n = n)
    .Call("_flam_maxLambda_a1_C_single", PACKAGE = "flam", ycenter, 
        xcol, n)
}
