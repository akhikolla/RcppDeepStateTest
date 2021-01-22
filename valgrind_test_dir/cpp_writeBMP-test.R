function (image) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_writeBMP"]][[length(e[["cpp_writeBMP"]]) + 1]] <- list(image = image)
    .Call("_IFC_cpp_writeBMP", image)
}
