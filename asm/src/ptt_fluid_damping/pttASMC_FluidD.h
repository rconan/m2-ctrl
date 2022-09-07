/*
 * File: pttASMC_FluidD.h
 *
 * Code generated for Simulink model 'pttASMC_FluidD'.
 *
 * Model version                  : 5.75
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Sep  2 10:56:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pttASMC_FluidD_h_
#define RTW_HEADER_pttASMC_FluidD_h_
#include <string.h>
#include <stddef.h>
#ifndef pttASMC_FluidD_COMMON_INCLUDES_
#define pttASMC_FluidD_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pttASMC_FluidD_COMMON_INCLUDES_ */

#include "pttASMC_FluidD_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Internal_DSTATE[126];         /* '<S3>/Internal' */
  real_T Internal_DSTATE_m[21];        /* '<S4>/Internal' */
  real_T UD_DSTATE[21];                /* '<S2>/UD' */
} DW_pttASMC_FluidD_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Internal_A
   * Referenced by: '<S3>/Internal'
   */
  real_T Internal_A[588];

  /* Computed Parameter: Internal_C
   * Referenced by: '<S3>/Internal'
   */
  real_T Internal_C[252];

  /* Expression: sm.Kd
   * Referenced by: '<S1>/Kd'
   */
  real_T Kd_Gain[441];

  /* Expression: kron([1;-1],kron(eye(7),[zeros(2,3);eye(3);zeros(1,3)]))
   * Referenced by: '<S1>/FzMxy_2_6F'
   */
  real_T FzMxy_2_6F_Gain[1764];

  /* Expression: sm.Kfd
   * Referenced by: '<S1>/Kfd'
   */
  real_T Kfd_Gain[441];

  /* Expression: kron([-1;1],kron(eye(7),[zeros(2,3);eye(3);zeros(1,3)]))
   * Referenced by: '<S1>/FzMxydamp_2_6F'
   */
  real_T FzMxydamp_2_6F_Gain[1764];
} ConstP_pttASMC_FluidD_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Rrbfs[21];                    /* '<Root>/Rrbfs' */
  real_T ASM_FS_6D[42];                /* '<Root>/ASM_FS_6D' */
  real_T ASM_RB_6D[42];                /* '<Root>/ASM_RB_6D' */
} ExtU_pttASMC_FluidD_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Ucp[42];                      /* '<Root>/Ucp' */
  real_T Urb[42];                      /* '<Root>/Urb' */
  real_T Ufs[42];                      /* '<Root>/Ufs' */
} ExtY_pttASMC_FluidD_T;

/* Real-time Model Data Structure */
struct tag_RTM_pttASMC_FluidD_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_pttASMC_FluidD_T pttASMC_FluidD_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_pttASMC_FluidD_T pttASMC_FluidD_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_pttASMC_FluidD_T pttASMC_FluidD_Y;

/* Constant parameters (default storage) */
extern const ConstP_pttASMC_FluidD_T pttASMC_FluidD_ConstP;

/* Model entry point functions */
extern void pttASMC_FluidD_initialize(void);
extern void pttASMC_FluidD_step(void);
extern void pttASMC_FluidD_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pttASMC_FluidD_T *const pttASMC_FluidD_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/gain2' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ims_Build5pt3b_PTTasm/pttASMC_FluidD')    - opens subsystem ims_Build5pt3b_PTTasm/pttASMC_FluidD
 * hilite_system('ims_Build5pt3b_PTTasm/pttASMC_FluidD/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt3b_PTTasm'
 * '<S1>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD'
 * '<S2>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Discrete Derivative'
 * '<S3>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Flagd'
 * '<S4>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Fpi_d'
 * '<S5>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Flagd/Input Delay'
 * '<S6>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Flagd/Output Delay'
 * '<S7>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Fpi_d/Input Delay'
 * '<S8>'   : 'ims_Build5pt3b_PTTasm/pttASMC_FluidD/Fpi_d/Output Delay'
 */
#endif                                 /* RTW_HEADER_pttASMC_FluidD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
