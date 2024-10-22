/*
 * finalist.c
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
#include "finalist_dt.h"

/* Block signals (default storage) */
B_finalist_T finalist_B;

/* Block states (default storage) */
DW_finalist_T finalist_DW;

/* Real-time model */
static RT_MODEL_finalist_T finalist_M_;
RT_MODEL_finalist_T *const finalist_M = &finalist_M_;

/* Forward declaration for local functions */
static void finalist_SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static void finalist_SystemCore_setup(codertarget_arduinobase_inter_T *obj)
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

/* Model step function */
void finalist_step(void)
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

  /* MATLABSystem: '<S2>/MPU6050 IMU Sensor' */
  if (finalist_DW.obj.SampleTime != finalist_P.MPU6050IMUSensor_SampleTime) {
    finalist_DW.obj.SampleTime = finalist_P.MPU6050IMUSensor_SampleTime;
  }

  finalist_DW.obj.I2CReadWriteError = 0U;
  obj = &finalist_DW.obj.i2cObjmpu;
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
    if (finalist_DW.obj.InitializationFlag) {
      finalist_DW.obj.InitError = true;
    } else if (finalist_DW.obj.I2CReadWriteError == 0) {
      finalist_DW.obj.I2CReadWriteError = status;
    }
  }

  if (finalist_DW.obj.InitError) {
    AccelData_idx_0 = 0.0;
  } else {
    AccelData_idx_0 = (real_T)(b_RegisterValue[0] << 8 | b_RegisterValue[1]) *
      9.80665 / 16384.0;
  }

  if (finalist_DW.obj.InitError) {
    AccelData = 0.0;
  } else {
    AccelData = (real_T)(b_RegisterValue[4] << 8 | b_RegisterValue[5]) * 9.80665
      / 16384.0;
  }

  obj = &finalist_DW.obj.i2cObjmpu;
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
    if (finalist_DW.obj.InitializationFlag) {
      finalist_DW.obj.InitError = true;
    } else if (finalist_DW.obj.I2CReadWriteError == 0) {
      finalist_DW.obj.I2CReadWriteError = status;
    }
  }

  if (finalist_DW.obj.InitError) {
    GyroData = 0.0;
  } else {
    GyroData = (real_T)(b_RegisterValue[0] << 8 | b_RegisterValue[1]) *
      0.00762939453125;
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Ts'
   *  MATLABSystem: '<S2>/MPU6050 IMU Sensor'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S2>/Sum'
   *  Trigonometry: '<S2>/Atan2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  finalist_DW.UnitDelay_DSTATE = ((GyroData - finalist_P.Constant_Value) *
    finalist_P.Ts_Gain + finalist_DW.UnitDelay_DSTATE) * finalist_P.c + (1.0 -
    finalist_P.c) * rt_atan2d_snf(AccelData_idx_0, AccelData);

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Add1'
   */
  finalist_B.deg = (finalist_DW.UnitDelay_DSTATE + finalist_P.Constant1_Value) *
    finalist_P.Gain2_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (finalist_B.deg > finalist_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    finalist_B.Saturation = finalist_P.Saturation_UpperSat;
  } else if (finalist_B.deg < finalist_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    finalist_B.Saturation = finalist_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    finalist_B.Saturation = finalist_B.deg;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, (real_T)finalist_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(finalist_M)!=-1) &&
        !((rtmGetTFinal(finalist_M)-finalist_M->Timing.taskTime0) >
          finalist_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(finalist_M, "Simulation finished");
    }

    if (rtmGetStopRequested(finalist_M)) {
      rtmSetErrorStatus(finalist_M, "Simulation finished");
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
  if (!(++finalist_M->Timing.clockTick0)) {
    ++finalist_M->Timing.clockTickH0;
  }

  finalist_M->Timing.taskTime0 = finalist_M->Timing.clockTick0 *
    finalist_M->Timing.stepSize0 + finalist_M->Timing.clockTickH0 *
    finalist_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void finalist_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)finalist_M, 0,
                sizeof(RT_MODEL_finalist_T));
  rtmSetTFinal(finalist_M, -1);
  finalist_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  finalist_M->Sizes.checksums[0] = (1085796973U);
  finalist_M->Sizes.checksums[1] = (2245852635U);
  finalist_M->Sizes.checksums[2] = (4055678679U);
  finalist_M->Sizes.checksums[3] = (32738348U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    finalist_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(finalist_M->extModeInfo,
      &finalist_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(finalist_M->extModeInfo, finalist_M->Sizes.checksums);
    rteiSetTPtr(finalist_M->extModeInfo, rtmGetTPtr(finalist_M));
  }

  /* block I/O */
  (void) memset(((void *) &finalist_B), 0,
                sizeof(B_finalist_T));

  /* states (dwork) */
  (void) memset((void *)&finalist_DW, 0,
                sizeof(DW_finalist_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    finalist_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    i_codertarget_arduinobase_int_T *obj;

    /* Start for MATLABSystem: '<S2>/MPU6050 IMU Sensor' */
    finalist_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    finalist_DW.obj.matlabCodegenIsDeleted = true;
    finalist_DW.obj.I2CReadWriteError = 0U;
    finalist_DW.obj.InitError = false;
    finalist_DW.obj.isInitialized = 0L;
    finalist_DW.obj.SampleTime = -1.0;
    obj = &finalist_DW.obj.i2cObjmpu;
    finalist_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
    finalist_DW.obj.i2cObjmpu.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    finalist_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
    finalist_DW.obj.matlabCodegenIsDeleted = false;
    finalist_DW.objisempty = true;
    finalist_DW.obj.SampleTime = finalist_P.MPU6050IMUSensor_SampleTime;
    finalist_SystemCore_setup(&finalist_DW.obj);
  }

  /* InitializeConditions for Sum: '<S1>/Add' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  finalist_DW.UnitDelay_DSTATE = finalist_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void finalist_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for MATLABSystem: '<S2>/MPU6050 IMU Sensor' */
  if (!finalist_DW.obj.matlabCodegenIsDeleted) {
    finalist_DW.obj.matlabCodegenIsDeleted = true;
    if ((finalist_DW.obj.isInitialized == 1L) && finalist_DW.obj.isSetupComplete)
    {
      obj = &finalist_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &finalist_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/MPU6050 IMU Sensor' */
}
