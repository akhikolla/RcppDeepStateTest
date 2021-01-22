function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ryser_cpp"]][[length(e[["ryser_cpp"]]) + 1]] <- list(A = A)
    .Call("_expperm_ryser_cpp", A)
}
