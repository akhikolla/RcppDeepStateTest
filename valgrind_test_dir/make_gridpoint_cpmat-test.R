function (data, resp, gridsize, num_cp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["make_gridpoint_cpmat"]][[length(e[["make_gridpoint_cpmat"]]) + 
        1]] <- list(data = data, resp = resp, gridsize = gridsize, 
        num_cp = num_cp)
    .Call("_bartBMA_make_gridpoint_cpmat", data, resp, gridsize, 
        num_cp)
}
