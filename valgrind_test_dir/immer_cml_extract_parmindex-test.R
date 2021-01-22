function (esf_par0, parm_index_pp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_cml_extract_parmindex"]][[length(e[["immer_cml_extract_parmindex"]]) + 
        1]] <- list(esf_par0 = esf_par0, parm_index_pp = parm_index_pp)
    .Call("_immer_immer_cml_extract_parmindex", PACKAGE = "immer", 
        esf_par0, parm_index_pp)
}
