function (winsA, teamA, teamB, weightsA, weightsB, weights, nTeams) 
{
    e <- get("data.env", .GlobalEnv)
    e[["eloWinPct"]][[length(e[["eloWinPct"]]) + 1]] <- list(winsA = winsA, 
        teamA = teamA, teamB = teamB, weightsA = weightsA, weightsB = weightsB, 
        weights = weights, nTeams = nTeams)
    .Call("_elo_eloWinPct", PACKAGE = "elo", winsA, teamA, teamB, 
        weightsA, weightsB, weights, nTeams)
}
