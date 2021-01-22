function (v1, v2, sec) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bmat2C"]][[length(e[["bmat2C"]]) + 1]] <- list(v1 = v1, 
        v2 = v2, sec = sec)
    .Call("_rlme_bmat2C", PACKAGE = "rlme", v1, v2, sec)
}
