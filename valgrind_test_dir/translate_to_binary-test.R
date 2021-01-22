function (X, max_number_of_iterations) 
{
    e <- get("data.env", .GlobalEnv)
    e[["translate_to_binary"]][[length(e[["translate_to_binary"]]) + 
        1]] <- list(X = X, max_number_of_iterations = max_number_of_iterations)
    .Call("_xyz_translate_to_binary", X, max_number_of_iterations)
}
