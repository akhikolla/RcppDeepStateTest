function (m, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matVecProd"]][[length(e[["matVecProd"]]) + 1]] <- list(m = m, 
        v = v)
    .Call("_PanelCount_matVecProd", PACKAGE = "PanelCount", m, 
        v)
}
