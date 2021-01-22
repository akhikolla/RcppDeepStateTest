function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["convert_from_excel_ref"]][[length(e[["convert_from_excel_ref"]]) + 
        1]] <- list(x = x)
    .Call("_openxlsx_convert_from_excel_ref", x)
}
