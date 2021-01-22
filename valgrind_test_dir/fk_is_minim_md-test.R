function (x, y, x_eval, h, betas, al, C) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fk_is_minim_md"]][[length(e[["fk_is_minim_md"]]) + 1]] <- list(x = x, 
        y = y, x_eval = x_eval, h = h, betas = betas, al = al, 
        C = C)
    .Call("_FKSUM_fk_is_minim_md", x, y, x_eval, h, betas, al, 
        C)
}
