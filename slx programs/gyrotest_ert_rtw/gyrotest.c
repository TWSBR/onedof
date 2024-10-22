/*
 * gyrotest.c
 *
 * Code generation for model "gyrotest".
 *
 * Model version              : 5.11
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Apr  5 21:22:44 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gyrotest.h"
#include "gyrotest_types.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "gyrotest_private.h"

/* Block signals (default storage) */
B_gyrotest_T gyrotest_B;

/* Block states (default storage) */
DW_gyrotest_T gyrotest_DW;

/* Real-time model */
static RT_MODEL_gyrotest_T gyrotest_M_;
RT_MODEL_gyrotest_T *const gyrotest_M = &gyrotest_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_inter_T *g_arduinoMPU6050_arduinoMPU6050
  (codertarget_arduinobase_inter_T *obj);
static void gyrotest_SystemCore_setup(codertarget_arduinobase_inter_T *obj);
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

static void gyrotest_SystemCore_setup(codertarget_arduinobase_inter_T *obj)
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

    regSet = (uint8_T)((regSet & 248) | 1);
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

/* Model step function */
void gyrotest_step(void)
{
  i_codertarget_arduinobase_int_T *obj_tmp;
  int16_T i;
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* MATLABSystem: '<S1>/Base sensor block' */
  if (gyrotest_DW.obj.SampleTime != gyrotest_P.MPU6050IMUSensor_SampleTime) {
    gyrotest_DW.obj.SampleTime = gyrotest_P.MPU6050IMUSensor_SampleTime;
  }

  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  if (!gyrotest_DW.obj.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    gyrotest_DW.obj.IsFirstStep = true;
  }

  gyrotest_DW.obj.I2CReadWriteError = 0U;
  obj_tmp = &gyrotest_DW.obj.i2cObjmpu;
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
    if (gyrotest_DW.obj.InitializationFlag) {
      gyrotest_DW.obj.InitError = true;
    } else if (gyrotest_DW.obj.I2CReadWriteError == 0) {
      gyrotest_DW.obj.I2CReadWriteError = status;
    }
  }

  gyrotest_B.Basesensorblock_o1[0] = b_RegisterValue[0] << 8 | b_RegisterValue[1];
  gyrotest_B.Basesensorblock_o1[1] = b_RegisterValue[2] << 8 | b_RegisterValue[3];
  gyrotest_B.Basesensorblock_o1[2] = b_RegisterValue[4] << 8 | b_RegisterValue[5];
  if (gyrotest_DW.obj.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    gyrotest_B.Basesensorblock_o1[0] = 0.0;
    gyrotest_B.Basesensorblock_o1[1] = 0.0;
    gyrotest_B.Basesensorblock_o1[2] = 0.0;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    gyrotest_B.Basesensorblock_o1[0] = gyrotest_B.Basesensorblock_o1[0] *
      9.80665 / 16384.0;
    gyrotest_B.Basesensorblock_o1[1] = gyrotest_B.Basesensorblock_o1[1] *
      9.80665 / 16384.0;
    gyrotest_B.Basesensorblock_o1[2] = gyrotest_B.Basesensorblock_o1[2] *
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
    if (gyrotest_DW.obj.InitializationFlag) {
      gyrotest_DW.obj.InitError = true;
    } else if (gyrotest_DW.obj.I2CReadWriteError == 0) {
      gyrotest_DW.obj.I2CReadWriteError = status;
    }
  }

  gyrotest_B.Basesensorblock_o2[0] = b_RegisterValue[0] << 8 | b_RegisterValue[1];
  gyrotest_B.Basesensorblock_o2[1] = b_RegisterValue[2] << 8 | b_RegisterValue[3];
  gyrotest_B.Basesensorblock_o2[2] = b_RegisterValue[4] << 8 | b_RegisterValue[5];
  if (gyrotest_DW.obj.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    gyrotest_B.Basesensorblock_o2[0] = 0.0;
    gyrotest_B.Basesensorblock_o2[1] = 0.0;
    gyrotest_B.Basesensorblock_o2[2] = 0.0;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    gyrotest_B.Basesensorblock_o2[0] *= 0.00762939453125;
    gyrotest_B.Basesensorblock_o2[1] *= 0.00762939453125;
    gyrotest_B.Basesensorblock_o2[2] *= 0.00762939453125;
  }

  /* End of MATLABSystem: '<S1>/Base sensor block' */
  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor' */
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
  if (!(++gyrotest_M->Timing.clockTick0)) {
    ++gyrotest_M->Timing.clockTickH0;
  }

  gyrotest_M->Timing.taskTime0 = gyrotest_M->Timing.clockTick0 *
    gyrotest_M->Timing.stepSize0 + gyrotest_M->Timing.clockTickH0 *
    gyrotest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void gyrotest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)gyrotest_M, 0,
                sizeof(RT_MODEL_gyrotest_T));
  rtmSetTFinal(gyrotest_M, -1);
  gyrotest_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  gyrotest_M->Sizes.checksums[0] = (4098534100U);
  gyrotest_M->Sizes.checksums[1] = (1268267426U);
  gyrotest_M->Sizes.checksums[2] = (2691158650U);
  gyrotest_M->Sizes.checksums[3] = (3607090709U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    gyrotest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(gyrotest_M->extModeInfo,
      &gyrotest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(gyrotest_M->extModeInfo, gyrotest_M->Sizes.checksums);
    rteiSetTPtr(gyrotest_M->extModeInfo, rtmGetTPtr(gyrotest_M));
  }

  /* block I/O */
  (void) memset(((void *) &gyrotest_B), 0,
                sizeof(B_gyrotest_T));

  /* states (dwork) */
  (void) memset((void *)&gyrotest_DW, 0,
                sizeof(DW_gyrotest_T));

  /* Start for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Start for MATLABSystem: '<S1>/Base sensor block' */
  gyrotest_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
  gyrotest_DW.obj.matlabCodegenIsDeleted = true;
  g_arduinoMPU6050_arduinoMPU6050(&gyrotest_DW.obj);
  gyrotest_DW.objisempty = true;

  /* Start for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  gyrotest_DW.obj.SampleTime = gyrotest_P.MPU6050IMUSensor_SampleTime;

  /* End of Start for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  gyrotest_SystemCore_setup(&gyrotest_DW.obj);

  /* End of Start for SubSystem: '<Root>/MPU6050 IMU Sensor' */
}

/* Model terminate function */
void gyrotest_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Terminate for MATLABSystem: '<S1>/Base sensor block' */
  if (!gyrotest_DW.obj.matlabCodegenIsDeleted) {
    gyrotest_DW.obj.matlabCodegenIsDeleted = true;
    if ((gyrotest_DW.obj.isInitialized == 1L) && gyrotest_DW.obj.isSetupComplete)
    {
      obj = &gyrotest_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &gyrotest_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Base sensor block' */
  /* End of Terminate for SubSystem: '<Root>/MPU6050 IMU Sensor' */
}
