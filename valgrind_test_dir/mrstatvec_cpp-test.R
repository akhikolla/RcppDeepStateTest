function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrstatvec_cpp"]][[length(e[["mrstatvec_cpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
