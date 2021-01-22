function (yy, XX_aug, alpha, init) 
{
    e <- get("data.env", .GlobalEnv)
    e[["logliknormLR"]][[length(e[["logliknormLR"]]) + 1]] <- list(yy = yy, 
        XX_aug = XX_aug, alpha = alpha, init = init)
    .Call("_PWD_logliknormLR", PACKAGE = "PWD", yy, XX_aug, alpha, 
        init)
}
