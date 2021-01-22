function (data, group, frame, ease) 
{
    e <- get("data.env", .GlobalEnv)
    e[["constant_element_interpolator"]][[length(e[["constant_element_interpolator"]]) + 
        1]] <- list(data = data, group = group, frame = frame, 
        ease = ease)
    .Call("_tweenr_constant_element_interpolator", PACKAGE = "tweenr", 
        data, group, frame, ease)
}
