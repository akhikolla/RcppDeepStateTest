#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

// Referring to the generated functions in RcppExports.cpp
extern SEXP _adeba_find_constants(SEXP);
extern SEXP _adeba_is_constant(SEXP);
extern SEXP _adeba_get_bandwidths(SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_adeba_find_constants", (DL_FUNC) &_adeba_find_constants, 1},
    {"_adeba_is_constant", (DL_FUNC) &_adeba_is_constant, 1},
    {"_adeba_get_bandwidths", (DL_FUNC) &_adeba_get_bandwidths, 3},
    {NULL, NULL, 0}
};

void R_init_adeba(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

