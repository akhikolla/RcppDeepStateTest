#include <Rcpp.h>
using namespace Rcpp;

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cmath>
#include <cfloat>

typedef uint64_t vset;
typedef double score_t;
const uint64_t ONE_LLU = 1;
#define cerr Rcerr

#include "OrderNode.h"
#include "ParentScore.h"
#include "ASterQueue.h"

IntegerVector extractResult(int n, ASterQueue& queue, ParentScore& ps)
{
    IntegerVector result;
    vset node = (ONE_LLU << n) - 1;
    while (node > 0) {
        int x = queue.getNode(node)->getParentPos();
        vset u = (ONE_LLU << x);
        node &= ~u;
        vset c = ps.getBestParent(x, node);
        for (int i = 0; c != 0; ++i) {
            //if (i != x) { // skip if i == x
                if ((c & ONE_LLU) != 0) { // make arc "i -> x"
                    result.push_back(i);
                    result.push_back(x);
                }
                c >>= 1;
            //}
        }
    }
    return result;
}

score_t heuristics(vset vs)
{
    return 0;
}

IntegerVector runAster(NumericMatrix matrix, ParentScore& ps, int tree_width)
{
    const int n = matrix.ncol();
    ASterQueue queue(n, tree_width, ps);

    score_t initial_estimated_score = heuristics(0);
    queue.addNode(new OrderNode(initial_estimated_score)); // initial node

    while (!queue.empty()) {

        // pop the node having the minimum estimated score
        // u must not be deleted because it will be used later.
        OrderNode* u = queue.pop();

        if (u->isGoal(n)) { // reach the goal
            cerr << "goal: " << u->toString(n) << "\n";
            return extractResult(n, queue, ps);
        }
        vset u_vset = u->getVset();
        for (int x = 0; x < n; ++x) {
            if (((u_vset >> x) & ONE_LLU) == 0) { // for each i in V minus U
                vset x_vset = (ONE_LLU << x);
                vset ux = (u_vset | x_vset);
                score_t g_new = queue.getBestScore(x, u_vset) + u->getScore();
                queue.addOrUpdateNode(ux, g_new, g_new + heuristics(ux), x);
            }
        }
    }
    return IntegerVector();
}


// [[Rcpp::export]]
NumericVector aster_cpp(NumericMatrix matrix, int tree_width = 0, int proc=1, double s=0, int n=0, int ss=0)
{
    if (matrix.ncol() >= 64) {
        stop("The data with more than 64 variables is not supported.");
    }

    // give true to the argument because of flipping the sign
    // for solving the maximization problem.
    ParentScore ps(true);
    ps.computeParentScore(matrix, tree_width, proc, s, n, ss);

    IntegerVector result = runAster(matrix, ps, tree_width);

    NumericVector v;
    for (int i = 0; i < result.size(); ++i) {
        v.push_back(result[i]);
    }
    return v;
}

// [[Rcpp::export]]
NumericVector aster_cpp_p(NumericMatrix matrix, List psl, int tree_width = 0, int proc=1, double s=0, int n=0, int ss=0)
{
    if (matrix.ncol() >= 64) {
        stop("The data with more than 64 variables is not supported.");
    }

    // give true to the argument because of flipping the sign
    // for solving the maximization problem.
    ParentScore ps(true);
    ps.importTable(psl);

    IntegerVector result = runAster(matrix, ps, tree_width);

    NumericVector v;
    for (int i = 0; i < result.size(); ++i) {
        v.push_back(result[i]);
    }
    return v;
}

