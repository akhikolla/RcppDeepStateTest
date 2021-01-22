function (left, right, elp, maxlength) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cumsum_elp"]][[length(e[["cumsum_elp"]]) + 1]] <- list(left = left, 
        right = right, elp = elp, maxlength = maxlength)
    .Call("_frailtyEM_cumsum_elp", left, right, elp, maxlength)
}
