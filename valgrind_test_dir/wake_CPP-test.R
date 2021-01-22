function (Rotorf, wakr, leA) 
{
    e <- get("data.env", .GlobalEnv)
    e[["wake_CPP"]][[length(e[["wake_CPP"]]) + 1]] <- list(Rotorf = Rotorf, 
        wakr = wakr, leA = leA)
    .Call("_windfarmGA_wake_CPP", Rotorf, wakr, leA)
}
