#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP bnnSurvival_weighted_kaplan_meier(SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"bnnSurvival_weighted_kaplan_meier", (DL_FUNC) &bnnSurvival_weighted_kaplan_meier, 3},
    {NULL, NULL, 0}
};

void R_init_bnnSurvival(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
