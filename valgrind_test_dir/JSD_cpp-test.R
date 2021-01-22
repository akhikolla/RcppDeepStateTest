function (p, q) 
{
    e <- get("data.env", .GlobalEnv)
    e[["JSD_cpp"]][[length(e[["JSD_cpp"]]) + 1]] <- list(p = p, 
        q = q)
    .Call("_textmineR_JSD_cpp", p, q)
}
