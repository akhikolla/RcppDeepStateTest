function (x, y, w, i, j, skip) 
{
    e <- get("data.env", .GlobalEnv)
    e[["summarize_input"]][[length(e[["summarize_input"]]) + 
        1]] <- list(x = x, y = y, w = w, i = i, j = j, skip = skip)
    .Call("_RcppDynProg_summarize_input", PACKAGE = "RcppDynProg", 
        x, y, w, i, j, skip)
}
