function (r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["computeNorm"]][[length(e[["computeNorm"]]) + 1]] <- list(r = r)
    .Call("_mousetrap_computeNorm", r)
}
