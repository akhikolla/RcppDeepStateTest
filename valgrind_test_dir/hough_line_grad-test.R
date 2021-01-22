function (im, ntheta, alpha = 1.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hough_line_grad"]][[length(e[["hough_line_grad"]]) + 
        1]] <- list(im = im, ntheta = ntheta, alpha = alpha)
    .Call("_imager_hough_line_grad", im, ntheta, alpha)
}
