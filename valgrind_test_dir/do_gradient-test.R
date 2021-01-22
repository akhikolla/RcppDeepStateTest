function (m, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_gradient"]][[length(e[["do_gradient"]]) + 1]] <- list(m = m, 
        x = x, y = y)
    .Call("_oce_do_gradient", m, x, y)
}
