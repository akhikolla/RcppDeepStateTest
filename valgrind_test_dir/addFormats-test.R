function (fmt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["addFormats"]][[length(e[["addFormats"]]) + 1]] <- list(fmt = fmt)
    invisible(c(".Call", "'_anytime_addFormats`", "fmt"))
}
