function (ctgt, smooth) 
{
    e <- get("data.env", .GlobalEnv)
    e[["smooth_sideeffect"]][[length(e[["smooth_sideeffect"]]) + 
        1]] <- list(ctgt = ctgt, smooth = smooth)
    .Call("_bnclassify_smooth_sideeffect", PACKAGE = "bnclassify", 
        ctgt, smooth)
}
