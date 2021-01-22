function (knots, degree) 
{
    e <- get("data.env", .GlobalEnv)
    e[["makenewknots"]][[length(e[["makenewknots"]]) + 1]] <- list(knots = knots, 
        degree = degree)
    .Call("_GeDS_makenewknots", PACKAGE = "GeDS", knots, degree)
}
