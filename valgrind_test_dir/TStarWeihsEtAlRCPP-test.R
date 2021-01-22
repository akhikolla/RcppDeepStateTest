function (xNumeric, yNumeric) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TStarWeihsEtAlRCPP"]][[length(e[["TStarWeihsEtAlRCPP"]]) + 
        1]] <- list(xNumeric = xNumeric, yNumeric = yNumeric)
    .Call("_TauStar_TStarWeihsEtAlRCPP", PACKAGE = "TauStar", 
        xNumeric, yNumeric)
}
