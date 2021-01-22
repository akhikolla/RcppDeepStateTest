function (x, lx = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calculate_transition_probabilities"]][[length(e[["calculate_transition_probabilities"]]) + 
        1]] <- list(x = x, lx = lx)
    .Call("_RTransferEntropy_calculate_transition_probabilities", 
        PACKAGE = "RTransferEntropy", x, lx)
}
