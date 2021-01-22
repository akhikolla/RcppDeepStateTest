function (t, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_s_h"]][[length(e[["c_s_h"]]) + 1]] <- list(t = t, h = h)
    .Call("_cgAUC_c_s_h", PACKAGE = "cgAUC", t, h)
}
