function (x, y, offset, end_x = -1, end_y = -1, arrow_offset = -1, 
    rm_intersect = 3L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calculateLinesAndArrow"]][[length(e[["calculateLinesAndArrow"]]) + 
        1]] <- list(x = x, y = y, offset = offset, end_x = end_x, 
        end_y = end_y, arrow_offset = arrow_offset, rm_intersect = rm_intersect)
    .Call("_Gmisc_calculateLinesAndArrow", PACKAGE = "Gmisc", 
        x, y, offset, end_x, end_y, arrow_offset, rm_intersect)
}
