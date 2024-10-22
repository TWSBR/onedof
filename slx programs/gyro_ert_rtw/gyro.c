/*
 * gyro.c
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
#include "gyro_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "gyro_private.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_gyro_T gyro_B;

/* Block states (default storage) */
DW_gyro_T gyro_DW;

/* Real-time model */
static RT_MODEL_gyro_T gyro_M_;
RT_MODEL_gyro_T *const gyro_M = &gyro_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_inter_T *g_arduinoMPU6050_arduinoMPU6050
  (codertarget_arduinobase_inter_T *obj);
static void gyro_SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static codertarget_arduinobase_inter_T *g_arduinoMPU6050_arduinoMPU6050
  (codertarget_arduinobase_inter_T *obj)
{
  codertarget_arduinobase_inter_T *b_obj;
  obj->I2CReadWriteError = 0U;
  obj->InitError = false;
  obj->isInitialized = 0L;
  obj->SampleTime = -1.0;
  obj->IsFirstStep = false;
  b_obj = obj;
  obj->i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  obj->i2cObjmpu.isInitialized = 0L;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = NULL;
  obj->i2cObjmpu.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void gyro_SystemCore_setup(codertarget_arduinobase_inter_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regSet;
  uint8_T status;
  obj->isInitialized = 1L;
  obj->InitializationFlag = true;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObjmpu.BusSpeed = 100000UL;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE,
                     obj->i2cObjmpu.BusSpeed);
  regSet = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
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
  regSet = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
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
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes_0, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                      &SwappedDataBytes_0, 1UL, false, true);
    memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
           (uint8_T));
  } else {
    regSet = 0U;
  }

  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  obj->MPUConnect = (regSet == 104);
  if (obj->MPUConnect) {
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
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
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
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
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
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
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)((regSet & 248) | 5);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T tmp;
  int16_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
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

