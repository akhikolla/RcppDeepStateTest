function (seq1, seq2, upper_limit) 
{
    e <- get("data.env", .GlobalEnv)
    e[["early_abandoned_dist"]][[length(e[["early_abandoned_dist"]]) + 
        1]] <- list(seq1 = seq1, seq2 = seq2, upper_limit = upper_limit)
    .Call("_jmotif_early_abandoned_dist", PACKAGE = "jmotif", 
        seq1, seq2, upper_limit)
}
