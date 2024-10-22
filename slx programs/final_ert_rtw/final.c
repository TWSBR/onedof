/*
 * final.c
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

#include "final.h"
#include "final_private.h"
#include "final_dt.h"

/* Block signals (default storage) */
B_final_T final_B;

/* Block states (default storage) */
DW_final_T final_DW;

/* Real-time model */
static RT_MODEL_final_T final_M_;
RT_MODEL_final_T *const final_M = &final_M_;

/* Forward declaration for local functions */
static void final_SystemCore_setup(codertarget_arduinobase_int_k_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void final_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(final_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(final_M, 2));
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
  (final_M->Timing.TaskCounters.TID[1])++;
  if ((final_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    final_M->Timing.TaskCounters.TID[1] = 0;
  }

  (final_M->Timing.TaskCounters.TID[2])++;
  if ((final_M->Timing.TaskCounters.TID[2]) > 499) {/* Sample time: [0.05s, 0.0s] */
    final_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void final_SystemCore_setup(codertarget_arduinobase_int_k_T *obj)
{
  uint32_T i2cname;
  i_codertarget_arduinobase_int_T *obj_0;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes_0;
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1L;
  obj->InitializationFlag = true;
  obj_0 = &obj->i2cObjmpu;
  i2cname = 0;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  obj->i2cObjmpu.BusSpeed = 100000UL;
  varargin_1 = obj->i2cObjmpu.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  CastedData = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint16_T)
         ((size_t)2 * sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(1UL);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint16_T)
         ((size_t)2 * sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(100UL);
  status = 117U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes_0, 1UL, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                      &SwappedDataBytes_0, 1UL, false, true);
    memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)((size_t)
            1 * sizeof(uint8_T)));
  } else {
    CastedData = 0U;
  }

  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  obj->MPUConnect = (CastedData == 104);
  if (obj->MPUConnect) {
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 28U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)
             ((size_t)1 * sizeof(uint8_T)));
    } else {
      CastedData = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    CastedData = (uint8_T)(CastedData & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 27U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)
             ((size_t)1 * sizeof(uint8_T)));
    } else {
      CastedData = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    CastedData = (uint8_T)(CastedData & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 26U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)
             ((size_t)1 * sizeof(uint8_T)));
    } else {
      CastedData = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    CastedData = (uint8_T)((CastedData & 248) | 5);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }
  } else {
    obj->InitError = true;
  }

  obj->InitializationFlag = false;
  obj->isSetupComplete = true;
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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void final_step0(void)                 /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(0, (real_T)final_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0001s, 0.0s] */
    if ((rtmGetTFinal(final_M)!=-1) &&
        !((rtmGetTFinal(final_M)-final_M->Timing.taskTime0) >
          final_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(final_M, "Simulation finished");
    }

    if (rtmGetStopRequested(final_M)) {
      rtmSetErrorStatus(final_M, "Simulation finished");
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
  if (!(++final_M->Timing.clockTick0)) {
    ++final_M->Timing.clockTickH0;
  }

  final_M->Timing.taskTime0 = final_M->Timing.clockTick0 *
    final_M->Timing.stepSize0 + final_M->Timing.clockTickH0 *
    final_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void final_step1(void)                 /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_PulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (final_DW.clockTickCounter < final_P.PulseGenerator_Duty)
    && (final_DW.clockTickCounter >= 0L) ? final_P.PulseGenerator_Amp : 0.0;
  if (final_DW.clockTickCounter >= final_P.PulseGenerator_Period - 1.0) {
    final_DW.clockTickCounter = 0L;
  } else {
    final_DW.clockTickCounter++;
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
  rtExtModeUpload(1, (real_T)(((final_M->Timing.clockTick1+
    final_M->Timing.clockTickH1* 4294967296.0)) * 0.001));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  final_M->Timing.clockTick1++;
  if (!final_M->Timing.clockTick1) {
    final_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void final_step2(void)                 /* Sample time: [0.05s, 0.0s] */
{
  i_codertarget_arduinobase_int_T *obj;
  real_T AccelData;
  real_T AccelData_idx_0;
  real_T GyroData;
  int16_T i;
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* MATLABSystem: '<S3>/MPU6050 IMU Sensor' */
  if (final_DW.obj.SampleTime != final_P.MPU6050IMUSensor_SampleTime) {
    final_DW.obj.SampleTime = final_P.MPU6050IMUSensor_SampleTime;
  }

  final_DW.obj.I2CReadWriteError = 0U;
  obj = &final_DW.obj.i2cObjmpu;
  status = 59U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint16_T)
           ((size_t)6 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (final_DW.obj.InitializationFlag) {
      final_DW.obj.InitError = true;
    } else if (final_DW.obj.I2CReadWriteError == 0) {
      final_DW.obj.I2CReadWriteError = status;
    }
  }

  if (final_DW.obj.InitError) {
    AccelData_idx_0 = 0.0;
  } else {
    AccelData_idx_0 = (real_T)(b_RegisterValue[0] << 8 | b_RegisterValue[1]) *
      9.80665 / 16384.0;
  }

  if (final_DW.obj.InitError) {
    AccelData = 0.0;
  } else {
    AccelData = (real_T)(b_RegisterValue[4] << 8 | b_RegisterValue[5]) * 9.80665
      / 16384.0;
  }

  obj = &final_DW.obj.i2cObjmpu;
  status = 67U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint16_T)
           ((size_t)6 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (final_DW.obj.InitializationFlag) {
      final_DW.obj.InitError = true;
    } else if (final_DW.obj.I2CReadWriteError == 0) {
      final_DW.obj.I2CReadWriteError = status;
    }
  }

  if (final_DW.obj.InitError) {
    GyroData = 0.0;
  } else {
    GyroData = (real_T)(b_RegisterValue[0] << 8 | b_RegisterValue[1]) *
      0.00762939453125;
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Ts'
   *  MATLABSystem: '<S3>/MPU6050 IMU Sensor'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S3>/Sum'
   *  Trigonometry: '<S3>/Atan2'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  final_DW.UnitDelay_DSTATE = ((GyroData - final_P.Constant_Value) *
    final_P.Ts_Gain + final_DW.UnitDelay_DSTATE) * final_P.c + (1.0 - final_P.c)
    * rt_atan2d_snf(AccelData_idx_0, AccelData);

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Add1'
   */
  final_B.deg = (final_DW.UnitDelay_DSTATE + final_P.Constant1_Value) *
    final_P.Gain2_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (final_B.deg > final_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    final_B.Saturation = final_P.Saturation_UpperSat;
  } else if (final_B.deg < final_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    final_B.Saturation = final_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    final_B.Saturation = final_B.deg;
  }

  /* End of Saturate: '<Root>/Saturation' */
  rtExtModeUpload(2, (real_T)(((final_M->Timing.clockTick2+
    final_M->Timing.clockTickH2* 4294967296.0)) * 0.05));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  final_M->Timing.clockTick2++;
  if (!final_M->Timing.clockTick2) {
    final_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void final_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)final_M, 0,
                sizeof(RT_MODEL_final_T));
  rtmSetTFinal(final_M, -1);
  final_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  final_M->Sizes.checksums[0] = (2895729274U);
  final_M->Sizes.checksums[1] = (2659255459U);
  final_M->Sizes.checksums[2] = (2738522377U);
  final_M->Sizes.checksums[3] = (2371351012U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    final_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(final_M->extModeInfo,
      &final_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(final_M->extModeInfo, final_M->Sizes.checksums);
    rteiSetTPtr(final_M->extModeInfo, rtmGetTPtr(final_M));
  }

  /* block I/O */
  (void) memset(((void *) &final_B), 0,
                sizeof(B_final_T));

  /* states (dwork) */
  (void) memset((void *)&final_DW, 0,
                sizeof(DW_final_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    final_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    i_codertarget_arduinobase_int_T *obj;

    /* Start for MATLABSystem: '<Root>/Continuous Servo Write' */
    final_DW.obj_d.isInitialized = 0L;
    final_DW.objisempty_l = true;
    final_DW.obj_d.isInitialized = 1L;
    MW_servoAttach(0, 9);

    /* Start for MATLABSystem: '<S3>/MPU6050 IMU Sensor' */
    final_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    final_DW.obj.matlabCodegenIsDeleted = true;
    final_DW.obj.I2CReadWriteError = 0U;
    final_DW.obj.InitError = false;
    final_DW.obj.isInitialized = 0L;
    final_DW.obj.SampleTime = -1.0;
    obj = &final_DW.obj.i2cObjmpu;
    final_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
    final_DW.obj.i2cObjmpu.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    final_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
    final_DW.obj.matlabCodegenIsDeleted = false;
    final_DW.objisempty = true;
    final_DW.obj.SampleTime = final_P.MPU6050IMUSensor_SampleTime;
    final_SystemCore_setup(&final_DW.obj);
  }

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  final_DW.clockTickCounter = -1L;

  /* InitializeConditions for Sum: '<S2>/Add' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  final_DW.UnitDelay_DSTATE = final_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void final_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for MATLABSystem: '<S3>/MPU6050 IMU Sensor' */
  if (!final_DW.obj.matlabCodegenIsDeleted) {
    final_DW.obj.matlabCodegenIsDeleted = true;
    if ((final_DW.obj.isInitialized == 1L) && final_DW.obj.isSetupComplete) {
      obj = &final_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &final_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/MPU6050 IMU Sensor' */
}
