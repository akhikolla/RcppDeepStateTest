function (mat, nTeams) 
{
    e <- get("data.env", .GlobalEnv)
    e[["finalElos"]][[length(e[["finalElos"]]) + 1]] <- list(mat = mat, 
        nTeams = nTeams)
    .Call("_elo_finalElos", PACKAGE = "elo", mat, nTeams)
}
