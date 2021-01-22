function (x, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["empirical_cmi"]][[length(e[["empirical_cmi"]]) + 1]] <- list(x = x, 
        y = y, z = z)
    .Call("_BNSL_empirical_cmi", x, y, z)
}
