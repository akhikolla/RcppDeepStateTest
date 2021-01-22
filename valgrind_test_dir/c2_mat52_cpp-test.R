function (x, t, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c2_mat52_cpp"]][[length(e[["c2_mat52_cpp"]]) + 1]] <- list(x = x, 
        t = t, w = w)
    .Call("_hetGP_c2_mat52_cpp", PACKAGE = "hetGP", x, t, w)
}
