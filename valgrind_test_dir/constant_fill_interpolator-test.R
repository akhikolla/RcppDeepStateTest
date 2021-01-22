function (data, ease) 
{
    e <- get("data.env", .GlobalEnv)
    e[["constant_fill_interpolator"]][[length(e[["constant_fill_interpolator"]]) + 
        1]] <- list(data = data, ease = ease)
    .Call("_tweenr_constant_fill_interpolator", PACKAGE = "tweenr", 
        data, ease)
}
