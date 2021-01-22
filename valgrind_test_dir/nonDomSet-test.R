function (points, ref) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nonDomSet"]][[length(e[["nonDomSet"]]) + 1]] <- list(points = points, 
        ref = ref)
    .Call("_GPareto_nonDomSet", points, ref)
}
