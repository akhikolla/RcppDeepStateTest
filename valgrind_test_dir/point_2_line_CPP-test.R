function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["point_2_line_CPP"]][[length(e[["point_2_line_CPP"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_windfarmGA_point_2_line_CPP", x, y)
}
