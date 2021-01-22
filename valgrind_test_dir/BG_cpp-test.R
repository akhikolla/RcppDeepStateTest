function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BG_cpp"]][[length(e[["BG_cpp"]]) + 1]] <- list(A = A)
    .Call("_expperm_BG_cpp", A)
}
