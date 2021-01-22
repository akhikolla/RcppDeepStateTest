function (mult, Y2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_tUY2"]][[length(e[["fast_tUY2"]]) + 1]] <- list(mult = mult, 
        Y2 = Y2)
    .Call("_hetGP_fast_tUY2", PACKAGE = "hetGP", mult, Y2)
}
