function (sim, dist, ratio, rs, area, nobj, stoyan, nrank) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pcf_envelope"]][[length(e[["pcf_envelope"]]) + 1]] <- list(sim = sim, 
        dist = dist, ratio = ratio, rs = rs, area = area, nobj = nobj, 
        stoyan = stoyan, nrank = nrank)
    .Call("_apcf_pcf_envelope", sim, dist, ratio, rs, area, nobj, 
        stoyan, nrank)
}
