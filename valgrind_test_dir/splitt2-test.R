function (X, Y, m_feature, Index, Inv_Cov_Y, Command, ff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitt2"]][[length(e[["splitt2"]]) + 1]] <- list(X = X, 
        Y = Y, m_feature = m_feature, Index = Index, Inv_Cov_Y = Inv_Cov_Y, 
        Command = Command, ff = ff)
    .Call("_MultivariateRandomForest_splitt2", X, Y, m_feature, 
        Index, Inv_Cov_Y, Command, ff)
}
