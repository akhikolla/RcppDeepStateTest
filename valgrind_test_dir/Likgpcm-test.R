function (awv, DELTA, ALPHA, nodes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Likgpcm"]][[length(e[["Likgpcm"]]) + 1]] <- list(awv = awv, 
        DELTA = DELTA, ALPHA = ALPHA, nodes = nodes)
    .Call("_PP_Likgpcm", awv, DELTA, ALPHA, nodes)
}
