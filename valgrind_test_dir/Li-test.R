function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Li"]][[length(e[["Li"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Li", data)
}
