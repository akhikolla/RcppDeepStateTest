function (I, w, MSEmat, S, maxlevel) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_fastmatclcr"]][[length(e[["rcpp_fastmatclcr"]]) + 
        1]] <- list(I = I, w = w, MSEmat = MSEmat, S = S, maxlevel = maxlevel)
    invisible(c(".Call", "_CGGP_rcpp_fastmatclcr", "CGGP", "I", 
    "w", "MSEmat", "S", "maxlevel"))
}
