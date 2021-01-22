function (v, cent, origin, pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["surfConvHullTri"]][[length(e[["surfConvHullTri"]]) + 
        1]] <- list(v = v, cent = cent, origin = origin, pi = pi)
    .Call("_icosa_surfConvHullTri", v, cent, origin, pi)
}
