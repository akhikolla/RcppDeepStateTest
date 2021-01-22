function (v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sorted"]][[length(e[["sorted"]]) + 1]] <- list(v = v)
    .Call("_superml_sorted", PACKAGE = "superml", v)
}
