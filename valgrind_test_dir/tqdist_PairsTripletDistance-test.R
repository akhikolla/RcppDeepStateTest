function (file1, file2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_PairsTripletDistance"]][[length(e[["tqdist_PairsTripletDistance"]]) + 
        1]] <- list(file1 = file1, file2 = file2)
    .Call("_Quartet_tqdist_PairsTripletDistance", file1, file2)
}
