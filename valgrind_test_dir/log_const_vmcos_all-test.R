function (par_mat, uni_rand) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_const_vmcos_all"]][[length(e[["log_const_vmcos_all"]]) + 
        1]] <- list(par_mat = par_mat, uni_rand = uni_rand)
    .Call("_BAMBI_log_const_vmcos_all", par_mat, uni_rand)
}
