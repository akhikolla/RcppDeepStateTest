function (x, y, minx = 1, maxx = -1, miny = 1, maxy = -1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EmptiestQuarter"]][[length(e[["EmptiestQuarter"]]) + 
        1]] <- list(x = x, y = y, minx = minx, maxx = maxx, miny = miny, 
        maxy = maxy)
    .Call("_hutilscpp_EmptiestQuarter", x, y, minx, maxx, miny, 
        maxy)
}
