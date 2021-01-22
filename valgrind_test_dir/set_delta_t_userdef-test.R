function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_delta_t_userdef"]][[length(e[["set_delta_t_userdef"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
