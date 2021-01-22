function (tD) 
{
    e <- get("data.env", .GlobalEnv)
    e[["draw_SBM_geodesic_angle_CPP"]][[length(e[["draw_SBM_geodesic_angle_CPP"]]) + 
        1]] <- list(tD = tD)
    .Call("_castor_draw_SBM_geodesic_angle_CPP", tD)
}
