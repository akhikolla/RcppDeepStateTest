function (allele1, allele2, min_alleles = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hwe_frequencies"]][[length(e[["hwe_frequencies"]]) + 
        1]] <- list(allele1 = allele1, allele2 = allele2, min_alleles = min_alleles)
    .Call("_MESS_hwe_frequencies", allele1, allele2, min_alleles)
}
