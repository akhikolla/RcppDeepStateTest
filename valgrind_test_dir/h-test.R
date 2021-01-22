function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["h"]][[length(e[["h"]]) + 1]] <- list()
    list(NULL, character(0))
}
