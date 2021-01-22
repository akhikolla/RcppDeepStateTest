function (heading, pitch, roll, starboard, forward, mast) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_sfm_enu"]][[length(e[["do_sfm_enu"]]) + 1]] <- list(heading = heading, 
        pitch = pitch, roll = roll, starboard = starboard, forward = forward, 
        mast = mast)
    .Call("_oce_do_sfm_enu", heading, pitch, roll, starboard, 
        forward, mast)
}
