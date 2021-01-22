function (con, subcon, pos, term_i, length) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sequence_hit_ids_cpp"]][[length(e[["sequence_hit_ids_cpp"]]) + 
        1]] <- list(con = con, subcon = subcon, pos = pos, term_i = term_i, 
        length = length)
    .Call("_corpustools_sequence_hit_ids_cpp", PACKAGE = "corpustools", 
        con, subcon, pos, term_i, length)
}
