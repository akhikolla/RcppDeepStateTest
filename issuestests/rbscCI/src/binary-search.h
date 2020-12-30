#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <functional>

#include "util.h"

const breal CONVERGENCE_GOAL = 1e-13;
const unsigned int ITERATION_LIMIT = 100;

/* Find paramater value within search_space s.t. func( param ) is close to goal */
breal param_binary_search( Interval search_space,
                           std::function<breal (const breal)> func,
                           const breal goal,
                           const bool slope );

#endif
