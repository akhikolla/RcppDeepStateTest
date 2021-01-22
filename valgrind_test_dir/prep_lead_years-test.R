function (ts, lead_window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["prep_lead_years"]][[length(e[["prep_lead_years"]]) + 
        1]] <- list(ts = ts, lead_window = lead_window)
    .Call("_PanelMatch_prep_lead_years", PACKAGE = "PanelMatch", 
        ts, lead_window)
}
