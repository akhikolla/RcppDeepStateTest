function (varnodes, nrnodes, p, parents, idcskeep, nodect, rowoffset, 
    nodevars) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nodeVars"]][[length(e[["nodeVars"]]) + 1]] <- list(varnodes = varnodes, 
        nrnodes = nrnodes, p = p, parents = parents, idcskeep = idcskeep, 
        nodect = nodect, rowoffset = rowoffset, nodevars = nodevars)
    .Call("_iRF_nodeVars", PACKAGE = "iRF", varnodes, nrnodes, 
        p, parents, idcskeep, nodect, rowoffset, nodevars)
}
