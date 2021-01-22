function (s, Theta, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Hvec"]][[length(e[["Hvec"]]) + 1]] <- list(s = s, Theta = Theta, 
        N = N)
    .Call("_IsingSampler_Hvec", PACKAGE = "IsingSampler", s, 
        Theta, N)
}
