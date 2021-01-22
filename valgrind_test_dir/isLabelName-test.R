function (lblToCheck, lbl) 
{
    e <- get("data.env", .GlobalEnv)
    e[["isLabelName"]][[length(e[["isLabelName"]]) + 1]] <- list(lblToCheck = lblToCheck, 
        lbl = lbl)
    .Call("_phylobase_isLabelName", lblToCheck, lbl)
}
