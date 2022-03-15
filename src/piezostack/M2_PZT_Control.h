#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: M2_PZT_Control.h
 *
 * Code generated for Simulink model 'M2_PZT_Control'.
 *
 * Model version                  : 1.900
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 14:24:24 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M2_PZT_Control_h_
#define RTW_HEADER_M2_PZT_Control_h_
#include <string.h>
#include <stddef.h>
#ifndef M2_PZT_Control_COMMON_INCLUDES_
# define M2_PZT_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M2_PZT_Control_COMMON_INCLUDES_ */

#include "M2_PZT_Control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteSS_DSTATE[15];        /* '<S12>/Discrete SS' */
  real_T DiscreteSS_DSTATE_a[20];      /* '<S13>/Discrete SS' */
  real_T DiscreteSS_DSTATE_j[15];      /* '<S14>/Discrete SS' */
  real_T DiscreteSS_DSTATE_af[20];     /* '<S15>/Discrete SS' */
  real_T DiscreteSS_DSTATE_c[15];      /* '<S16>/Discrete SS' */
  real_T DiscreteSS_DSTATE_l[20];      /* '<S17>/Discrete SS' */
  real_T DiscreteSS_DSTATE_jv[9];      /* '<S18>/Discrete SS' */
} DW_M2_PZT_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: kron(eye(3),[-1,1]))
   * Referenced by:
   *   '<S5>/rel_PZT_D'
   *   '<S6>/rel_PZT_D'
   *   '<S7>/rel_PZT_D'
   *   '<S8>/rel_PZT_D'
   *   '<S9>/rel_PZT_D'
   *   '<S10>/rel_PZT_D'
   *   '<S11>/rel_PZT_D'
   */
  real_T pooled1[18];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S12>/Discrete SS'
   *   '<S14>/Discrete SS'
   *   '<S16>/Discrete SS'
   */
  real_T pooled4[15];

  /* Pooled Parameter (Expression: kron(eye(3),[-1;1]))
   * Referenced by:
   *   '<S5>/spliF_matrix'
   *   '<S6>/spliF_matrix'
   *   '<S7>/spliF_matrix'
   *   '<S8>/spliF_matrix'
   *   '<S9>/spliF_matrix'
   *   '<S10>/spliF_matrix'
   *   '<S11>/spliF_matrix'
   */
  real_T pooled7[18];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S13>/Discrete SS'
   *   '<S15>/Discrete SS'
   *   '<S17>/Discrete SS'
   */
  real_T pooled10[15];
} ConstP_M2_PZT_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T TT_cmd[21];                   /* '<Root>/TT_cmd' */
  real_T PZT_FB[42];                   /* '<Root>/PZT_FB' */
} ExtU_M2_PZT_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T PZT_F[42];                    /* '<Root>/PZT_F' */
} ExtY_M2_PZT_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_M2_PZT_Control_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M2_PZT_Control_T M2_PZT_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M2_PZT_Control_T M2_PZT_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M2_PZT_Control_T M2_PZT_Control_Y;

/* Constant parameters (default storage) */
extern const ConstP_M2_PZT_Control_T M2_PZT_Control_ConstP;

/* Model entry point functions */
extern void M2_PZT_Control_initialize(void);
extern void M2_PZT_Control_step(void);
extern void M2_PZT_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M2_PZT_Control_T *const M2_PZT_Control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/rPZT' : Unused code path elimination
 * Block '<S12>/RTin' : Eliminated since input and output rates are identical
 * Block '<S12>/RTout' : Eliminated since input and output rates are identical
 * Block '<S13>/RTin' : Eliminated since input and output rates are identical
 * Block '<S13>/RTout' : Eliminated since input and output rates are identical
 * Block '<S14>/RTin' : Eliminated since input and output rates are identical
 * Block '<S14>/RTout' : Eliminated since input and output rates are identical
 * Block '<S15>/RTin' : Eliminated since input and output rates are identical
 * Block '<S15>/RTout' : Eliminated since input and output rates are identical
 * Block '<S16>/RTin' : Eliminated since input and output rates are identical
 * Block '<S16>/RTout' : Eliminated since input and output rates are identical
 * Block '<S17>/RTin' : Eliminated since input and output rates are identical
 * Block '<S17>/RTout' : Eliminated since input and output rates are identical
 * Block '<S18>/RTin' : Eliminated since input and output rates are identical
 * Block '<S18>/RTout' : Eliminated since input and output rates are identical
 * Block '<S1>/m2PZT_en' : Eliminated nontunable gain of 1
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
 * hilite_system('ims_Build5pt1e/M2_PZT_Control')    - opens subsystem ims_Build5pt1e/M2_PZT_Control
 * hilite_system('ims_Build5pt1e/M2_PZT_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1e'
 * '<S1>'   : 'ims_Build5pt1e/M2_PZT_Control'
 * '<S2>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT Selector'
 * '<S3>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT selector'
 * '<S4>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT selector1'
 * '<S5>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM1'
 * '<S6>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM2'
 * '<S7>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM3'
 * '<S8>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM4'
 * '<S9>'   : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM5'
 * '<S10>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM6'
 * '<S11>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM7'
 * '<S12>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM1/multi-rate SS'
 * '<S13>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM2/multi-rate SS'
 * '<S14>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM3/multi-rate SS'
 * '<S15>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM4/multi-rate SS'
 * '<S16>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM5/multi-rate SS'
 * '<S17>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM6/multi-rate SS'
 * '<S18>'  : 'ims_Build5pt1e/M2_PZT_Control/PZT_Control_FSM7/multi-rate SS'
 */
#endif                                 /* RTW_HEADER_M2_PZT_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
