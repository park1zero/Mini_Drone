#include "rtwtypes.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "mean_DcZkqR6r.h"

void mean_DcZkqR6r(const real_T x[38400], real_T y[2])
{
  real_T bsum;
  int32_T counts[2];
  int32_T b_k;
  int32_T hi;
  int32_T k;
  int32_T xblockoffset;
  int32_T xi;
  int32_T xoffset;
  int32_T xpageoffset;
  for (xi = 0; xi < 2; xi++) {
    xpageoffset = xi * 19200;
    if (muDoubleScalarIsNaN(x[xpageoffset])) {
      y[xi] = 0.0;
      counts[xi] = 0;
    } else {
      y[xi] = x[xpageoffset];
      counts[xi] = 1;
    }

    for (k = 0; k < 1023; k++) {
      xblockoffset = counts[xi];
      bsum = y[xi];
      xoffset = (xpageoffset + k) + 1;
      if (!muDoubleScalarIsNaN(x[xoffset])) {
        bsum += x[xoffset];
        xblockoffset++;
      }

      y[xi] = bsum;
      counts[xi] = xblockoffset;
    }

    for (k = 0; k < 18; k++) {
      xblockoffset = ((k + 1) << 10) + xpageoffset;
      if (muDoubleScalarIsNaN(x[xblockoffset])) {
        bsum = 0.0;
      } else {
        bsum = x[xblockoffset];
        counts[xi]++;
      }

      if (k + 2 == 19) {
        hi = 768;
      } else {
        hi = 1024;
      }

      for (b_k = 2; b_k <= hi; b_k++) {
        xoffset = (xblockoffset + b_k) - 1;
        if (!muDoubleScalarIsNaN(x[xoffset])) {
          bsum += x[xoffset];
          counts[xi]++;
        }
      }

      y[xi] += bsum;
    }

    y[xi] /= (real_T)counts[xi];
  }
}
