function (x, y, x_eval, h, betas, Counts = numeric(1)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dksum"]][[length(e[["dksum"]]) + 1]] <- list(x = x, y = y, 
        x_eval = x_eval, h = h, betas = betas, Counts = Counts)
    .Call("_FKSUM_dksum", x, y, x_eval, h, betas, Counts)
}
