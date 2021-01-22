function (DAT, DATRESP, LATRESP, GUESS, SLIP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_din_deterministic_devcrit"]][[length(e[["cdm_rcpp_din_deterministic_devcrit"]]) + 
        1]] <- list(DAT = DAT, DATRESP = DATRESP, LATRESP = LATRESP, 
        GUESS = GUESS, SLIP = SLIP)
    .Call("_CDM_cdm_rcpp_din_deterministic_devcrit", PACKAGE = "CDM", 
        DAT, DATRESP, LATRESP, GUESS, SLIP)
}
