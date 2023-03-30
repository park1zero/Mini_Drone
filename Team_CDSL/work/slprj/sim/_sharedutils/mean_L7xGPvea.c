#include "rtwtypes.h"
#include "mean_L7xGPvea.h"
#include "mwmathutil.h"

void mean_L7xGPvea(const real_T x[2400], real_T y[2])
{
  real_T bsum;
  real_T x_p;
  int32_T counts[2];
  int32_T k;
  int32_T xi;
  int32_T xpageoffset;
  for (xi = 0; xi < 2; xi++) {
    xpageoffset = xi * 1200;
    x_p = x[xpageoffset];
    if (muDoubleScalarIsNaN(x_p)) {
      y[xi] = 0.0;
      counts[xi] = 0;
    } else {
      y[xi] = x_p;
      counts[xi] = 1;
    }

    for (k = 0; k < 1023; k++) {
      x_p = x[(xpageoffset + k) + 1];
      if (!muDoubleScalarIsNaN(x_p)) {
        y[xi] += x_p;
        counts[xi]++;
      }
    }

    bsum = x[xpageoffset + 1024];
    if (muDoubleScalarIsNaN(bsum)) {
      bsum = 0.0;
    } else {
      counts[xi]++;
    }

    for (k = 0; k < 175; k++) {
      x_p = x[(xpageoffset + k) + 1025];
      if (!muDoubleScalarIsNaN(x_p)) {
        bsum += x_p;
        counts[xi]++;
      }
    }

    y[xi] = (y[xi] + bsum) / (real_T)counts[xi];
  }
}
