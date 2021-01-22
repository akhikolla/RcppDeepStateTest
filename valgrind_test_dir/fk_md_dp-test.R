function (xo, y, x_eval, h, betas, al, C) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fk_md_dp"]][[length(e[["fk_md_dp"]]) + 1]] <- list(xo = xo, 
        y = y, x_eval = x_eval, h = h, betas = betas, al = al, 
        C = C)
    .Call("_FKSUM_fk_md_dp", xo, y, x_eval, h, betas, al, C)
}
