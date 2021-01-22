function (z, x_init, A, B, Sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tvARMAcpp"]][[length(e[["tvARMAcpp"]]) + 1]] <- list(z = z, 
        x_init = x_init, A = A, B = B, Sigma = Sigma)
    .Call("_forecastSNSTS_tvARMAcpp", PACKAGE = "forecastSNSTS", 
        z, x_init, A, B, Sigma)
}
