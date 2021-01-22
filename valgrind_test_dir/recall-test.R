function (kappa, BR, P) 
{
    e <- get("data.env", .GlobalEnv)
    e[["recall"]][[length(e[["recall"]]) + 1]] <- list(kappa = kappa, 
        BR = BR, P = P)
    .Call("_rhoR_recall", PACKAGE = "rhoR", kappa, BR, P)
}
