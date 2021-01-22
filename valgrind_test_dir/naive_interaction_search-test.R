function (X, Y, max_number_of_pairs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["naive_interaction_search"]][[length(e[["naive_interaction_search"]]) + 
        1]] <- list(X = X, Y = Y, max_number_of_pairs = max_number_of_pairs)
    .Call("_xyz_naive_interaction_search", X, Y, max_number_of_pairs)
}
