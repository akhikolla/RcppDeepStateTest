function (C, g, r, N, Ve) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SAMP"]][[length(e[["SAMP"]]) + 1]] <- list(C = C, g = g, 
        r = r, N = N, Ve = Ve)
    invisible(c(".Call", "'_NAM_SAMP`", "C", "g", "r", "N", "Ve"
    ))
}
