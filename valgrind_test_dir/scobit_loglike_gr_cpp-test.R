function (x1, x2, y, params) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scobit_loglike_gr_cpp"]][[length(e[["scobit_loglike_gr_cpp"]]) + 
        1]] <- list(x1 = x1, x2 = x2, y = y, params = params)
    .Call("_backbone_scobit_loglike_gr_cpp", PACKAGE = "backbone", 
        x1, x2, y, params)
}
