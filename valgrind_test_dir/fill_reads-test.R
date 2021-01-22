function (new_reads, new_counts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fill_reads"]][[length(e[["fill_reads"]]) + 1]] <- list(new_reads = new_reads, 
        new_counts = new_counts)
    .Call("_immunarch_fill_reads", new_reads, new_counts)
}
