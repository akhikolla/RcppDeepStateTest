function (est, err, numb_wells, numb_cells, numb_sample) 
{
    e <- get("data.env", .GlobalEnv)
    e[["likelihood_dualdual"]][[length(e[["likelihood_dualdual"]]) + 
        1]] <- list(est = est, err = err, numb_wells = numb_wells, 
        numb_cells = numb_cells, numb_sample = numb_sample)
    .Call("_alphabetr_likelihood_dualdual", PACKAGE = "alphabetr", 
        est, err, numb_wells, numb_cells, numb_sample)
}
