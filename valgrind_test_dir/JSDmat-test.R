function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["JSDmat"]][[length(e[["JSDmat"]]) + 1]] <- list(A = A)
    .Call("_textmineR_JSDmat", A)
}
