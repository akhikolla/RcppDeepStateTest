function (vec, P) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vec2Graph"]][[length(e[["vec2Graph"]]) + 1]] <- list(vec = vec, 
        P = P)
    .Call("_IsingSampler_vec2Graph", PACKAGE = "IsingSampler", 
        vec, P)
}
