function (id, time) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_find_duplicates"]][[length(e[["cpp_find_duplicates"]]) + 
        1]] <- list(id = id, time = time)
    .Call("_fixest_cpp_find_duplicates", id, time)
}
