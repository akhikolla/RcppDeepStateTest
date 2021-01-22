function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vecminInd"]][[length(e[["vecminInd"]]) + 1]] <- list(x = x)
    .Call("_Rvoterdistance_vecminInd", x)
}
