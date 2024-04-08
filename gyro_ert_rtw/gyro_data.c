/*
 * gyro_data.c
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

#include "gyro.h"

/* Block parameters (default storage) */
P_gyro_T gyro_P = {
  /* Variable: c
   * Referenced by:
   *   '<S1>/Gain'
   *   '<S1>/Gain1'
   */
  0.02,

  /* Mask Parameter: MPU6050IMUSensor_SampleTime
   * Referenced by: '<S3>/Base sensor block'
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
