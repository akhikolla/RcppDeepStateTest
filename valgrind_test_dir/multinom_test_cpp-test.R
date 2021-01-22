function (x, p, theta = 1e-04) 
{
    e <- get("data.env", .GlobalEnv)
    e[["multinom_test_cpp"]][[length(e[["multinom_test_cpp"]]) + 
        1]] <- list(x = x, p = p, theta = theta)
    .Call("_ExactMultinom_multinom_test_cpp", x, p, theta)
}
