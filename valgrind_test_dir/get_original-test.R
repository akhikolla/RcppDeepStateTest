function (low, high, sp_low, sp_high, sum_preds) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_original"]][[length(e[["get_original"]]) + 1]] <- list(low = low, 
        high = high, sp_low = sp_low, sp_high = sp_high, sum_preds = sum_preds)
    .Call("_bartBMA_get_original", low, high, sp_low, sp_high, 
        sum_preds)
}
