function (probmatrix) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matMultinom"]][[length(e[["matMultinom"]]) + 1]] <- list(probmatrix = probmatrix)
    .Call("_simstudy_matMultinom", probmatrix)
}
