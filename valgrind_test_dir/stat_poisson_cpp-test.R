function (yin, yout, ein, eout, a, shape) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stat_poisson_cpp"]][[length(e[["stat_poisson_cpp"]]) + 
        1]] <- list(yin = yin, yout = yout, ein = ein, eout = eout, 
        a = a, shape = shape)
    .Call("_smerc_stat_poisson_cpp", yin, yout, ein, eout, a, 
        shape)
}
