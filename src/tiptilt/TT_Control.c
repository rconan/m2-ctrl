/*
 * File: TT_Control.c
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

#include "TT_Control.h"
#include "TT_Control_private.h"

/* Block states (default storage) */
DW_TT_Control_T TT_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TT_Control_T TT_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TT_Control_T TT_Control_Y;

/* Real-time model */
RT_MODEL_TT_Control_T TT_Control_M_;
RT_MODEL_TT_Control_T *const TT_Control_M = &TT_Control_M_;

/* Model step function */
void TT_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum1[14];
  real_T rtb_TTController[14];
  int32_T i;
  int32_T i_0;
  int32_T tmp;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/TT_FB'
   *  Inport: '<Root>/TT_SP'
   */
  for (i = 0; i < 14; i++) {
    rtb_Sum1[i] = TT_Control_U.TT_SP - TT_Control_U.TT_FB[i];
  }

  /* End of Sum: '<S1>/Sum1' */

  /* DiscreteStateSpace: '<S1>/TT Controller' */
  {
    rtb_TTController[0] = (0.6)*TT_Control_DW.TTController_DSTATE[0];
    rtb_TTController[0] += (0.15)*rtb_Sum1[0];
    rtb_TTController[1] = (0.6)*TT_Control_DW.TTController_DSTATE[1];
    rtb_TTController[1] += (0.15)*rtb_Sum1[1];
    rtb_TTController[2] = (0.6)*TT_Control_DW.TTController_DSTATE[2];
    rtb_TTController[2] += (0.15)*rtb_Sum1[2];
    rtb_TTController[3] = (0.6)*TT_Control_DW.TTController_DSTATE[3];
    rtb_TTController[3] += (0.15)*rtb_Sum1[3];
    rtb_TTController[4] = (0.6)*TT_Control_DW.TTController_DSTATE[4];
    rtb_TTController[4] += (0.15)*rtb_Sum1[4];
    rtb_TTController[5] = (0.6)*TT_Control_DW.TTController_DSTATE[5];
    rtb_TTController[5] += (0.15)*rtb_Sum1[5];
    rtb_TTController[6] = (0.6)*TT_Control_DW.TTController_DSTATE[6];
    rtb_TTController[6] += (0.15)*rtb_Sum1[6];
    rtb_TTController[7] = (0.6)*TT_Control_DW.TTController_DSTATE[7];
    rtb_TTController[7] += (0.15)*rtb_Sum1[7];
    rtb_TTController[8] = (0.6)*TT_Control_DW.TTController_DSTATE[8];
    rtb_TTController[8] += (0.15)*rtb_Sum1[8];
    rtb_TTController[9] = (0.6)*TT_Control_DW.TTController_DSTATE[9];
    rtb_TTController[9] += (0.15)*rtb_Sum1[9];
    rtb_TTController[10] = (0.6)*TT_Control_DW.TTController_DSTATE[10];
    rtb_TTController[10] += (0.15)*rtb_Sum1[10];
    rtb_TTController[11] = (0.6)*TT_Control_DW.TTController_DSTATE[11];
    rtb_TTController[11] += (0.15)*rtb_Sum1[11];
    rtb_TTController[12] = (0.6)*TT_Control_DW.TTController_DSTATE[12];
    rtb_TTController[12] += (0.15)*rtb_Sum1[12];
    rtb_TTController[13] = (0.6)*TT_Control_DW.TTController_DSTATE[13];
    rtb_TTController[13] += (0.15)*rtb_Sum1[13];
  }

  /* Outport: '<Root>/TT_cmd' incorporates:
   *  Gain: '<S1>/TT2PZT'
   */
  for (i = 0; i < 21; i++) {
    TT_Control_Y.TT_cmd[i] = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 14; i_0++) {
      TT_Control_Y.TT_cmd[i] += TT_Control_ConstP.TT2PZT_Gain[tmp + i] *
        rtb_TTController[i_0];
      tmp += 21;
    }
  }

  /* End of Outport: '<Root>/TT_cmd' */

  /* Update for DiscreteStateSpace: '<S1>/TT Controller' */
  {
    real_T xnew[14];
    xnew[0] = (1.0)*TT_Control_DW.TTController_DSTATE[0];
    xnew[0] += (0.5)*rtb_Sum1[0];
    xnew[1] = (1.0)*TT_Control_DW.TTController_DSTATE[1];
    xnew[1] += (0.5)*rtb_Sum1[1];
    xnew[2] = (1.0)*TT_Control_DW.TTController_DSTATE[2];
    xnew[2] += (0.5)*rtb_Sum1[2];
    xnew[3] = (1.0)*TT_Control_DW.TTController_DSTATE[3];
    xnew[3] += (0.5)*rtb_Sum1[3];
    xnew[4] = (1.0)*TT_Control_DW.TTController_DSTATE[4];
    xnew[4] += (0.5)*rtb_Sum1[4];
    xnew[5] = (1.0)*TT_Control_DW.TTController_DSTATE[5];
    xnew[5] += (0.5)*rtb_Sum1[5];
    xnew[6] = (1.0)*TT_Control_DW.TTController_DSTATE[6];
    xnew[6] += (0.5)*rtb_Sum1[6];
    xnew[7] = (1.0)*TT_Control_DW.TTController_DSTATE[7];
    xnew[7] += (0.5)*rtb_Sum1[7];
    xnew[8] = (1.0)*TT_Control_DW.TTController_DSTATE[8];
    xnew[8] += (0.5)*rtb_Sum1[8];
    xnew[9] = (1.0)*TT_Control_DW.TTController_DSTATE[9];
    xnew[9] += (0.5)*rtb_Sum1[9];
    xnew[10] = (1.0)*TT_Control_DW.TTController_DSTATE[10];
    xnew[10] += (0.5)*rtb_Sum1[10];
    xnew[11] = (1.0)*TT_Control_DW.TTController_DSTATE[11];
    xnew[11] += (0.5)*rtb_Sum1[11];
    xnew[12] = (1.0)*TT_Control_DW.TTController_DSTATE[12];
    xnew[12] += (0.5)*rtb_Sum1[12];
    xnew[13] = (1.0)*TT_Control_DW.TTController_DSTATE[13];
    xnew[13] += (0.5)*rtb_Sum1[13];
    (void) memcpy(&TT_Control_DW.TTController_DSTATE[0], xnew,
                  sizeof(real_T)*14);
  }
}

/* Model initialize function */
void TT_Control_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(TT_Control_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&TT_Control_DW, 0,
                sizeof(DW_TT_Control_T));

  /* external inputs */
  (void)memset(&TT_Control_U, 0, sizeof(ExtU_TT_Control_T));

  /* external outputs */
  (void) memset(&TT_Control_Y.TT_cmd[0], 0,
                21U*sizeof(real_T));
}

/* Model terminate function */
void TT_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
