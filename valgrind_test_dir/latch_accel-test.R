function (vector_size, accel_input, samp_rate) 
{
    e <- get("data.env", .GlobalEnv)
    e[["latch_accel"]][[length(e[["latch_accel"]]) + 1]] <- list(vector_size = vector_size, 
        accel_input = accel_input, samp_rate = samp_rate)
    .Call("_AGread_latch_accel", PACKAGE = "AGread", vector_size, 
        accel_input, samp_rate)
}
