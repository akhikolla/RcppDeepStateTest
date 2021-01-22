function (v, f, origin, pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spherTriSurfs"]][[length(e[["spherTriSurfs"]]) + 1]] <- list(v = v, 
        f = f, origin = origin, pi = pi)
    .Call("_icosa_spherTriSurfs", v, f, origin, pi)
}
