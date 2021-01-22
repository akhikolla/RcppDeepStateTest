function (weight, response, gamma, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DoBlock"]][[length(e[["DoBlock"]]) + 1]] <- list(weight = weight, 
        response = response, gamma = gamma, lambda = lambda)
    .Call("_CatReg_DoBlock", PACKAGE = "CatReg", weight, response, 
        gamma, lambda)
}
