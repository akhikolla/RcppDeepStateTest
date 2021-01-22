function (beta, Y, DataM, DataM0, DataM1, phat, qhat, weight, 
    offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scoreprobitcpp"]][[length(e[["scoreprobitcpp"]]) + 1]] <- list(beta = beta, 
        Y = Y, DataM = DataM, DataM0 = DataM0, DataM1 = DataM1, 
        phat = phat, qhat = qhat, weight = weight, offset = offset)
    .Call("_augSIMEX_scoreprobitcpp", PACKAGE = "augSIMEX", beta, 
        Y, DataM, DataM0, DataM1, phat, qhat, weight, offset)
}
