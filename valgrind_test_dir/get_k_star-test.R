function (x_star, k_hat, G_l, G_r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_k_star"]][[length(e[["get_k_star"]]) + 1]] <- list(x_star = x_star, 
        k_hat = k_hat, G_l = G_l, G_r = G_r)
    .Call("_mosum_get_k_star", x_star, k_hat, G_l, G_r)
}
