function (log_wt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["residualResampling"]][[length(e[["residualResampling"]]) + 
        1]] <- list(log_wt = log_wt)
    .Call("_serrsBayes_residualResampling", PACKAGE = "serrsBayes", 
        log_wt)
}
