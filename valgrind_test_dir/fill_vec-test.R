function (read_vec, read_indices) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fill_vec"]][[length(e[["fill_vec"]]) + 1]] <- list(read_vec = read_vec, 
        read_indices = read_indices)
    .Call("_immunarch_fill_vec", read_vec, read_indices)
}
