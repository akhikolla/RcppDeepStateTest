function (conjugate_arg, precision, feasible_point, max_iter, 
    min_iter, value_tol, initial_step) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_barrier_"]][[length(e[["solve_barrier_"]]) + 1]] <- list(conjugate_arg = conjugate_arg, 
        precision = precision, feasible_point = feasible_point, 
        max_iter = max_iter, min_iter = min_iter, value_tol = value_tol, 
        initial_step = initial_step)
    .Call("_selectiveInference_solve_barrier_", PACKAGE = "selectiveInference", 
        conjugate_arg, precision, feasible_point, max_iter, min_iter, 
        value_tol, initial_step)
}
