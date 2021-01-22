function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_op2M"]][[length(e[["do_op2M"]]) + 1]] <- list(x = x)
    .Call("_hutilscpp_do_op2M", x)
}
