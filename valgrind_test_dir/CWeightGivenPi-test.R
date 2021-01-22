function (r1, r2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CWeightGivenPi"]][[length(e[["CWeightGivenPi"]]) + 1]] <- list(r1 = r1, 
        r2 = r2)
    .Call("_rankdist_CWeightGivenPi", r1, r2)
}
