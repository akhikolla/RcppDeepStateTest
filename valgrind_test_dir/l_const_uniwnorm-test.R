function (k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["l_const_uniwnorm"]][[length(e[["l_const_uniwnorm"]]) + 
        1]] <- list(k = k)
    .Call("_BAMBI_l_const_uniwnorm", k)
}
