/*
 * finalist_types.h
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

#ifndef RTW_HEADER_finalist_types_h_
#define RTW_HEADER_finalist_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S2>/MPU6050 IMU Sensor' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C_fi_T
#define typedef_c_arduinodriver_ArduinoI2C_fi_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_fi_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_fi_T */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C_fi_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_i_codertarget_arduinobase_int_T
#define typedef_i_codertarget_arduinobase_int_T

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG i_codertarget_arduinobase_int_T;

#endif                             /* typedef_i_codertarget_arduinobase_int_T */

#ifndef struct_tag_pKaMlIDB7t6p8HEWJiqmMD
#define struct_tag_pKaMlIDB7t6p8HEWJiqmMD

struct tag_pKaMlIDB7t6p8HEWJiqmMD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  i_codertarget_arduinobase_int_T i2cObjmpu;
  boolean_T MPUConnect;
  uint8_T I2CReadWriteError;
  boolean_T InitializationFlag;
  boolean_T InitError;
};

#endif                                 /* struct_tag_pKaMlIDB7t6p8HEWJiqmMD */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_pKaMlIDB7t6p8HEWJiqmMD codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_finalist_T_ P_finalist_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_finalist_T RT_MODEL_finalist_T;

#endif                                 /* RTW_HEADER_finalist_types_h_ */
