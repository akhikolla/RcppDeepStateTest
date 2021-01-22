function (Mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["k_distmat"]][[length(e[["k_distmat"]]) + 1]] <- list(Mat = Mat)
    .Call("_krige_k_distmat", Mat)
}
