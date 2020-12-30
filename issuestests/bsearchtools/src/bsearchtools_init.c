#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP bsearchtools_indexesEqualTo(SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesEqualToCharacter(SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesEqualToInteger(SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesEqualToLogical(SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesEqualToNumeric(SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesInRange(SEXP, SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesInRangeCharacter(SEXP, SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesInRangeInteger(SEXP, SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesInRangeLogical(SEXP, SEXP, SEXP, SEXP);
extern SEXP bsearchtools_indexesInRangeNumeric(SEXP, SEXP, SEXP, SEXP);
extern SEXP bsearchtools_intersectInteger(SEXP, SEXP);
extern SEXP bsearchtools_lb(SEXP, SEXP);
extern SEXP bsearchtools_lbCharacter(SEXP, SEXP);
extern SEXP bsearchtools_lbInteger(SEXP, SEXP);
extern SEXP bsearchtools_lbLogical(SEXP, SEXP);
extern SEXP bsearchtools_lbNumeric(SEXP, SEXP);
extern SEXP bsearchtools_ub(SEXP, SEXP);
extern SEXP bsearchtools_ubCharacter(SEXP, SEXP);
extern SEXP bsearchtools_ubInteger(SEXP, SEXP);
extern SEXP bsearchtools_ubLogical(SEXP, SEXP);
extern SEXP bsearchtools_ubNumeric(SEXP, SEXP);
extern SEXP bsearchtools_unionInteger(SEXP, SEXP);
extern SEXP bsearchtools_unionIntegerList(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"bsearchtools_indexesEqualTo",          (DL_FUNC) &bsearchtools_indexesEqualTo,          3},
    {"bsearchtools_indexesEqualToCharacter", (DL_FUNC) &bsearchtools_indexesEqualToCharacter, 3},
    {"bsearchtools_indexesEqualToInteger",   (DL_FUNC) &bsearchtools_indexesEqualToInteger,   3},
    {"bsearchtools_indexesEqualToLogical",   (DL_FUNC) &bsearchtools_indexesEqualToLogical,   3},
    {"bsearchtools_indexesEqualToNumeric",   (DL_FUNC) &bsearchtools_indexesEqualToNumeric,   3},
    {"bsearchtools_indexesInRange",          (DL_FUNC) &bsearchtools_indexesInRange,          4},
    {"bsearchtools_indexesInRangeCharacter", (DL_FUNC) &bsearchtools_indexesInRangeCharacter, 4},
    {"bsearchtools_indexesInRangeInteger",   (DL_FUNC) &bsearchtools_indexesInRangeInteger,   4},
    {"bsearchtools_indexesInRangeLogical",   (DL_FUNC) &bsearchtools_indexesInRangeLogical,   4},
    {"bsearchtools_indexesInRangeNumeric",   (DL_FUNC) &bsearchtools_indexesInRangeNumeric,   4},
    {"bsearchtools_intersectInteger",        (DL_FUNC) &bsearchtools_intersectInteger,        2},
    {"bsearchtools_lb",                      (DL_FUNC) &bsearchtools_lb,                      2},
    {"bsearchtools_lbCharacter",             (DL_FUNC) &bsearchtools_lbCharacter,             2},
    {"bsearchtools_lbInteger",               (DL_FUNC) &bsearchtools_lbInteger,               2},
    {"bsearchtools_lbLogical",               (DL_FUNC) &bsearchtools_lbLogical,               2},
    {"bsearchtools_lbNumeric",               (DL_FUNC) &bsearchtools_lbNumeric,               2},
    {"bsearchtools_ub",                      (DL_FUNC) &bsearchtools_ub,                      2},
    {"bsearchtools_ubCharacter",             (DL_FUNC) &bsearchtools_ubCharacter,             2},
    {"bsearchtools_ubInteger",               (DL_FUNC) &bsearchtools_ubInteger,               2},
    {"bsearchtools_ubLogical",               (DL_FUNC) &bsearchtools_ubLogical,               2},
    {"bsearchtools_ubNumeric",               (DL_FUNC) &bsearchtools_ubNumeric,               2},
    {"bsearchtools_unionInteger",            (DL_FUNC) &bsearchtools_unionInteger,            2},
    {"bsearchtools_unionIntegerList",        (DL_FUNC) &bsearchtools_unionIntegerList,        1},
    {NULL, NULL, 0}
};

void R_init_bsearchtools(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
