function (pred_vals, resp_vals) 
{
    e <- get("data.env", .GlobalEnv)
    e[["iodaSumC"]][[length(e[["iodaSumC"]]) + 1]] <- list(pred_vals = pred_vals, 
        resp_vals = resp_vals)
    .Call("_remote_iodaSumC", PACKAGE = "remote", pred_vals, 
        resp_vals)
}
