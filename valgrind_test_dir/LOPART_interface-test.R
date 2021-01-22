function (input_data, input_label_start, input_label_end, input_label_changes, 
    n_updates, penalty_unlabeled, penalty_labeled = 0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LOPART_interface"]][[length(e[["LOPART_interface"]]) + 
        1]] <- list(input_data = input_data, input_label_start = input_label_start, 
        input_label_end = input_label_end, input_label_changes = input_label_changes, 
        n_updates = n_updates, penalty_unlabeled = penalty_unlabeled, 
        penalty_labeled = penalty_labeled)
    .Call("_LOPART_LOPART_interface", input_data, input_label_start, 
        input_label_end, input_label_changes, n_updates, penalty_unlabeled, 
        penalty_labeled)
}
