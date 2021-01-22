function (k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_uniwnorm"]][[length(e[["const_uniwnorm"]]) + 1]] <- list(k = k)
    .Call("_BAMBI_const_uniwnorm", k)
}
