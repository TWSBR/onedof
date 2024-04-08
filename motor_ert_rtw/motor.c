/*
 * motor.c
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
#include "motor_dt.h"

/* Block states (default storage) */
DW_motor_T motor_DW;

/* Real-time model */
static RT_MODEL_motor_T motor_M_;
RT_MODEL_motor_T *const motor_M = &motor_M_;
real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1UL] - yL_0d0) * frac + yL_0d0;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void motor_step(void)
{
  real_T rtb_Lookup;
  uint8_T rtb_Lookup_0;

  /* Lookup_n-D: '<S1>/Lookup' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  SampleTimeMath: '<S1>/Sample Time Math'
   *  UnitDelay: '<S2>/Output'
   *
   * About '<S1>/Sample Time Math':
   *  y = u * K where K = ( w * Ts )
   */
  rtb_Lookup = look1_binlcpw((real_T)motor_DW.Output_DSTATE *
    motor_P.SampleTimeMath_WtEt, motor_P.RepeatingSequenceInterpolated_T,
    motor_P.RepeatingSequenceInterpolated_O, 7UL);

  /* MATLABSystem: '<Root>/Continuous Servo Write' */
  if (rtb_Lookup + 90.0 < 0.0) {
    rtb_Lookup_0 = 0U;
  } else if (rtb_Lookup + 90.0 > 180.0) {
    rtb_Lookup_0 = 180U;
  } else {
    rtb_Lookup = rt_roundd_snf(rtb_Lookup + 90.0);
    if (rtb_Lookup < 256.0) {
      if (rtb_Lookup >= 0.0) {
        rtb_Lookup_0 = (uint8_T)rtb_Lookup;
      } else {
        rtb_Lookup_0 = 0U;
      }
    } else {
      rtb_Lookup_0 = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, rtb_Lookup_0);

  /* End of MATLABSystem: '<Root>/Continuous Servo Write' */

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  motor_DW.Output_DSTATE = (uint8_T)((uint16_T)motor_DW.Output_DSTATE +
    motor_P.FixPtConstant_Value);

  /* Switch: '<S4>/FixPt Switch' */
  if (motor_DW.Output_DSTATE > motor_P.LimitedCounter_uplimit) {
    /* Sum: '<S3>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/Constant'
     *  UnitDelay: '<S2>/Output'
     */
    motor_DW.Output_DSTATE = motor_P.Constant_Value;
  }

  /* End of Switch: '<S4>/FixPt Switch' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)motor_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(motor_M)!=-1) &&
        !((rtmGetTFinal(motor_M)-motor_M->Timing.taskTime0) >
          motor_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motor_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motor_M)) {
      rtmSetErrorStatus(motor_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++motor_M->Timing.clockTick0)) {
    ++motor_M->Timing.clockTickH0;
  }

  motor_M->Timing.taskTime0 = motor_M->Timing.clockTick0 *
    motor_M->Timing.stepSize0 + motor_M->Timing.clockTickH0 *
    motor_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void motor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_M, 0,
                sizeof(RT_MODEL_motor_T));
  rtmSetTFinal(motor_M, -1);
  motor_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  motor_M->Sizes.checksums[0] = (72831046U);
  motor_M->Sizes.checksums[1] = (1772609781U);
  motor_M->Sizes.checksums[2] = (1731675676U);
  motor_M->Sizes.checksums[3] = (4207108474U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_M->extModeInfo,
      &motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_M->extModeInfo, motor_M->Sizes.checksums);
    rteiSetTPtr(motor_M->extModeInfo, rtmGetTPtr(motor_M));
  }

  /* states (dwork) */
  (void) memset((void *)&motor_DW, 0,
                sizeof(DW_motor_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Continuous Servo Write' */
  motor_DW.obj.isInitialized = 0L;
  motor_DW.objisempty = true;
  motor_DW.obj.isInitialized = 1L;
  MW_servoAttach(0, 9);

  /* InitializeConditions for Sum: '<S3>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  motor_DW.Output_DSTATE = motor_P.Output_InitialCondition;
}

/* Model terminate function */
void motor_terminate(void)
{
  /* (no terminate code required) */
}
