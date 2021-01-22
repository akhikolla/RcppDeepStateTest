function (julianDay, millisecond) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_epic_time_to_ymdhms"]][[length(e[["do_epic_time_to_ymdhms"]]) + 
        1]] <- list(julianDay = julianDay, millisecond = millisecond)
    .Call("_oce_do_epic_time_to_ymdhms", julianDay, millisecond)
}
