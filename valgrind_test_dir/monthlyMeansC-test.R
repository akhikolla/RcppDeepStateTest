function (x, nCycleWindow) 
{
    e <- get("data.env", .GlobalEnv)
    e[["monthlyMeansC"]][[length(e[["monthlyMeansC"]]) + 1]] <- list(x = x, 
        nCycleWindow = nCycleWindow)
    .Call("_remote_monthlyMeansC", PACKAGE = "remote", x, nCycleWindow)
}
