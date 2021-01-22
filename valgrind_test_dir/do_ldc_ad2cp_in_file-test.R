function (filename, from, to, by) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_ldc_ad2cp_in_file"]][[length(e[["do_ldc_ad2cp_in_file"]]) + 
        1]] <- list(filename = filename, from = from, to = to, 
        by = by)
    .Call("_oce_do_ldc_ad2cp_in_file", filename, from, to, by)
}
