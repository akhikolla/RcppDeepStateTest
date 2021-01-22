function (a, b, c, d, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scale_response"]][[length(e[["scale_response"]]) + 1]] <- list(a = a, 
        b = b, c = c, d = d, y = y)
    .Call("_bartBMA_scale_response", a, b, c, d, y)
}
