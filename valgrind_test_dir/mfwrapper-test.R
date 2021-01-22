function (xi, weights, qJ, Lv, Eps, priorCount) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mfwrapper"]][[length(e[["mfwrapper"]]) + 1]] <- list(xi = xi, 
        weights = weights, qJ = qJ, Lv = Lv, Eps = Eps, priorCount = priorCount)
    .Call("_bbl_mfwrapper", PACKAGE = "bbl", xi, weights, qJ, 
        Lv, Eps, priorCount)
}
