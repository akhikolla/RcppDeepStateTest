function (inset_scores, outset_scores, expression_value) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gseaPermutation"]][[length(e[["gseaPermutation"]]) + 
        1]] <- list(inset_scores = inset_scores, outset_scores = outset_scores, 
        expression_value = expression_value)
    .Call("_WebGestaltR_gseaPermutation", PACKAGE = "WebGestaltR", 
        inset_scores, outset_scores, expression_value)
}
