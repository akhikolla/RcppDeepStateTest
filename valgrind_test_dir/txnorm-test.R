function (pi, mu, sd, ex) 
{
    e <- get("data.env", .GlobalEnv)
    e[["txnorm"]][[length(e[["txnorm"]]) + 1]] <- list(pi = pi, 
        mu = mu, sd = sd, ex = ex)
    .Call("_mixR_txnorm", pi, mu, sd, ex)
}
