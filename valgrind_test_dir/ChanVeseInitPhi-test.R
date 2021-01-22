function (Width, Height) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ChanVeseInitPhi"]][[length(e[["ChanVeseInitPhi"]]) + 
        1]] <- list(Width = Width, Height = Height)
    .Call("_imagerExtra_ChanVeseInitPhi", Width, Height)
}
