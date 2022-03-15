/*
 * File: M2_PZT_Control_data.c
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

/* Constant parameters (default storage) */
const ConstP_M2_PZT_Control_T M2_PZT_Control_ConstP = {
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
  { -1.0, -0.0, -0.0, 1.0, 0.0, 0.0, -0.0, -1.0, -0.0, 0.0, 1.0, 0.0, -0.0, -0.0,
    -1.0, 0.0, 0.0, 1.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S12>/Discrete SS'
   *   '<S14>/Discrete SS'
   *   '<S16>/Discrete SS'
   */
  { 1948.2783190777952, 1120.5510534092778, -336.90539860045186,
    -128.53410133650209, -176.45378527605379, 1948.2783190777952,
    1120.5510534092778, -336.90539860045186, -128.53410133650209,
    -176.45378527605379, 1948.2783190777952, 958.303128961501,
    -189.81526262059111, 149.26785650881027, -230.40381097529243 },

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
  { -1.0, 1.0, -0.0, 0.0, -0.0, 0.0, -0.0, 0.0, -1.0, 1.0, -0.0, 0.0, -0.0, 0.0,
    -0.0, 0.0, -1.0, 1.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S13>/Discrete SS'
   *   '<S15>/Discrete SS'
   *   '<S17>/Discrete SS'
   */
  { 1948.2783190777952, 1120.5510534092778, -336.90539860045186,
    -128.53410133650209, -176.45378527605379, 1948.2783190777952,
    958.303128961501, -189.81526262059111, 149.26785650881027,
    -230.40381097529243, 1948.2783190777952, 1120.5510534092778,
    -336.90539860045186, -128.53410133650209, -176.45378527605379 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
