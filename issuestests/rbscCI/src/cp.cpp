// [[Rcpp::depends(BH)]]

#include <boost/math/special_functions/beta.hpp>

#include "cp.h"
#include "binary-search.h"

using namespace boost::math;

ClopperPearson::ClopperPearson( const unsigned int s_N, const breal s_alpha )
  : limits_( s_N, s_alpha )
{
  for ( unsigned int k = 0; k <= s_N; k++ ) {
    /* calculate lower limit */
    if ( k != 0 ) {
      limits_.limits[ k ].lower = ibeta_inv( k, s_N - k + 1, s_alpha / 2.0 );
    }

    /* calculate upper limit */
    if ( k != s_N ) {
      limits_.limits[ k ].upper = ibeta_inv( k + 1, s_N - k, 1 - s_alpha / 2.0 );
    }
  }
}
