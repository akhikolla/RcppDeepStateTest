function (x, y, x_eval, h, betas, Counts = numeric(0)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kndksum"]][[length(e[["kndksum"]]) + 1]] <- list(x = x, 
        y = y, x_eval = x_eval, h = h, betas = betas, Counts = Counts)
    .Call("_FKSUM_kndksum", x, y, x_eval, h, betas, Counts)
}
