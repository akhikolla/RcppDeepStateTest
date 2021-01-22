function (pred, ref) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FmeasureC"]][[length(e[["FmeasureC"]]) + 1]] <- list(pred = pred, 
        ref = ref)
    .Call("_cytometree_FmeasureC", pred, ref)
}
