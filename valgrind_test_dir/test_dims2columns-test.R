function (cpt, class_var, columns_db) 
{
    e <- get("data.env", .GlobalEnv)
    e[["test_dims2columns"]][[length(e[["test_dims2columns"]]) + 
        1]] <- list(cpt = cpt, class_var = class_var, columns_db = columns_db)
    .Call("_bnclassify_test_dims2columns", PACKAGE = "bnclassify", 
        cpt, class_var, columns_db)
}
