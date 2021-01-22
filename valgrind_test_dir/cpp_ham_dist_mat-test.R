function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_ham_dist_mat"]][[length(e[["cpp_ham_dist_mat"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_jiebaR_cpp_ham_dist_mat", x, y)
}
