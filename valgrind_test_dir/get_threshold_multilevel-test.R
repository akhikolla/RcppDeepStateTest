function (im_density, im_integral_density, n_thres, sn, mcn, 
    limit) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_threshold_multilevel"]][[length(e[["get_threshold_multilevel"]]) + 
        1]] <- list(im_density = im_density, im_integral_density = im_integral_density, 
        n_thres = n_thres, sn = sn, mcn = mcn, limit = limit)
    .Call("_imagerExtra_get_threshold_multilevel", im_density, 
        im_integral_density, n_thres, sn, mcn, limit)
}
