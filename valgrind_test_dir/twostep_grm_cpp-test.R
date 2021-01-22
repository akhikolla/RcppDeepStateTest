function (genotype, freq, est0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["twostep_grm_cpp"]][[length(e[["twostep_grm_cpp"]]) + 
        1]] <- list(genotype = genotype, freq = freq, est0 = est0)
    .Call("_rres_twostep_grm_cpp", PACKAGE = "rres", genotype, 
        freq, est0)
}
