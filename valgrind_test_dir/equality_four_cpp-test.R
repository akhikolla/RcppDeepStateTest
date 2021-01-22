function (Wit_vals, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["equality_four_cpp"]][[length(e[["equality_four_cpp"]]) + 
        1]] <- list(Wit_vals = Wit_vals, y = y, z = z)
    .Call("_PanelMatch_equality_four_cpp", PACKAGE = "PanelMatch", 
        Wit_vals, y, z)
}
