function (p, q) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Hellinger_cpp"]][[length(e[["Hellinger_cpp"]]) + 1]] <- list(p = p, 
        q = q)
    .Call("_textmineR_Hellinger_cpp", p, q)
}
