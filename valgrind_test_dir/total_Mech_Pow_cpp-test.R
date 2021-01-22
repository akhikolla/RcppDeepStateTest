function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["total_Mech_Pow_cpp"]][[length(e[["total_Mech_Pow_cpp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
