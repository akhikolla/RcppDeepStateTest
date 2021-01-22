function (nfeats) 
{
    e <- get("data.env", .GlobalEnv)
    e[["labRcpp"]][[length(e[["labRcpp"]]) + 1]] <- list(nfeats = nfeats)
    .Call("_propr_labRcpp", nfeats)
}
