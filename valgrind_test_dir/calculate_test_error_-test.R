function (vardep, predicted_class_int) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calculate_test_error_"]][[length(e[["calculate_test_error_"]]) + 
        1]] <- list(vardep = vardep, predicted_class_int = predicted_class_int)
    .Call("_fastAdaboost_calculate_test_error_", PACKAGE = "fastAdaboost", 
        vardep, predicted_class_int)
}
