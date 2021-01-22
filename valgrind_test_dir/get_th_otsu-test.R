function (prob_otsu, bins) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_th_otsu"]][[length(e[["get_th_otsu"]]) + 1]] <- list(prob_otsu = prob_otsu, 
        bins = bins)
    .Call("_imagerExtra_get_th_otsu", prob_otsu, bins)
}
