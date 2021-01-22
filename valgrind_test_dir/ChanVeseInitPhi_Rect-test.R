function (Width, Height, rect) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ChanVeseInitPhi_Rect"]][[length(e[["ChanVeseInitPhi_Rect"]]) + 
        1]] <- list(Width = Width, Height = Height, rect = rect)
    .Call("_imagerExtra_ChanVeseInitPhi_Rect", Width, Height, 
        rect)
}
