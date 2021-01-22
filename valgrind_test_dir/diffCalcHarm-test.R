function (idt, pw) 
{
    e <- get("data.env", .GlobalEnv)
    e[["diffCalcHarm"]][[length(e[["diffCalcHarm"]]) + 1]] <- list(idt = idt, 
        pw = pw)
    .Call("_diveRsity_diffCalcHarm", idt, pw)
}
