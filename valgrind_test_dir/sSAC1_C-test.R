function (x, y, id_spec) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sSAC1_C"]][[length(e[["sSAC1_C"]]) + 1]] <- list(x = x, 
        y = y, id_spec = id_spec)
    .Call("_mobsim_sSAC1_C", x, y, id_spec)
}
