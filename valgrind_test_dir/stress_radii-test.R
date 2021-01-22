function (y, W, D, r, tseq) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stress_radii"]][[length(e[["stress_radii"]]) + 1]] <- list(y = y, 
        W = W, D = D, r = r, tseq = tseq)
    .Call("_graphlayouts_stress_radii", y, W, D, r, tseq)
}
