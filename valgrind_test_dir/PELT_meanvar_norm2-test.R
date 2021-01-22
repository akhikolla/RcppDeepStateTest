function (resp, pen) 
{
    e <- get("data.env", .GlobalEnv)
    e[["PELT_meanvar_norm2"]][[length(e[["PELT_meanvar_norm2"]]) + 
        1]] <- list(resp = resp, pen = pen)
    .Call("_bartBMA_PELT_meanvar_norm2", resp, pen)
}
