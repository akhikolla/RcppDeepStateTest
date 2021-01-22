function (XtX, Xty, X, y, U, w, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_iv_product_completion"]][[length(e[["cpp_iv_product_completion"]]) + 
        1]] <- list(XtX = XtX, Xty = Xty, X = X, y = y, U = U, 
        w = w, nthreads = nthreads)
    .Call("_fixest_cpp_iv_product_completion", XtX, Xty, X, y, 
        U, w, nthreads)
}
