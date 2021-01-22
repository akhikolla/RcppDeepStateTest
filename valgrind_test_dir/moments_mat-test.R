function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["moments_mat"]][[length(e[["moments_mat"]]) + 1]] <- list(mat = mat)
    .Call("_mousetrap_moments_mat", mat)
}
