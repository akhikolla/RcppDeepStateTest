function (wht, restmp, x, dcm, oldknots, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Knotnew"]][[length(e[["Knotnew"]]) + 1]] <- list(wht = wht, 
        restmp = restmp, x = x, dcm = dcm, oldknots = oldknots, 
        tol = tol)
    .Call("_GeDS_Knotnew", PACKAGE = "GeDS", wht, restmp, x, 
        dcm, oldknots, tol)
}
