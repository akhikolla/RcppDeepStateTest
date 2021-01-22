function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sign_cpp"]][[length(e[["sign_cpp"]]) + 1]] <- list(x = x)
    .Call("_WinRatio_sign_cpp", x)
}
