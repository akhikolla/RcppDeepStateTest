function (ix, jx, ti, tj) 
{
    e <- get("data.env", .GlobalEnv)
    e[["match_ij"]][[length(e[["match_ij"]]) + 1]] <- list(ix = ix, 
        jx = jx, ti = ti, tj = tj)
    .Call("_multbxxc_match_ij", ix, jx, ti, tj)
}
