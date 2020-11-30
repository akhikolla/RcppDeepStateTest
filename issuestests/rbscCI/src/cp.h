#ifndef CP_H
#define CP_H

#include "util.h"

class ClopperPearson
{
private:
  IntervalCollection limits_;

public:
  /* N draws, with confidence parameter alpha */
  ClopperPearson( const unsigned int s_N, const breal s_alpha );

  /* Confidence interval when N draws give k successes */
  const IntervalCollection & limits( void ) const { return limits_; }
};

#endif
