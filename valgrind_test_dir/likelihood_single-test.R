function (est, err, numb_wells, numb_cells, numb_sample) 
{
    e <- get("data.env", .GlobalEnv)
    e[["likelihood_single"]][[length(e[["likelihood_single"]]) + 
        1]] <- list(est = est, err = err, numb_wells = numb_wells, 
        numb_cells = numb_cells, numb_sample = numb_sample)
    .Call("_alphabetr_likelihood_single", PACKAGE = "alphabetr", 
        est, err, numb_wells, numb_cells, numb_sample)
}
