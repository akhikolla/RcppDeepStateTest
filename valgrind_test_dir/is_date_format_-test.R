function (formats) 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_date_format_"]][[length(e[["is_date_format_"]]) + 
        1]] <- list(formats = formats)
    .Call("_tidyxl_is_date_format_", PACKAGE = "tidyxl", formats)
}
