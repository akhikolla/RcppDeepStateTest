function (esf_par1, splitvec_len_pp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_cml_splitvec"]][[length(e[["immer_cml_splitvec"]]) + 
        1]] <- list(esf_par1 = esf_par1, splitvec_len_pp = splitvec_len_pp)
    .Call("_immer_immer_cml_splitvec", PACKAGE = "immer", esf_par1, 
        splitvec_len_pp)
}
