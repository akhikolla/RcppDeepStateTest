function (x, pos, lgth) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rowsum_vec"]][[length(e[["rowsum_vec"]]) + 1]] <- list(x = x, 
        pos = pos, lgth = lgth)
    .Call("_frailtyEM_rowsum_vec", x, pos, lgth)
}
