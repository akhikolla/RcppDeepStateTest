function (v1, v2, v3, section_counts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bmat_schC"]][[length(e[["bmat_schC"]]) + 1]] <- list(v1 = v1, 
        v2 = v2, v3 = v3, section_counts = section_counts)
    .Call("_rlme_bmat_schC", PACKAGE = "rlme", v1, v2, v3, section_counts)
}
