/*
 * motor.c
 *
 * Code generation for model "motor".
 *
 * Model version              : 1.90
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Mar 19 22:39:38 2024
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
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void motor_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(motor_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (motor_M->Timing.TaskCounters.TID[1])++;
  if ((motor_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    motor_M->Timing.TaskCounters.TID[1] = 0;
  }
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

/* Model step function for TID0 */
void motor_step0(void)                 /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)motor_M->Timing.taskTime0);

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

  /* Update absolute time */
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

/* Model step function for TID1 */
void motor_step1(void)                 /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_PulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (motor_DW.clockTickCounter < motor_P.PulseGenerator_Duty)
    && (motor_DW.clockTickCounter >= 0L) ? motor_P.PulseGenerator_Amp : 0.0;
  if (motor_DW.clockTickCounter >= motor_P.PulseGenerator_Period - 1.0) {
    motor_DW.clockTickCounter = 0L;
  } else {
    motor_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Continuous Servo Write' */
  if (rtb_PulseGenerator + 90.0 < 0.0) {
    rtb_PulseGenerator_0 = 0U;
  } else if (rtb_PulseGenerator + 90.0 > 180.0) {
    rtb_PulseGenerator_0 = 180U;
  } else {
    rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator + 90.0);
    if (rtb_PulseGenerator < 256.0) {
      if (rtb_PulseGenerator >= 0.0) {
        rtb_PulseGenerator_0 = (uint8_T)rtb_PulseGenerator;
      } else {
        rtb_PulseGenerator_0 = 0U;
      }
    } else {
      rtb_PulseGenerator_0 = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, rtb_PulseGenerator_0);

  /* End of MATLABSystem: '<Root>/Continuous Servo Write' */
  rtExtModeUpload(1, (real_T)(((motor_M->Timing.clockTick1+
    motor_M->Timing.clockTickH1* 4294967296.0)) * 0.01));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  motor_M->Timing.clockTick1++;
  if (!motor_M->Timing.clockTick1) {
    motor_M->Timing.clockTickH1++;
  }
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
  motor_M->Sizes.checksums[0] = (1864690186U);
  motor_M->Sizes.checksums[1] = (1666157690U);
  motor_M->Sizes.checksums[2] = (4088764093U);
  motor_M->Sizes.checksums[3] = (2479982336U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
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

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  motor_DW.clockTickCounter = -1L;
}

/* Model terminate function */
void motor_terminate(void)
{
  /* (no terminate code required) */
}
