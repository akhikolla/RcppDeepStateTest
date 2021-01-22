function (As) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Eigen_C_value"]][[length(e[["Eigen_C_value"]]) + 1]] <- list(As = As)
    .Call("_CKLRT_Eigen_C_value", PACKAGE = "CKLRT", As)
}
