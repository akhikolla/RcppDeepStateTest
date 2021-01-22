function (s, M) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sMultiple"]][[length(e[["sMultiple"]]) + 1]] <- list(s = s, 
        M = M)
    .Call("_Opt5PL_sMultiple", s, M)
}
