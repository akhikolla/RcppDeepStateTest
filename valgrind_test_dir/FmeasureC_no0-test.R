function (pred, ref) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FmeasureC_no0"]][[length(e[["FmeasureC_no0"]]) + 1]] <- list(pred = pred, 
        ref = ref)
    .Call("_cytometree_FmeasureC_no0", pred, ref)
}
