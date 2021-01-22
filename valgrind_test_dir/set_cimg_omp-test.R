function (mode) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_cimg_omp"]][[length(e[["set_cimg_omp"]]) + 1]] <- list(mode = mode)
    .Call("_imager_set_cimg_omp", mode)
}
