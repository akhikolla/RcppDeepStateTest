function (probs, rn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["subimmer_sample_prob_index"]][[length(e[["subimmer_sample_prob_index"]]) + 
        1]] <- list(probs = probs, rn = rn)
    .Call("_immer_subimmer_sample_prob_index", PACKAGE = "immer", 
        probs, rn)
}
