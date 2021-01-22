function (n_points, n_mother_points, sigma, mu, xmin = 0, xmax = 1, 
    ymin = 0, ymax = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rThomas_rcpp"]][[length(e[["rThomas_rcpp"]]) + 1]] <- list(n_points = n_points, 
        n_mother_points = n_mother_points, sigma = sigma, mu = mu, 
        xmin = xmin, xmax = xmax, ymin = ymin, ymax = ymax)
    .Call("_mobsim_rThomas_rcpp", n_points, n_mother_points, 
        sigma, mu, xmin, xmax, ymin, ymax)
}
