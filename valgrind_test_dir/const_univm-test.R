function (k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_univm"]][[length(e[["const_univm"]]) + 1]] <- list(k = k)
    .Call("_BAMBI_const_univm", k)
}
