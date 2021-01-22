function (data, ease) 
{
    e <- get("data.env", .GlobalEnv)
    e[["numeric_fill_interpolator"]][[length(e[["numeric_fill_interpolator"]]) + 
        1]] <- list(data = data, ease = ease)
    .Call("_tweenr_numeric_fill_interpolator", PACKAGE = "tweenr", 
        data, ease)
}
