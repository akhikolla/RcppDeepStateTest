function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_ham_dist"]][[length(e[["cpp_ham_dist"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_jiebaR_cpp_ham_dist", x, y)
}
