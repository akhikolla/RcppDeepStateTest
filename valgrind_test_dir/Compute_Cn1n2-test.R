function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Compute_Cn1n2"]][[length(e[["Compute_Cn1n2"]]) + 1]] <- list(x = x)
    .Call("_MuChPoint_Compute_Cn1n2", PACKAGE = "MuChPoint", 
        x)
}
