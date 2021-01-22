function (indptr1, indices1, data1, indptr2, indices2, data2, 
    result_row, result_col, result_val, mix_weight = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["general_sset_intersection_cpp"]][[length(e[["general_sset_intersection_cpp"]]) + 
        1]] <- list(indptr1 = indptr1, indices1 = indices1, data1 = data1, 
        indptr2 = indptr2, indices2 = indices2, data2 = data2, 
        result_row = result_row, result_col = result_col, result_val = result_val, 
        mix_weight = mix_weight)
    .Call("_uwot_general_sset_intersection_cpp", indptr1, indices1, 
        data1, indptr2, indices2, data2, result_row, result_col, 
        result_val, mix_weight)
}
