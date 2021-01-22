function (file1, file2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_TripletDistance"]][[length(e[["tqdist_TripletDistance"]]) + 
        1]] <- list(file1 = file1, file2 = file2)
    .Call("_Quartet_tqdist_TripletDistance", file1, file2)
}
