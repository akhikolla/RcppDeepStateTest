function (precision, rec, length, baserate) 
{
    e <- get("data.env", .GlobalEnv)
    e[["contingency_table"]][[length(e[["contingency_table"]]) + 
        1]] <- list(precision = precision, rec = rec, length = length, 
        baserate = baserate)
    .Call("_rhoR_contingency_table", PACKAGE = "rhoR", precision, 
        rec, length, baserate)
}
