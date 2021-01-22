function (y, Inv_Cov_Y, Command) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Node_cost"]][[length(e[["Node_cost"]]) + 1]] <- list(y = y, 
        Inv_Cov_Y = Inv_Cov_Y, Command = Command)
    .Call("_MultivariateRandomForest_Node_cost", y, Inv_Cov_Y, 
        Command)
}
