function (dict, model, idf, stop, user) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sim_ptr"]][[length(e[["sim_ptr"]]) + 1]] <- list(dict = dict, 
        model = model, idf = idf, stop = stop, user = user)
    .Call("_jiebaR_sim_ptr", dict, model, idf, stop, user)
}
