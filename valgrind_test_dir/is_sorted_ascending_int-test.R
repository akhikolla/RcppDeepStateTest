function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_sorted_ascending_int"]][[length(e[["is_sorted_ascending_int"]]) + 
        1]] <- list(x = x)
    .Call("_hutilscpp_is_sorted_ascending_int", x)
}
