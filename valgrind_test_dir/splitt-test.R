function (X, Y, m_feature, Index, Inv_Cov_Y, Command, ff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitt"]][[length(e[["splitt"]]) + 1]] <- list(X = X, 
        Y = Y, m_feature = m_feature, Index = Index, Inv_Cov_Y = Inv_Cov_Y, 
        Command = Command, ff = ff)
    .Call("_IntegratedMRF_splitt", X, Y, m_feature, Index, Inv_Cov_Y, 
        Command, ff)
}
