function (x, cip) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hmodeci"]][[length(e[["hmodeci"]]) + 1]] <- list(x = x, 
        cip = cip)
    .Call("_waspr_hmodeci", x, cip)
}
