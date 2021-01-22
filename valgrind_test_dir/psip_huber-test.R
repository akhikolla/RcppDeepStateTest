function (x, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["psip_huber"]][[length(e[["psip_huber"]]) + 1]] <- list(x = x, 
        c = c)
    .Call("_robustBLME_psip_huber", x, c)
}
