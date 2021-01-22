function (x, df, ncp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pnct"]][[length(e[["pnct"]]) + 1]] <- list(x = x, df = df, 
        ncp = ncp)
    .Call("_exceedProb_pnct", x, df, ncp)
}
