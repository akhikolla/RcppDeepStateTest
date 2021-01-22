function (x, y, x_eval, h, betas, al, C) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fk_md_b"]][[length(e[["fk_md_b"]]) + 1]] <- list(x = x, 
        y = y, x_eval = x_eval, h = h, betas = betas, al = al, 
        C = C)
    .Call("_FKSUM_fk_md_b", x, y, x_eval, h, betas, al, C)
}
