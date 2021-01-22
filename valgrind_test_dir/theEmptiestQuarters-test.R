function (x, y, minx = 1, maxx = -1, miny = 1, maxy = -1, depth = 4L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["theEmptiestQuarters"]][[length(e[["theEmptiestQuarters"]]) + 
        1]] <- list(x = x, y = y, minx = minx, maxx = maxx, miny = miny, 
        maxy = maxy, depth = depth)
    .Call("_hutilscpp_theEmptiestQuarters", x, y, minx, maxx, 
        miny, maxy, depth)
}
