function (seq1, seq2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["euclidean_dist"]][[length(e[["euclidean_dist"]]) + 1]] <- list(seq1 = seq1, 
        seq2 = seq2)
    .Call("_jmotif_euclidean_dist", PACKAGE = "jmotif", seq1, 
        seq2)
}
