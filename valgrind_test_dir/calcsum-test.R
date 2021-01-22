function (thetamat, n, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcsum"]][[length(e[["calcsum"]]) + 1]] <- list(thetamat = thetamat, 
        n = n, p = p)
    .Call("_flam_calcsum", PACKAGE = "flam", thetamat, n, p)
}
