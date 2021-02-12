#!/bin/bash
set -o errexit
cat > rinside-problem.cpp <<EOF
#include <RInside.h>
#include <DeepState.hpp>
TEST(deepstate_test,rinside_test){
    RInside R;
    R["txt"] = "Hello, world!\n";
    R.parseEvalQ("cat(txt)");
}
EOF
R_HOME=$(bash R RHOME)
RCPPFLAGS=$(bash $R_HOME/bin/R CMD config --cppflags)
RLDFLAGS=$(bash $R_HOME/bin/R CMD config --ldflags)
RBLAS=$(bash $R_HOME/bin/R CMD config BLAS_LIBS)
RLAPACK=$(bash $R_HOME/bin/R CMD config LAPACK_LIBS)
RCPPINCL=$(bash $R_HOME/bin/R --vanilla --slave)
RCPPLIBS=$(bash $R_HOME/bin/R --vanilla --slave)
RINSIDEINCL=$(bash $R_HOME/bin/R --vanilla --slave)
RINSIDELIBS=$(bash $R_HOME/bin/R --vanilla --slave)
