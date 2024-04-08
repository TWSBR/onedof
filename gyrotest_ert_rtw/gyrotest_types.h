/*
 * gyrotest_types.h
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

#ifndef RTW_HEADER_gyrotest_types_h_
#define RTW_HEADER_gyrotest_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<S1>/Base sensor block' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C_gy_T
#define typedef_c_arduinodriver_ArduinoI2C_gy_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_gy_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_gy_T */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C_gy_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_i_codertarget_arduinobase_int_T
#define typedef_i_codertarget_arduinobase_int_T

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG i_codertarget_arduinobase_int_T;

#endif                             /* typedef_i_codertarget_arduinobase_int_T */

#ifndef struct_tag_PPH3t26m7cLBRQSg9IpsaC
#define struct_tag_PPH3t26m7cLBRQSg9IpsaC

struct tag_PPH3t26m7cLBRQSg9IpsaC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  boolean_T IsFirstStep;
  i_codertarget_arduinobase_int_T i2cObjmpu;
  boolean_T MPUConnect;
  uint8_T I2CReadWriteError;
  boolean_T InitializationFlag;
  boolean_T InitError;
};

#endif                                 /* struct_tag_PPH3t26m7cLBRQSg9IpsaC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_PPH3t26m7cLBRQSg9IpsaC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_gyrotest_T_ P_gyrotest_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_gyrotest_T RT_MODEL_gyrotest_T;

#endif                                 /* RTW_HEADER_gyrotest_types_h_ */
