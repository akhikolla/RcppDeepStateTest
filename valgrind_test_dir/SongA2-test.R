function (ncases_nor, ncases_abn, max_nl, max_ll, n_les, nl, 
    ll) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SongA2"]][[length(e[["SongA2"]]) + 1]] <- list(ncases_nor = ncases_nor, 
        ncases_abn = ncases_abn, max_nl = max_nl, max_ll = max_ll, 
        n_les = n_les, nl = nl, ll = ll)
    .Call("_RJafroc_SongA2", PACKAGE = "RJafroc", ncases_nor, 
        ncases_abn, max_nl, max_ll, n_les, nl, ll)
}
