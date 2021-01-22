function (a, b, zetas, fi, ti) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BMNLLInner"]][[length(e[["BMNLLInner"]]) + 1]] <- list(a = a, 
        b = b, zetas = zetas, fi = fi, ti = ti)
    .Call("_RJafroc_BMNLLInner", PACKAGE = "RJafroc", a, b, zetas, 
        fi, ti)
}
