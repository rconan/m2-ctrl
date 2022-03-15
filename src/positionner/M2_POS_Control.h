#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: M2_POS_Control.h
 *
 * Code generated for Simulink model 'M2_POS_Control'.
 *
 * Model version                  : 1.900
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 14:23:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M2_POS_Control_h_
#define RTW_HEADER_M2_POS_Control_h_
#include <string.h>
#include <stddef.h>
#ifndef M2_POS_Control_COMMON_INCLUDES_
# define M2_POS_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M2_POS_Control_COMMON_INCLUDES_ */

#include "M2_POS_Control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T FBcontroller_states[126];     /* '<S1>/FB controller' */
} DW_M2_POS_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m2pos.Km2p_dec
   * Referenced by: '<S1>/Gain'
   */
  real_T Gain_Gain[1764];

  /* Expression: kron(eye(42),[1;-1])
   * Referenced by: '<S1>/kron(eye(42),[1;-1])'
   */
  real_T kroneye4211_Gain[3528];
} ConstP_M2_POS_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T M2_pos_cmd[42];               /* '<Root>/M2_pos_cmd' */
  real_T M2_pos_FB[84];                /* '<Root>/M2_pos_FB' */
} ExtU_M2_POS_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T M2_pos_act_F[84];             /* '<Root>/M2_pos_act_F' */
} ExtY_M2_POS_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_M2_POS_Control_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M2_POS_Control_T M2_POS_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M2_POS_Control_T M2_POS_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M2_POS_Control_T M2_POS_Control_Y;

/* Constant parameters (default storage) */
extern const ConstP_M2_POS_Control_T M2_POS_Control_ConstP;

/* Model entry point functions */
extern void M2_POS_Control_initialize(void);
extern void M2_POS_Control_step(void);
extern void M2_POS_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M2_POS_Control_T *const M2_POS_Control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/m2_pos_en' : Eliminated nontunable gain of 1
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
 * hilite_system('ims_Build5pt1e/M2_POS_Control')    - opens subsystem ims_Build5pt1e/M2_POS_Control
 * hilite_system('ims_Build5pt1e/M2_POS_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1e'
 * '<S1>'   : 'ims_Build5pt1e/M2_POS_Control'
 */
#endif                                 /* RTW_HEADER_M2_POS_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
