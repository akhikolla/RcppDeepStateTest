function (xNumeric, yNumeric) 
{
    e <- get("data.env", .GlobalEnv)
    e[["VTStarWeihsEtAlRCPP"]][[length(e[["VTStarWeihsEtAlRCPP"]]) + 
        1]] <- list(xNumeric = xNumeric, yNumeric = yNumeric)
    .Call("_TauStar_VTStarWeihsEtAlRCPP", PACKAGE = "TauStar", 
        xNumeric, yNumeric)
}
