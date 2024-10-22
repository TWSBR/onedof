/*
 * motor_data.c
 *
 * Code generation for model "motor".
 *
 * Model version              : 1.92
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Mar 20 00:08:40 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor.h"
#include "motor_private.h"

/* Block parameters (default storage) */
P_motor_T motor_P = {
  /* Mask Parameter: RepeatingSequenceInterpolated_O
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 0.0, 10.0, 20.0, 20.0, 10.0, 0.0, 0.0 },

  /* Mask Parameter: RepeatingSequenceInterpolated_T
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 0.002, 0.004, 0.006, 0.01, 0.012, 0.014, 0.016 },

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S4>/FixPt Switch'
   */
  16U,

  /* Computed Parameter: SampleTimeMath_WtEt
   * Referenced by: '<S1>/Sample Time Math'
   */
  0.001,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S4>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S2>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S3>/FixPt Constant'
   */
  1U
};
