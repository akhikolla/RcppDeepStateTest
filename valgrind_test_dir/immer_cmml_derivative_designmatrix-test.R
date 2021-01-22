function (probs_der_par, W_par, par, do_log) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_cmml_derivative_designmatrix"]][[length(e[["immer_cmml_derivative_designmatrix"]]) + 
        1]] <- list(probs_der_par = probs_der_par, W_par = W_par, 
        par = par, do_log = do_log)
    .Call("_immer_immer_cmml_derivative_designmatrix", PACKAGE = "immer", 
        probs_der_par, W_par, par, do_log)
}
