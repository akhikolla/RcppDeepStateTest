function (pastSenderTimes, xlog, currentTime, weightvar) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightTimesSummationCpp"]][[length(e[["weightTimesSummationCpp"]]) + 
        1]] <- list(pastSenderTimes = pastSenderTimes, xlog = xlog, 
        currentTime = currentTime, weightvar = weightvar)
    .Call("_rem_weightTimesSummationCpp", pastSenderTimes, xlog, 
        currentTime, weightvar)
}
