function (wht, restmp, x, dcm, oldknots, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Knotnewtest"]][[length(e[["Knotnewtest"]]) + 1]] <- list(wht = wht, 
        restmp = restmp, x = x, dcm = dcm, oldknots = oldknots, 
        tol = tol)
    .Call("_GeDS_Knotnewtest", PACKAGE = "GeDS", wht, restmp, 
        x, dcm, oldknots, tol)
}
