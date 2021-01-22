function (N, m, M, alpha, H) 
{
    e <- get("data.env", .GlobalEnv)
    e[["a_tilda_cpp"]][[length(e[["a_tilda_cpp"]]) + 1]] <- list(N = N, 
        m = m, M = M, alpha = alpha, H = H)
    .Call("_rlfsm_a_tilda_cpp", N, m, M, alpha, H)
}
