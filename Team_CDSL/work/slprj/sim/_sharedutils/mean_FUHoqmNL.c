#include "rtwtypes.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "mean_FUHoqmNL.h"

void mean_FUHoqmNL(const real_T x[2400], real_T y[2])
{
  real_T bsum;
  int32_T counts[2];
  int32_T counts_p;
  int32_T k;
  int32_T xi;
  int32_T xoffset;
  int32_T xpageoffset;
  for (xi = 0; xi < 2; xi++) {
    xpageoffset = xi * 1200;
    if (muDoubleScalarIsNaN(x[xpageoffset])) {
      y[xi] = 0.0;
      counts[xi] = 0;
    } else {
      y[xi] = x[xpageoffset];
      counts[xi] = 1;
    }

    for (k = 0; k < 1023; k++) {
      counts_p = counts[xi];
      bsum = y[xi];
      xoffset = (xpageoffset + k) + 1;
      if (!muDoubleScalarIsNaN(x[xoffset])) {
        bsum += x[xoffset];
        counts_p++;
      }

      y[xi] = bsum;
      counts[xi] = counts_p;
    }

    bsum = x[xpageoffset + 1024];
    if (muDoubleScalarIsNaN(bsum)) {
      bsum = 0.0;
    } else {
      counts[xi]++;
    }

    for (k = 0; k < 175; k++) {
      counts_p = counts[xi];
      xoffset = (xpageoffset + k) + 1025;
      if (!muDoubleScalarIsNaN(x[xoffset])) {
        bsum += x[xoffset];
        counts_p++;
      }

      counts[xi] = counts_p;
    }

    y[xi] += bsum;
    y[xi] /= (real_T)counts[xi];
  }
}
