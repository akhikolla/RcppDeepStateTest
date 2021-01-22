function (vec, P) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vec2Thresh"]][[length(e[["vec2Thresh"]]) + 1]] <- list(vec = vec, 
        P = P)
    .Call("_IsingSampler_vec2Thresh", PACKAGE = "IsingSampler", 
        vec, P)
}
