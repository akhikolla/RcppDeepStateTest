function (Wtriplet, Wtripletsum, n_triplet, nsites, phi, theta, 
    rho) 
{
    e <- get("data.env", .GlobalEnv)
    e[["quadform"]][[length(e[["quadform"]]) + 1]] <- list(Wtriplet = Wtriplet, 
        Wtripletsum = Wtripletsum, n_triplet = n_triplet, nsites = nsites, 
        phi = phi, theta = theta, rho = rho)
    .Call("_CARBayes_quadform", Wtriplet, Wtripletsum, n_triplet, 
        nsites, phi, theta, rho)
}
