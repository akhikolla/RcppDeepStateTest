function (dayvars, rows, days, wk, we) 
{
    e <- get("data.env", .GlobalEnv)
    e[["personvars"]][[length(e[["personvars"]]) + 1]] <- list(dayvars = dayvars, 
        rows = rows, days = days, wk = wk, we = we)
    .Call("_accelerometry_personvars", dayvars, rows, days, wk, 
        we)
}
