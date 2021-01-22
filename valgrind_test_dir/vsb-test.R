function (probs, ys, xs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vsb"]][[length(e[["vsb"]]) + 1]] <- list(probs = probs, 
        ys = ys, xs = xs)
    .Call("_BalancedSampling_vsb", PACKAGE = "BalancedSampling", 
        probs, ys, xs)
}
