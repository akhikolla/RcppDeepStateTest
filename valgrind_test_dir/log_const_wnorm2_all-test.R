function (par_mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_const_wnorm2_all"]][[length(e[["log_const_wnorm2_all"]]) + 
        1]] <- list(par_mat = par_mat)
    .Call("_BAMBI_log_const_wnorm2_all", par_mat)
}
