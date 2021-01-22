function (set) 
{
    e <- get("data.env", .GlobalEnv)
    e[["det_cpp"]][[length(e[["det_cpp"]]) + 1]] <- list(set = set)
    .Call("_idefix_det_cpp", PACKAGE = "idefix", set)
}
