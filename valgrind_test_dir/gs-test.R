function (C, g, r, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gs"]][[length(e[["gs"]]) + 1]] <- list(C = C, g = g, 
        r = r, N = N)
    invisible(c(".Call", "'_NAM_gs`", "C", "g", "r", "N"))
}
