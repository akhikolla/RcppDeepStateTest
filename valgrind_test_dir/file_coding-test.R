function (file) 
{
    e <- get("data.env", .GlobalEnv)
    e[["file_coding"]][[length(e[["file_coding"]]) + 1]] <- list(file = file)
    .Call("_jiebaR_file_coding", file)
}
