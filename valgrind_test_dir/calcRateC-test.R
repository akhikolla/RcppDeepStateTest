function (M, Aj, days, searches) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcRateC"]][[length(e[["calcRateC"]]) + 1]] <- list(M = M, 
        Aj = Aj, days = days, searches = searches)
    .Call("_GenEst_calcRateC", M, Aj, days, searches)
}
