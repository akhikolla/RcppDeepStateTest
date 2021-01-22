function (data, F, N, smax, smin, max, min, max_range, min_range) 
{
    e <- get("data.env", .GlobalEnv)
    e[["piecewise_transformation"]][[length(e[["piecewise_transformation"]]) + 
        1]] <- list(data = data, F = F, N = N, smax = smax, smin = smin, 
        max = max, min = min, max_range = max_range, min_range = min_range)
    .Call("_imagerExtra_piecewise_transformation", data, F, N, 
        smax, smin, max, min, max_range, min_range)
}
