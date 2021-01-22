function (theta1, b_ii, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_gpcm_prob_one_item_one_person"]][[length(e[["immer_gpcm_prob_one_item_one_person"]]) + 
        1]] <- list(theta1 = theta1, b_ii = b_ii, a = a)
    .Call("_immer_immer_gpcm_prob_one_item_one_person", PACKAGE = "immer", 
        theta1, b_ii, a)
}
