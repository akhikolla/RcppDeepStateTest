function (alpha2, linvec2, Phibig2, tUeach2, Ueach2, Tmat2, Phidoublebig2, 
    Udoubleeach2, XW2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IntegrMultiCpp"]][[length(e[["IntegrMultiCpp"]]) + 1]] <- list(alpha2 = alpha2, 
        linvec2 = linvec2, Phibig2 = Phibig2, tUeach2 = tUeach2, 
        Ueach2 = Ueach2, Tmat2 = Tmat2, Phidoublebig2 = Phidoublebig2, 
        Udoubleeach2 = Udoubleeach2, XW2 = XW2)
    .Call("_PenCoxFrail_IntegrMultiCpp", PACKAGE = "PenCoxFrail", 
        alpha2, linvec2, Phibig2, tUeach2, Ueach2, Tmat2, Phidoublebig2, 
        Udoubleeach2, XW2)
}
