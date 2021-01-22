function (hhat_mat, xpxi_mat, D_mat, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["newey_west_pw"]][[length(e[["newey_west_pw"]]) + 1]] <- list(hhat_mat = hhat_mat, 
        xpxi_mat = xpxi_mat, D_mat = D_mat, h = h)
    .Call("_lpirfs_newey_west_pw", hhat_mat, xpxi_mat, D_mat, 
        h)
}
