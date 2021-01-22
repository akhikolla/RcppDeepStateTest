function (probabilities, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sample_int_replace"]][[length(e[["sample_int_replace"]]) + 
        1]] <- list(probabilities = probabilities, n = n)
    .Call("_xyz_sample_int_replace", probabilities, n)
}
