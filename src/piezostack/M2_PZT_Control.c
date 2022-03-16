/*
 * File: M2_PZT_Control.c
 *
 * Code generated for Simulink model 'M2_PZT_Control'.
 *
 * Model version                  : 1.1033
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 16 13:49:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M2_PZT_Control.h"
#include "M2_PZT_Control_private.h"

/* Block states (default storage) */
DW_M2_PZT_Control_T M2_PZT_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M2_PZT_Control_T M2_PZT_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M2_PZT_Control_T M2_PZT_Control_Y;

/* Real-time model */
RT_MODEL_M2_PZT_Control_T M2_PZT_Control_M_;
RT_MODEL_M2_PZT_Control_T *const M2_PZT_Control_M = &M2_PZT_Control_M_;

/* Model step function */
void M2_PZT_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum[3];
  real_T rtb_Sum_f[3];
  real_T rtb_Sum_c[3];
  real_T rtb_Sum_j[3];
  real_T rtb_Sum_i[3];
  real_T rtb_Sum_i3[3];
  real_T rtb_Sum_a[3];
  real_T rtb_DiscreteSS[3];
  real_T rtb_spliF_matrix[6];
  real_T rtb_spliF_matrix_k[6];
  real_T rtb_spliF_matrix_pk[6];
  real_T rtb_spliF_matrix_l[6];
  real_T rtb_spliF_matrix_o[6];
  real_T rtb_spliF_matrix_g[6];
  real_T tmp[6];
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  for (i = 0; i < 3; i++) {
    /* Gain: '<S5>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0];
      i_1 += 3;
    }

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum[i] = M2_PZT_Control_U.PZT_cmd[i] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S12>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE[0]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3];
    rtb_DiscreteSS[0] += (170864.20553097979)*rtb_Sum[0];
    rtb_DiscreteSS[1] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE[4]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE[5]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7];
    rtb_DiscreteSS[1] += (170864.20553097979)*rtb_Sum[1];

    {
      static const int_T colCidxRow2[6] = { 8, 9, 10, 11, 12, 13 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC8 = &M2_PZT_Control_ConstP.pooled4[8];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 5;
      *y2 = (*pC8++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC8++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (137876.56582902896)*rtb_Sum[2];
  }

  /* Gain: '<S5>/spliF_matrix' */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_spliF_matrix[i_1] = 0.0;
    rtb_spliF_matrix[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] *
      rtb_DiscreteSS[0];
    rtb_spliF_matrix[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] *
      rtb_DiscreteSS[1];
    rtb_spliF_matrix[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] *
      rtb_DiscreteSS[2];
  }

  /* End of Gain: '<S5>/spliF_matrix' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S6>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0 + 6];
      i_1 += 3;
    }

    /* Sum: '<S6>/Sum' incorporates:
     *  Gain: '<S6>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum_f[i] = M2_PZT_Control_U.PZT_cmd[i + 3] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S13>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3];
    rtb_DiscreteSS[0] += (170864.20553097979)*rtb_Sum_f[0];

    {
      static const int_T colCidxRow1[6] = { 4, 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC4 = &M2_PZT_Control_ConstP.pooled10[4];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 5;
      *y1 = (*pC4++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC4++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (137876.56582902896)*rtb_Sum_f[1];
    rtb_DiscreteSS[2] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_a[10]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13];
    rtb_DiscreteSS[2] += (170864.20553097979)*rtb_Sum_f[2];
  }

  /* Gain: '<S6>/spliF_matrix' */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_spliF_matrix_k[i_1] = 0.0;
    rtb_spliF_matrix_k[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] *
      rtb_DiscreteSS[0];
    rtb_spliF_matrix_k[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] *
      rtb_DiscreteSS[1];
    rtb_spliF_matrix_k[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] *
      rtb_DiscreteSS[2];
  }

  /* End of Gain: '<S6>/spliF_matrix' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S7>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0 + 12];
      i_1 += 3;
    }

    /* Sum: '<S7>/Sum' incorporates:
     *  Gain: '<S7>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum_c[i] = M2_PZT_Control_U.PZT_cmd[i + 6] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S14>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3];
    rtb_DiscreteSS[0] += (170864.20553097979)*rtb_Sum_c[0];
    rtb_DiscreteSS[1] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_j[4]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[5]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7];
    rtb_DiscreteSS[1] += (170864.20553097979)*rtb_Sum_c[1];

    {
      static const int_T colCidxRow2[6] = { 8, 9, 10, 11, 12, 13 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC8 = &M2_PZT_Control_ConstP.pooled4[8];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 5;
      *y2 = (*pC8++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC8++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (137876.56582902896)*rtb_Sum_c[2];
  }

  /* Gain: '<S7>/spliF_matrix' */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_spliF_matrix_pk[i_1] = 0.0;
    rtb_spliF_matrix_pk[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] *
      rtb_DiscreteSS[0];
    rtb_spliF_matrix_pk[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] *
      rtb_DiscreteSS[1];
    rtb_spliF_matrix_pk[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] *
      rtb_DiscreteSS[2];
  }

  /* End of Gain: '<S7>/spliF_matrix' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S8>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0 + 18];
      i_1 += 3;
    }

    /* Sum: '<S8>/Sum' incorporates:
     *  Gain: '<S8>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum_j[i] = M2_PZT_Control_U.PZT_cmd[i + 9] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S15>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3];
    rtb_DiscreteSS[0] += (170864.20553097979)*rtb_Sum_j[0];

    {
      static const int_T colCidxRow1[6] = { 4, 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC4 = &M2_PZT_Control_ConstP.pooled10[4];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 5;
      *y1 = (*pC4++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC4++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (137876.56582902896)*rtb_Sum_j[1];
    rtb_DiscreteSS[2] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_af[10]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13];
    rtb_DiscreteSS[2] += (170864.20553097979)*rtb_Sum_j[2];
  }

  /* Gain: '<S8>/spliF_matrix' */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_spliF_matrix_l[i_1] = 0.0;
    rtb_spliF_matrix_l[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] *
      rtb_DiscreteSS[0];
    rtb_spliF_matrix_l[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] *
      rtb_DiscreteSS[1];
    rtb_spliF_matrix_l[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] *
      rtb_DiscreteSS[2];
  }

  /* End of Gain: '<S8>/spliF_matrix' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S9>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0 + 24];
      i_1 += 3;
    }

    /* Sum: '<S9>/Sum' incorporates:
     *  Gain: '<S9>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum_i[i] = M2_PZT_Control_U.PZT_cmd[i + 12] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S16>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3];
    rtb_DiscreteSS[0] += (170864.20553097979)*rtb_Sum_i[0];
    rtb_DiscreteSS[1] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_c[4]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[5]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7];
    rtb_DiscreteSS[1] += (170864.20553097979)*rtb_Sum_i[1];

    {
      static const int_T colCidxRow2[6] = { 8, 9, 10, 11, 12, 13 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC8 = &M2_PZT_Control_ConstP.pooled4[8];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 5;
      *y2 = (*pC8++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC8++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (137876.56582902896)*rtb_Sum_i[2];
  }

  /* Gain: '<S9>/spliF_matrix' */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_spliF_matrix_o[i_1] = 0.0;
    rtb_spliF_matrix_o[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] *
      rtb_DiscreteSS[0];
    rtb_spliF_matrix_o[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] *
      rtb_DiscreteSS[1];
    rtb_spliF_matrix_o[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] *
      rtb_DiscreteSS[2];
  }

  /* End of Gain: '<S9>/spliF_matrix' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S10>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0 + 30];
      i_1 += 3;
    }

    /* Sum: '<S10>/Sum' incorporates:
     *  Gain: '<S10>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum_i3[i] = M2_PZT_Control_U.PZT_cmd[i + 15] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S17>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3];
    rtb_DiscreteSS[0] += (170864.20553097979)*rtb_Sum_i3[0];

    {
      static const int_T colCidxRow1[6] = { 4, 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC4 = &M2_PZT_Control_ConstP.pooled10[4];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 5;
      *y1 = (*pC4++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC4++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (137876.56582902896)*rtb_Sum_i3[1];
    rtb_DiscreteSS[2] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_l[10]
      + (1270.1957308562392)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (437.16703540404353)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (155.05035259361495)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13];
    rtb_DiscreteSS[2] += (170864.20553097979)*rtb_Sum_i3[2];
  }

  /* Gain: '<S10>/spliF_matrix' */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_spliF_matrix_g[i_1] = 0.0;
    rtb_spliF_matrix_g[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] *
      rtb_DiscreteSS[0];
    rtb_spliF_matrix_g[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] *
      rtb_DiscreteSS[1];
    rtb_spliF_matrix_g[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] *
      rtb_DiscreteSS[2];
  }

  /* End of Gain: '<S10>/spliF_matrix' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S11>/rel_PZT_D' incorporates:
     *  Inport: '<Root>/PZT_FB'
     */
    rtb_DiscreteSS[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DiscreteSS[i] += M2_PZT_Control_ConstP.pooled1[i_1 + i] *
        M2_PZT_Control_U.PZT_FB[i_0 + 36];
      i_1 += 3;
    }

    /* Sum: '<S11>/Sum' incorporates:
     *  Gain: '<S11>/rel_PZT_D'
     *  Inport: '<Root>/PZT_cmd'
     */
    rtb_Sum_a[i] = M2_PZT_Control_U.PZT_cmd[i + 18] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S18>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[0]
      + (1282.6182631360691)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (-445.20254803033697)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2]
      + (134.91895164674634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[3];
    rtb_DiscreteSS[0] += (173159.13265436474)*rtb_Sum_a[0];
    rtb_DiscreteSS[1] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[4]
      + (1282.6182631360691)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5]
      + (-445.20254803033697)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[6]
      + (134.91895164674634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7];
    rtb_DiscreteSS[1] += (173159.13265436474)*rtb_Sum_a[1];
    rtb_DiscreteSS[2] = (1792.4160535515716)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[8]
      + (1282.6182631360691)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[9]
      + (-445.20254803033697)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[10]
      + (134.91895164674634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[11];
    rtb_DiscreteSS[2] += (173159.13265436474)*rtb_Sum_a[2];
  }

  for (i_1 = 0; i_1 < 6; i_1++) {
    /* Gain: '<S11>/spliF_matrix' */
    tmp[i_1] = 0.0;
    tmp[i_1] += M2_PZT_Control_ConstP.pooled7[i_1] * rtb_DiscreteSS[0];
    tmp[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 6] * rtb_DiscreteSS[1];
    tmp[i_1] += M2_PZT_Control_ConstP.pooled7[i_1 + 12] * rtb_DiscreteSS[2];

    /* Outport: '<Root>/PZT_F' incorporates:
     *  Gain: '<S11>/spliF_matrix'
     */
    M2_PZT_Control_Y.PZT_F[i_1] = rtb_spliF_matrix[i_1];
    M2_PZT_Control_Y.PZT_F[i_1 + 6] = rtb_spliF_matrix_k[i_1];
    M2_PZT_Control_Y.PZT_F[i_1 + 12] = rtb_spliF_matrix_pk[i_1];
    M2_PZT_Control_Y.PZT_F[i_1 + 18] = rtb_spliF_matrix_l[i_1];
    M2_PZT_Control_Y.PZT_F[i_1 + 24] = rtb_spliF_matrix_o[i_1];
    M2_PZT_Control_Y.PZT_F[i_1 + 30] = rtb_spliF_matrix_g[i_1];
    M2_PZT_Control_Y.PZT_F[i_1 + 36] = tmp[i_1];
  }

  /* Update for DiscreteStateSpace: '<S12>/Discrete SS' */
  {
    real_T xnew[14];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
    xnew[0] += (1023.9999999999998)*rtb_Sum[0];
    xnew[1] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3];
    xnew[1] += (-1270.1957308562403)*rtb_Sum[0];
    xnew[2] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3];
    xnew[2] += (437.167035404043)*rtb_Sum[0];
    xnew[3] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3];
    xnew[3] += (-155.05035259361762)*rtb_Sum[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE[4];
    xnew[4] += (1023.9999999999998)*rtb_Sum[1];
    xnew[5] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE[5]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7];
    xnew[5] += (-1270.1957308562403)*rtb_Sum[1];
    xnew[6] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE[5]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7];
    xnew[6] += (437.167035404043)*rtb_Sum[1];
    xnew[7] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE[5]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7];
    xnew[7] += (-155.05035259361762)*rtb_Sum[1];
    xnew[8] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE[8];
    xnew[8] += (2048.0)*rtb_Sum[2];

    {
      static const int_T colAidxRow9[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA21 = &M2_PZT_Control_ConstP.pooled2[21];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 4;
      *pxnew9 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[9] += (-1285.6060021703452)*rtb_Sum[2];

    {
      static const int_T colAidxRow10[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA26 = &M2_PZT_Control_ConstP.pooled2[26];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 4;
      *pxnew10 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-367.75839337479982)*rtb_Sum[2];

    {
      static const int_T colAidxRow11[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA31 = &M2_PZT_Control_ConstP.pooled2[31];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 4;
      *pxnew11 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[11] += (-96.142478538355036)*rtb_Sum[2];

    {
      static const int_T colAidxRow12[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA36 = &M2_PZT_Control_ConstP.pooled2[36];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 4;
      *pxnew12 = (*pA36++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA36++) * xd[*pAidx++];
      }
    }

    xnew[12] += (-149.11383683399757)*rtb_Sum[2];

    {
      static const int_T colAidxRow13[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA41 = &M2_PZT_Control_ConstP.pooled2[41];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 4;
      *pxnew13 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[13] += (76.492081338907425)*rtb_Sum[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE[0], xnew,
                  sizeof(real_T)*14);
  }

  /* Update for DiscreteStateSpace: '<S13>/Discrete SS' */
  {
    real_T xnew[20];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
    xnew[0] += (1023.9999999999998)*rtb_Sum_f[0];
    xnew[1] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3];
    xnew[1] += (-1270.1957308562403)*rtb_Sum_f[0];
    xnew[2] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3];
    xnew[2] += (437.167035404043)*rtb_Sum_f[0];
    xnew[3] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3];
    xnew[3] += (-155.05035259361762)*rtb_Sum_f[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[4];
    xnew[4] += (2048.0)*rtb_Sum_f[1];

    {
      static const int_T colAidxRow5[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA11 = &M2_PZT_Control_ConstP.pooled8[11];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 4;
      *pxnew5 = (*pA11++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA11++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-1285.6060021703452)*rtb_Sum_f[1];

    {
      static const int_T colAidxRow6[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA16 = &M2_PZT_Control_ConstP.pooled8[16];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 4;
      *pxnew6 = (*pA16++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA16++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-367.75839337479982)*rtb_Sum_f[1];

    {
      static const int_T colAidxRow7[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA21 = &M2_PZT_Control_ConstP.pooled8[21];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 4;
      *pxnew7 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-96.142478538355036)*rtb_Sum_f[1];

    {
      static const int_T colAidxRow8[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA26 = &M2_PZT_Control_ConstP.pooled8[26];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 4;
      *pxnew8 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-149.11383683399757)*rtb_Sum_f[1];

    {
      static const int_T colAidxRow9[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA31 = &M2_PZT_Control_ConstP.pooled8[31];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 4;
      *pxnew9 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[9] += (76.492081338907425)*rtb_Sum_f[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[10];
    xnew[10] += (1023.9999999999998)*rtb_Sum_f[2];
    xnew[11] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13];
    xnew[11] += (-1270.1957308562403)*rtb_Sum_f[2];
    xnew[12] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13];
    xnew[12] += (437.167035404043)*rtb_Sum_f[2];
    xnew[13] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13];
    xnew[13] += (-155.05035259361762)*rtb_Sum_f[2];
    xnew[14] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[14];

    {
      static const int_T colAidxRow15[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow15[0];
      const real_T *pA47 = &M2_PZT_Control_ConstP.pooled8[47];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 4;
      *pxnew15 = (*pA47++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew15 += (*pA47++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow16[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow16[0];
      const real_T *pA52 = &M2_PZT_Control_ConstP.pooled8[52];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew16 = &xnew[16];
      int_T numNonZero = 4;
      *pxnew16 = (*pA52++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew16 += (*pA52++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow17[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow17[0];
      const real_T *pA57 = &M2_PZT_Control_ConstP.pooled8[57];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew17 = &xnew[17];
      int_T numNonZero = 4;
      *pxnew17 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew17 += (*pA57++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow18[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow18[0];
      const real_T *pA62 = &M2_PZT_Control_ConstP.pooled8[62];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 4;
      *pxnew18 = (*pA62++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew18 += (*pA62++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow19[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow19[0];
      const real_T *pA67 = &M2_PZT_Control_ConstP.pooled8[67];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 4;
      *pxnew19 = (*pA67++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew19 += (*pA67++) * xd[*pAidx++];
      }
    }

    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0], xnew,
                  sizeof(real_T)*20);
  }

  /* Update for DiscreteStateSpace: '<S14>/Discrete SS' */
  {
    real_T xnew[14];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
    xnew[0] += (1023.9999999999998)*rtb_Sum_c[0];
    xnew[1] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3];
    xnew[1] += (-1270.1957308562403)*rtb_Sum_c[0];
    xnew[2] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3];
    xnew[2] += (437.167035404043)*rtb_Sum_c[0];
    xnew[3] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3];
    xnew[3] += (-155.05035259361762)*rtb_Sum_c[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[4];
    xnew[4] += (1023.9999999999998)*rtb_Sum_c[1];
    xnew[5] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[5]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7];
    xnew[5] += (-1270.1957308562403)*rtb_Sum_c[1];
    xnew[6] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[5]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7];
    xnew[6] += (437.167035404043)*rtb_Sum_c[1];
    xnew[7] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[5]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7];
    xnew[7] += (-155.05035259361762)*rtb_Sum_c[1];
    xnew[8] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[8];
    xnew[8] += (2048.0)*rtb_Sum_c[2];

    {
      static const int_T colAidxRow9[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA21 = &M2_PZT_Control_ConstP.pooled2[21];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 4;
      *pxnew9 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[9] += (-1285.6060021703452)*rtb_Sum_c[2];

    {
      static const int_T colAidxRow10[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA26 = &M2_PZT_Control_ConstP.pooled2[26];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 4;
      *pxnew10 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-367.75839337479982)*rtb_Sum_c[2];

    {
      static const int_T colAidxRow11[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA31 = &M2_PZT_Control_ConstP.pooled2[31];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 4;
      *pxnew11 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[11] += (-96.142478538355036)*rtb_Sum_c[2];

    {
      static const int_T colAidxRow12[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA36 = &M2_PZT_Control_ConstP.pooled2[36];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 4;
      *pxnew12 = (*pA36++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA36++) * xd[*pAidx++];
      }
    }

    xnew[12] += (-149.11383683399757)*rtb_Sum_c[2];

    {
      static const int_T colAidxRow13[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA41 = &M2_PZT_Control_ConstP.pooled2[41];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 4;
      *pxnew13 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[13] += (76.492081338907425)*rtb_Sum_c[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0], xnew,
                  sizeof(real_T)*14);
  }

  /* Update for DiscreteStateSpace: '<S15>/Discrete SS' */
  {
    real_T xnew[20];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
    xnew[0] += (1023.9999999999998)*rtb_Sum_j[0];
    xnew[1] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3];
    xnew[1] += (-1270.1957308562403)*rtb_Sum_j[0];
    xnew[2] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3];
    xnew[2] += (437.167035404043)*rtb_Sum_j[0];
    xnew[3] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3];
    xnew[3] += (-155.05035259361762)*rtb_Sum_j[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[4];
    xnew[4] += (2048.0)*rtb_Sum_j[1];

    {
      static const int_T colAidxRow5[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA11 = &M2_PZT_Control_ConstP.pooled8[11];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 4;
      *pxnew5 = (*pA11++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA11++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-1285.6060021703452)*rtb_Sum_j[1];

    {
      static const int_T colAidxRow6[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA16 = &M2_PZT_Control_ConstP.pooled8[16];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 4;
      *pxnew6 = (*pA16++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA16++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-367.75839337479982)*rtb_Sum_j[1];

    {
      static const int_T colAidxRow7[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA21 = &M2_PZT_Control_ConstP.pooled8[21];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 4;
      *pxnew7 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-96.142478538355036)*rtb_Sum_j[1];

    {
      static const int_T colAidxRow8[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA26 = &M2_PZT_Control_ConstP.pooled8[26];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 4;
      *pxnew8 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-149.11383683399757)*rtb_Sum_j[1];

    {
      static const int_T colAidxRow9[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA31 = &M2_PZT_Control_ConstP.pooled8[31];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 4;
      *pxnew9 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[9] += (76.492081338907425)*rtb_Sum_j[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[10];
    xnew[10] += (1023.9999999999998)*rtb_Sum_j[2];
    xnew[11] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13];
    xnew[11] += (-1270.1957308562403)*rtb_Sum_j[2];
    xnew[12] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13];
    xnew[12] += (437.167035404043)*rtb_Sum_j[2];
    xnew[13] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13];
    xnew[13] += (-155.05035259361762)*rtb_Sum_j[2];
    xnew[14] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[14];

    {
      static const int_T colAidxRow15[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow15[0];
      const real_T *pA47 = &M2_PZT_Control_ConstP.pooled8[47];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 4;
      *pxnew15 = (*pA47++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew15 += (*pA47++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow16[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow16[0];
      const real_T *pA52 = &M2_PZT_Control_ConstP.pooled8[52];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew16 = &xnew[16];
      int_T numNonZero = 4;
      *pxnew16 = (*pA52++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew16 += (*pA52++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow17[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow17[0];
      const real_T *pA57 = &M2_PZT_Control_ConstP.pooled8[57];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew17 = &xnew[17];
      int_T numNonZero = 4;
      *pxnew17 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew17 += (*pA57++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow18[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow18[0];
      const real_T *pA62 = &M2_PZT_Control_ConstP.pooled8[62];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 4;
      *pxnew18 = (*pA62++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew18 += (*pA62++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow19[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow19[0];
      const real_T *pA67 = &M2_PZT_Control_ConstP.pooled8[67];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 4;
      *pxnew19 = (*pA67++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew19 += (*pA67++) * xd[*pAidx++];
      }
    }

    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0], xnew,
                  sizeof(real_T)*20);
  }

  /* Update for DiscreteStateSpace: '<S16>/Discrete SS' */
  {
    real_T xnew[14];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
    xnew[0] += (1023.9999999999998)*rtb_Sum_i[0];
    xnew[1] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3];
    xnew[1] += (-1270.1957308562403)*rtb_Sum_i[0];
    xnew[2] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3];
    xnew[2] += (437.167035404043)*rtb_Sum_i[0];
    xnew[3] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3];
    xnew[3] += (-155.05035259361762)*rtb_Sum_i[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[4];
    xnew[4] += (1023.9999999999998)*rtb_Sum_i[1];
    xnew[5] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[5]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7];
    xnew[5] += (-1270.1957308562403)*rtb_Sum_i[1];
    xnew[6] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[5]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7];
    xnew[6] += (437.167035404043)*rtb_Sum_i[1];
    xnew[7] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[5]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7];
    xnew[7] += (-155.05035259361762)*rtb_Sum_i[1];
    xnew[8] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[8];
    xnew[8] += (2048.0)*rtb_Sum_i[2];

    {
      static const int_T colAidxRow9[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA21 = &M2_PZT_Control_ConstP.pooled2[21];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 4;
      *pxnew9 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[9] += (-1285.6060021703452)*rtb_Sum_i[2];

    {
      static const int_T colAidxRow10[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA26 = &M2_PZT_Control_ConstP.pooled2[26];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 4;
      *pxnew10 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-367.75839337479982)*rtb_Sum_i[2];

    {
      static const int_T colAidxRow11[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA31 = &M2_PZT_Control_ConstP.pooled2[31];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 4;
      *pxnew11 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[11] += (-96.142478538355036)*rtb_Sum_i[2];

    {
      static const int_T colAidxRow12[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA36 = &M2_PZT_Control_ConstP.pooled2[36];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 4;
      *pxnew12 = (*pA36++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA36++) * xd[*pAidx++];
      }
    }

    xnew[12] += (-149.11383683399757)*rtb_Sum_i[2];

    {
      static const int_T colAidxRow13[5] = { 9, 10, 11, 12, 13 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA41 = &M2_PZT_Control_ConstP.pooled2[41];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 4;
      *pxnew13 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[13] += (76.492081338907425)*rtb_Sum_i[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0], xnew,
                  sizeof(real_T)*14);
  }

  /* Update for DiscreteStateSpace: '<S17>/Discrete SS' */
  {
    real_T xnew[20];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
    xnew[0] += (1023.9999999999998)*rtb_Sum_i3[0];
    xnew[1] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3];
    xnew[1] += (-1270.1957308562403)*rtb_Sum_i3[0];
    xnew[2] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3];
    xnew[2] += (437.167035404043)*rtb_Sum_i3[0];
    xnew[3] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3];
    xnew[3] += (-155.05035259361762)*rtb_Sum_i3[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[4];
    xnew[4] += (2048.0)*rtb_Sum_i3[1];

    {
      static const int_T colAidxRow5[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA11 = &M2_PZT_Control_ConstP.pooled8[11];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 4;
      *pxnew5 = (*pA11++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA11++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-1285.6060021703452)*rtb_Sum_i3[1];

    {
      static const int_T colAidxRow6[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA16 = &M2_PZT_Control_ConstP.pooled8[16];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 4;
      *pxnew6 = (*pA16++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA16++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-367.75839337479982)*rtb_Sum_i3[1];

    {
      static const int_T colAidxRow7[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA21 = &M2_PZT_Control_ConstP.pooled8[21];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 4;
      *pxnew7 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-96.142478538355036)*rtb_Sum_i3[1];

    {
      static const int_T colAidxRow8[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA26 = &M2_PZT_Control_ConstP.pooled8[26];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 4;
      *pxnew8 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-149.11383683399757)*rtb_Sum_i3[1];

    {
      static const int_T colAidxRow9[5] = { 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA31 = &M2_PZT_Control_ConstP.pooled8[31];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 4;
      *pxnew9 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[9] += (76.492081338907425)*rtb_Sum_i3[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[10];
    xnew[10] += (1023.9999999999998)*rtb_Sum_i3[2];
    xnew[11] = (0.82981252247312409)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (-0.14089998548737512)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (-0.038474195178203593)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13];
    xnew[11] += (-1270.1957308562403)*rtb_Sum_i3[2];
    xnew[12] = (0.14089998548737542)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (0.68660055043878454)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (-0.31860430284095181)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13];
    xnew[12] += (437.167035404043)*rtb_Sum_i3[2];
    xnew[13] = (-0.0384741951782019)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (0.31860430284095115)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (0.64779442780487639)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13];
    xnew[13] += (-155.05035259361762)*rtb_Sum_i3[2];
    xnew[14] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[14];

    {
      static const int_T colAidxRow15[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow15[0];
      const real_T *pA47 = &M2_PZT_Control_ConstP.pooled8[47];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 4;
      *pxnew15 = (*pA47++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew15 += (*pA47++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow16[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow16[0];
      const real_T *pA52 = &M2_PZT_Control_ConstP.pooled8[52];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew16 = &xnew[16];
      int_T numNonZero = 4;
      *pxnew16 = (*pA52++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew16 += (*pA52++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow17[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow17[0];
      const real_T *pA57 = &M2_PZT_Control_ConstP.pooled8[57];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew17 = &xnew[17];
      int_T numNonZero = 4;
      *pxnew17 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew17 += (*pA57++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow18[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow18[0];
      const real_T *pA62 = &M2_PZT_Control_ConstP.pooled8[62];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 4;
      *pxnew18 = (*pA62++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew18 += (*pA62++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colAidxRow19[5] = { 15, 16, 17, 18, 19 };

      const int_T *pAidx = &colAidxRow19[0];
      const real_T *pA67 = &M2_PZT_Control_ConstP.pooled8[67];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 4;
      *pxnew19 = (*pA67++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew19 += (*pA67++) * xd[*pAidx++];
      }
    }

    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0], xnew,
                  sizeof(real_T)*20);
  }

  /* Update for DiscreteStateSpace: '<S18>/Discrete SS' */
  {
    real_T xnew[12];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[0];
    xnew[0] += (1024.0000000000005)*rtb_Sum_a[0];
    xnew[1] = (0.83198423159630153)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (0.13773951362369649)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2]
      + (-0.033248462288313747)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[3];
    xnew[1] += (-1282.6182631360689)*rtb_Sum_a[0];
    xnew[2] = (-0.1377395136236963)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (0.63982700974886242)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2]
      + (0.30757002934736644)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[3];
    xnew[2] += (-445.20254803033691)*rtb_Sum_a[0];
    xnew[3] = (-0.03324846228831306)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (-0.30757002934736666)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2]
      + (0.563366170610091)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[3];
    xnew[3] += (-134.91895164674759)*rtb_Sum_a[0];
    xnew[4] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[4];
    xnew[4] += (1024.0000000000005)*rtb_Sum_a[1];
    xnew[5] = (0.83198423159630153)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5]
      + (0.13773951362369649)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[6]
      + (-0.033248462288313747)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7];
    xnew[5] += (-1282.6182631360689)*rtb_Sum_a[1];
    xnew[6] = (-0.1377395136236963)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5]
      + (0.63982700974886242)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[6]
      + (0.30757002934736644)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7];
    xnew[6] += (-445.20254803033691)*rtb_Sum_a[1];
    xnew[7] = (-0.03324846228831306)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5]
      + (-0.30757002934736666)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[6]
      + (0.563366170610091)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7];
    xnew[7] += (-134.91895164674759)*rtb_Sum_a[1];
    xnew[8] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[8];
    xnew[8] += (1024.0000000000005)*rtb_Sum_a[2];
    xnew[9] = (0.83198423159630153)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[9]
      + (0.13773951362369649)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[10]
      + (-0.033248462288313747)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[11];
    xnew[9] += (-1282.6182631360689)*rtb_Sum_a[2];
    xnew[10] = (-0.1377395136236963)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[9]
      + (0.63982700974886242)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[10]
      + (0.30757002934736644)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[11];
    xnew[10] += (-445.20254803033691)*rtb_Sum_a[2];
    xnew[11] = (-0.03324846228831306)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[9]
      + (-0.30757002934736666)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[10]
      + (0.563366170610091)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[11];
    xnew[11] += (-134.91895164674759)*rtb_Sum_a[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[0], xnew,
                  sizeof(real_T)*12);
  }
}

/* Model initialize function */
void M2_PZT_Control_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M2_PZT_Control_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M2_PZT_Control_DW, 0,
                sizeof(DW_M2_PZT_Control_T));

  /* external inputs */
  (void)memset(&M2_PZT_Control_U, 0, sizeof(ExtU_M2_PZT_Control_T));

  /* external outputs */
  (void) memset(&M2_PZT_Control_Y.PZT_F[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M2_PZT_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
