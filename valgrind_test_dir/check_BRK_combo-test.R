function (BR, P, K) 
{
    e <- get("data.env", .GlobalEnv)
    e[["check_BRK_combo"]][[length(e[["check_BRK_combo"]]) + 
        1]] <- list(BR = BR, P = P, K = K)
    .Call("_rhoR_check_BRK_combo", PACKAGE = "rhoR", BR, P, K)
}
