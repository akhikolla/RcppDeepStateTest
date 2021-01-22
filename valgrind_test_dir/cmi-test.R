function (x, y, z, proc = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cmi"]][[length(e[["cmi"]]) + 1]] <- list(x = x, y = y, 
        z = z, proc = proc)
    .Call("_BNSL_cmi", x, y, z, proc)
}
