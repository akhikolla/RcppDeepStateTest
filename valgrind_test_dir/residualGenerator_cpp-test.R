function (RN_res, parCor1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["residualGenerator_cpp"]][[length(e[["residualGenerator_cpp"]]) + 
        1]] <- list(RN_res = RN_res, parCor1 = parCor1)
    .Call("_foreSIGHT_residualGenerator_cpp", RN_res, parCor1)
}
