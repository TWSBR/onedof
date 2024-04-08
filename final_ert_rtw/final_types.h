/*
 * final_types.h
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

#ifndef RTW_HEADER_final_types_h_
#define RTW_HEADER_final_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_UhdjAlk5m2xbK6E3oTj7hC
#define struct_tag_UhdjAlk5m2xbK6E3oTj7hC

struct tag_UhdjAlk5m2xbK6E3oTj7hC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_UhdjAlk5m2xbK6E3oTj7hC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_UhdjAlk5m2xbK6E3oTj7hC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Custom Type definition for MATLABSystem: '<S3>/MPU6050 IMU Sensor' */
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

#ifndef typedef_codertarget_arduinobase_int_k_T
#define typedef_codertarget_arduinobase_int_k_T

typedef struct tag_pKaMlIDB7t6p8HEWJiqmMD codertarget_arduinobase_int_k_T;

#endif                             /* typedef_codertarget_arduinobase_int_k_T */

/* Parameters (default storage) */
typedef struct P_final_T_ P_final_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_final_T RT_MODEL_final_T;

#endif                                 /* RTW_HEADER_final_types_h_ */
