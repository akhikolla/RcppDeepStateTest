testlist <- list(alignCode = 889924430L, increment = 1298265599L, n = -645489399L,      x = c(-1.06960341877259e+114, -3.47955013064173e-216, -8.9518097672271e+215,      1.38348243341209e-136, 6.24605057871232e+181, -4.11367928127064e+80     ))
result <- do.call(seismicRoll:::roll_range_numeric_vector,testlist)
str(result)