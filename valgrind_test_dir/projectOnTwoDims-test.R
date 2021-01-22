function (a, b, p, f, kern, dims, data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["projectOnTwoDims"]][[length(e[["projectOnTwoDims"]]) + 
        1]] <- list(a = a, b = b, p = p, f = f, kern = kern, 
        dims = dims, data = data)
    .Call("_cort_projectOnTwoDims", a, b, p, f, kern, dims, data)
}
