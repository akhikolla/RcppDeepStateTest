function (predictions) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc_rowsums"]][[length(e[["calc_rowsums"]]) + 1]] <- list(predictions = predictions)
    .Call("_bartBMA_calc_rowsums", predictions)
}
