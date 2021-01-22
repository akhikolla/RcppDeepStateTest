function (Y, kern, max_l) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_lrv_vec_cpp"]][[length(e[["get_lrv_vec_cpp"]]) + 
        1]] <- list(Y = Y, kern = kern, max_l = max_l)
    .Call("_CPAT_get_lrv_vec_cpp", PACKAGE = "CPAT", Y, kern, 
        max_l)
}
