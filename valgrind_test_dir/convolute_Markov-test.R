function (time_vector, diff_vector, probtrans_vector_1, probtrans_vector_2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["convolute_Markov"]][[length(e[["convolute_Markov"]]) + 
        1]] <- list(time_vector = time_vector, diff_vector = diff_vector, 
        probtrans_vector_1 = probtrans_vector_1, probtrans_vector_2 = probtrans_vector_2)
    .Call("_ebmstate_convolute_Markov", time_vector, diff_vector, 
        probtrans_vector_1, probtrans_vector_2)
}
