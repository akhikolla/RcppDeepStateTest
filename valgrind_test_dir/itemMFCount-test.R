function (sim_index, user_vector, pt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["itemMFCount"]][[length(e[["itemMFCount"]]) + 1]] <- list(sim_index = sim_index, 
        user_vector = user_vector, pt = pt)
    .Call("_rrecsys_itemMFCount", PACKAGE = "rrecsys", sim_index, 
        user_vector, pt)
}
