function (m, s, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dresscrps_cpp"]][[length(e[["dresscrps_cpp"]]) + 1]] <- list(m = m, 
        s = s, y = y)
    .Call("_SpecsVerification_dresscrps_cpp", m, s, y)
}
