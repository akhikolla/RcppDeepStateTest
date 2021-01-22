function (n_rand_steps, start_x, start_y, rel_angle, rand_sl, 
    rand_ta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["random_steps_cpp_one_step"]][[length(e[["random_steps_cpp_one_step"]]) + 
        1]] <- list(n_rand_steps = n_rand_steps, start_x = start_x, 
        start_y = start_y, rel_angle = rel_angle, rand_sl = rand_sl, 
        rand_ta = rand_ta)
    .Call("_amt_random_steps_cpp_one_step", PACKAGE = "amt", 
        n_rand_steps, start_x, start_y, rel_angle, rand_sl, rand_ta)
}
