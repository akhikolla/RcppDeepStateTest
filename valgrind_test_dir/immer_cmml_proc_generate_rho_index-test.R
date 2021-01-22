function (I) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_cmml_proc_generate_rho_index"]][[length(e[["immer_cmml_proc_generate_rho_index"]]) + 
        1]] <- list(I = I)
    .Call("_immer_immer_cmml_proc_generate_rho_index", PACKAGE = "immer", 
        I)
}
