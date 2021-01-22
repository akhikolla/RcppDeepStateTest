function (x, fx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["integrate"]][[length(e[["integrate"]]) + 1]] <- list(x = x, 
        fx = fx)
    .Call("_irt_integrate", x, fx)
}
