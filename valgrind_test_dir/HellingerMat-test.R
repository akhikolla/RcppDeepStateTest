function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HellingerMat"]][[length(e[["HellingerMat"]]) + 1]] <- list(A = A)
    .Call("_textmineR_HellingerMat", A)
}
