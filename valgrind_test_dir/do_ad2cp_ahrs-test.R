function (v, ahrs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_ad2cp_ahrs"]][[length(e[["do_ad2cp_ahrs"]]) + 1]] <- list(v = v, 
        ahrs = ahrs)
    .Call("_oce_do_ad2cp_ahrs", v, ahrs)
}
