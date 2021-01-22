function (Label, Distance, L_C = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_ksNN"]][[length(e[["rcpp_ksNN"]]) + 1]] <- list(Label = Label, 
        Distance = Distance, L_C = L_C)
    .Call("_ksNN_rcpp_ksNN", Label, Distance, L_C)
}
