function (data, resp, pen, num_cp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["make_pelt_cpmat"]][[length(e[["make_pelt_cpmat"]]) + 
        1]] <- list(data = data, resp = resp, pen = pen, num_cp = num_cp)
    .Call("_bartBMA_make_pelt_cpmat", data, resp, pen, num_cp)
}
