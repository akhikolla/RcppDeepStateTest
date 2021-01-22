function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sd_mat"]][[length(e[["sd_mat"]]) + 1]] <- list(mat = mat)
    .Call("_mousetrap_sd_mat", mat)
}
