function (imax, jumps = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["backtrace_c"]][[length(e[["backtrace_c"]]) + 1]] <- list(imax = imax, 
        jumps = jumps)
    .Call("_dpseg_backtrace_c", PACKAGE = "dpseg", imax, jumps)
}
