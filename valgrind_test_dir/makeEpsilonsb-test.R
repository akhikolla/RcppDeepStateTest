function (data, Xs, Ys, degree) 
{
    e <- get("data.env", .GlobalEnv)
    e[["makeEpsilonsb"]][[length(e[["makeEpsilonsb"]]) + 1]] <- list(data = data, 
        Xs = Xs, Ys = Ys, degree = degree)
    .Call("_GeDS_makeEpsilonsb", PACKAGE = "GeDS", data, Xs, 
        Ys, degree)
}
