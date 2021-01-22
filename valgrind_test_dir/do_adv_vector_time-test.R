function (vvdStart, vsdStart, vsdTime, vvdhStart, vvdhTime, n, 
    f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_adv_vector_time"]][[length(e[["do_adv_vector_time"]]) + 
        1]] <- list(vvdStart = vvdStart, vsdStart = vsdStart, 
        vsdTime = vsdTime, vvdhStart = vvdhStart, vvdhTime = vvdhTime, 
        n = n, f = f)
    .Call("_oce_do_adv_vector_time", vvdStart, vsdStart, vsdTime, 
        vvdhStart, vvdhTime, n, f)
}
