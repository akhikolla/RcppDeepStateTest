function (file) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_AllPairsTripletDistance"]][[length(e[["tqdist_AllPairsTripletDistance"]]) + 
        1]] <- list(file = file)
    .Call("_Quartet_tqdist_AllPairsTripletDistance", file)
}
