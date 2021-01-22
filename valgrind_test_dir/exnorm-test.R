function (data, mu, sd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["exnorm"]][[length(e[["exnorm"]]) + 1]] <- list(data = data, 
        mu = mu, sd = sd)
    .Call("_mixR_exnorm", data, mu, sd)
}
