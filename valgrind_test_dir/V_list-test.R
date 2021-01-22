function (sig2_b, sig2_eps, ZZt_b, ZZt_b_ii, ZZt_eps, ZZt_eps_ii, 
    m_i) 
{
    e <- get("data.env", .GlobalEnv)
    e[["V_list"]][[length(e[["V_list"]]) + 1]] <- list(sig2_b = sig2_b, 
        sig2_eps = sig2_eps, ZZt_b = ZZt_b, ZZt_b_ii = ZZt_b_ii, 
        ZZt_eps = ZZt_eps, ZZt_eps_ii = ZZt_eps_ii, m_i = m_i)
    .Call("_robustBLME_V_list", sig2_b, sig2_eps, ZZt_b, ZZt_b_ii, 
        ZZt_eps, ZZt_eps_ii, m_i)
}
