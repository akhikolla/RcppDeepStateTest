function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["minpowspeed_cpp"]][[length(e[["minpowspeed_cpp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
