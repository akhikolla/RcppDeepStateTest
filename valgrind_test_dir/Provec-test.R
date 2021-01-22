function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Provec"]][[length(e[["Provec"]]) + 1]] <- list(x = x)
    .Call("_HistDAWass_Provec", PACKAGE = "HistDAWass", x)
}
