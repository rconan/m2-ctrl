/*
 * File: TT_Control.c
 *
 * Code generated for Simulink model 'TT_Control'.
 *
 * Model version                  : 1.1033
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 16 13:45:10 2022
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
    rtb_Sum1[i] = TT_Control_U.TT_SP[i] - TT_Control_U.TT_FB[i];
  }

  /* End of Sum: '<S1>/Sum1' */

  /* DiscreteStateSpace: '<S1>/TT Controller' */
  {
    rtb_TTController[0] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[0]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[1]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[2]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[3];
    rtb_TTController[0] += (0.65860373533989458)*rtb_Sum1[0];
    rtb_TTController[1] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[4]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[5]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[6]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[7];
    rtb_TTController[1] += (0.65860373533989458)*rtb_Sum1[1];
    rtb_TTController[2] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[8]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[9]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[10]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[11];
    rtb_TTController[2] += (0.65860373533989458)*rtb_Sum1[2];
    rtb_TTController[3] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[12]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[13]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[14]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[15];
    rtb_TTController[3] += (0.65860373533989458)*rtb_Sum1[3];
    rtb_TTController[4] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[16]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[17]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[18]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[19];
    rtb_TTController[4] += (0.65860373533989458)*rtb_Sum1[4];
    rtb_TTController[5] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[20]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[21]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[22]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[23];
    rtb_TTController[5] += (0.65860373533989458)*rtb_Sum1[5];
    rtb_TTController[6] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[24]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[25]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[26]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[27];
    rtb_TTController[6] += (0.65860373533989458)*rtb_Sum1[6];
    rtb_TTController[7] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[28]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[29]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[30]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[31];
    rtb_TTController[7] += (0.65860373533989458)*rtb_Sum1[7];
    rtb_TTController[8] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[32]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[33]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[34]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[35];
    rtb_TTController[8] += (0.65860373533989458)*rtb_Sum1[8];
    rtb_TTController[9] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[36]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[37]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[38]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[39];
    rtb_TTController[9] += (0.65860373533989458)*rtb_Sum1[9];
    rtb_TTController[10] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[40]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[41]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[42]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[43];
    rtb_TTController[10] += (0.65860373533989458)*rtb_Sum1[10];
    rtb_TTController[11] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[44]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[45]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[46]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[47];
    rtb_TTController[11] += (0.65860373533989458)*rtb_Sum1[11];
    rtb_TTController[12] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[48]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[49]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[50]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[51];
    rtb_TTController[12] += (0.65860373533989458)*rtb_Sum1[12];
    rtb_TTController[13] = (-0.25475982044084683)*
      TT_Control_DW.TTController_DSTATE[52]
      + (-1.1853009346526489)*TT_Control_DW.TTController_DSTATE[53]
      + (0.29187341611018253)*TT_Control_DW.TTController_DSTATE[54]
      + (0.27365385151055438)*TT_Control_DW.TTController_DSTATE[55];
    rtb_TTController[13] += (0.65860373533989458)*rtb_Sum1[13];
  }

  /* Outport: '<Root>/PZT_cmd' incorporates:
   *  Gain: '<S1>/TT2PZT'
   */
  for (i = 0; i < 21; i++) {
    TT_Control_Y.PZT_cmd[i] = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 14; i_0++) {
      TT_Control_Y.PZT_cmd[i] += TT_Control_ConstP.TT2PZT_Gain[tmp + i] *
        rtb_TTController[i_0];
      tmp += 21;
    }
  }

  /* End of Outport: '<Root>/PZT_cmd' */

  /* Update for DiscreteStateSpace: '<S1>/TT Controller' */
  {
    real_T xnew[56];
    xnew[0] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[0];
    xnew[0] += (-6.6619717846840878)*rtb_Sum1[0];
    xnew[1] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[1]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[2]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[3];
    xnew[1] += (1.1853009346526491)*rtb_Sum1[0];
    xnew[2] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[1]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[2]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[3];
    xnew[2] += (0.2918734161123025)*rtb_Sum1[0];
    xnew[3] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[1]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[2]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[3];
    xnew[3] += (-0.273653851508281)*rtb_Sum1[0];
    xnew[4] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[4];
    xnew[4] += (-6.6619717846840878)*rtb_Sum1[1];
    xnew[5] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[5]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[6]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[7];
    xnew[5] += (1.1853009346526491)*rtb_Sum1[1];
    xnew[6] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[5]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[6]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[7];
    xnew[6] += (0.2918734161123025)*rtb_Sum1[1];
    xnew[7] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[5]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[6]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[7];
    xnew[7] += (-0.273653851508281)*rtb_Sum1[1];
    xnew[8] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[8];
    xnew[8] += (-6.6619717846840878)*rtb_Sum1[2];
    xnew[9] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[9]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[10]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[11];
    xnew[9] += (1.1853009346526491)*rtb_Sum1[2];
    xnew[10] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[9]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[10]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[11];
    xnew[10] += (0.2918734161123025)*rtb_Sum1[2];
    xnew[11] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[9]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[10]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[11];
    xnew[11] += (-0.273653851508281)*rtb_Sum1[2];
    xnew[12] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[12];
    xnew[12] += (-6.6619717846840878)*rtb_Sum1[3];
    xnew[13] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[13]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[14]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[15];
    xnew[13] += (1.1853009346526491)*rtb_Sum1[3];
    xnew[14] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[13]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[14]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[15];
    xnew[14] += (0.2918734161123025)*rtb_Sum1[3];
    xnew[15] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[13]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[14]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[15];
    xnew[15] += (-0.273653851508281)*rtb_Sum1[3];
    xnew[16] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[16];
    xnew[16] += (-6.6619717846840878)*rtb_Sum1[4];
    xnew[17] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[17]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[18]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[19];
    xnew[17] += (1.1853009346526491)*rtb_Sum1[4];
    xnew[18] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[17]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[18]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[19];
    xnew[18] += (0.2918734161123025)*rtb_Sum1[4];
    xnew[19] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[17]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[18]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[19];
    xnew[19] += (-0.273653851508281)*rtb_Sum1[4];
    xnew[20] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[20];
    xnew[20] += (-6.6619717846840878)*rtb_Sum1[5];
    xnew[21] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[21]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[22]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[23];
    xnew[21] += (1.1853009346526491)*rtb_Sum1[5];
    xnew[22] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[21]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[22]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[23];
    xnew[22] += (0.2918734161123025)*rtb_Sum1[5];
    xnew[23] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[21]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[22]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[23];
    xnew[23] += (-0.273653851508281)*rtb_Sum1[5];
    xnew[24] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[24];
    xnew[24] += (-6.6619717846840878)*rtb_Sum1[6];
    xnew[25] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[25]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[26]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[27];
    xnew[25] += (1.1853009346526491)*rtb_Sum1[6];
    xnew[26] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[25]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[26]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[27];
    xnew[26] += (0.2918734161123025)*rtb_Sum1[6];
    xnew[27] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[25]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[26]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[27];
    xnew[27] += (-0.273653851508281)*rtb_Sum1[6];
    xnew[28] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[28];
    xnew[28] += (-6.6619717846840878)*rtb_Sum1[7];
    xnew[29] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[29]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[30]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[31];
    xnew[29] += (1.1853009346526491)*rtb_Sum1[7];
    xnew[30] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[29]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[30]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[31];
    xnew[30] += (0.2918734161123025)*rtb_Sum1[7];
    xnew[31] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[29]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[30]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[31];
    xnew[31] += (-0.273653851508281)*rtb_Sum1[7];
    xnew[32] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[32];
    xnew[32] += (-6.6619717846840878)*rtb_Sum1[8];
    xnew[33] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[33]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[34]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[35];
    xnew[33] += (1.1853009346526491)*rtb_Sum1[8];
    xnew[34] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[33]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[34]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[35];
    xnew[34] += (0.2918734161123025)*rtb_Sum1[8];
    xnew[35] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[33]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[34]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[35];
    xnew[35] += (-0.273653851508281)*rtb_Sum1[8];
    xnew[36] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[36];
    xnew[36] += (-6.6619717846840878)*rtb_Sum1[9];
    xnew[37] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[37]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[38]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[39];
    xnew[37] += (1.1853009346526491)*rtb_Sum1[9];
    xnew[38] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[37]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[38]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[39];
    xnew[38] += (0.2918734161123025)*rtb_Sum1[9];
    xnew[39] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[37]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[38]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[39];
    xnew[39] += (-0.273653851508281)*rtb_Sum1[9];
    xnew[40] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[40];
    xnew[40] += (-6.6619717846840878)*rtb_Sum1[10];
    xnew[41] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[41]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[42]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[43];
    xnew[41] += (1.1853009346526491)*rtb_Sum1[10];
    xnew[42] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[41]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[42]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[43];
    xnew[42] += (0.2918734161123025)*rtb_Sum1[10];
    xnew[43] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[41]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[42]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[43];
    xnew[43] += (-0.273653851508281)*rtb_Sum1[10];
    xnew[44] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[44];
    xnew[44] += (-6.6619717846840878)*rtb_Sum1[11];
    xnew[45] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[45]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[46]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[47];
    xnew[45] += (1.1853009346526491)*rtb_Sum1[11];
    xnew[46] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[45]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[46]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[47];
    xnew[46] += (0.2918734161123025)*rtb_Sum1[11];
    xnew[47] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[45]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[46]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[47];
    xnew[47] += (-0.273653851508281)*rtb_Sum1[11];
    xnew[48] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[48];
    xnew[48] += (-6.6619717846840878)*rtb_Sum1[12];
    xnew[49] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[49]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[50]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[51];
    xnew[49] += (1.1853009346526491)*rtb_Sum1[12];
    xnew[50] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[49]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[50]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[51];
    xnew[50] += (0.2918734161123025)*rtb_Sum1[12];
    xnew[51] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[49]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[50]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[51];
    xnew[51] += (-0.273653851508281)*rtb_Sum1[12];
    xnew[52] = (1.0000000000000002)*TT_Control_DW.TTController_DSTATE[52];
    xnew[52] += (-6.6619717846840878)*rtb_Sum1[13];
    xnew[53] = (0.99529000270517765)*TT_Control_DW.TTController_DSTATE[53]
      + (0.0023255403759604265)*TT_Control_DW.TTController_DSTATE[54]
      + (0.0021803989441341819)*TT_Control_DW.TTController_DSTATE[55];
    xnew[53] += (1.1853009346526491)*rtb_Sum1[13];
    xnew[54] = (-0.0023255403759768821)*TT_Control_DW.TTController_DSTATE[53]
      + (-0.37909782732929342)*TT_Control_DW.TTController_DSTATE[54]
      + (0.58517873223594141)*TT_Control_DW.TTController_DSTATE[55];
    xnew[54] += (0.2918734161123025)*rtb_Sum1[13];
    xnew[55] = (0.0021803989441182554)*TT_Control_DW.TTController_DSTATE[53]
      + (-0.58517873224236483)*TT_Control_DW.TTController_DSTATE[54]
      + (0.4484831868367492)*TT_Control_DW.TTController_DSTATE[55];
    xnew[55] += (-0.273653851508281)*rtb_Sum1[13];
    (void) memcpy(&TT_Control_DW.TTController_DSTATE[0], xnew,
                  sizeof(real_T)*56);
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
  (void) memset(&TT_Control_Y.PZT_cmd[0], 0,
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
