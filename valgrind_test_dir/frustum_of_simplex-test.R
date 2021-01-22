function (a, z0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["frustum_of_simplex"]][[length(e[["frustum_of_simplex"]]) + 
        1]] <- list(a = a, z0 = z0)
    .Call("_volesti_frustum_of_simplex", a, z0)
}
