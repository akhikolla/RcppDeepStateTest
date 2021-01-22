function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["dfdrseg_cpp"]][[length(e[["dfdrseg_cpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
