/*
 * File: M2_POS_Control.c
 *
 * Code generated for Simulink model 'M2_POS_Control'.
 *
 * Model version                  : 5.76
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Sep  2 12:29:45 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M2_POS_Control.h"
#include "M2_POS_Control_private.h"

/* Block states (default storage) */
DW_M2_POS_Control_T M2_POS_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M2_POS_Control_T M2_POS_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M2_POS_Control_T M2_POS_Control_Y;

/* Real-time model */
static RT_MODEL_M2_POS_Control_T M2_POS_Control_M_;
RT_MODEL_M2_POS_Control_T *const M2_POS_Control_M = &M2_POS_Control_M_;

/* Model step function */
void M2_POS_Control_step(void)
{
  real_T FBcontroller_tmp[42];
  real_T rtb_FBcontroller[42];
  real_T denAccum;
  int32_T i;
  int32_T i_0;
  int32_T memOffset;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/M2_pos_FB'
   */
  rtb_FBcontroller[0] = M2_POS_Control_U.M2_pos_FB[0] -
    M2_POS_Control_U.M2_pos_FB[1];
  rtb_FBcontroller[1] = M2_POS_Control_U.M2_pos_FB[2] -
    M2_POS_Control_U.M2_pos_FB[3];
  rtb_FBcontroller[2] = M2_POS_Control_U.M2_pos_FB[4] -
    M2_POS_Control_U.M2_pos_FB[5];
  rtb_FBcontroller[3] = M2_POS_Control_U.M2_pos_FB[6] -
    M2_POS_Control_U.M2_pos_FB[7];
  rtb_FBcontroller[4] = M2_POS_Control_U.M2_pos_FB[8] -
    M2_POS_Control_U.M2_pos_FB[9];
  rtb_FBcontroller[5] = M2_POS_Control_U.M2_pos_FB[10] -
    M2_POS_Control_U.M2_pos_FB[11];
  rtb_FBcontroller[6] = M2_POS_Control_U.M2_pos_FB[12] -
    M2_POS_Control_U.M2_pos_FB[13];
  rtb_FBcontroller[7] = M2_POS_Control_U.M2_pos_FB[14] -
    M2_POS_Control_U.M2_pos_FB[15];
  rtb_FBcontroller[8] = M2_POS_Control_U.M2_pos_FB[16] -
    M2_POS_Control_U.M2_pos_FB[17];
  rtb_FBcontroller[9] = M2_POS_Control_U.M2_pos_FB[18] -
    M2_POS_Control_U.M2_pos_FB[19];
  rtb_FBcontroller[10] = M2_POS_Control_U.M2_pos_FB[20] -
    M2_POS_Control_U.M2_pos_FB[21];
  rtb_FBcontroller[11] = M2_POS_Control_U.M2_pos_FB[22] -
    M2_POS_Control_U.M2_pos_FB[23];
  rtb_FBcontroller[12] = M2_POS_Control_U.M2_pos_FB[24] -
    M2_POS_Control_U.M2_pos_FB[25];
  rtb_FBcontroller[13] = M2_POS_Control_U.M2_pos_FB[26] -
    M2_POS_Control_U.M2_pos_FB[27];
  rtb_FBcontroller[14] = M2_POS_Control_U.M2_pos_FB[28] -
    M2_POS_Control_U.M2_pos_FB[29];
  rtb_FBcontroller[15] = M2_POS_Control_U.M2_pos_FB[30] -
    M2_POS_Control_U.M2_pos_FB[31];
  rtb_FBcontroller[16] = M2_POS_Control_U.M2_pos_FB[32] -
    M2_POS_Control_U.M2_pos_FB[33];
  rtb_FBcontroller[17] = M2_POS_Control_U.M2_pos_FB[34] -
    M2_POS_Control_U.M2_pos_FB[35];
  rtb_FBcontroller[18] = M2_POS_Control_U.M2_pos_FB[36] -
    M2_POS_Control_U.M2_pos_FB[37];
  rtb_FBcontroller[19] = M2_POS_Control_U.M2_pos_FB[38] -
    M2_POS_Control_U.M2_pos_FB[39];
  rtb_FBcontroller[20] = M2_POS_Control_U.M2_pos_FB[40] -
    M2_POS_Control_U.M2_pos_FB[41];
  rtb_FBcontroller[21] = M2_POS_Control_U.M2_pos_FB[42] -
    M2_POS_Control_U.M2_pos_FB[43];
  rtb_FBcontroller[22] = M2_POS_Control_U.M2_pos_FB[44] -
    M2_POS_Control_U.M2_pos_FB[45];
  rtb_FBcontroller[23] = M2_POS_Control_U.M2_pos_FB[46] -
    M2_POS_Control_U.M2_pos_FB[47];
  rtb_FBcontroller[24] = M2_POS_Control_U.M2_pos_FB[48] -
    M2_POS_Control_U.M2_pos_FB[49];
  rtb_FBcontroller[25] = M2_POS_Control_U.M2_pos_FB[50] -
    M2_POS_Control_U.M2_pos_FB[51];
  rtb_FBcontroller[26] = M2_POS_Control_U.M2_pos_FB[52] -
    M2_POS_Control_U.M2_pos_FB[53];
  rtb_FBcontroller[27] = M2_POS_Control_U.M2_pos_FB[54] -
    M2_POS_Control_U.M2_pos_FB[55];
  rtb_FBcontroller[28] = M2_POS_Control_U.M2_pos_FB[56] -
    M2_POS_Control_U.M2_pos_FB[57];
  rtb_FBcontroller[29] = M2_POS_Control_U.M2_pos_FB[58] -
    M2_POS_Control_U.M2_pos_FB[59];
  rtb_FBcontroller[30] = M2_POS_Control_U.M2_pos_FB[60] -
    M2_POS_Control_U.M2_pos_FB[61];
  rtb_FBcontroller[31] = M2_POS_Control_U.M2_pos_FB[62] -
    M2_POS_Control_U.M2_pos_FB[63];
  rtb_FBcontroller[32] = M2_POS_Control_U.M2_pos_FB[64] -
    M2_POS_Control_U.M2_pos_FB[65];
  rtb_FBcontroller[33] = M2_POS_Control_U.M2_pos_FB[66] -
    M2_POS_Control_U.M2_pos_FB[67];
  rtb_FBcontroller[34] = M2_POS_Control_U.M2_pos_FB[68] -
    M2_POS_Control_U.M2_pos_FB[69];
  rtb_FBcontroller[35] = M2_POS_Control_U.M2_pos_FB[70] -
    M2_POS_Control_U.M2_pos_FB[71];
  rtb_FBcontroller[36] = M2_POS_Control_U.M2_pos_FB[72] -
    M2_POS_Control_U.M2_pos_FB[73];
  rtb_FBcontroller[37] = M2_POS_Control_U.M2_pos_FB[74] -
    M2_POS_Control_U.M2_pos_FB[75];
  rtb_FBcontroller[38] = M2_POS_Control_U.M2_pos_FB[76] -
    M2_POS_Control_U.M2_pos_FB[77];
  rtb_FBcontroller[39] = M2_POS_Control_U.M2_pos_FB[78] -
    M2_POS_Control_U.M2_pos_FB[79];
  rtb_FBcontroller[40] = M2_POS_Control_U.M2_pos_FB[80] -
    M2_POS_Control_U.M2_pos_FB[81];
  rtb_FBcontroller[41] = M2_POS_Control_U.M2_pos_FB[82] -
    M2_POS_Control_U.M2_pos_FB[83];
  for (i = 0; i < 42; i++) {
    /* DiscreteTransferFcn: '<S1>/FB controller' incorporates:
     *  Inport: '<Root>/M2_pos_cmd'
     *  Sum: '<S1>/Sum1'
     */
    memOffset = i * 3;
    denAccum = (((M2_POS_Control_U.M2_pos_cmd[i] - rtb_FBcontroller[i]) -
                 -2.9921153371845048 *
                 M2_POS_Control_DW.FBcontroller_states[memOffset]) -
                M2_POS_Control_DW.FBcontroller_states[memOffset + 1] *
                2.9842921174770662) -
      M2_POS_Control_DW.FBcontroller_states[memOffset + 2] *
      -0.99217678029256162;
    FBcontroller_tmp[i] = denAccum;
    denAccum *= 0.49701414758691181;
    denAccum += 5.4585635599046549 *
      M2_POS_Control_DW.FBcontroller_states[memOffset];
    denAccum += M2_POS_Control_DW.FBcontroller_states[memOffset + 1] *
      5.4499959812615542;
    rtb_FBcontroller[i] = M2_POS_Control_DW.FBcontroller_states[memOffset + 2] *
      0.49467753220551575 + denAccum;
  }

  /* Outport: '<Root>/M2_pos_act_F' incorporates:
   *  Gain: '<S1>/kron(eye(42),[1;-1])'
   */
  for (memOffset = 0; memOffset < 84; memOffset++) {
    M2_POS_Control_Y.M2_pos_act_F[memOffset] = 0.0;
    i = 0;
    for (i_0 = 0; i_0 < 42; i_0++) {
      M2_POS_Control_Y.M2_pos_act_F[memOffset] +=
        M2_POS_Control_ConstP.kroneye4211_Gain[i + memOffset] *
        rtb_FBcontroller[i_0];
      i += 84;
    }
  }

  /* End of Outport: '<Root>/M2_pos_act_F' */

  /* Update for DiscreteTransferFcn: '<S1>/FB controller' */
  for (i = 0; i < 42; i++) {
    memOffset = i * 3;
    M2_POS_Control_DW.FBcontroller_states[memOffset + 2] =
      M2_POS_Control_DW.FBcontroller_states[memOffset + 1];
    M2_POS_Control_DW.FBcontroller_states[memOffset + 1] =
      M2_POS_Control_DW.FBcontroller_states[memOffset];
    M2_POS_Control_DW.FBcontroller_states[memOffset] = FBcontroller_tmp[i];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/FB controller' */
}

/* Model initialize function */
void M2_POS_Control_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M2_POS_Control_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M2_POS_Control_DW, 0,
                sizeof(DW_M2_POS_Control_T));

  /* external inputs */
  (void)memset(&M2_POS_Control_U, 0, sizeof(ExtU_M2_POS_Control_T));

  /* external outputs */
  (void) memset(&M2_POS_Control_Y.M2_pos_act_F[0], 0,
                84U*sizeof(real_T));
}

/* Model terminate function */
void M2_POS_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
