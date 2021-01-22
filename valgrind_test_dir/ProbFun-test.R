function (x, v, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ProbFun"]][[length(e[["ProbFun"]]) + 1]] <- list(x = x, 
        v = v, w = w)
    .Call("_RaceID_ProbFun", x, v, w)
}
