/*
 * finalist_data.c
 *
 * Code generation for model "finalist".
 *
 * Model version              : 1.86
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Mar 19 21:17:06 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "finalist.h"
#include "finalist_private.h"

/* Block parameters (default storage) */
P_finalist_T finalist_P = {
  /* Variable: c
   * Referenced by:
   *   '<S1>/Gain'
   *   '<S1>/Gain1'
   */
  0.02,

  /* Expression: 0.05
   * Referenced by: '<S2>/MPU6050 IMU Sensor'
   */
  0.05,

  /* Expression: 0.3948
   * Referenced by: '<S2>/Constant'
   */
  0.3948,

  /* Expression: 0.05
   * Referenced by: '<S1>/Ts'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<Root>/Constant1'
   */
  0.05,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain2'
   */
  57.295779513082323,

  /* Expression: 20
   * Referenced by: '<Root>/Saturation'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0
};
