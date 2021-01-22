function (t_id_key, control_treatment_t_ids, control_treatment_set_nums) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_vit_index_unsigned"]][[length(e[["get_vit_index_unsigned"]]) + 
        1]] <- list(t_id_key = t_id_key, control_treatment_t_ids = control_treatment_t_ids, 
        control_treatment_set_nums = control_treatment_set_nums)
    .Call("_PanelMatch_get_vit_index_unsigned", PACKAGE = "PanelMatch", 
        t_id_key, control_treatment_t_ids, control_treatment_set_nums)
}
