
#include "filter.h"

SecondOrderSection::SecondOrderSection(int _b0, int _b1, int _b2, int _a1, int _a2):
  b0(_b0), b1(_b1), b2(_b2), a1(_a1), a2(_a2)
{
  zx[0] = zx[1] = zy[0] = zy[1] = 0;
  // that's it here

  // fixed point precision
  //  b0/2:  Q15
  //  b1/2:  Q15
  //  b2:    Q15
  // -a1/2:  Q15
  // -a2:    Q15
}

long SecondOrderSection::process(long x)
{
  // x is Q12

  // Q12 * Q15 = Q27
  long y = ((b0*x + b1*zx[0] + a1*zy[0]) << 1) + b2*zx[1] + a2*zy[1];

  zx[1] = zx[0];
  zx[0] = x;
  zy[1] = zy[0];
  zy[0] = y >> 15;

  // output is Q10
  return zy[0];
}

