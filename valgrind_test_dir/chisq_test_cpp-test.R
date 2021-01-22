function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["chisq_test_cpp"]][[length(e[["chisq_test_cpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
