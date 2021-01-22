function (x, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cont_cmi"]][[length(e[["cont_cmi"]]) + 1]] <- list(x = x, 
        y = y, z = z)
    .Call("_BNSL_cont_cmi", x, y, z)
}
