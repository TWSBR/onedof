/*
 * finalist.h
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

#ifndef RTW_HEADER_finalist_h_
#define RTW_HEADER_finalist_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef finalist_COMMON_INCLUDES_
#define finalist_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#endif                                 /* finalist_COMMON_INCLUDES_ */

#include "finalist_types.h"

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

/* Block signals (default storage) */
typedef struct {
  real_T deg;                          /* '<Root>/Gain2' */
  real_T Saturation;                   /* '<Root>/Saturation' */
} B_finalist_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/MPU6050 IMU Sensor' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  boolean_T objisempty;                /* '<S2>/MPU6050 IMU Sensor' */
} DW_finalist_T;

/* Parameters (default storage) */
struct P_finalist_T_ {
  real_T c;                            /* Variable: c
                                        * Referenced by:
                                        *   '<S1>/Gain'
                                        *   '<S1>/Gain1'
                                        */
  real_T MPU6050IMUSensor_SampleTime;  /* Expression: 0.05
                                        * Referenced by: '<S2>/MPU6050 IMU Sensor'
                                        */
  real_T Constant_Value;               /* Expression: 0.3948
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Ts_Gain;                      /* Expression: 0.05
                                        * Referenced by: '<S1>/Ts'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
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
struct tag_RTM_finalist_T {
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_finalist_T finalist_P;

/* Block signals (default storage) */
extern B_finalist_T finalist_B;

/* Block states (default storage) */
extern DW_finalist_T finalist_DW;

/* Model entry point functions */
extern void finalist_initialize(void);
extern void finalist_step(void);
extern void finalist_terminate(void);

/* Real-time Model object */
extern RT_MODEL_finalist_T *const finalist_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'finalist'
 * '<S1>'   : 'finalist/cf'
 * '<S2>'   : 'finalist/r'
 */
#endif                                 /* RTW_HEADER_finalist_h_ */
