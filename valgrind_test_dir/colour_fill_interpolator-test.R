function (data, ease) 
{
    e <- get("data.env", .GlobalEnv)
    e[["colour_fill_interpolator"]][[length(e[["colour_fill_interpolator"]]) + 
        1]] <- list(data = data, ease = ease)
    .Call("_tweenr_colour_fill_interpolator", PACKAGE = "tweenr", 
        data, ease)
}
