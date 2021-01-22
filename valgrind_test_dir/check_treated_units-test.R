function (compmat, compmat_row_units, compmat_cols, lead, treated_ids, 
    treated_ts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["check_treated_units"]][[length(e[["check_treated_units"]]) + 
        1]] <- list(compmat = compmat, compmat_row_units = compmat_row_units, 
        compmat_cols = compmat_cols, lead = lead, treated_ids = treated_ids, 
        treated_ts = treated_ts)
    .Call("_PanelMatch_check_treated_units", PACKAGE = "PanelMatch", 
        compmat, compmat_row_units, compmat_cols, lead, treated_ids, 
        treated_ts)
}
