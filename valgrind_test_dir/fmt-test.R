function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fmt"]][[length(e[["fmt"]]) + 1]] <- list(x = x)
    .Call("_anytime_fmt", x)
}
