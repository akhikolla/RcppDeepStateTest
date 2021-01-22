function (D1, D2, PROSUM, schema, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_STEP_2_2_WEIGHTS_ADA_KMEANS"]][[length(e[["c_STEP_2_2_WEIGHTS_ADA_KMEANS"]]) + 
        1]] <- list(D1 = D1, D2 = D2, PROSUM = PROSUM, schema = schema, 
        theta = theta)
    .Call("_HistDAWass_c_STEP_2_2_WEIGHTS_ADA_KMEANS", PACKAGE = "HistDAWass", 
        D1, D2, PROSUM, schema, theta)
}
