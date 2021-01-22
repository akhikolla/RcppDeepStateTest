function (df0, h, tw = 0L, proc = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["parent"]][[length(e[["parent"]]) + 1]] <- list(df0 = df0, 
        h = h, tw = tw, proc = proc)
    .Call("_BNSL_parent", df0, h, tw, proc)
}
