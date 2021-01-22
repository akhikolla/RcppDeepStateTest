function (y, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["atan2_north_cpp"]][[length(e[["atan2_north_cpp"]]) + 
        1]] <- list(y = y, x = x)
    .Call("_amt_atan2_north_cpp", PACKAGE = "amt", y, x)
}
