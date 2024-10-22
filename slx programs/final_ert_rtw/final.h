/*
 * final.h
 *
 * Code generation for model "final".
 *
 * Model version              : 1.87
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Mar 19 21:13:20 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_final_h_
#define RTW_HEADER_final_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef final_COMMON_INCLUDES_
#define final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_ServoWriteRead.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#endif                                 /* final_COMMON_INCLUDES_ */

#include "final_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T deg;                          /* '<Root>/Gain2' */
  real_T Saturation;                   /* '<Root>/Saturation' */
} B_final_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_k_T obj; /* '<S3>/MPU6050 IMU Sensor' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Continuous Servo Write' */
  boolean_T objisempty;                /* '<S3>/MPU6050 IMU Sensor' */
  boolean_T objisempty_l;              /* '<Root>/Continuous Servo Write' */
} DW_final_T;

/* Parameters (default storage) */
struct P_final_T_ {
  real_T c;                            /* Variable: c
                                        * Referenced by:
                                        *   '<S2>/Gain'
                                        *   '<S2>/Gain1'
                                        */
  real_T MPU6050IMUSensor_SampleTime;  /* Expression: 0.05
                                        * Referenced by: '<S3>/MPU6050 IMU Sensor'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 4
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T Constant_Value;               /* Expression: 0.3948
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Ts_Gain;                      /* Expression: 0.05
                                        * Referenced by: '<S2>/Ts'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 0.05
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 20
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_final_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_final_T final_P;

/* Block signals (default storage) */
extern B_final_T final_B;

/* Block states (default storage) */
extern DW_final_T final_DW;

/* External function called from main */
extern void final_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void final_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void final_initialize(void);
extern void final_step0(void);
extern void final_step1(void);
extern void final_step2(void);
extern void final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_final_T *const final_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S29>/Derivative Gain' : Unused code path elimination
 * Block '<S30>/DTDup' : Unused code path elimination
 * Block '<S30>/Diff' : Unused code path elimination
 * Block '<S32>/Tsamp' : Unused code path elimination
 * Block '<S30>/UD' : Unused code path elimination
 * Block '<S34>/Integral Gain' : Unused code path elimination
 * Block '<S37>/Integrator' : Unused code path elimination
 * Block '<S42>/Proportional Gain' : Unused code path elimination
 * Block '<S46>/Sum' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'final'
 * '<S1>'   : 'final/Discrete PID Controller'
 * '<S2>'   : 'final/cf'
 * '<S3>'   : 'final/r'
 * '<S4>'   : 'final/Discrete PID Controller/Anti-windup'
 * '<S5>'   : 'final/Discrete PID Controller/D Gain'
 * '<S6>'   : 'final/Discrete PID Controller/Filter'
 * '<S7>'   : 'final/Discrete PID Controller/Filter ICs'
 * '<S8>'   : 'final/Discrete PID Controller/I Gain'
 * '<S9>'   : 'final/Discrete PID Controller/Ideal P Gain'
 * '<S10>'  : 'final/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'final/Discrete PID Controller/Integrator'
 * '<S12>'  : 'final/Discrete PID Controller/Integrator ICs'
 * '<S13>'  : 'final/Discrete PID Controller/N Copy'
 * '<S14>'  : 'final/Discrete PID Controller/N Gain'
 * '<S15>'  : 'final/Discrete PID Controller/P Copy'
 * '<S16>'  : 'final/Discrete PID Controller/Parallel P Gain'
 * '<S17>'  : 'final/Discrete PID Controller/Reset Signal'
 * '<S18>'  : 'final/Discrete PID Controller/Saturation'
 * '<S19>'  : 'final/Discrete PID Controller/Saturation Fdbk'
 * '<S20>'  : 'final/Discrete PID Controller/Sum'
 * '<S21>'  : 'final/Discrete PID Controller/Sum Fdbk'
 * '<S22>'  : 'final/Discrete PID Controller/Tracking Mode'
 * '<S23>'  : 'final/Discrete PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'final/Discrete PID Controller/Tsamp - Integral'
 * '<S25>'  : 'final/Discrete PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'final/Discrete PID Controller/postSat Signal'
 * '<S27>'  : 'final/Discrete PID Controller/preSat Signal'
 * '<S28>'  : 'final/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'final/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S30>'  : 'final/Discrete PID Controller/Filter/Differentiator'
 * '<S31>'  : 'final/Discrete PID Controller/Filter/Differentiator/Tsamp'
 * '<S32>'  : 'final/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S33>'  : 'final/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S34>'  : 'final/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'final/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'final/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'final/Discrete PID Controller/Integrator/Discrete'
 * '<S38>'  : 'final/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'final/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'final/Discrete PID Controller/N Gain/Passthrough'
 * '<S41>'  : 'final/Discrete PID Controller/P Copy/Disabled'
 * '<S42>'  : 'final/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'final/Discrete PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'final/Discrete PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'final/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'final/Discrete PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'final/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'final/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'final/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'final/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S51>'  : 'final/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'final/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'final/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_final_h_ */
