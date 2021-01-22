function (file1, file2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_QuartetDistance"]][[length(e[["tqdist_QuartetDistance"]]) + 
        1]] <- list(file1 = file1, file2 = file2)
    .Call("_Quartet_tqdist_QuartetDistance", file1, file2)
}
