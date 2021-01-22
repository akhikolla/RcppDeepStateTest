function (t_id_key, nonempty_t_ids) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_dits"]][[length(e[["get_dits"]]) + 1]] <- list(t_id_key = t_id_key, 
        nonempty_t_ids = nonempty_t_ids)
    .Call("_PanelMatch_get_dits", PACKAGE = "PanelMatch", t_id_key, 
        nonempty_t_ids)
}
