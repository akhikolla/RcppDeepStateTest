function (M = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["test_intersect3_stdint"]][[length(e[["test_intersect3_stdint"]]) + 
        1]] <- list(M = M)
    .Call("_hutilscpp_test_intersect3_stdint", M)
}
