function (x, pos, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_add_elements"]][[length(e[["immer_add_elements"]]) + 
        1]] <- list(x = x, pos = pos, h = h)
    .Call("_immer_immer_add_elements", PACKAGE = "immer", x, 
        pos, h)
}
