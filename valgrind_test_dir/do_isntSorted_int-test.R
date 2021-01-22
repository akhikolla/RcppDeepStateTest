function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_isntSorted_int"]][[length(e[["do_isntSorted_int"]]) + 
        1]] <- list(x = x)
    .Call("_hutilscpp_do_isntSorted_int", x)
}
