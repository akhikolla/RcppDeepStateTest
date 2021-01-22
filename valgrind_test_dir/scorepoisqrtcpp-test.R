function (beta, Y, DataM, DataM0, DataM1, phat, qhat, weight, 
    offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scorepoisqrtcpp"]][[length(e[["scorepoisqrtcpp"]]) + 
        1]] <- list(beta = beta, Y = Y, DataM = DataM, DataM0 = DataM0, 
        DataM1 = DataM1, phat = phat, qhat = qhat, weight = weight, 
        offset = offset)
    .Call("_augSIMEX_scorepoisqrtcpp", PACKAGE = "augSIMEX", 
        beta, Y, DataM, DataM0, DataM1, phat, qhat, weight, offset)
}
