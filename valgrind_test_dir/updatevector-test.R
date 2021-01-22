function (vector, update, length) 
{
    e <- get("data.env", .GlobalEnv)
    e[["updatevector"]][[length(e[["updatevector"]]) + 1]] <- list(vector = vector, 
        update = update, length = length)
    invisible(c(".Call", "_flam_updatevector", "flam", "vector", 
    "update", "length"))
}
