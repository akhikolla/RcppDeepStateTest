function (from, to, at, ease) 
{
    e <- get("data.env", .GlobalEnv)
    e[["numeric_at_interpolator"]][[length(e[["numeric_at_interpolator"]]) + 
        1]] <- list(from = from, to = to, at = at, ease = ease)
    .Call("_tweenr_numeric_at_interpolator", PACKAGE = "tweenr", 
        from, to, at, ease)
}
