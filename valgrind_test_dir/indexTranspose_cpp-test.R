function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["indexTranspose_cpp"]][[length(e[["indexTranspose_cpp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
