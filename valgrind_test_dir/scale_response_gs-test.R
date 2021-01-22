function (a, b, c, d, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scale_response_gs"]][[length(e[["scale_response_gs"]]) + 
        1]] <- list(a = a, b = b, c = c, d = d, y = y)
    .Call("_bartBMA_scale_response_gs", a, b, c, d, y)
}
