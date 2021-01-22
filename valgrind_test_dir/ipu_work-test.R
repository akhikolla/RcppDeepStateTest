function (inp, con, w, eps, verbose) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipu_work"]][[length(e[["ipu_work"]]) + 1]] <- list(inp = inp, 
        con = con, w = w, eps = eps, verbose = verbose)
    .Call("_simPop_ipu_work", PACKAGE = "simPop", inp, con, w, 
        eps, verbose)
}
