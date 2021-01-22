function (Q2, w, m, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["update1_"]][[length(e[["update1_"]]) + 1]] <- list(Q2 = Q2, 
        w = w, m = m, k = k)
    .Call("_selectiveInference_update1_", PACKAGE = "selectiveInference", 
        Q2, w, m, k)
}
