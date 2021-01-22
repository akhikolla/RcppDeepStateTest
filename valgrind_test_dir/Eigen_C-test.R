function (As) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Eigen_C"]][[length(e[["Eigen_C"]]) + 1]] <- list(As = As)
    .Call("_CKLRT_Eigen_C", PACKAGE = "CKLRT", As)
}
