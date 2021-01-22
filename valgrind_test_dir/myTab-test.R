function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["myTab"]][[length(e[["myTab"]]) + 1]] <- list(x = x)
    .Call("_diveRsity_myTab", x)
}
