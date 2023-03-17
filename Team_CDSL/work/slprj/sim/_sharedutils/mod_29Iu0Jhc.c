#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "mod_29Iu0Jhc.h"

real_T mod_29Iu0Jhc(real_T x)
{
  real_T q;
  real_T r;
  boolean_T rEQ0;
  if (muDoubleScalarIsNaN(x) || muDoubleScalarIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = muDoubleScalarRem(x, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q = muDoubleScalarAbs(x / 6.2831853071795862);
      rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
               2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 6.2831853071795862;
    }
  }

  return r;
}
