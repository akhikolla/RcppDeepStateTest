function (theta, a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Pr_2PL"]][[length(e[["Pr_2PL"]]) + 1]] <- list(theta = theta, 
        a = a, b = b)
    .Call("_GDINA_Pr_2PL", PACKAGE = "GDINA", theta, a, b)
}
