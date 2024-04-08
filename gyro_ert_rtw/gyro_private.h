/*
 * gyro_private.h
 *
 * Code generation for model "gyro".
 *
 * Model version              : 1.88
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Apr  5 21:53:41 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_gyro_private_h_
#define RTW_HEADER_gyro_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "gyro_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);

#endif                                 /* RTW_HEADER_gyro_private_h_ */
