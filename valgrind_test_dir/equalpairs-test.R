function (u, v, ou, ov, max_number_of_pairs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["equalpairs"]][[length(e[["equalpairs"]]) + 1]] <- list(u = u, 
        v = v, ou = ou, ov = ov, max_number_of_pairs = max_number_of_pairs)
    .Call("_xyz_equalpairs", u, v, ou, ov, max_number_of_pairs)
}
