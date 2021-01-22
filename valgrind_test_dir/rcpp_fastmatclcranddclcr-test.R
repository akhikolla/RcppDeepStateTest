function (I, w, MSEmat, dMSEmat, S, dS, maxlevel, numpara) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_fastmatclcranddclcr"]][[length(e[["rcpp_fastmatclcranddclcr"]]) + 
        1]] <- list(I = I, w = w, MSEmat = MSEmat, dMSEmat = dMSEmat, 
        S = S, dS = dS, maxlevel = maxlevel, numpara = numpara)
    invisible(c(".Call", "_CGGP_rcpp_fastmatclcranddclcr", "CGGP", 
    "I", "w", "MSEmat", "dMSEmat", "S", "dS", "maxlevel", "numpara"
    ))
}
