function (target, candidate, ratio) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_match"]][[length(e[["c_match"]]) + 1]] <- list(target = target, 
        candidate = candidate, ratio = ratio)
    .Call("_psrwe_c_match", target, candidate, ratio)
}
