function (data, max_im, min_im, max_range, min_range) 
{
    e <- get("data.env", .GlobalEnv)
    e[["saturateim"]][[length(e[["saturateim"]]) + 1]] <- list(data = data, 
        max_im = max_im, min_im = min_im, max_range = max_range, 
        min_range = min_range)
    .Call("_imagerExtra_saturateim", data, max_im, min_im, max_range, 
        min_range)
}
