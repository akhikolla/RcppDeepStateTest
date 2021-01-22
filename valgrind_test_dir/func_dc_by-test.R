function (z, dmby, dtby) 
{
    e <- get("data.env", .GlobalEnv)
    e[["func_dc_by"]][[length(e[["func_dc_by"]]) + 1]] <- list(z = z, 
        dmby = dmby, dtby = dtby)
    .Call("_factorcpt_func_dc_by", PACKAGE = "factorcpt", z, 
        dmby, dtby)
}
