#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: TT_Control.h
 *
 * Code generated for Simulink model 'TT_Control'.
 *
 * Model version                  : 1.901
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 14:29:48 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TT_Control_h_
#define RTW_HEADER_TT_Control_h_
#include <string.h>
#include <stddef.h>
#ifndef TT_Control_COMMON_INCLUDES_
# define TT_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TT_Control_COMMON_INCLUDES_ */

#include "TT_Control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TTController_DSTATE[14];      /* '<S1>/TT Controller' */
} DW_TT_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: tt7.TT2PZT
   * Referenced by: '<S1>/TT2PZT'
   */
  real_T TT2PZT_Gain[294];
} ConstP_TT_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T TT_SP;                        /* '<Root>/TT_SP' */
  real_T TT_FB[14];                    /* '<Root>/TT_FB' */
} ExtU_TT_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TT_cmd[21];                   /* '<Root>/TT_cmd' */
} ExtY_TT_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_TT_Control_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TT_Control_T TT_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TT_Control_T TT_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TT_Control_T TT_Control_Y;

/* Constant parameters (default storage) */
extern const ConstP_TT_Control_T TT_Control_ConstP;

/* Model entry point functions */
extern void TT_Control_initialize(void);
extern void TT_Control_step(void);
extern void TT_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TT_Control_T *const TT_Control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/m2TT_en' : Eliminated nontunable gain of 1
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
 * hilite_system('ims_Build5pt1e/TT_Control')    - opens subsystem ims_Build5pt1e/TT_Control
 * hilite_system('ims_Build5pt1e/TT_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1e'
 * '<S1>'   : 'ims_Build5pt1e/TT_Control'
 */
#endif                                 /* RTW_HEADER_TT_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
