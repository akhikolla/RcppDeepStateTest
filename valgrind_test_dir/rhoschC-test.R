function (ahat, section_counts, student_counts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rhoschC"]][[length(e[["rhoschC"]]) + 1]] <- list(ahat = ahat, 
        section_counts = section_counts, student_counts = student_counts)
    .Call("_rlme_rhoschC", PACKAGE = "rlme", ahat, section_counts, 
        student_counts)
}
