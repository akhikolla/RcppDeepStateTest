function (x, psi, omega, n, p, B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_rcTest"]][[length(e[["C_rcTest"]]) + 1]] <- list(x = x, 
        psi = psi, omega = omega, n = n, p = p, B = B)
    .Call("_Qtools_C_rcTest", x, psi, omega, n, p, B)
}
