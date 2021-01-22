function (ncases_nor, ncases_abn, max_nl, max_ll, n_les, nl, 
    ll) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SongA1"]][[length(e[["SongA1"]]) + 1]] <- list(ncases_nor = ncases_nor, 
        ncases_abn = ncases_abn, max_nl = max_nl, max_ll = max_ll, 
        n_les = n_les, nl = nl, ll = ll)
    .Call("_RJafroc_SongA1", PACKAGE = "RJafroc", ncases_nor, 
        ncases_abn, max_nl, max_ll, n_les, nl, ll)
}
