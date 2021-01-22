function (id, seq, event) 
{
    e <- get("data.env", .GlobalEnv)
    e[["clipVec"]][[length(e[["clipVec"]]) + 1]] <- list(id = id, 
        seq = seq, event = event)
    .Call("_simstudy_clipVec", id, seq, event)
}
