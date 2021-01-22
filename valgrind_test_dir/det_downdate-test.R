function (A, v, det) 
{
    e <- get("data.env", .GlobalEnv)
    e[["det_downdate"]][[length(e[["det_downdate"]]) + 1]] <- list(A = A, 
        v = v, det = det)
    .Call("_Benchmarking_det_downdate", A, v, det)
}
