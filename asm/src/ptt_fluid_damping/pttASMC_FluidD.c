/*
 * File: pttASMC_FluidD.c
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

#include "pttASMC_FluidD.h"
#include "pttASMC_FluidD_private.h"

/* Block states (default storage) */
DW_pttASMC_FluidD_T pttASMC_FluidD_DW;

/* External inputs (root inport signals with default storage) */
ExtU_pttASMC_FluidD_T pttASMC_FluidD_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_pttASMC_FluidD_T pttASMC_FluidD_Y;

/* Real-time model */
static RT_MODEL_pttASMC_FluidD_T pttASMC_FluidD_M_;
RT_MODEL_pttASMC_FluidD_T *const pttASMC_FluidD_M = &pttASMC_FluidD_M_;

/* Model step function */
void pttASMC_FluidD_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum1[21];
  real_T rtb_Internal[42];
  real_T rtb_Ucpfs[21];
  real_T rtb_FzMxy_2_6F[84];
  real_T rtb_FzMxydamp_2_6F[84];
  real_T rtb_Add[42];
  real_T rtb_TSamp[21];
  real_T rtb_gain1[21];
  real_T tmp[21];
  real_T tmp_0;
  int32_T i;
  int32_T i_0;
  int32_T tmp_1;

  /* DiscreteStateSpace: '<S3>/Internal' incorporates:
   *  Inport: '<Root>/Rrbfs'
   */
  {
    {
      static const int_T colCidxRow0[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = pttASMC_FluidD_ConstP.Internal_C;
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y0 = &rtb_Internal[0];
      int_T numNonZero = 5;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Internal[0] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[0];

    {
      static const int_T colCidxRow1[6] = { 6, 7, 8, 9, 10, 11 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC6 = &pttASMC_FluidD_ConstP.Internal_C[6];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y1 = &rtb_Internal[1];
      int_T numNonZero = 5;
      *y1 = (*pC6++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC6++) * xd[*pCidx++];
      }
    }

    rtb_Internal[1] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[1];

    {
      static const int_T colCidxRow2[6] = { 12, 13, 14, 15, 16, 17 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC12 = &pttASMC_FluidD_ConstP.Internal_C[12];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y2 = &rtb_Internal[2];
      int_T numNonZero = 5;
      *y2 = (*pC12++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC12++) * xd[*pCidx++];
      }
    }

    rtb_Internal[2] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[2];

    {
      static const int_T colCidxRow3[6] = { 18, 19, 20, 21, 22, 23 };

      const int_T *pCidx = &colCidxRow3[0];
      const real_T *pC18 = &pttASMC_FluidD_ConstP.Internal_C[18];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y3 = &rtb_Internal[3];
      int_T numNonZero = 5;
      *y3 = (*pC18++) * xd[*pCidx++];
      while (numNonZero--) {
        *y3 += (*pC18++) * xd[*pCidx++];
      }
    }

    rtb_Internal[3] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[3];

    {
      static const int_T colCidxRow4[6] = { 24, 25, 26, 27, 28, 29 };

      const int_T *pCidx = &colCidxRow4[0];
      const real_T *pC24 = &pttASMC_FluidD_ConstP.Internal_C[24];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y4 = &rtb_Internal[4];
      int_T numNonZero = 5;
      *y4 = (*pC24++) * xd[*pCidx++];
      while (numNonZero--) {
        *y4 += (*pC24++) * xd[*pCidx++];
      }
    }

    rtb_Internal[4] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[4];

    {
      static const int_T colCidxRow5[6] = { 30, 31, 32, 33, 34, 35 };

      const int_T *pCidx = &colCidxRow5[0];
      const real_T *pC30 = &pttASMC_FluidD_ConstP.Internal_C[30];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y5 = &rtb_Internal[5];
      int_T numNonZero = 5;
      *y5 = (*pC30++) * xd[*pCidx++];
      while (numNonZero--) {
        *y5 += (*pC30++) * xd[*pCidx++];
      }
    }

    rtb_Internal[5] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[5];

    {
      static const int_T colCidxRow6[6] = { 36, 37, 38, 39, 40, 41 };

      const int_T *pCidx = &colCidxRow6[0];
      const real_T *pC36 = &pttASMC_FluidD_ConstP.Internal_C[36];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y6 = &rtb_Internal[6];
      int_T numNonZero = 5;
      *y6 = (*pC36++) * xd[*pCidx++];
      while (numNonZero--) {
        *y6 += (*pC36++) * xd[*pCidx++];
      }
    }

    rtb_Internal[6] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[6];

    {
      static const int_T colCidxRow7[6] = { 42, 43, 44, 45, 46, 47 };

      const int_T *pCidx = &colCidxRow7[0];
      const real_T *pC42 = &pttASMC_FluidD_ConstP.Internal_C[42];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y7 = &rtb_Internal[7];
      int_T numNonZero = 5;
      *y7 = (*pC42++) * xd[*pCidx++];
      while (numNonZero--) {
        *y7 += (*pC42++) * xd[*pCidx++];
      }
    }

    rtb_Internal[7] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[7];

    {
      static const int_T colCidxRow8[6] = { 48, 49, 50, 51, 52, 53 };

      const int_T *pCidx = &colCidxRow8[0];
      const real_T *pC48 = &pttASMC_FluidD_ConstP.Internal_C[48];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y8 = &rtb_Internal[8];
      int_T numNonZero = 5;
      *y8 = (*pC48++) * xd[*pCidx++];
      while (numNonZero--) {
        *y8 += (*pC48++) * xd[*pCidx++];
      }
    }

    rtb_Internal[8] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[8];

    {
      static const int_T colCidxRow9[6] = { 54, 55, 56, 57, 58, 59 };

      const int_T *pCidx = &colCidxRow9[0];
      const real_T *pC54 = &pttASMC_FluidD_ConstP.Internal_C[54];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y9 = &rtb_Internal[9];
      int_T numNonZero = 5;
      *y9 = (*pC54++) * xd[*pCidx++];
      while (numNonZero--) {
        *y9 += (*pC54++) * xd[*pCidx++];
      }
    }

    rtb_Internal[9] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[9];

    {
      static const int_T colCidxRow10[6] = { 60, 61, 62, 63, 64, 65 };

      const int_T *pCidx = &colCidxRow10[0];
      const real_T *pC60 = &pttASMC_FluidD_ConstP.Internal_C[60];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y10 = &rtb_Internal[10];
      int_T numNonZero = 5;
      *y10 = (*pC60++) * xd[*pCidx++];
      while (numNonZero--) {
        *y10 += (*pC60++) * xd[*pCidx++];
      }
    }

    rtb_Internal[10] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[10];

    {
      static const int_T colCidxRow11[6] = { 66, 67, 68, 69, 70, 71 };

      const int_T *pCidx = &colCidxRow11[0];
      const real_T *pC66 = &pttASMC_FluidD_ConstP.Internal_C[66];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y11 = &rtb_Internal[11];
      int_T numNonZero = 5;
      *y11 = (*pC66++) * xd[*pCidx++];
      while (numNonZero--) {
        *y11 += (*pC66++) * xd[*pCidx++];
      }
    }

    rtb_Internal[11] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[11];

    {
      static const int_T colCidxRow12[6] = { 72, 73, 74, 75, 76, 77 };

      const int_T *pCidx = &colCidxRow12[0];
      const real_T *pC72 = &pttASMC_FluidD_ConstP.Internal_C[72];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y12 = &rtb_Internal[12];
      int_T numNonZero = 5;
      *y12 = (*pC72++) * xd[*pCidx++];
      while (numNonZero--) {
        *y12 += (*pC72++) * xd[*pCidx++];
      }
    }

    rtb_Internal[12] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[12];

    {
      static const int_T colCidxRow13[6] = { 78, 79, 80, 81, 82, 83 };

      const int_T *pCidx = &colCidxRow13[0];
      const real_T *pC78 = &pttASMC_FluidD_ConstP.Internal_C[78];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y13 = &rtb_Internal[13];
      int_T numNonZero = 5;
      *y13 = (*pC78++) * xd[*pCidx++];
      while (numNonZero--) {
        *y13 += (*pC78++) * xd[*pCidx++];
      }
    }

    rtb_Internal[13] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[13];

    {
      static const int_T colCidxRow14[6] = { 84, 85, 86, 87, 88, 89 };

      const int_T *pCidx = &colCidxRow14[0];
      const real_T *pC84 = &pttASMC_FluidD_ConstP.Internal_C[84];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y14 = &rtb_Internal[14];
      int_T numNonZero = 5;
      *y14 = (*pC84++) * xd[*pCidx++];
      while (numNonZero--) {
        *y14 += (*pC84++) * xd[*pCidx++];
      }
    }

    rtb_Internal[14] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[14];

    {
      static const int_T colCidxRow15[6] = { 90, 91, 92, 93, 94, 95 };

      const int_T *pCidx = &colCidxRow15[0];
      const real_T *pC90 = &pttASMC_FluidD_ConstP.Internal_C[90];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y15 = &rtb_Internal[15];
      int_T numNonZero = 5;
      *y15 = (*pC90++) * xd[*pCidx++];
      while (numNonZero--) {
        *y15 += (*pC90++) * xd[*pCidx++];
      }
    }

    rtb_Internal[15] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[15];

    {
      static const int_T colCidxRow16[6] = { 96, 97, 98, 99, 100, 101 };

      const int_T *pCidx = &colCidxRow16[0];
      const real_T *pC96 = &pttASMC_FluidD_ConstP.Internal_C[96];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y16 = &rtb_Internal[16];
      int_T numNonZero = 5;
      *y16 = (*pC96++) * xd[*pCidx++];
      while (numNonZero--) {
        *y16 += (*pC96++) * xd[*pCidx++];
      }
    }

    rtb_Internal[16] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[16];

    {
      static const int_T colCidxRow17[6] = { 102, 103, 104, 105, 106, 107 };

      const int_T *pCidx = &colCidxRow17[0];
      const real_T *pC102 = &pttASMC_FluidD_ConstP.Internal_C[102];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y17 = &rtb_Internal[17];
      int_T numNonZero = 5;
      *y17 = (*pC102++) * xd[*pCidx++];
      while (numNonZero--) {
        *y17 += (*pC102++) * xd[*pCidx++];
      }
    }

    rtb_Internal[17] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[17];

    {
      static const int_T colCidxRow18[6] = { 108, 109, 110, 111, 112, 113 };

      const int_T *pCidx = &colCidxRow18[0];
      const real_T *pC108 = &pttASMC_FluidD_ConstP.Internal_C[108];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y18 = &rtb_Internal[18];
      int_T numNonZero = 5;
      *y18 = (*pC108++) * xd[*pCidx++];
      while (numNonZero--) {
        *y18 += (*pC108++) * xd[*pCidx++];
      }
    }

    rtb_Internal[18] += (1.393702265659542E+7)*pttASMC_FluidD_U.Rrbfs[18];

    {
      static const int_T colCidxRow19[6] = { 114, 115, 116, 117, 118, 119 };

      const int_T *pCidx = &colCidxRow19[0];
      const real_T *pC114 = &pttASMC_FluidD_ConstP.Internal_C[114];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y19 = &rtb_Internal[19];
      int_T numNonZero = 5;
      *y19 = (*pC114++) * xd[*pCidx++];
      while (numNonZero--) {
        *y19 += (*pC114++) * xd[*pCidx++];
      }
    }

    rtb_Internal[19] += (974394.034385261)*pttASMC_FluidD_U.Rrbfs[19];

    {
      static const int_T colCidxRow20[6] = { 120, 121, 122, 123, 124, 125 };

      const int_T *pCidx = &colCidxRow20[0];
      const real_T *pC120 = &pttASMC_FluidD_ConstP.Internal_C[120];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y20 = &rtb_Internal[20];
      int_T numNonZero = 5;
      *y20 = (*pC120++) * xd[*pCidx++];
      while (numNonZero--) {
        *y20 += (*pC120++) * xd[*pCidx++];
      }
    }

    rtb_Internal[20] += (974394.03438526159)*pttASMC_FluidD_U.Rrbfs[20];

    {
      static const int_T colCidxRow21[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pCidx = &colCidxRow21[0];
      const real_T *pC126 = &pttASMC_FluidD_ConstP.Internal_C[126];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y21 = &rtb_Internal[21];
      int_T numNonZero = 5;
      *y21 = (*pC126++) * xd[*pCidx++];
      while (numNonZero--) {
        *y21 += (*pC126++) * xd[*pCidx++];
      }
    }

    rtb_Internal[21] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[0];

    {
      static const int_T colCidxRow22[6] = { 6, 7, 8, 9, 10, 11 };

      const int_T *pCidx = &colCidxRow22[0];
      const real_T *pC132 = &pttASMC_FluidD_ConstP.Internal_C[132];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y22 = &rtb_Internal[22];
      int_T numNonZero = 5;
      *y22 = (*pC132++) * xd[*pCidx++];
      while (numNonZero--) {
        *y22 += (*pC132++) * xd[*pCidx++];
      }
    }

    rtb_Internal[22] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[1];

    {
      static const int_T colCidxRow23[6] = { 12, 13, 14, 15, 16, 17 };

      const int_T *pCidx = &colCidxRow23[0];
      const real_T *pC138 = &pttASMC_FluidD_ConstP.Internal_C[138];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y23 = &rtb_Internal[23];
      int_T numNonZero = 5;
      *y23 = (*pC138++) * xd[*pCidx++];
      while (numNonZero--) {
        *y23 += (*pC138++) * xd[*pCidx++];
      }
    }

    rtb_Internal[23] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[2];

    {
      static const int_T colCidxRow24[6] = { 18, 19, 20, 21, 22, 23 };

      const int_T *pCidx = &colCidxRow24[0];
      const real_T *pC144 = &pttASMC_FluidD_ConstP.Internal_C[144];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y24 = &rtb_Internal[24];
      int_T numNonZero = 5;
      *y24 = (*pC144++) * xd[*pCidx++];
      while (numNonZero--) {
        *y24 += (*pC144++) * xd[*pCidx++];
      }
    }

    rtb_Internal[24] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[3];

    {
      static const int_T colCidxRow25[6] = { 24, 25, 26, 27, 28, 29 };

      const int_T *pCidx = &colCidxRow25[0];
      const real_T *pC150 = &pttASMC_FluidD_ConstP.Internal_C[150];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y25 = &rtb_Internal[25];
      int_T numNonZero = 5;
      *y25 = (*pC150++) * xd[*pCidx++];
      while (numNonZero--) {
        *y25 += (*pC150++) * xd[*pCidx++];
      }
    }

    rtb_Internal[25] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[4];

    {
      static const int_T colCidxRow26[6] = { 30, 31, 32, 33, 34, 35 };

      const int_T *pCidx = &colCidxRow26[0];
      const real_T *pC156 = &pttASMC_FluidD_ConstP.Internal_C[156];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y26 = &rtb_Internal[26];
      int_T numNonZero = 5;
      *y26 = (*pC156++) * xd[*pCidx++];
      while (numNonZero--) {
        *y26 += (*pC156++) * xd[*pCidx++];
      }
    }

    rtb_Internal[26] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[5];

    {
      static const int_T colCidxRow27[6] = { 36, 37, 38, 39, 40, 41 };

      const int_T *pCidx = &colCidxRow27[0];
      const real_T *pC162 = &pttASMC_FluidD_ConstP.Internal_C[162];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y27 = &rtb_Internal[27];
      int_T numNonZero = 5;
      *y27 = (*pC162++) * xd[*pCidx++];
      while (numNonZero--) {
        *y27 += (*pC162++) * xd[*pCidx++];
      }
    }

    rtb_Internal[27] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[6];

    {
      static const int_T colCidxRow28[6] = { 42, 43, 44, 45, 46, 47 };

      const int_T *pCidx = &colCidxRow28[0];
      const real_T *pC168 = &pttASMC_FluidD_ConstP.Internal_C[168];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y28 = &rtb_Internal[28];
      int_T numNonZero = 5;
      *y28 = (*pC168++) * xd[*pCidx++];
      while (numNonZero--) {
        *y28 += (*pC168++) * xd[*pCidx++];
      }
    }

    rtb_Internal[28] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[7];

    {
      static const int_T colCidxRow29[6] = { 48, 49, 50, 51, 52, 53 };

      const int_T *pCidx = &colCidxRow29[0];
      const real_T *pC174 = &pttASMC_FluidD_ConstP.Internal_C[174];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y29 = &rtb_Internal[29];
      int_T numNonZero = 5;
      *y29 = (*pC174++) * xd[*pCidx++];
      while (numNonZero--) {
        *y29 += (*pC174++) * xd[*pCidx++];
      }
    }

    rtb_Internal[29] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[8];

    {
      static const int_T colCidxRow30[6] = { 54, 55, 56, 57, 58, 59 };

      const int_T *pCidx = &colCidxRow30[0];
      const real_T *pC180 = &pttASMC_FluidD_ConstP.Internal_C[180];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y30 = &rtb_Internal[30];
      int_T numNonZero = 5;
      *y30 = (*pC180++) * xd[*pCidx++];
      while (numNonZero--) {
        *y30 += (*pC180++) * xd[*pCidx++];
      }
    }

    rtb_Internal[30] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[9];

    {
      static const int_T colCidxRow31[6] = { 60, 61, 62, 63, 64, 65 };

      const int_T *pCidx = &colCidxRow31[0];
      const real_T *pC186 = &pttASMC_FluidD_ConstP.Internal_C[186];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y31 = &rtb_Internal[31];
      int_T numNonZero = 5;
      *y31 = (*pC186++) * xd[*pCidx++];
      while (numNonZero--) {
        *y31 += (*pC186++) * xd[*pCidx++];
      }
    }

    rtb_Internal[31] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[10];

    {
      static const int_T colCidxRow32[6] = { 66, 67, 68, 69, 70, 71 };

      const int_T *pCidx = &colCidxRow32[0];
      const real_T *pC192 = &pttASMC_FluidD_ConstP.Internal_C[192];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y32 = &rtb_Internal[32];
      int_T numNonZero = 5;
      *y32 = (*pC192++) * xd[*pCidx++];
      while (numNonZero--) {
        *y32 += (*pC192++) * xd[*pCidx++];
      }
    }

    rtb_Internal[32] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[11];

    {
      static const int_T colCidxRow33[6] = { 72, 73, 74, 75, 76, 77 };

      const int_T *pCidx = &colCidxRow33[0];
      const real_T *pC198 = &pttASMC_FluidD_ConstP.Internal_C[198];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y33 = &rtb_Internal[33];
      int_T numNonZero = 5;
      *y33 = (*pC198++) * xd[*pCidx++];
      while (numNonZero--) {
        *y33 += (*pC198++) * xd[*pCidx++];
      }
    }

    rtb_Internal[33] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[12];

    {
      static const int_T colCidxRow34[6] = { 78, 79, 80, 81, 82, 83 };

      const int_T *pCidx = &colCidxRow34[0];
      const real_T *pC204 = &pttASMC_FluidD_ConstP.Internal_C[204];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y34 = &rtb_Internal[34];
      int_T numNonZero = 5;
      *y34 = (*pC204++) * xd[*pCidx++];
      while (numNonZero--) {
        *y34 += (*pC204++) * xd[*pCidx++];
      }
    }

    rtb_Internal[34] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[13];

    {
      static const int_T colCidxRow35[6] = { 84, 85, 86, 87, 88, 89 };

      const int_T *pCidx = &colCidxRow35[0];
      const real_T *pC210 = &pttASMC_FluidD_ConstP.Internal_C[210];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y35 = &rtb_Internal[35];
      int_T numNonZero = 5;
      *y35 = (*pC210++) * xd[*pCidx++];
      while (numNonZero--) {
        *y35 += (*pC210++) * xd[*pCidx++];
      }
    }

    rtb_Internal[35] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[14];

    {
      static const int_T colCidxRow36[6] = { 90, 91, 92, 93, 94, 95 };

      const int_T *pCidx = &colCidxRow36[0];
      const real_T *pC216 = &pttASMC_FluidD_ConstP.Internal_C[216];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y36 = &rtb_Internal[36];
      int_T numNonZero = 5;
      *y36 = (*pC216++) * xd[*pCidx++];
      while (numNonZero--) {
        *y36 += (*pC216++) * xd[*pCidx++];
      }
    }

    rtb_Internal[36] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[15];

    {
      static const int_T colCidxRow37[6] = { 96, 97, 98, 99, 100, 101 };

      const int_T *pCidx = &colCidxRow37[0];
      const real_T *pC222 = &pttASMC_FluidD_ConstP.Internal_C[222];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y37 = &rtb_Internal[37];
      int_T numNonZero = 5;
      *y37 = (*pC222++) * xd[*pCidx++];
      while (numNonZero--) {
        *y37 += (*pC222++) * xd[*pCidx++];
      }
    }

    rtb_Internal[37] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[16];

    {
      static const int_T colCidxRow38[6] = { 102, 103, 104, 105, 106, 107 };

      const int_T *pCidx = &colCidxRow38[0];
      const real_T *pC228 = &pttASMC_FluidD_ConstP.Internal_C[228];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y38 = &rtb_Internal[38];
      int_T numNonZero = 5;
      *y38 = (*pC228++) * xd[*pCidx++];
      while (numNonZero--) {
        *y38 += (*pC228++) * xd[*pCidx++];
      }
    }

    rtb_Internal[38] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[17];

    {
      static const int_T colCidxRow39[6] = { 108, 109, 110, 111, 112, 113 };

      const int_T *pCidx = &colCidxRow39[0];
      const real_T *pC234 = &pttASMC_FluidD_ConstP.Internal_C[234];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y39 = &rtb_Internal[39];
      int_T numNonZero = 5;
      *y39 = (*pC234++) * xd[*pCidx++];
      while (numNonZero--) {
        *y39 += (*pC234++) * xd[*pCidx++];
      }
    }

    rtb_Internal[39] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[18];

    {
      static const int_T colCidxRow40[6] = { 114, 115, 116, 117, 118, 119 };

      const int_T *pCidx = &colCidxRow40[0];
      const real_T *pC240 = &pttASMC_FluidD_ConstP.Internal_C[240];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y40 = &rtb_Internal[40];
      int_T numNonZero = 5;
      *y40 = (*pC240++) * xd[*pCidx++];
      while (numNonZero--) {
        *y40 += (*pC240++) * xd[*pCidx++];
      }
    }

    rtb_Internal[40] += (0.0060642155112588048)*pttASMC_FluidD_U.Rrbfs[19];

    {
      static const int_T colCidxRow41[6] = { 120, 121, 122, 123, 124, 125 };

      const int_T *pCidx = &colCidxRow41[0];
      const real_T *pC246 = &pttASMC_FluidD_ConstP.Internal_C[246];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *y41 = &rtb_Internal[41];
      int_T numNonZero = 5;
      *y41 = (*pC246++) * xd[*pCidx++];
      while (numNonZero--) {
        *y41 += (*pC246++) * xd[*pCidx++];
      }
    }

    rtb_Internal[41] += (0.0060642155112588074)*pttASMC_FluidD_U.Rrbfs[20];
  }

  /* Sum: '<S1>/Add1' incorporates:
   *  Inport: '<Root>/ASM_FS_6D'
   *  Inport: '<Root>/ASM_RB_6D'
   */
  for (i = 0; i < 42; i++) {
    rtb_Add[i] = pttASMC_FluidD_U.ASM_RB_6D[i] - pttASMC_FluidD_U.ASM_FS_6D[i];
  }

  /* End of Sum: '<S1>/Add1' */

  /* Sum: '<S1>/Sum1' */
  rtb_Sum1[0] = rtb_Internal[21] - rtb_Add[2];
  rtb_Sum1[3] = rtb_Internal[24] - rtb_Add[8];
  rtb_Sum1[6] = rtb_Internal[27] - rtb_Add[14];
  rtb_Sum1[9] = rtb_Internal[30] - rtb_Add[20];
  rtb_Sum1[12] = rtb_Internal[33] - rtb_Add[26];
  rtb_Sum1[15] = rtb_Internal[36] - rtb_Add[32];
  rtb_Sum1[18] = rtb_Internal[39] - rtb_Add[38];
  rtb_Sum1[1] = rtb_Internal[22] - rtb_Add[3];
  rtb_Sum1[4] = rtb_Internal[25] - rtb_Add[9];
  rtb_Sum1[7] = rtb_Internal[28] - rtb_Add[15];
  rtb_Sum1[10] = rtb_Internal[31] - rtb_Add[21];
  rtb_Sum1[13] = rtb_Internal[34] - rtb_Add[27];
  rtb_Sum1[16] = rtb_Internal[37] - rtb_Add[33];
  rtb_Sum1[19] = rtb_Internal[40] - rtb_Add[39];
  rtb_Sum1[2] = rtb_Internal[23] - rtb_Add[4];
  rtb_Sum1[5] = rtb_Internal[26] - rtb_Add[10];
  rtb_Sum1[8] = rtb_Internal[29] - rtb_Add[16];
  rtb_Sum1[11] = rtb_Internal[32] - rtb_Add[22];
  rtb_Sum1[14] = rtb_Internal[35] - rtb_Add[28];
  rtb_Sum1[17] = rtb_Internal[38] - rtb_Add[34];
  rtb_Sum1[20] = rtb_Internal[41] - rtb_Add[40];

  /* DiscreteStateSpace: '<S4>/Internal' */
  {
    rtb_Ucpfs[0] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[0];
    rtb_Ucpfs[0] += (4.727109375E+7)*rtb_Sum1[0];
    rtb_Ucpfs[1] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[1];
    rtb_Ucpfs[1] += (3.30491475E+6)*rtb_Sum1[1];
    rtb_Ucpfs[2] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[2];
    rtb_Ucpfs[2] += (3.30491475E+6)*rtb_Sum1[2];
    rtb_Ucpfs[3] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[3];
    rtb_Ucpfs[3] += (4.727109375E+7)*rtb_Sum1[3];
    rtb_Ucpfs[4] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[4];
    rtb_Ucpfs[4] += (3.30491475E+6)*rtb_Sum1[4];
    rtb_Ucpfs[5] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[5];
    rtb_Ucpfs[5] += (3.30491475E+6)*rtb_Sum1[5];
    rtb_Ucpfs[6] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[6];
    rtb_Ucpfs[6] += (4.727109375E+7)*rtb_Sum1[6];
    rtb_Ucpfs[7] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[7];
    rtb_Ucpfs[7] += (3.30491475E+6)*rtb_Sum1[7];
    rtb_Ucpfs[8] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[8];
    rtb_Ucpfs[8] += (3.30491475E+6)*rtb_Sum1[8];
    rtb_Ucpfs[9] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[9];
    rtb_Ucpfs[9] += (4.727109375E+7)*rtb_Sum1[9];
    rtb_Ucpfs[10] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[10];
    rtb_Ucpfs[10] += (3.30491475E+6)*rtb_Sum1[10];
    rtb_Ucpfs[11] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[11];
    rtb_Ucpfs[11] += (3.30491475E+6)*rtb_Sum1[11];
    rtb_Ucpfs[12] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[12];
    rtb_Ucpfs[12] += (4.727109375E+7)*rtb_Sum1[12];
    rtb_Ucpfs[13] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[13];
    rtb_Ucpfs[13] += (3.30491475E+6)*rtb_Sum1[13];
    rtb_Ucpfs[14] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[14];
    rtb_Ucpfs[14] += (3.30491475E+6)*rtb_Sum1[14];
    rtb_Ucpfs[15] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[15];
    rtb_Ucpfs[15] += (4.727109375E+7)*rtb_Sum1[15];
    rtb_Ucpfs[16] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[16];
    rtb_Ucpfs[16] += (3.30491475E+6)*rtb_Sum1[16];
    rtb_Ucpfs[17] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[17];
    rtb_Ucpfs[17] += (3.30491475E+6)*rtb_Sum1[17];
    rtb_Ucpfs[18] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[18];
    rtb_Ucpfs[18] += (4.727109375E+7)*rtb_Sum1[18];
    rtb_Ucpfs[19] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[19];
    rtb_Ucpfs[19] += (3.30491475E+6)*rtb_Sum1[19];
    rtb_Ucpfs[20] = (976.5625)*pttASMC_FluidD_DW.Internal_DSTATE_m[20];
    rtb_Ucpfs[20] += (3.30491475E+6)*rtb_Sum1[20];
  }

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp[0] = rtb_Add[2] * 8000.0;
  rtb_TSamp[3] = rtb_Add[8] * 8000.0;
  rtb_TSamp[6] = rtb_Add[14] * 8000.0;
  rtb_TSamp[9] = rtb_Add[20] * 8000.0;
  rtb_TSamp[12] = rtb_Add[26] * 8000.0;
  rtb_TSamp[15] = rtb_Add[32] * 8000.0;
  rtb_TSamp[18] = rtb_Add[38] * 8000.0;
  rtb_TSamp[1] = rtb_Add[3] * 8000.0;
  rtb_TSamp[4] = rtb_Add[9] * 8000.0;
  rtb_TSamp[7] = rtb_Add[15] * 8000.0;
  rtb_TSamp[10] = rtb_Add[21] * 8000.0;
  rtb_TSamp[13] = rtb_Add[27] * 8000.0;
  rtb_TSamp[16] = rtb_Add[33] * 8000.0;
  rtb_TSamp[19] = rtb_Add[39] * 8000.0;
  rtb_TSamp[2] = rtb_Add[4] * 8000.0;
  rtb_TSamp[5] = rtb_Add[10] * 8000.0;
  rtb_TSamp[8] = rtb_Add[16] * 8000.0;
  rtb_TSamp[11] = rtb_Add[22] * 8000.0;
  rtb_TSamp[14] = rtb_Add[28] * 8000.0;
  rtb_TSamp[17] = rtb_Add[34] * 8000.0;
  rtb_TSamp[20] = rtb_Add[40] * 8000.0;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  for (i = 0; i < 21; i++) {
    rtb_gain1[i] = rtb_TSamp[i] - pttASMC_FluidD_DW.UD_DSTATE[i];
  }

  /* End of Sum: '<S2>/Diff' */
  for (i = 0; i < 21; i++) {
    /* Sum: '<S1>/Sum3' incorporates:
     *  Gain: '<S1>/Kd'
     */
    tmp_0 = 0.0;
    tmp_1 = 0;
    for (i_0 = 0; i_0 < 21; i_0++) {
      tmp_0 += pttASMC_FluidD_ConstP.Kd_Gain[tmp_1 + i] * rtb_gain1[i_0];
      tmp_1 += 21;
    }

    rtb_Ucpfs[i] = (rtb_Internal[i] + rtb_Ucpfs[i]) - tmp_0;

    /* End of Sum: '<S1>/Sum3' */
  }

  /* Gain: '<S1>/FzMxy_2_6F' */
  for (i = 0; i < 84; i++) {
    rtb_FzMxy_2_6F[i] = 0.0;
    tmp_1 = 0;
    for (i_0 = 0; i_0 < 21; i_0++) {
      rtb_FzMxy_2_6F[i] += pttASMC_FluidD_ConstP.FzMxy_2_6F_Gain[tmp_1 + i] *
        rtb_Ucpfs[i_0];
      tmp_1 += 84;
    }
  }

  /* End of Gain: '<S1>/FzMxy_2_6F' */

  /* Outport: '<Root>/Ucp' */
  memcpy(&pttASMC_FluidD_Y.Ucp[0], &rtb_FzMxy_2_6F[0], 42U * sizeof(real_T));

  /* Gain: '<S1>/gain1' */
  for (i = 0; i < 21; i++) {
    rtb_gain1[i] = -rtb_gain1[i];
  }

  /* End of Gain: '<S1>/gain1' */

  /* Gain: '<S1>/Kfd' */
  for (i = 0; i < 21; i++) {
    tmp[i] = 0.0;
    tmp_1 = 0;
    for (i_0 = 0; i_0 < 21; i_0++) {
      tmp[i] += pttASMC_FluidD_ConstP.Kfd_Gain[tmp_1 + i] * rtb_gain1[i_0];
      tmp_1 += 21;
    }
  }

  /* End of Gain: '<S1>/Kfd' */

  /* Gain: '<S1>/FzMxydamp_2_6F' */
  for (i = 0; i < 84; i++) {
    rtb_FzMxydamp_2_6F[i] = 0.0;
    tmp_1 = 0;
    for (i_0 = 0; i_0 < 21; i_0++) {
      rtb_FzMxydamp_2_6F[i] += pttASMC_FluidD_ConstP.FzMxydamp_2_6F_Gain[tmp_1 +
        i] * tmp[i_0];
      tmp_1 += 84;
    }
  }

  /* End of Gain: '<S1>/FzMxydamp_2_6F' */
  for (i = 0; i < 42; i++) {
    /* Outport: '<Root>/Urb' */
    pttASMC_FluidD_Y.Urb[i] = rtb_FzMxydamp_2_6F[i + 42];

    /* Outport: '<Root>/Ufs' incorporates:
     *  Outport: '<Root>/Urb'
     *  Sum: '<S1>/Add'
     */
    pttASMC_FluidD_Y.Ufs[i] = rtb_FzMxy_2_6F[i + 42] + rtb_FzMxydamp_2_6F[i];
  }

  /* Update for DiscreteStateSpace: '<S3>/Internal' incorporates:
   *  Inport: '<Root>/Rrbfs'
   */
  {
    real_T xnew[126];

    {
      static const int_T colAidxRow0[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = pttASMC_FluidD_ConstP.Internal_A;
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 5;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[0];

    {
      static const int_T colAidxRow1[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA6 = &pttASMC_FluidD_ConstP.Internal_A[6];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 5;
      *pxnew1 = (*pA6++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA6++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[0];

    {
      static const int_T colAidxRow2[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA12 = &pttASMC_FluidD_ConstP.Internal_A[12];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 5;
      *pxnew2 = (*pA12++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA12++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[0];

    {
      static const int_T colAidxRow3[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA18 = &pttASMC_FluidD_ConstP.Internal_A[18];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 5;
      *pxnew3 = (*pA18++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA18++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[0];
    xnew[4] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[4]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[5];
    xnew[4] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[0];
    xnew[5] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[4]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[5];
    xnew[5] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[0];

    {
      static const int_T colAidxRow6[6] = { 6, 7, 8, 9, 10, 11 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA28 = &pttASMC_FluidD_ConstP.Internal_A[28];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 5;
      *pxnew6 = (*pA28++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA28++) * xd[*pAidx++];
      }
    }

    xnew[6] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[1];

    {
      static const int_T colAidxRow7[6] = { 6, 7, 8, 9, 10, 11 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA34 = &pttASMC_FluidD_ConstP.Internal_A[34];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 5;
      *pxnew7 = (*pA34++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA34++) * xd[*pAidx++];
      }
    }

    xnew[7] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[1];

    {
      static const int_T colAidxRow8[6] = { 6, 7, 8, 9, 10, 11 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA40 = &pttASMC_FluidD_ConstP.Internal_A[40];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 5;
      *pxnew8 = (*pA40++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA40++) * xd[*pAidx++];
      }
    }

    xnew[8] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[1];

    {
      static const int_T colAidxRow9[6] = { 6, 7, 8, 9, 10, 11 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA46 = &pttASMC_FluidD_ConstP.Internal_A[46];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 5;
      *pxnew9 = (*pA46++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA46++) * xd[*pAidx++];
      }
    }

    xnew[9] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[1];
    xnew[10] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[10]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[11];
    xnew[10] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[1];
    xnew[11] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[10]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[11];
    xnew[11] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[1];

    {
      static const int_T colAidxRow12[6] = { 12, 13, 14, 15, 16, 17 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA56 = &pttASMC_FluidD_ConstP.Internal_A[56];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 5;
      *pxnew12 = (*pA56++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA56++) * xd[*pAidx++];
      }
    }

    xnew[12] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[2];

    {
      static const int_T colAidxRow13[6] = { 12, 13, 14, 15, 16, 17 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA62 = &pttASMC_FluidD_ConstP.Internal_A[62];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 5;
      *pxnew13 = (*pA62++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA62++) * xd[*pAidx++];
      }
    }

    xnew[13] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[2];

    {
      static const int_T colAidxRow14[6] = { 12, 13, 14, 15, 16, 17 };

      const int_T *pAidx = &colAidxRow14[0];
      const real_T *pA68 = &pttASMC_FluidD_ConstP.Internal_A[68];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew14 = &xnew[14];
      int_T numNonZero = 5;
      *pxnew14 = (*pA68++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew14 += (*pA68++) * xd[*pAidx++];
      }
    }

    xnew[14] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[2];

    {
      static const int_T colAidxRow15[6] = { 12, 13, 14, 15, 16, 17 };

      const int_T *pAidx = &colAidxRow15[0];
      const real_T *pA74 = &pttASMC_FluidD_ConstP.Internal_A[74];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 5;
      *pxnew15 = (*pA74++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew15 += (*pA74++) * xd[*pAidx++];
      }
    }

    xnew[15] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[2];
    xnew[16] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[16]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[17];
    xnew[16] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[2];
    xnew[17] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[16]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[17];
    xnew[17] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[2];

    {
      static const int_T colAidxRow18[6] = { 18, 19, 20, 21, 22, 23 };

      const int_T *pAidx = &colAidxRow18[0];
      const real_T *pA84 = &pttASMC_FluidD_ConstP.Internal_A[84];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 5;
      *pxnew18 = (*pA84++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew18 += (*pA84++) * xd[*pAidx++];
      }
    }

    xnew[18] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[3];

    {
      static const int_T colAidxRow19[6] = { 18, 19, 20, 21, 22, 23 };

      const int_T *pAidx = &colAidxRow19[0];
      const real_T *pA90 = &pttASMC_FluidD_ConstP.Internal_A[90];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 5;
      *pxnew19 = (*pA90++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew19 += (*pA90++) * xd[*pAidx++];
      }
    }

    xnew[19] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[3];

    {
      static const int_T colAidxRow20[6] = { 18, 19, 20, 21, 22, 23 };

      const int_T *pAidx = &colAidxRow20[0];
      const real_T *pA96 = &pttASMC_FluidD_ConstP.Internal_A[96];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew20 = &xnew[20];
      int_T numNonZero = 5;
      *pxnew20 = (*pA96++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew20 += (*pA96++) * xd[*pAidx++];
      }
    }

    xnew[20] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[3];

    {
      static const int_T colAidxRow21[6] = { 18, 19, 20, 21, 22, 23 };

      const int_T *pAidx = &colAidxRow21[0];
      const real_T *pA102 = &pttASMC_FluidD_ConstP.Internal_A[102];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew21 = &xnew[21];
      int_T numNonZero = 5;
      *pxnew21 = (*pA102++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew21 += (*pA102++) * xd[*pAidx++];
      }
    }

    xnew[21] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[3];
    xnew[22] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[22]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[23];
    xnew[22] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[3];
    xnew[23] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[22]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[23];
    xnew[23] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[3];

    {
      static const int_T colAidxRow24[6] = { 24, 25, 26, 27, 28, 29 };

      const int_T *pAidx = &colAidxRow24[0];
      const real_T *pA112 = &pttASMC_FluidD_ConstP.Internal_A[112];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew24 = &xnew[24];
      int_T numNonZero = 5;
      *pxnew24 = (*pA112++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew24 += (*pA112++) * xd[*pAidx++];
      }
    }

    xnew[24] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[4];

    {
      static const int_T colAidxRow25[6] = { 24, 25, 26, 27, 28, 29 };

      const int_T *pAidx = &colAidxRow25[0];
      const real_T *pA118 = &pttASMC_FluidD_ConstP.Internal_A[118];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew25 = &xnew[25];
      int_T numNonZero = 5;
      *pxnew25 = (*pA118++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew25 += (*pA118++) * xd[*pAidx++];
      }
    }

    xnew[25] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[4];

    {
      static const int_T colAidxRow26[6] = { 24, 25, 26, 27, 28, 29 };

      const int_T *pAidx = &colAidxRow26[0];
      const real_T *pA124 = &pttASMC_FluidD_ConstP.Internal_A[124];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew26 = &xnew[26];
      int_T numNonZero = 5;
      *pxnew26 = (*pA124++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew26 += (*pA124++) * xd[*pAidx++];
      }
    }

    xnew[26] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[4];

    {
      static const int_T colAidxRow27[6] = { 24, 25, 26, 27, 28, 29 };

      const int_T *pAidx = &colAidxRow27[0];
      const real_T *pA130 = &pttASMC_FluidD_ConstP.Internal_A[130];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew27 = &xnew[27];
      int_T numNonZero = 5;
      *pxnew27 = (*pA130++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew27 += (*pA130++) * xd[*pAidx++];
      }
    }

    xnew[27] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[4];
    xnew[28] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[28]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[29];
    xnew[28] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[4];
    xnew[29] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[28]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[29];
    xnew[29] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[4];

    {
      static const int_T colAidxRow30[6] = { 30, 31, 32, 33, 34, 35 };

      const int_T *pAidx = &colAidxRow30[0];
      const real_T *pA140 = &pttASMC_FluidD_ConstP.Internal_A[140];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew30 = &xnew[30];
      int_T numNonZero = 5;
      *pxnew30 = (*pA140++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew30 += (*pA140++) * xd[*pAidx++];
      }
    }

    xnew[30] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[5];

    {
      static const int_T colAidxRow31[6] = { 30, 31, 32, 33, 34, 35 };

      const int_T *pAidx = &colAidxRow31[0];
      const real_T *pA146 = &pttASMC_FluidD_ConstP.Internal_A[146];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew31 = &xnew[31];
      int_T numNonZero = 5;
      *pxnew31 = (*pA146++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew31 += (*pA146++) * xd[*pAidx++];
      }
    }

    xnew[31] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[5];

    {
      static const int_T colAidxRow32[6] = { 30, 31, 32, 33, 34, 35 };

      const int_T *pAidx = &colAidxRow32[0];
      const real_T *pA152 = &pttASMC_FluidD_ConstP.Internal_A[152];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew32 = &xnew[32];
      int_T numNonZero = 5;
      *pxnew32 = (*pA152++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew32 += (*pA152++) * xd[*pAidx++];
      }
    }

    xnew[32] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[5];

    {
      static const int_T colAidxRow33[6] = { 30, 31, 32, 33, 34, 35 };

      const int_T *pAidx = &colAidxRow33[0];
      const real_T *pA158 = &pttASMC_FluidD_ConstP.Internal_A[158];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew33 = &xnew[33];
      int_T numNonZero = 5;
      *pxnew33 = (*pA158++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew33 += (*pA158++) * xd[*pAidx++];
      }
    }

    xnew[33] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[5];
    xnew[34] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[34]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[35];
    xnew[34] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[5];
    xnew[35] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[34]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[35];
    xnew[35] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[5];

    {
      static const int_T colAidxRow36[6] = { 36, 37, 38, 39, 40, 41 };

      const int_T *pAidx = &colAidxRow36[0];
      const real_T *pA168 = &pttASMC_FluidD_ConstP.Internal_A[168];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew36 = &xnew[36];
      int_T numNonZero = 5;
      *pxnew36 = (*pA168++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew36 += (*pA168++) * xd[*pAidx++];
      }
    }

    xnew[36] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[6];

    {
      static const int_T colAidxRow37[6] = { 36, 37, 38, 39, 40, 41 };

      const int_T *pAidx = &colAidxRow37[0];
      const real_T *pA174 = &pttASMC_FluidD_ConstP.Internal_A[174];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew37 = &xnew[37];
      int_T numNonZero = 5;
      *pxnew37 = (*pA174++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew37 += (*pA174++) * xd[*pAidx++];
      }
    }

    xnew[37] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[6];

    {
      static const int_T colAidxRow38[6] = { 36, 37, 38, 39, 40, 41 };

      const int_T *pAidx = &colAidxRow38[0];
      const real_T *pA180 = &pttASMC_FluidD_ConstP.Internal_A[180];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew38 = &xnew[38];
      int_T numNonZero = 5;
      *pxnew38 = (*pA180++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew38 += (*pA180++) * xd[*pAidx++];
      }
    }

    xnew[38] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[6];

    {
      static const int_T colAidxRow39[6] = { 36, 37, 38, 39, 40, 41 };

      const int_T *pAidx = &colAidxRow39[0];
      const real_T *pA186 = &pttASMC_FluidD_ConstP.Internal_A[186];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew39 = &xnew[39];
      int_T numNonZero = 5;
      *pxnew39 = (*pA186++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew39 += (*pA186++) * xd[*pAidx++];
      }
    }

    xnew[39] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[6];
    xnew[40] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[40]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[41];
    xnew[40] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[6];
    xnew[41] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[40]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[41];
    xnew[41] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[6];

    {
      static const int_T colAidxRow42[6] = { 42, 43, 44, 45, 46, 47 };

      const int_T *pAidx = &colAidxRow42[0];
      const real_T *pA196 = &pttASMC_FluidD_ConstP.Internal_A[196];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew42 = &xnew[42];
      int_T numNonZero = 5;
      *pxnew42 = (*pA196++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew42 += (*pA196++) * xd[*pAidx++];
      }
    }

    xnew[42] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[7];

    {
      static const int_T colAidxRow43[6] = { 42, 43, 44, 45, 46, 47 };

      const int_T *pAidx = &colAidxRow43[0];
      const real_T *pA202 = &pttASMC_FluidD_ConstP.Internal_A[202];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew43 = &xnew[43];
      int_T numNonZero = 5;
      *pxnew43 = (*pA202++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew43 += (*pA202++) * xd[*pAidx++];
      }
    }

    xnew[43] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[7];

    {
      static const int_T colAidxRow44[6] = { 42, 43, 44, 45, 46, 47 };

      const int_T *pAidx = &colAidxRow44[0];
      const real_T *pA208 = &pttASMC_FluidD_ConstP.Internal_A[208];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew44 = &xnew[44];
      int_T numNonZero = 5;
      *pxnew44 = (*pA208++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew44 += (*pA208++) * xd[*pAidx++];
      }
    }

    xnew[44] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[7];

    {
      static const int_T colAidxRow45[6] = { 42, 43, 44, 45, 46, 47 };

      const int_T *pAidx = &colAidxRow45[0];
      const real_T *pA214 = &pttASMC_FluidD_ConstP.Internal_A[214];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew45 = &xnew[45];
      int_T numNonZero = 5;
      *pxnew45 = (*pA214++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew45 += (*pA214++) * xd[*pAidx++];
      }
    }

    xnew[45] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[7];
    xnew[46] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[46]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[47];
    xnew[46] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[7];
    xnew[47] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[46]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[47];
    xnew[47] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[7];

    {
      static const int_T colAidxRow48[6] = { 48, 49, 50, 51, 52, 53 };

      const int_T *pAidx = &colAidxRow48[0];
      const real_T *pA224 = &pttASMC_FluidD_ConstP.Internal_A[224];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew48 = &xnew[48];
      int_T numNonZero = 5;
      *pxnew48 = (*pA224++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew48 += (*pA224++) * xd[*pAidx++];
      }
    }

    xnew[48] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[8];

    {
      static const int_T colAidxRow49[6] = { 48, 49, 50, 51, 52, 53 };

      const int_T *pAidx = &colAidxRow49[0];
      const real_T *pA230 = &pttASMC_FluidD_ConstP.Internal_A[230];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew49 = &xnew[49];
      int_T numNonZero = 5;
      *pxnew49 = (*pA230++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew49 += (*pA230++) * xd[*pAidx++];
      }
    }

    xnew[49] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[8];

    {
      static const int_T colAidxRow50[6] = { 48, 49, 50, 51, 52, 53 };

      const int_T *pAidx = &colAidxRow50[0];
      const real_T *pA236 = &pttASMC_FluidD_ConstP.Internal_A[236];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew50 = &xnew[50];
      int_T numNonZero = 5;
      *pxnew50 = (*pA236++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew50 += (*pA236++) * xd[*pAidx++];
      }
    }

    xnew[50] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[8];

    {
      static const int_T colAidxRow51[6] = { 48, 49, 50, 51, 52, 53 };

      const int_T *pAidx = &colAidxRow51[0];
      const real_T *pA242 = &pttASMC_FluidD_ConstP.Internal_A[242];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew51 = &xnew[51];
      int_T numNonZero = 5;
      *pxnew51 = (*pA242++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew51 += (*pA242++) * xd[*pAidx++];
      }
    }

    xnew[51] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[8];
    xnew[52] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[52]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[53];
    xnew[52] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[8];
    xnew[53] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[52]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[53];
    xnew[53] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[8];

    {
      static const int_T colAidxRow54[6] = { 54, 55, 56, 57, 58, 59 };

      const int_T *pAidx = &colAidxRow54[0];
      const real_T *pA252 = &pttASMC_FluidD_ConstP.Internal_A[252];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew54 = &xnew[54];
      int_T numNonZero = 5;
      *pxnew54 = (*pA252++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew54 += (*pA252++) * xd[*pAidx++];
      }
    }

    xnew[54] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[9];

    {
      static const int_T colAidxRow55[6] = { 54, 55, 56, 57, 58, 59 };

      const int_T *pAidx = &colAidxRow55[0];
      const real_T *pA258 = &pttASMC_FluidD_ConstP.Internal_A[258];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew55 = &xnew[55];
      int_T numNonZero = 5;
      *pxnew55 = (*pA258++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew55 += (*pA258++) * xd[*pAidx++];
      }
    }

    xnew[55] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[9];

    {
      static const int_T colAidxRow56[6] = { 54, 55, 56, 57, 58, 59 };

      const int_T *pAidx = &colAidxRow56[0];
      const real_T *pA264 = &pttASMC_FluidD_ConstP.Internal_A[264];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew56 = &xnew[56];
      int_T numNonZero = 5;
      *pxnew56 = (*pA264++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew56 += (*pA264++) * xd[*pAidx++];
      }
    }

    xnew[56] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[9];

    {
      static const int_T colAidxRow57[6] = { 54, 55, 56, 57, 58, 59 };

      const int_T *pAidx = &colAidxRow57[0];
      const real_T *pA270 = &pttASMC_FluidD_ConstP.Internal_A[270];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew57 = &xnew[57];
      int_T numNonZero = 5;
      *pxnew57 = (*pA270++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew57 += (*pA270++) * xd[*pAidx++];
      }
    }

    xnew[57] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[9];
    xnew[58] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[58]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[59];
    xnew[58] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[9];
    xnew[59] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[58]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[59];
    xnew[59] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[9];

    {
      static const int_T colAidxRow60[6] = { 60, 61, 62, 63, 64, 65 };

      const int_T *pAidx = &colAidxRow60[0];
      const real_T *pA280 = &pttASMC_FluidD_ConstP.Internal_A[280];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew60 = &xnew[60];
      int_T numNonZero = 5;
      *pxnew60 = (*pA280++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew60 += (*pA280++) * xd[*pAidx++];
      }
    }

    xnew[60] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[10];

    {
      static const int_T colAidxRow61[6] = { 60, 61, 62, 63, 64, 65 };

      const int_T *pAidx = &colAidxRow61[0];
      const real_T *pA286 = &pttASMC_FluidD_ConstP.Internal_A[286];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew61 = &xnew[61];
      int_T numNonZero = 5;
      *pxnew61 = (*pA286++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew61 += (*pA286++) * xd[*pAidx++];
      }
    }

    xnew[61] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[10];

    {
      static const int_T colAidxRow62[6] = { 60, 61, 62, 63, 64, 65 };

      const int_T *pAidx = &colAidxRow62[0];
      const real_T *pA292 = &pttASMC_FluidD_ConstP.Internal_A[292];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew62 = &xnew[62];
      int_T numNonZero = 5;
      *pxnew62 = (*pA292++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew62 += (*pA292++) * xd[*pAidx++];
      }
    }

    xnew[62] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[10];

    {
      static const int_T colAidxRow63[6] = { 60, 61, 62, 63, 64, 65 };

      const int_T *pAidx = &colAidxRow63[0];
      const real_T *pA298 = &pttASMC_FluidD_ConstP.Internal_A[298];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew63 = &xnew[63];
      int_T numNonZero = 5;
      *pxnew63 = (*pA298++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew63 += (*pA298++) * xd[*pAidx++];
      }
    }

    xnew[63] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[10];
    xnew[64] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[64]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[65];
    xnew[64] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[10];
    xnew[65] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[64]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[65];
    xnew[65] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[10];

    {
      static const int_T colAidxRow66[6] = { 66, 67, 68, 69, 70, 71 };

      const int_T *pAidx = &colAidxRow66[0];
      const real_T *pA308 = &pttASMC_FluidD_ConstP.Internal_A[308];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew66 = &xnew[66];
      int_T numNonZero = 5;
      *pxnew66 = (*pA308++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew66 += (*pA308++) * xd[*pAidx++];
      }
    }

    xnew[66] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[11];

    {
      static const int_T colAidxRow67[6] = { 66, 67, 68, 69, 70, 71 };

      const int_T *pAidx = &colAidxRow67[0];
      const real_T *pA314 = &pttASMC_FluidD_ConstP.Internal_A[314];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew67 = &xnew[67];
      int_T numNonZero = 5;
      *pxnew67 = (*pA314++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew67 += (*pA314++) * xd[*pAidx++];
      }
    }

    xnew[67] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[11];

    {
      static const int_T colAidxRow68[6] = { 66, 67, 68, 69, 70, 71 };

      const int_T *pAidx = &colAidxRow68[0];
      const real_T *pA320 = &pttASMC_FluidD_ConstP.Internal_A[320];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew68 = &xnew[68];
      int_T numNonZero = 5;
      *pxnew68 = (*pA320++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew68 += (*pA320++) * xd[*pAidx++];
      }
    }

    xnew[68] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[11];

    {
      static const int_T colAidxRow69[6] = { 66, 67, 68, 69, 70, 71 };

      const int_T *pAidx = &colAidxRow69[0];
      const real_T *pA326 = &pttASMC_FluidD_ConstP.Internal_A[326];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew69 = &xnew[69];
      int_T numNonZero = 5;
      *pxnew69 = (*pA326++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew69 += (*pA326++) * xd[*pAidx++];
      }
    }

    xnew[69] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[11];
    xnew[70] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[70]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[71];
    xnew[70] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[11];
    xnew[71] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[70]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[71];
    xnew[71] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[11];

    {
      static const int_T colAidxRow72[6] = { 72, 73, 74, 75, 76, 77 };

      const int_T *pAidx = &colAidxRow72[0];
      const real_T *pA336 = &pttASMC_FluidD_ConstP.Internal_A[336];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew72 = &xnew[72];
      int_T numNonZero = 5;
      *pxnew72 = (*pA336++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew72 += (*pA336++) * xd[*pAidx++];
      }
    }

    xnew[72] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[12];

    {
      static const int_T colAidxRow73[6] = { 72, 73, 74, 75, 76, 77 };

      const int_T *pAidx = &colAidxRow73[0];
      const real_T *pA342 = &pttASMC_FluidD_ConstP.Internal_A[342];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew73 = &xnew[73];
      int_T numNonZero = 5;
      *pxnew73 = (*pA342++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew73 += (*pA342++) * xd[*pAidx++];
      }
    }

    xnew[73] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[12];

    {
      static const int_T colAidxRow74[6] = { 72, 73, 74, 75, 76, 77 };

      const int_T *pAidx = &colAidxRow74[0];
      const real_T *pA348 = &pttASMC_FluidD_ConstP.Internal_A[348];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew74 = &xnew[74];
      int_T numNonZero = 5;
      *pxnew74 = (*pA348++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew74 += (*pA348++) * xd[*pAidx++];
      }
    }

    xnew[74] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[12];

    {
      static const int_T colAidxRow75[6] = { 72, 73, 74, 75, 76, 77 };

      const int_T *pAidx = &colAidxRow75[0];
      const real_T *pA354 = &pttASMC_FluidD_ConstP.Internal_A[354];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew75 = &xnew[75];
      int_T numNonZero = 5;
      *pxnew75 = (*pA354++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew75 += (*pA354++) * xd[*pAidx++];
      }
    }

    xnew[75] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[12];
    xnew[76] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[76]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[77];
    xnew[76] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[12];
    xnew[77] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[76]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[77];
    xnew[77] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[12];

    {
      static const int_T colAidxRow78[6] = { 78, 79, 80, 81, 82, 83 };

      const int_T *pAidx = &colAidxRow78[0];
      const real_T *pA364 = &pttASMC_FluidD_ConstP.Internal_A[364];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew78 = &xnew[78];
      int_T numNonZero = 5;
      *pxnew78 = (*pA364++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew78 += (*pA364++) * xd[*pAidx++];
      }
    }

    xnew[78] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[13];

    {
      static const int_T colAidxRow79[6] = { 78, 79, 80, 81, 82, 83 };

      const int_T *pAidx = &colAidxRow79[0];
      const real_T *pA370 = &pttASMC_FluidD_ConstP.Internal_A[370];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew79 = &xnew[79];
      int_T numNonZero = 5;
      *pxnew79 = (*pA370++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew79 += (*pA370++) * xd[*pAidx++];
      }
    }

    xnew[79] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[13];

    {
      static const int_T colAidxRow80[6] = { 78, 79, 80, 81, 82, 83 };

      const int_T *pAidx = &colAidxRow80[0];
      const real_T *pA376 = &pttASMC_FluidD_ConstP.Internal_A[376];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew80 = &xnew[80];
      int_T numNonZero = 5;
      *pxnew80 = (*pA376++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew80 += (*pA376++) * xd[*pAidx++];
      }
    }

    xnew[80] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[13];

    {
      static const int_T colAidxRow81[6] = { 78, 79, 80, 81, 82, 83 };

      const int_T *pAidx = &colAidxRow81[0];
      const real_T *pA382 = &pttASMC_FluidD_ConstP.Internal_A[382];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew81 = &xnew[81];
      int_T numNonZero = 5;
      *pxnew81 = (*pA382++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew81 += (*pA382++) * xd[*pAidx++];
      }
    }

    xnew[81] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[13];
    xnew[82] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[82]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[83];
    xnew[82] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[13];
    xnew[83] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[82]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[83];
    xnew[83] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[13];

    {
      static const int_T colAidxRow84[6] = { 84, 85, 86, 87, 88, 89 };

      const int_T *pAidx = &colAidxRow84[0];
      const real_T *pA392 = &pttASMC_FluidD_ConstP.Internal_A[392];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew84 = &xnew[84];
      int_T numNonZero = 5;
      *pxnew84 = (*pA392++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew84 += (*pA392++) * xd[*pAidx++];
      }
    }

    xnew[84] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[14];

    {
      static const int_T colAidxRow85[6] = { 84, 85, 86, 87, 88, 89 };

      const int_T *pAidx = &colAidxRow85[0];
      const real_T *pA398 = &pttASMC_FluidD_ConstP.Internal_A[398];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew85 = &xnew[85];
      int_T numNonZero = 5;
      *pxnew85 = (*pA398++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew85 += (*pA398++) * xd[*pAidx++];
      }
    }

    xnew[85] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[14];

    {
      static const int_T colAidxRow86[6] = { 84, 85, 86, 87, 88, 89 };

      const int_T *pAidx = &colAidxRow86[0];
      const real_T *pA404 = &pttASMC_FluidD_ConstP.Internal_A[404];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew86 = &xnew[86];
      int_T numNonZero = 5;
      *pxnew86 = (*pA404++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew86 += (*pA404++) * xd[*pAidx++];
      }
    }

    xnew[86] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[14];

    {
      static const int_T colAidxRow87[6] = { 84, 85, 86, 87, 88, 89 };

      const int_T *pAidx = &colAidxRow87[0];
      const real_T *pA410 = &pttASMC_FluidD_ConstP.Internal_A[410];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew87 = &xnew[87];
      int_T numNonZero = 5;
      *pxnew87 = (*pA410++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew87 += (*pA410++) * xd[*pAidx++];
      }
    }

    xnew[87] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[14];
    xnew[88] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[88]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[89];
    xnew[88] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[14];
    xnew[89] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[88]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[89];
    xnew[89] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[14];

    {
      static const int_T colAidxRow90[6] = { 90, 91, 92, 93, 94, 95 };

      const int_T *pAidx = &colAidxRow90[0];
      const real_T *pA420 = &pttASMC_FluidD_ConstP.Internal_A[420];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew90 = &xnew[90];
      int_T numNonZero = 5;
      *pxnew90 = (*pA420++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew90 += (*pA420++) * xd[*pAidx++];
      }
    }

    xnew[90] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[15];

    {
      static const int_T colAidxRow91[6] = { 90, 91, 92, 93, 94, 95 };

      const int_T *pAidx = &colAidxRow91[0];
      const real_T *pA426 = &pttASMC_FluidD_ConstP.Internal_A[426];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew91 = &xnew[91];
      int_T numNonZero = 5;
      *pxnew91 = (*pA426++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew91 += (*pA426++) * xd[*pAidx++];
      }
    }

    xnew[91] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[15];

    {
      static const int_T colAidxRow92[6] = { 90, 91, 92, 93, 94, 95 };

      const int_T *pAidx = &colAidxRow92[0];
      const real_T *pA432 = &pttASMC_FluidD_ConstP.Internal_A[432];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew92 = &xnew[92];
      int_T numNonZero = 5;
      *pxnew92 = (*pA432++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew92 += (*pA432++) * xd[*pAidx++];
      }
    }

    xnew[92] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[15];

    {
      static const int_T colAidxRow93[6] = { 90, 91, 92, 93, 94, 95 };

      const int_T *pAidx = &colAidxRow93[0];
      const real_T *pA438 = &pttASMC_FluidD_ConstP.Internal_A[438];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew93 = &xnew[93];
      int_T numNonZero = 5;
      *pxnew93 = (*pA438++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew93 += (*pA438++) * xd[*pAidx++];
      }
    }

    xnew[93] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[15];
    xnew[94] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[94]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[95];
    xnew[94] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[15];
    xnew[95] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[94]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[95];
    xnew[95] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[15];

    {
      static const int_T colAidxRow96[6] = { 96, 97, 98, 99, 100, 101 };

      const int_T *pAidx = &colAidxRow96[0];
      const real_T *pA448 = &pttASMC_FluidD_ConstP.Internal_A[448];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew96 = &xnew[96];
      int_T numNonZero = 5;
      *pxnew96 = (*pA448++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew96 += (*pA448++) * xd[*pAidx++];
      }
    }

    xnew[96] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[16];

    {
      static const int_T colAidxRow97[6] = { 96, 97, 98, 99, 100, 101 };

      const int_T *pAidx = &colAidxRow97[0];
      const real_T *pA454 = &pttASMC_FluidD_ConstP.Internal_A[454];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew97 = &xnew[97];
      int_T numNonZero = 5;
      *pxnew97 = (*pA454++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew97 += (*pA454++) * xd[*pAidx++];
      }
    }

    xnew[97] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[16];

    {
      static const int_T colAidxRow98[6] = { 96, 97, 98, 99, 100, 101 };

      const int_T *pAidx = &colAidxRow98[0];
      const real_T *pA460 = &pttASMC_FluidD_ConstP.Internal_A[460];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew98 = &xnew[98];
      int_T numNonZero = 5;
      *pxnew98 = (*pA460++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew98 += (*pA460++) * xd[*pAidx++];
      }
    }

    xnew[98] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[16];

    {
      static const int_T colAidxRow99[6] = { 96, 97, 98, 99, 100, 101 };

      const int_T *pAidx = &colAidxRow99[0];
      const real_T *pA466 = &pttASMC_FluidD_ConstP.Internal_A[466];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew99 = &xnew[99];
      int_T numNonZero = 5;
      *pxnew99 = (*pA466++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew99 += (*pA466++) * xd[*pAidx++];
      }
    }

    xnew[99] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[16];
    xnew[100] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[100]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[101];
    xnew[100] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[16];
    xnew[101] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[100]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[101];
    xnew[101] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[16];

    {
      static const int_T colAidxRow102[6] = { 102, 103, 104, 105, 106, 107 };

      const int_T *pAidx = &colAidxRow102[0];
      const real_T *pA476 = &pttASMC_FluidD_ConstP.Internal_A[476];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew102 = &xnew[102];
      int_T numNonZero = 5;
      *pxnew102 = (*pA476++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew102 += (*pA476++) * xd[*pAidx++];
      }
    }

    xnew[102] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[17];

    {
      static const int_T colAidxRow103[6] = { 102, 103, 104, 105, 106, 107 };

      const int_T *pAidx = &colAidxRow103[0];
      const real_T *pA482 = &pttASMC_FluidD_ConstP.Internal_A[482];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew103 = &xnew[103];
      int_T numNonZero = 5;
      *pxnew103 = (*pA482++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew103 += (*pA482++) * xd[*pAidx++];
      }
    }

    xnew[103] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[17];

    {
      static const int_T colAidxRow104[6] = { 102, 103, 104, 105, 106, 107 };

      const int_T *pAidx = &colAidxRow104[0];
      const real_T *pA488 = &pttASMC_FluidD_ConstP.Internal_A[488];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew104 = &xnew[104];
      int_T numNonZero = 5;
      *pxnew104 = (*pA488++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew104 += (*pA488++) * xd[*pAidx++];
      }
    }

    xnew[104] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[17];

    {
      static const int_T colAidxRow105[6] = { 102, 103, 104, 105, 106, 107 };

      const int_T *pAidx = &colAidxRow105[0];
      const real_T *pA494 = &pttASMC_FluidD_ConstP.Internal_A[494];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew105 = &xnew[105];
      int_T numNonZero = 5;
      *pxnew105 = (*pA494++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew105 += (*pA494++) * xd[*pAidx++];
      }
    }

    xnew[105] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[17];
    xnew[106] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[106]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[107];
    xnew[106] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[17];
    xnew[107] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[106]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[107];
    xnew[107] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[17];

    {
      static const int_T colAidxRow108[6] = { 108, 109, 110, 111, 112, 113 };

      const int_T *pAidx = &colAidxRow108[0];
      const real_T *pA504 = &pttASMC_FluidD_ConstP.Internal_A[504];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew108 = &xnew[108];
      int_T numNonZero = 5;
      *pxnew108 = (*pA504++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew108 += (*pA504++) * xd[*pAidx++];
      }
    }

    xnew[108] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[18];

    {
      static const int_T colAidxRow109[6] = { 108, 109, 110, 111, 112, 113 };

      const int_T *pAidx = &colAidxRow109[0];
      const real_T *pA510 = &pttASMC_FluidD_ConstP.Internal_A[510];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew109 = &xnew[109];
      int_T numNonZero = 5;
      *pxnew109 = (*pA510++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew109 += (*pA510++) * xd[*pAidx++];
      }
    }

    xnew[109] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[18];

    {
      static const int_T colAidxRow110[6] = { 108, 109, 110, 111, 112, 113 };

      const int_T *pAidx = &colAidxRow110[0];
      const real_T *pA516 = &pttASMC_FluidD_ConstP.Internal_A[516];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew110 = &xnew[110];
      int_T numNonZero = 5;
      *pxnew110 = (*pA516++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew110 += (*pA516++) * xd[*pAidx++];
      }
    }

    xnew[110] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[18];

    {
      static const int_T colAidxRow111[6] = { 108, 109, 110, 111, 112, 113 };

      const int_T *pAidx = &colAidxRow111[0];
      const real_T *pA522 = &pttASMC_FluidD_ConstP.Internal_A[522];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew111 = &xnew[111];
      int_T numNonZero = 5;
      *pxnew111 = (*pA522++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew111 += (*pA522++) * xd[*pAidx++];
      }
    }

    xnew[111] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[18];
    xnew[112] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[112]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[113];
    xnew[112] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[18];
    xnew[113] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[112]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[113];
    xnew[113] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[18];

    {
      static const int_T colAidxRow114[6] = { 114, 115, 116, 117, 118, 119 };

      const int_T *pAidx = &colAidxRow114[0];
      const real_T *pA532 = &pttASMC_FluidD_ConstP.Internal_A[532];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew114 = &xnew[114];
      int_T numNonZero = 5;
      *pxnew114 = (*pA532++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew114 += (*pA532++) * xd[*pAidx++];
      }
    }

    xnew[114] += (0.0001741663873205826)*pttASMC_FluidD_U.Rrbfs[19];

    {
      static const int_T colAidxRow115[6] = { 114, 115, 116, 117, 118, 119 };

      const int_T *pAidx = &colAidxRow115[0];
      const real_T *pA538 = &pttASMC_FluidD_ConstP.Internal_A[538];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew115 = &xnew[115];
      int_T numNonZero = 5;
      *pxnew115 = (*pA538++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew115 += (*pA538++) * xd[*pAidx++];
      }
    }

    xnew[115] += (0.00035669276123255315)*pttASMC_FluidD_U.Rrbfs[19];

    {
      static const int_T colAidxRow116[6] = { 114, 115, 116, 117, 118, 119 };

      const int_T *pAidx = &colAidxRow116[0];
      const real_T *pA544 = &pttASMC_FluidD_ConstP.Internal_A[544];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew116 = &xnew[116];
      int_T numNonZero = 5;
      *pxnew116 = (*pA544++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew116 += (*pA544++) * xd[*pAidx++];
      }
    }

    xnew[116] += (0.00036525338750213488)*pttASMC_FluidD_U.Rrbfs[19];

    {
      static const int_T colAidxRow117[6] = { 114, 115, 116, 117, 118, 119 };

      const int_T *pAidx = &colAidxRow117[0];
      const real_T *pA550 = &pttASMC_FluidD_ConstP.Internal_A[550];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew117 = &xnew[117];
      int_T numNonZero = 5;
      *pxnew117 = (*pA550++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew117 += (*pA550++) * xd[*pAidx++];
      }
    }

    xnew[117] += (0.00018700973440109308)*pttASMC_FluidD_U.Rrbfs[19];
    xnew[118] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[118]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[119];
    xnew[118] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[19];
    xnew[119] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[118]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[119];
    xnew[119] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[19];

    {
      static const int_T colAidxRow120[6] = { 120, 121, 122, 123, 124, 125 };

      const int_T *pAidx = &colAidxRow120[0];
      const real_T *pA560 = &pttASMC_FluidD_ConstP.Internal_A[560];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew120 = &xnew[120];
      int_T numNonZero = 5;
      *pxnew120 = (*pA560++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew120 += (*pA560++) * xd[*pAidx++];
      }
    }

    xnew[120] += (0.00017416638732058276)*pttASMC_FluidD_U.Rrbfs[20];

    {
      static const int_T colAidxRow121[6] = { 120, 121, 122, 123, 124, 125 };

      const int_T *pAidx = &colAidxRow121[0];
      const real_T *pA566 = &pttASMC_FluidD_ConstP.Internal_A[566];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew121 = &xnew[121];
      int_T numNonZero = 5;
      *pxnew121 = (*pA566++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew121 += (*pA566++) * xd[*pAidx++];
      }
    }

    xnew[121] += (0.00035669276123255348)*pttASMC_FluidD_U.Rrbfs[20];

    {
      static const int_T colAidxRow122[6] = { 120, 121, 122, 123, 124, 125 };

      const int_T *pAidx = &colAidxRow122[0];
      const real_T *pA572 = &pttASMC_FluidD_ConstP.Internal_A[572];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew122 = &xnew[122];
      int_T numNonZero = 5;
      *pxnew122 = (*pA572++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew122 += (*pA572++) * xd[*pAidx++];
      }
    }

    xnew[122] += (0.00036525338750213472)*pttASMC_FluidD_U.Rrbfs[20];

    {
      static const int_T colAidxRow123[6] = { 120, 121, 122, 123, 124, 125 };

      const int_T *pAidx = &colAidxRow123[0];
      const real_T *pA578 = &pttASMC_FluidD_ConstP.Internal_A[578];
      const real_T *xd = &pttASMC_FluidD_DW.Internal_DSTATE[0];
      real_T *pxnew123 = &xnew[123];
      int_T numNonZero = 5;
      *pxnew123 = (*pA578++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew123 += (*pA578++) * xd[*pAidx++];
      }
    }

    xnew[123] += (0.00018700973440109316)*pttASMC_FluidD_U.Rrbfs[20];
    xnew[124] = (-0.64179104477611948)*pttASMC_FluidD_DW.Internal_DSTATE[124]
      + (-0.72877798507462688)*pttASMC_FluidD_DW.Internal_DSTATE[125];
    xnew[124] += (0.00573134328358209)*pttASMC_FluidD_U.Rrbfs[20];
    xnew[125] = (0.3668059701492537)*pttASMC_FluidD_DW.Internal_DSTATE[124]
      + (0.25373134328358204)*pttASMC_FluidD_DW.Internal_DSTATE[125];
    xnew[125] += (0.00586889552238806)*pttASMC_FluidD_U.Rrbfs[20];
    (void) memcpy(&pttASMC_FluidD_DW.Internal_DSTATE[0], xnew,
                  sizeof(real_T)*126);
  }

  /* Update for DiscreteStateSpace: '<S4>/Internal' */
  {
    real_T xnew[21];
    xnew[0] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[0];
    xnew[0] += (43.2)*rtb_Sum1[0];
    xnew[1] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[1];
    xnew[1] += (3.020288)*rtb_Sum1[1];
    xnew[2] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[2];
    xnew[2] += (3.020288)*rtb_Sum1[2];
    xnew[3] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[3];
    xnew[3] += (43.2)*rtb_Sum1[3];
    xnew[4] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[4];
    xnew[4] += (3.020288)*rtb_Sum1[4];
    xnew[5] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[5];
    xnew[5] += (3.020288)*rtb_Sum1[5];
    xnew[6] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[6];
    xnew[6] += (43.2)*rtb_Sum1[6];
    xnew[7] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[7];
    xnew[7] += (3.020288)*rtb_Sum1[7];
    xnew[8] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[8];
    xnew[8] += (3.020288)*rtb_Sum1[8];
    xnew[9] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[9];
    xnew[9] += (43.2)*rtb_Sum1[9];
    xnew[10] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[10];
    xnew[10] += (3.020288)*rtb_Sum1[10];
    xnew[11] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[11];
    xnew[11] += (3.020288)*rtb_Sum1[11];
    xnew[12] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[12];
    xnew[12] += (43.2)*rtb_Sum1[12];
    xnew[13] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[13];
    xnew[13] += (3.020288)*rtb_Sum1[13];
    xnew[14] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[14];
    xnew[14] += (3.020288)*rtb_Sum1[14];
    xnew[15] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[15];
    xnew[15] += (43.2)*rtb_Sum1[15];
    xnew[16] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[16];
    xnew[16] += (3.020288)*rtb_Sum1[16];
    xnew[17] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[17];
    xnew[17] += (3.020288)*rtb_Sum1[17];
    xnew[18] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[18];
    xnew[18] += (43.2)*rtb_Sum1[18];
    xnew[19] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[19];
    xnew[19] += (3.020288)*rtb_Sum1[19];
    xnew[20] = (1.0)*pttASMC_FluidD_DW.Internal_DSTATE_m[20];
    xnew[20] += (3.020288)*rtb_Sum1[20];
    (void) memcpy(&pttASMC_FluidD_DW.Internal_DSTATE_m[0], xnew,
                  sizeof(real_T)*21);
  }

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  memcpy(&pttASMC_FluidD_DW.UD_DSTATE[0], &rtb_TSamp[0], 21U * sizeof(real_T));
}

/* Model initialize function */
void pttASMC_FluidD_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(pttASMC_FluidD_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&pttASMC_FluidD_DW, 0,
                sizeof(DW_pttASMC_FluidD_T));

  /* external inputs */
  (void)memset(&pttASMC_FluidD_U, 0, sizeof(ExtU_pttASMC_FluidD_T));

  /* external outputs */
  (void) memset((void *)&pttASMC_FluidD_Y, 0,
                sizeof(ExtY_pttASMC_FluidD_T));
}

/* Model terminate function */
void pttASMC_FluidD_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