/* Model step function */
void gyro_step(void)
{
  i_codertarget_arduinobase_int_T *obj_tmp;
  real_T AccelData_idx_0;
  real_T AccelData_idx_2;
  real_T GyroData_idx_0;
  int16_T i;
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Atomic SubSystem: '<S2>/MPU6050 IMU Sensor' */
  /* Outputs for Atomic SubSystem: '<S2>/MPU6050 IMU Sensor' */
  /* MATLABSystem: '<S3>/Base sensor block' */
  if (gyro_DW.obj.SampleTime != gyro_P.MPU6050IMUSensor_SampleTime) {
    gyro_DW.obj.SampleTime = gyro_P.MPU6050IMUSensor_SampleTime;
  }

  /* End of Outputs for SubSystem: '<S2>/MPU6050 IMU Sensor' */
  if (!gyro_DW.obj.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    gyro_DW.obj.IsFirstStep = true;
  }

  gyro_DW.obj.I2CReadWriteError = 0U;
  obj_tmp = &gyro_DW.obj.i2cObjmpu;
  status = 59U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
           sizeof(uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (gyro_DW.obj.InitializationFlag) {
      gyro_DW.obj.InitError = true;
    } else if (gyro_DW.obj.I2CReadWriteError == 0) {
      gyro_DW.obj.I2CReadWriteError = status;
    }
  }

  if (gyro_DW.obj.InitError) {
    AccelData_idx_0 = 0.0;
    AccelData_idx_2 = 0.0;
  } else {
    AccelData_idx_0 = (real_T)(b_RegisterValue[0] << 8 | b_RegisterValue[1]) *
      9.80665 / 16384.0;
    AccelData_idx_2 = (real_T)(b_RegisterValue[4] << 8 | b_RegisterValue[5]) *
      9.80665 / 16384.0;
  }

  status = 67U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
           sizeof(uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (gyro_DW.obj.InitializationFlag) {
      gyro_DW.obj.InitError = true;
    } else if (gyro_DW.obj.I2CReadWriteError == 0) {
      gyro_DW.obj.I2CReadWriteError = status;
    }
  }

  if (gyro_DW.obj.InitError) {
    GyroData_idx_0 = 0.0;
  } else {
    GyroData_idx_0 = (real_T)(b_RegisterValue[0] << 8 | b_RegisterValue[1]) *
      0.00762939453125;
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Ts'
   *  MATLABSystem: '<S3>/Base sensor block'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S2>/Sum'
   *  Trigonometry: '<S2>/Atan2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  gyro_DW.UnitDelay_DSTATE = ((GyroData_idx_0 - gyro_P.Constant_Value) *
    gyro_P.Ts_Gain + gyro_DW.UnitDelay_DSTATE) * gyro_P.c + (1.0 - gyro_P.c) *
    rt_atan2d_snf(AccelData_idx_0, AccelData_idx_2);

  /* End of Outputs for SubSystem: '<S2>/MPU6050 IMU Sensor' */

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Add1'
   */
  gyro_B.deg = (gyro_DW.UnitDelay_DSTATE + gyro_P.Constant1_Value) *
    gyro_P.Gain2_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (gyro_B.deg > gyro_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    gyro_B.Saturation = gyro_P.Saturation_UpperSat;
  } else if (gyro_B.deg < gyro_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    gyro_B.Saturation = gyro_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    gyro_B.Saturation = gyro_B.deg;
  }

  /* End of Saturate: '<Root>/Saturation' */
  {                                    /* Sample time: [0.05s, 0.0s] */
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
  if (!(++gyro_M->Timing.clockTick0)) {
    ++gyro_M->Timing.clockTickH0;
  }

  gyro_M->Timing.taskTime0 = gyro_M->Timing.clockTick0 *
    gyro_M->Timing.stepSize0 + gyro_M->Timing.clockTickH0 *
    gyro_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void gyro_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)gyro_M, 0,
                sizeof(RT_MODEL_gyro_T));
  rtmSetTFinal(gyro_M, -1);
  gyro_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  gyro_M->Sizes.checksums[0] = (1735657038U);
  gyro_M->Sizes.checksums[1] = (601423141U);
  gyro_M->Sizes.checksums[2] = (76857045U);
  gyro_M->Sizes.checksums[3] = (912385084U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    gyro_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(gyro_M->extModeInfo,
      &gyro_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(gyro_M->extModeInfo, gyro_M->Sizes.checksums);
    rteiSetTPtr(gyro_M->extModeInfo, rtmGetTPtr(gyro_M));
  }

  /* block I/O */
  (void) memset(((void *) &gyro_B), 0,
                sizeof(B_gyro_T));

  /* states (dwork) */
  (void) memset((void *)&gyro_DW, 0,
                sizeof(DW_gyro_T));

  /* Start for Atomic SubSystem: '<S2>/MPU6050 IMU Sensor' */
  /* Start for MATLABSystem: '<S3>/Base sensor block' */
  gyro_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
  gyro_DW.obj.matlabCodegenIsDeleted = true;
  g_arduinoMPU6050_arduinoMPU6050(&gyro_DW.obj);
  gyro_DW.objisempty = true;

  /* Start for Atomic SubSystem: '<S2>/MPU6050 IMU Sensor' */
  gyro_DW.obj.SampleTime = gyro_P.MPU6050IMUSensor_SampleTime;

  /* End of Start for SubSystem: '<S2>/MPU6050 IMU Sensor' */
  gyro_SystemCore_setup(&gyro_DW.obj);

  /* End of Start for SubSystem: '<S2>/MPU6050 IMU Sensor' */

  /* InitializeConditions for Sum: '<S1>/Add' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  gyro_DW.UnitDelay_DSTATE = gyro_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void gyro_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for Atomic SubSystem: '<S2>/MPU6050 IMU Sensor' */
  /* Terminate for MATLABSystem: '<S3>/Base sensor block' */
  if (!gyro_DW.obj.matlabCodegenIsDeleted) {
    gyro_DW.obj.matlabCodegenIsDeleted = true;
    if ((gyro_DW.obj.isInitialized == 1L) && gyro_DW.obj.isSetupComplete) {
      obj = &gyro_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &gyro_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Base sensor block' */
  /* End of Terminate for SubSystem: '<S2>/MPU6050 IMU Sensor' */
}
