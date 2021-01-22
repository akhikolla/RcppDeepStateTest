function (y, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["factor_to_dummy_cpp"]][[length(e[["factor_to_dummy_cpp"]]) + 
        1]] <- list(y = y, c = c)
    .Call("_RSSL_factor_to_dummy_cpp", y, c)
}
