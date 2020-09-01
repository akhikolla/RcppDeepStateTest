makematrix = function(df) {
    nrow = dim(df)[1]
    ncol = dim(df)[2]
    m <- matrix(0, nrow = nrow, ncol = ncol)
    for (i in 1:nrow) {
        for (j in 1:ncol) {
            m[i, j] = as.numeric(df[i, j])
        }
    }
    return(m)
}

bnsl = function(df, tw = 0, proc=1, s = 0, n = 0, ss = 1) {
    m = data.matrix(df)
    v = aster_cpp(m, tw, proc, s, n, ss)
    g = empty.graph(names(df))

    i = 1
    while (i <= length(v)/2) {
        g = set.arc(g, names(df)[v[2 * i - 1] + 1], names(df)[v[2 * i] + 1])
        i = i + 1
    }
    return(g)
}

bnsl_p = function(df, psl, tw = 0, proc=1, s = 0, n = 0, ss = 1) {
    m = data.matrix(df)
    v = aster_cpp_p(m, psl, tw, proc, s, n, ss)
    g = empty.graph(names(df))

    i = 1
    while (i <= length(v)/2) {
        g = set.arc(g, names(df)[v[2 * i - 1] + 1], names(df)[v[2 * i] + 1])
        i = i + 1
    }
    return(g)
}
