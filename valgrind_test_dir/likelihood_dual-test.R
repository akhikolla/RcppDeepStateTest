function (est, err, numb_wells, numb_cells, numb_sample) 
{
    e <- get("data.env", .GlobalEnv)
    e[["likelihood_dual"]][[length(e[["likelihood_dual"]]) + 
        1]] <- list(est = est, err = err, numb_wells = numb_wells, 
        numb_cells = numb_cells, numb_sample = numb_sample)
    .Call("_alphabetr_likelihood_dual", PACKAGE = "alphabetr", 
        est, err, numb_wells, numb_cells, numb_sample)
}
