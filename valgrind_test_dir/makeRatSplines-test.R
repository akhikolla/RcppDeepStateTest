function (matrice, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["makeRatSplines"]][[length(e[["makeRatSplines"]]) + 1]] <- list(matrice = matrice, 
        h = h)
    .Call("_GeDS_makeRatSplines", PACKAGE = "GeDS", matrice, 
        h)
}
