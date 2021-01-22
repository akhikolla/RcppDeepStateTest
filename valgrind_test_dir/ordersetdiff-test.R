function (vector, remove) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ordersetdiff"]][[length(e[["ordersetdiff"]]) + 1]] <- list(vector = vector, 
        remove = remove)
    .Call("_bnclassify_ordersetdiff", PACKAGE = "bnclassify", 
        vector, remove)
}
