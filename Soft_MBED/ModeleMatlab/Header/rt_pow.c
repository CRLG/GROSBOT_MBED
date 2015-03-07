/*
 * File: rt_pow.c
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.966
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Mar 21 08:30:15 2013
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Mar 21 08:30:17 2013
 */

#include "rt_pow.h"
#include <math.h>

/*
 * Calls double-precision version of POW directly, with no guards against
 * domain error or non-finites
 */
real_T rt_pow(const real_T xr, const real_T yr)
{
  return(pow(xr,yr));
}                                      /* end rt_pow */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
