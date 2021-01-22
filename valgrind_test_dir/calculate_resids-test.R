function (predictions, response) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calculate_resids"]][[length(e[["calculate_resids"]]) + 
        1]] <- list(predictions = predictions, response = response)
    .Call("_bartBMA_calculate_resids", predictions, response)
}
