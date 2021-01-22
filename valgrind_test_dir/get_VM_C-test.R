function (x, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_VM_C"]][[length(e[["get_VM_C"]]) + 1]] <- list(x = x, 
        y = y, z = z)
    .Call("_AGread_get_VM_C", PACKAGE = "AGread", x, y, z)
}
