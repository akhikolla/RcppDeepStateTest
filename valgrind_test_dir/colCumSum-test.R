function (m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["colCumSum"]][[length(e[["colCumSum"]]) + 1]] <- list(m = m)
    .Call("_MESS_colCumSum", m)
}
