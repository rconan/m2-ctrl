/*
 * File: M2_PZT_Control.c
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum[i] = M2_PZT_Control_U.TT_cmd[i] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S12>/Discrete SS' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M2_PZT_Control_ConstP.pooled4;
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *y0 = &rtb_DiscreteSS[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[0] += (1.362753305373658E+6)*rtb_Sum[0];

    {
      static const int_T colCidxRow1[5] = { 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &M2_PZT_Control_ConstP.pooled4[5];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (1.362753305373658E+6)*rtb_Sum[1];

    {
      static const int_T colCidxRow2[5] = { 10, 11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC10 = &M2_PZT_Control_ConstP.pooled4[10];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 4;
      *y2 = (*pC10++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC10++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (1.3552590131977634E+6)*rtb_Sum[2];
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum_f[i] = M2_PZT_Control_U.TT_cmd[i + 3] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S13>/Discrete SS' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M2_PZT_Control_ConstP.pooled10;
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *y0 = &rtb_DiscreteSS[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[0] += (1.362753305373658E+6)*rtb_Sum_f[0];

    {
      static const int_T colCidxRow1[5] = { 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &M2_PZT_Control_ConstP.pooled10[5];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (1.3552590131977634E+6)*rtb_Sum_f[1];

    {
      static const int_T colCidxRow2[5] = { 10, 11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC10 = &M2_PZT_Control_ConstP.pooled10[10];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 4;
      *y2 = (*pC10++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC10++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (1.362753305373658E+6)*rtb_Sum_f[2];
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum_c[i] = M2_PZT_Control_U.TT_cmd[i + 6] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S14>/Discrete SS' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M2_PZT_Control_ConstP.pooled4;
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *y0 = &rtb_DiscreteSS[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[0] += (1.362753305373658E+6)*rtb_Sum_c[0];

    {
      static const int_T colCidxRow1[5] = { 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &M2_PZT_Control_ConstP.pooled4[5];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (1.362753305373658E+6)*rtb_Sum_c[1];

    {
      static const int_T colCidxRow2[5] = { 10, 11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC10 = &M2_PZT_Control_ConstP.pooled4[10];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 4;
      *y2 = (*pC10++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC10++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (1.3552590131977634E+6)*rtb_Sum_c[2];
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum_j[i] = M2_PZT_Control_U.TT_cmd[i + 9] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S15>/Discrete SS' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M2_PZT_Control_ConstP.pooled10;
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *y0 = &rtb_DiscreteSS[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[0] += (1.362753305373658E+6)*rtb_Sum_j[0];

    {
      static const int_T colCidxRow1[5] = { 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &M2_PZT_Control_ConstP.pooled10[5];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (1.3552590131977634E+6)*rtb_Sum_j[1];

    {
      static const int_T colCidxRow2[5] = { 10, 11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC10 = &M2_PZT_Control_ConstP.pooled10[10];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 4;
      *y2 = (*pC10++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC10++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (1.362753305373658E+6)*rtb_Sum_j[2];
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum_i[i] = M2_PZT_Control_U.TT_cmd[i + 12] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S16>/Discrete SS' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M2_PZT_Control_ConstP.pooled4;
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *y0 = &rtb_DiscreteSS[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[0] += (1.362753305373658E+6)*rtb_Sum_i[0];

    {
      static const int_T colCidxRow1[5] = { 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &M2_PZT_Control_ConstP.pooled4[5];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (1.362753305373658E+6)*rtb_Sum_i[1];

    {
      static const int_T colCidxRow2[5] = { 10, 11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC10 = &M2_PZT_Control_ConstP.pooled4[10];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 4;
      *y2 = (*pC10++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC10++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (1.3552590131977634E+6)*rtb_Sum_i[2];
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum_i3[i] = M2_PZT_Control_U.TT_cmd[i + 15] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S17>/Discrete SS' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M2_PZT_Control_ConstP.pooled10;
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *y0 = &rtb_DiscreteSS[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[0] += (1.362753305373658E+6)*rtb_Sum_i3[0];

    {
      static const int_T colCidxRow1[5] = { 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &M2_PZT_Control_ConstP.pooled10[5];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *y1 = &rtb_DiscreteSS[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[1] += (1.3552590131977634E+6)*rtb_Sum_i3[1];

    {
      static const int_T colCidxRow2[5] = { 10, 11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC10 = &M2_PZT_Control_ConstP.pooled10[10];
      const real_T *xd = &M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
      real_T *y2 = &rtb_DiscreteSS[2];
      int_T numNonZero = 4;
      *y2 = (*pC10++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC10++) * xd[*pCidx++];
      }
    }

    rtb_DiscreteSS[2] += (1.362753305373658E+6)*rtb_Sum_i3[2];
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
     *  Inport: '<Root>/TT_cmd'
     */
    rtb_Sum_a[i] = M2_PZT_Control_U.TT_cmd[i + 18] - rtb_DiscreteSS[i];
  }

  /* DiscreteStateSpace: '<S18>/Discrete SS' */
  {
    rtb_DiscreteSS[0] = (1948.2783190777952)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[0]
      + (1104.208084346717)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (-419.2778106332467)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2];
    rtb_DiscreteSS[0] += (1.4854105040507398E+6)*rtb_Sum_a[0];
    rtb_DiscreteSS[1] = (1948.2783190777952)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[3]
      + (1104.208084346717)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[4]
      + (-419.2778106332467)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5];
    rtb_DiscreteSS[1] += (1.4854105040507398E+6)*rtb_Sum_a[1];
    rtb_DiscreteSS[2] = (1948.2783190777952)*
      M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[6]
      + (1104.208084346717)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7]
      + (-419.2778106332467)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[8];
    rtb_DiscreteSS[2] += (1.4854105040507398E+6)*rtb_Sum_a[2];
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
    real_T xnew[15];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE[0];
    xnew[0] += (1023.9999999999999)*rtb_Sum[0];
    xnew[1] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE[4];
    xnew[1] += (-1120.5510534092775)*rtb_Sum[0];
    xnew[2] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE[4];
    xnew[2] += (-336.90539860045152)*rtb_Sum[0];
    xnew[3] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE[4];
    xnew[3] += (128.53410133650235)*rtb_Sum[0];
    xnew[4] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE[1]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE[2]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE[3]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE[4];
    xnew[4] += (-176.45378527605362)*rtb_Sum[0];
    xnew[5] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE[5];
    xnew[5] += (1023.9999999999999)*rtb_Sum[1];
    xnew[6] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE[8]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE[9];
    xnew[6] += (-1120.5510534092775)*rtb_Sum[1];
    xnew[7] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE[8]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE[9];
    xnew[7] += (-336.90539860045152)*rtb_Sum[1];
    xnew[8] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE[8]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE[9];
    xnew[8] += (128.53410133650235)*rtb_Sum[1];
    xnew[9] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE[6]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE[7]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE[8]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE[9];
    xnew[9] += (-176.45378527605362)*rtb_Sum[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE[10];
    xnew[10] += (1024.0)*rtb_Sum[2];
    xnew[11] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE[11]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE[12]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE[13]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE[14];
    xnew[11] += (-958.30312896150065)*rtb_Sum[2];
    xnew[12] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE[11]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE[12]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE[13]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE[14];
    xnew[12] += (-189.8152626205912)*rtb_Sum[2];
    xnew[13] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE[11]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE[12]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE[13]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE[14];
    xnew[13] += (-149.26785650881041)*rtb_Sum[2];
    xnew[14] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE[11]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE[12]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE[13]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE[14];
    xnew[14] += (-230.40381097529237)*rtb_Sum[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE[0], xnew,
                  sizeof(real_T)*15);
  }

  /* Update for DiscreteStateSpace: '<S13>/Discrete SS' */
  {
    real_T xnew[20];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0];
    xnew[0] += (1023.9999999999999)*rtb_Sum_f[0];
    xnew[1] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[4];
    xnew[1] += (-1120.5510534092775)*rtb_Sum_f[0];
    xnew[2] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[4];
    xnew[2] += (-336.90539860045152)*rtb_Sum_f[0];
    xnew[3] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[4];
    xnew[3] += (128.53410133650235)*rtb_Sum_f[0];
    xnew[4] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[1]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[2]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[3]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[4];
    xnew[4] += (-176.45378527605362)*rtb_Sum_f[0];
    xnew[5] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[5];
    xnew[5] += (1024.0)*rtb_Sum_f[1];
    xnew[6] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[6]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[7]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[8]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[9];
    xnew[6] += (-958.30312896150065)*rtb_Sum_f[1];
    xnew[7] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[6]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[7]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[8]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[9];
    xnew[7] += (-189.8152626205912)*rtb_Sum_f[1];
    xnew[8] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[6]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[7]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[8]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[9];
    xnew[8] += (-149.26785650881041)*rtb_Sum_f[1];
    xnew[9] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[6]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[7]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[8]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[9];
    xnew[9] += (-230.40381097529237)*rtb_Sum_f[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[10];
    xnew[10] += (1023.9999999999999)*rtb_Sum_f[2];
    xnew[11] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[14];
    xnew[11] += (-1120.5510534092775)*rtb_Sum_f[2];
    xnew[12] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[14];
    xnew[12] += (-336.90539860045152)*rtb_Sum_f[2];
    xnew[13] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[14];
    xnew[13] += (128.53410133650235)*rtb_Sum_f[2];
    xnew[14] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[11]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[12]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[13]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[14];
    xnew[14] += (-176.45378527605362)*rtb_Sum_f[2];
    xnew[15] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[15];
    xnew[16] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[16]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[17]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[18]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[19];
    xnew[17] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[16]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[17]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[18]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[19];
    xnew[18] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[16]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[17]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[18]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[19];
    xnew[19] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[16]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[17]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[18]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_a[19];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_a[0], xnew,
                  sizeof(real_T)*20);
  }

  /* Update for DiscreteStateSpace: '<S14>/Discrete SS' */
  {
    real_T xnew[15];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0];
    xnew[0] += (1023.9999999999999)*rtb_Sum_c[0];
    xnew[1] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[4];
    xnew[1] += (-1120.5510534092775)*rtb_Sum_c[0];
    xnew[2] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[4];
    xnew[2] += (-336.90539860045152)*rtb_Sum_c[0];
    xnew[3] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[4];
    xnew[3] += (128.53410133650235)*rtb_Sum_c[0];
    xnew[4] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[1]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[2]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[3]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[4];
    xnew[4] += (-176.45378527605362)*rtb_Sum_c[0];
    xnew[5] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[5];
    xnew[5] += (1023.9999999999999)*rtb_Sum_c[1];
    xnew[6] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[8]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[9];
    xnew[6] += (-1120.5510534092775)*rtb_Sum_c[1];
    xnew[7] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[8]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[9];
    xnew[7] += (-336.90539860045152)*rtb_Sum_c[1];
    xnew[8] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[8]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[9];
    xnew[8] += (128.53410133650235)*rtb_Sum_c[1];
    xnew[9] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[6]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[7]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[8]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[9];
    xnew[9] += (-176.45378527605362)*rtb_Sum_c[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[10];
    xnew[10] += (1024.0)*rtb_Sum_c[2];
    xnew[11] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[11]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[12]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[13]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[14];
    xnew[11] += (-958.30312896150065)*rtb_Sum_c[2];
    xnew[12] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[11]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[12]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[13]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[14];
    xnew[12] += (-189.8152626205912)*rtb_Sum_c[2];
    xnew[13] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[11]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[12]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[13]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[14];
    xnew[13] += (-149.26785650881041)*rtb_Sum_c[2];
    xnew[14] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[11]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[12]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[13]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_j[14];
    xnew[14] += (-230.40381097529237)*rtb_Sum_c[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_j[0], xnew,
                  sizeof(real_T)*15);
  }

  /* Update for DiscreteStateSpace: '<S15>/Discrete SS' */
  {
    real_T xnew[20];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0];
    xnew[0] += (1023.9999999999999)*rtb_Sum_j[0];
    xnew[1] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[4];
    xnew[1] += (-1120.5510534092775)*rtb_Sum_j[0];
    xnew[2] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[4];
    xnew[2] += (-336.90539860045152)*rtb_Sum_j[0];
    xnew[3] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[4];
    xnew[3] += (128.53410133650235)*rtb_Sum_j[0];
    xnew[4] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[1]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[2]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[3]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[4];
    xnew[4] += (-176.45378527605362)*rtb_Sum_j[0];
    xnew[5] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[5];
    xnew[5] += (1024.0)*rtb_Sum_j[1];
    xnew[6] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[6]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[7]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[8]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[9];
    xnew[6] += (-958.30312896150065)*rtb_Sum_j[1];
    xnew[7] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[6]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[7]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[8]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[9];
    xnew[7] += (-189.8152626205912)*rtb_Sum_j[1];
    xnew[8] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[6]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[7]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[8]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[9];
    xnew[8] += (-149.26785650881041)*rtb_Sum_j[1];
    xnew[9] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[6]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[7]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[8]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[9];
    xnew[9] += (-230.40381097529237)*rtb_Sum_j[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[10];
    xnew[10] += (1023.9999999999999)*rtb_Sum_j[2];
    xnew[11] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[14];
    xnew[11] += (-1120.5510534092775)*rtb_Sum_j[2];
    xnew[12] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[14];
    xnew[12] += (-336.90539860045152)*rtb_Sum_j[2];
    xnew[13] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[14];
    xnew[13] += (128.53410133650235)*rtb_Sum_j[2];
    xnew[14] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[11]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[12]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[13]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[14];
    xnew[14] += (-176.45378527605362)*rtb_Sum_j[2];
    xnew[15] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[15];
    xnew[16] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[16]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[17]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[18]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[19];
    xnew[17] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[16]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[17]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[18]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[19];
    xnew[18] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[16]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[17]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[18]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[19];
    xnew[19] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[16]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[17]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[18]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_af[19];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_af[0], xnew,
                  sizeof(real_T)*20);
  }

  /* Update for DiscreteStateSpace: '<S16>/Discrete SS' */
  {
    real_T xnew[15];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0];
    xnew[0] += (1023.9999999999999)*rtb_Sum_i[0];
    xnew[1] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[4];
    xnew[1] += (-1120.5510534092775)*rtb_Sum_i[0];
    xnew[2] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[4];
    xnew[2] += (-336.90539860045152)*rtb_Sum_i[0];
    xnew[3] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[4];
    xnew[3] += (128.53410133650235)*rtb_Sum_i[0];
    xnew[4] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[1]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[2]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[3]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[4];
    xnew[4] += (-176.45378527605362)*rtb_Sum_i[0];
    xnew[5] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[5];
    xnew[5] += (1023.9999999999999)*rtb_Sum_i[1];
    xnew[6] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[8]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[9];
    xnew[6] += (-1120.5510534092775)*rtb_Sum_i[1];
    xnew[7] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[8]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[9];
    xnew[7] += (-336.90539860045152)*rtb_Sum_i[1];
    xnew[8] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[8]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[9];
    xnew[8] += (128.53410133650235)*rtb_Sum_i[1];
    xnew[9] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[6]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[7]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[8]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[9];
    xnew[9] += (-176.45378527605362)*rtb_Sum_i[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[10];
    xnew[10] += (1024.0)*rtb_Sum_i[2];
    xnew[11] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[11]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[12]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[13]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[14];
    xnew[11] += (-958.30312896150065)*rtb_Sum_i[2];
    xnew[12] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[11]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[12]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[13]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[14];
    xnew[12] += (-189.8152626205912)*rtb_Sum_i[2];
    xnew[13] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[11]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[12]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[13]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[14];
    xnew[13] += (-149.26785650881041)*rtb_Sum_i[2];
    xnew[14] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[11]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[12]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[13]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_c[14];
    xnew[14] += (-230.40381097529237)*rtb_Sum_i[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_c[0], xnew,
                  sizeof(real_T)*15);
  }

  /* Update for DiscreteStateSpace: '<S17>/Discrete SS' */
  {
    real_T xnew[20];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0];
    xnew[0] += (1023.9999999999999)*rtb_Sum_i3[0];
    xnew[1] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[4];
    xnew[1] += (-1120.5510534092775)*rtb_Sum_i3[0];
    xnew[2] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[4];
    xnew[2] += (-336.90539860045152)*rtb_Sum_i3[0];
    xnew[3] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[4];
    xnew[3] += (128.53410133650235)*rtb_Sum_i3[0];
    xnew[4] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[1]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[2]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[3]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[4];
    xnew[4] += (-176.45378527605362)*rtb_Sum_i3[0];
    xnew[5] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[5];
    xnew[5] += (1024.0)*rtb_Sum_i3[1];
    xnew[6] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[6]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[7]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[8]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[9];
    xnew[6] += (-958.30312896150065)*rtb_Sum_i3[1];
    xnew[7] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[6]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[7]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[8]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[9];
    xnew[7] += (-189.8152626205912)*rtb_Sum_i3[1];
    xnew[8] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[6]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[7]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[8]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[9];
    xnew[8] += (-149.26785650881041)*rtb_Sum_i3[1];
    xnew[9] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[6]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[7]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[8]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[9];
    xnew[9] += (-230.40381097529237)*rtb_Sum_i3[1];
    xnew[10] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[10];
    xnew[10] += (1023.9999999999999)*rtb_Sum_i3[2];
    xnew[11] = (0.70838643675114987)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (0.060891724528976732)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13]
      + (0.09903799562420107)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[14];
    xnew[11] += (-1120.5510534092775)*rtb_Sum_i3[2];
    xnew[12] = (-0.27824257665809005)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (0.73756366872593626)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (-0.17339877708014395)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13]
      + (-0.16035877696154821)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[14];
    xnew[12] += (-336.90539860045152)*rtb_Sum_i3[2];
    xnew[13] = (0.060891724528977093)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (0.17339877708014437)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (0.65118641914495357)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13]
      + (-0.67781189298444855)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[14];
    xnew[13] += (128.53410133650235)*rtb_Sum_i3[2];
    xnew[14] = (-0.099037995624200667)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[11]
      + (-0.16035877696154735)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[12]
      + (0.6778118929844501)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[13]
      + (0.38128893584267776)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[14];
    xnew[14] += (-176.45378527605362)*rtb_Sum_i3[2];
    xnew[15] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[15];
    xnew[16] = (0.7223032536535634)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[16]
      + (0.21199163206941465)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[17]
      + (-0.09167255169410693)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[18]
      + (0.18280535147576971)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[19];
    xnew[17] = (-0.21199163206941463)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[16]
      + (0.90078105736385339)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[17]
      + (0.13540022789450382)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[18]
      + (-0.098958933944088945)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[19];
    xnew[18] = (-0.0916725516941071)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[16]
      + (-0.13540022789450415)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[17]
      + (0.7530958804882949)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[18]
      + (0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[19];
    xnew[19] = (-0.18280535147576968)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[16]
      + (-0.098958933944089)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[17]
      + (-0.59707458411084047)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[18]
      + (0.52115400072242024)*M2_PZT_Control_DW.DiscreteSS_DSTATE_l[19];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_l[0], xnew,
                  sizeof(real_T)*20);
  }

  /* Update for DiscreteStateSpace: '<S18>/Discrete SS' */
  {
    real_T xnew[9];
    xnew[0] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[0];
    xnew[0] += (1023.9999999999995)*rtb_Sum_a[0];
    xnew[1] = (0.70164366797693434)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (0.32563521369239856)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2];
    xnew[1] += (-1104.2080843467174)*rtb_Sum_a[0];
    xnew[2] = (-0.32563521369239834)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[1]
      + (0.55576606480653123)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[2];
    xnew[2] += (-419.27781063324659)*rtb_Sum_a[0];
    xnew[3] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[3];
    xnew[3] += (1023.9999999999995)*rtb_Sum_a[1];
    xnew[4] = (0.70164366797693434)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[4]
      + (0.32563521369239856)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5];
    xnew[4] += (-1104.2080843467174)*rtb_Sum_a[1];
    xnew[5] = (-0.32563521369239834)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[4]
      + (0.55576606480653123)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[5];
    xnew[5] += (-419.27781063324659)*rtb_Sum_a[1];
    xnew[6] = (1.0)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[6];
    xnew[6] += (1023.9999999999995)*rtb_Sum_a[2];
    xnew[7] = (0.70164366797693434)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7]
      + (0.32563521369239856)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[8];
    xnew[7] += (-1104.2080843467174)*rtb_Sum_a[2];
    xnew[8] = (-0.32563521369239834)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[7]
      + (0.55576606480653123)*M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[8];
    xnew[8] += (-419.27781063324659)*rtb_Sum_a[2];
    (void) memcpy(&M2_PZT_Control_DW.DiscreteSS_DSTATE_jv[0], xnew,
                  sizeof(real_T)*9);
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
