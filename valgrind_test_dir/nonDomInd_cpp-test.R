function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nonDomInd_cpp"]][[length(e[["nonDomInd_cpp"]]) + 1]] <- list(mat = mat)
    .Call("_GPareto_nonDomInd_cpp", mat)
}
