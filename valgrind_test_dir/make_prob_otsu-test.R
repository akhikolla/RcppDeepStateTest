function (ordered, bins, intervalnumber, width, height) 
{
    e <- get("data.env", .GlobalEnv)
    e[["make_prob_otsu"]][[length(e[["make_prob_otsu"]]) + 1]] <- list(ordered = ordered, 
        bins = bins, intervalnumber = intervalnumber, width = width, 
        height = height)
    .Call("_imagerExtra_make_prob_otsu", ordered, bins, intervalnumber, 
        width, height)
}
