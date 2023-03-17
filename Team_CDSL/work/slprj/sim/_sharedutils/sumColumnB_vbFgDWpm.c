#include "rtwtypes.h"
#include "multiword_types.h"
#include "sumColumnB_vbFgDWpm.h"

real_T sumColumnB_vbFgDWpm(const boolean_T x[16], int32_T col)
{
  real_T y;
  int32_T i0;
  int32_T k;
  i0 = (col - 1) << 4;
  y = x[i0];
  for (k = 0; k < 15; k++) {
    y += (real_T)x[(i0 + k) + 1];
  }

  return y;
}
