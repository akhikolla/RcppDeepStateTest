function (matrix, tree_width = 0L, proc = 1L, s = 0, n = 0L, 
    ss = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["aster_cpp"]][[length(e[["aster_cpp"]]) + 1]] <- list(matrix = matrix, 
        tree_width = tree_width, proc = proc, s = s, n = n, ss = ss)
    .Call("_BNSL_aster_cpp", matrix, tree_width, proc, s, n, 
        ss)
}
