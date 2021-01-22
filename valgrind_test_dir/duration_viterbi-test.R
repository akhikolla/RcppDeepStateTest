function (aa_sample, pipar, tpmpar, od, params) 
{
    e <- get("data.env", .GlobalEnv)
    e[["duration_viterbi"]][[length(e[["duration_viterbi"]]) + 
        1]] <- list(aa_sample = aa_sample, pipar = pipar, tpmpar = tpmpar, 
        od = od, params = params)
    .Call("_signalHsmm_duration_viterbi", PACKAGE = "signalHsmm", 
        aa_sample, pipar, tpmpar, od, params)
}
