function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["habConnRcpp"]][[length(e[["habConnRcpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
