function (teamA, teamB, winsA, weightsA, weightsB, weights, k, 
    nTeams) 
{
    e <- get("data.env", .GlobalEnv)
    e[["eloColley"]][[length(e[["eloColley"]]) + 1]] <- list(teamA = teamA, 
        teamB = teamB, winsA = winsA, weightsA = weightsA, weightsB = weightsB, 
        weights = weights, k = k, nTeams = nTeams)
    .Call("_elo_eloColley", PACKAGE = "elo", teamA, teamB, winsA, 
        weightsA, weightsB, weights, k, nTeams)
}
