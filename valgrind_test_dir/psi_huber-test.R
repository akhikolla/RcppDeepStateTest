function (x, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["psi_huber"]][[length(e[["psi_huber"]]) + 1]] <- list(x = x, 
        c = c)
    .Call("_robustBLME_psi_huber", x, c)
}
