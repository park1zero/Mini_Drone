/* Include files */

#include "flightControlSystem_sfun.h"
#include "c6_flightControlSystem.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c6_emlrtMCI = { 13, /* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtRSInfo c6_emlrtRSI = { 4,  /* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2927"          /* pathName */
};

static emlrtRSInfo c6_b_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwmorph.m"/* pathName */
};

static emlrtRSInfo c6_c_emlrtRSI = { 24,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_d_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_e_emlrtRSI = { 321,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_f_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_g_emlrtRSI = { 324,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_h_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_i_emlrtRSI = { 9,/* lineNo */
  "lutthin1",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\lutthin1.m"/* pathName */
};

static emlrtRSInfo c6_j_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m"/* pathName */
};

static emlrtRSInfo c6_k_emlrtRSI = { 9,/* lineNo */
  "lutthin2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\lutthin2.m"/* pathName */
};

/* Function Declarations */
static void initialize_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void enable_c6_flightControlSystem(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_update_jit_animation_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_do_animation_call_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_st);
static void sf_gateway_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_bwmorphApplyOnce(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c6_sp, boolean_T c6_bw[19200], boolean_T
  c6_b_bw[19200]);
static void c6_bwlookup(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_bwin[19200], boolean_T c6_B[19200]);
static void c6_b_bwlookup(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_bwin[19200], boolean_T c6_B[19200]);
static void c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_BW, const char_T *c6_identifier, boolean_T
  c6_y[19200]);
static void c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[19200]);
static uint8_T c6_c_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_flightControlSystem, const
  char_T *c6_identifier);
static uint8_T c6_d_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_chart_data_browse_helper(SFc6_flightControlSystemInstanceStruct
  *chartInstance, int32_T c6_ssIdNumber, const mxArray **c6_mxData, uint8_T
  *c6_isValueTooBig);
static void c6_b_bwmorphApplyOnce(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c6_sp, boolean_T c6_bw[19200]);
static void init_dsm_address_info(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c6_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c6_st.tls = chartInstance->c6_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c6_st, (const char_T *)"image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_flightControlSystem = 0U;
}

static void initialize_params_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_flightControlSystem(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_jit_animation_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_do_animation_call_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", *chartInstance->c6_BW, 11, 0U, 1U,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y",
    &chartInstance->c6_is_active_c6_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  int32_T c6_i;
  boolean_T c6_bv[19200];
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "BW",
                      c6_bv);
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    (*chartInstance->c6_BW)[c6_i] = c6_bv[c6_i];
  }

  chartInstance->c6_is_active_c6_flightControlSystem = c6_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_flightControlSystem");
  sf_mex_destroy(&c6_u);
  sf_mex_destroy(&c6_st);
}

static void sf_gateway_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c6_b_st;
  emlrtStack c6_c_st;
  emlrtStack c6_d_st;
  emlrtStack c6_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c6_b_k;
  real_T c6_iter;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_k;
  boolean_T c6_last_aout[19200];
  boolean_T c6_b_p;
  boolean_T c6_c_p;
  boolean_T c6_exitg1;
  boolean_T c6_exitg2;
  boolean_T c6_p;
  boolean_T c6_x1;
  boolean_T c6_x2;
  c6_st.tls = chartInstance->c6_fEmlrtCtx;
  c6_b_st.prev = &c6_st;
  c6_b_st.tls = c6_st.tls;
  c6_c_st.prev = &c6_b_st;
  c6_c_st.tls = c6_b_st.tls;
  c6_d_st.prev = &c6_c_st;
  c6_d_st.tls = c6_c_st.tls;
  chartInstance->c6_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, (real_T)
                      (*chartInstance->c6_bin_image)[c6_i]);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 0, 0);
  c6_b_st.site = &c6_emlrtRSI;
  c6_c_st.site = &c6_b_emlrtRSI;
  c6_iter = 0.0;
  for (c6_i1 = 0; c6_i1 < 19200; c6_i1++) {
    (*chartInstance->c6_BW)[c6_i1] = (*chartInstance->c6_bin_image)[c6_i1];
  }

  c6_exitg1 = false;
  while ((!c6_exitg1) && (c6_iter < rtInf)) {
    for (c6_i2 = 0; c6_i2 < 19200; c6_i2++) {
      c6_last_aout[c6_i2] = (*chartInstance->c6_BW)[c6_i2];
    }

    c6_d_st.site = &c6_d_emlrtRSI;
    c6_b_bwmorphApplyOnce(chartInstance, &c6_d_st, *chartInstance->c6_BW);
    c6_iter++;
    c6_p = false;
    c6_b_p = true;
    c6_k = 0;
    c6_exitg2 = false;
    while ((!c6_exitg2) && (c6_k < 19200)) {
      c6_b_k = 1.0 + (real_T)c6_k;
      c6_x1 = c6_last_aout[(int32_T)c6_b_k - 1];
      c6_x2 = (*chartInstance->c6_BW)[(int32_T)c6_b_k - 1];
      c6_c_p = ((int32_T)c6_x1 == (int32_T)c6_x2);
      if (!c6_c_p) {
        c6_b_p = false;
        c6_exitg2 = true;
      } else {
        c6_k++;
      }
    }

    if (c6_b_p) {
      c6_p = true;
    }

    if (c6_p) {
      c6_exitg1 = true;
    }
  }

  c6_do_animation_call_c6_flightControlSystem(chartInstance);
  for (c6_i3 = 0; c6_i3 < 19200; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U, (real_T)
                      (*chartInstance->c6_BW)[c6_i3]);
  }
}

static void mdl_start_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c6_decisionTxtEndIdx = 0U;
  static const uint32_T c6_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c6_chart_data_browse_helper);
  chartInstance->c6_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c6_RuntimeVar,
    &chartInstance->c6_IsDebuggerActive,
    &chartInstance->c6_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c6_mlFcnLineNumber, &chartInstance->c6_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c6_covrtInstance, 1U, 0U, 1U,
    57U);
  covrtChartInitFcn(chartInstance->c6_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c6_decisionTxtStartIdx, &c6_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 68);
}

static void mdl_cleanup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c6_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c6_covrtInstance);
}

static void initSimStructsc6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c6_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static void c6_bwmorphApplyOnce(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c6_sp, boolean_T c6_bw[19200], boolean_T
  c6_b_bw[19200])
{
  int32_T c6_i;
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    c6_b_bw[c6_i] = c6_bw[c6_i];
  }

  c6_b_bwmorphApplyOnce(chartInstance, c6_sp, c6_b_bw);
}

static void c6_bwlookup(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_bwin[19200], boolean_T c6_B[19200])
{
  static boolean_T c6_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  real_T c6_sizeIn[2];
  int32_T c6_i;
  (void)chartInstance;
  for (c6_i = 0; c6_i < 2; c6_i++) {
    c6_sizeIn[c6_i] = 120.0 + 40.0 * (real_T)c6_i;
  }

  bwlookup_tbb_boolean(&c6_bwin[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                       &c6_B[0]);
}

static void c6_b_bwlookup(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_bwin[19200], boolean_T c6_B[19200])
{
  static boolean_T c6_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  real_T c6_sizeIn[2];
  int32_T c6_i;
  (void)chartInstance;
  for (c6_i = 0; c6_i < 2; c6_i++) {
    c6_sizeIn[c6_i] = 120.0 + 40.0 * (real_T)c6_i;
  }

  bwlookup_tbb_boolean(&c6_bwin[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                       &c6_B[0]);
}

static void c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_BW, const char_T *c6_identifier, boolean_T
  c6_y[19200])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_BW), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_BW);
}

static void c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[19200])
{
  int32_T c6_i;
  boolean_T c6_bv[19200];
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    c6_y[c6_i] = c6_bv[c6_i];
  }

  sf_mex_destroy(&c6_u);
}

static uint8_T c6_c_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_flightControlSystem, const
  char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_flightControlSystem), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_flightControlSystem);
  return c6_y;
}

static uint8_T c6_d_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_b_u;
  uint8_T c6_y;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b_u, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_b_u;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_chart_data_browse_helper(SFc6_flightControlSystemInstanceStruct
  *chartInstance, int32_T c6_ssIdNumber, const mxArray **c6_mxData, uint8_T
  *c6_isValueTooBig)
{
  *c6_mxData = NULL;
  *c6_mxData = NULL;
  *c6_isValueTooBig = 0U;
  switch (c6_ssIdNumber) {
   case 4U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      *chartInstance->c6_bin_image, 11, 0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", *chartInstance->c6_BW, 11,
      0U, 1U, 0U, 2, 120, 160), false);
    break;
  }
}

static void c6_b_bwmorphApplyOnce(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c6_sp, boolean_T c6_bw[19200])
{
  static real_T c6_b_x[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  static real_T c6_d_x[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0 };

  static char_T c6_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  emlrtStack c6_b_st;
  emlrtStack c6_st;
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_b_k;
  real_T c6_c_x;
  real_T c6_d_k;
  real_T c6_x;
  int32_T c6_c_k;
  int32_T c6_i;
  int32_T c6_k;
  boolean_T c6_b_bw[19200];
  boolean_T c6_image_iter1[19200];
  boolean_T c6_b;
  boolean_T c6_b_b;
  c6_st.prev = c6_sp;
  c6_st.tls = c6_sp->tls;
  c6_b_st.prev = &c6_st;
  c6_b_st.tls = c6_st.tls;
  c6_st.site = &c6_e_emlrtRSI;
  c6_b_st.site = &c6_i_emlrtRSI;
  for (c6_k = 0; c6_k < 512; c6_k++) {
    c6_b_k = 1.0 + (real_T)c6_k;
    c6_x = c6_b_x[(int32_T)c6_b_k - 1];
    c6_b = muDoubleScalarIsNaN(c6_x);
    if (c6_b) {
      c6_y = NULL;
      sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c6_b_y = NULL;
      sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c6_b_st, &c6_emlrtMCI, "error", 0U, 2U, 14, c6_y, 14,
                  sf_mex_call(&c6_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c6_b_st, NULL, "message", 1U, 1U, 14, c6_b_y)));
    }
  }

  c6_st.site = &c6_f_emlrtRSI;
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    c6_b_bw[c6_i] = c6_bw[c6_i];
  }

  c6_bwlookup(chartInstance, c6_b_bw, c6_image_iter1);
  c6_st.site = &c6_g_emlrtRSI;
  c6_b_st.site = &c6_k_emlrtRSI;
  for (c6_c_k = 0; c6_c_k < 512; c6_c_k++) {
    c6_d_k = 1.0 + (real_T)c6_c_k;
    c6_c_x = c6_d_x[(int32_T)c6_d_k - 1];
    c6_b_b = muDoubleScalarIsNaN(c6_c_x);
    if (c6_b_b) {
      c6_c_y = NULL;
      sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c6_d_y = NULL;
      sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c6_b_st, &c6_emlrtMCI, "error", 0U, 2U, 14, c6_c_y, 14,
                  sf_mex_call(&c6_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c6_b_st, NULL, "message", 1U, 1U, 14, c6_d_y)));
    }
  }

  c6_st.site = &c6_h_emlrtRSI;
  c6_b_bwlookup(chartInstance, c6_image_iter1, c6_bw);
}

static void init_dsm_address_info(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c6_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_bin_image = (boolean_T (*)[19200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c6_BW = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c6_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2024890537U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2475312307U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3548021863U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1825006712U);
}

mxArray *sf_c6_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c6_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bwlookup_tbb_boolean");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c6_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI+E8AyHMKh4QLLHzIt1/BgTL9EP"
    "sDCLhfAcX9EH5mcXxicklmWWp8sll8Wk5mekaJc35eSVF+TnBlcUlqLsx/AIYJHNw="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sCZwdHEVgFhpOQbjbesghuH";
}

static void sf_opaque_initialize_c6_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c6_flightControlSystem
    ((SFc6_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_flightControlSystem(void *chartInstanceVar)
{
  enable_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_flightControlSystem(void *chartInstanceVar)
{
  disable_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c6_flightControlSystem
    ((SFc6_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c6_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c6_flightControlSystem
      ((SFc6_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c6_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c6_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_flightControlSystem
      ((SFc6_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c6_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [18] = {
    "eNrtV09v00gUd6KCttJSVauV9oJEb3DkhLgAJU6sRkppWbcFcakm9os9m/GMmT9Jc+QDcOA7cNj",
    "LHvajcONj7HEvi3hju2lwbIcSqNjVWnLdsX/vN+//mzit/r6D1xbe939ynOv4/AHvtpNf14p1a+",
    "HO3284t4v1axTiJjkkkiTKabw4SeBXUIIZTQXv85GohFE+Agk8QGwqpK5jUzQxjPKxZ3hg+dSzm",
    "AaxHwvDwg7KkvCAsxmypUYfIk+XSgi0BxDqWAoTxR4j0VxjqaduDMFYmaTJBAXaN6lVS+0bpmnK",
    "oHcGQZ8rTVBjdaGbr4kGV5/VmmktVf45UCQpo4RXWhsT5UOKDtZwnIb498BoNKoMC2IidQdiMgE",
    "1oOOMU3Aoc1KFH4aUEy0kJayXMNcKLut2yFCffRECa3AI6taRQMapoFzXx9/30NIeJ0MGXRiaqJ",
    "7Nh5fGBv+EwhRkrd9GrpiAJBEc8NpNM4f0zrJozbNkGaZpAidEPg4wfgrC2uzFzFE+wTjBEUrUw",
    "SAzsq+OJJ2ge2vZTNK3mbmqZEySB1utgmVsvQk0RWHO5gXcJYypWtiRSAcwAZaxdokmzbCctRqn",
    "FA2PBDrYpnd9NRhOMfAFzBU8pJXhmpQAWd95go3lU2RglBaJi8nbHQyWPy/D+lyDHJEAqrqAJFQ",
    "B+ixzbz1bSJWNPQJRK52pVwXOM2QVylEjw7tTIcfok4YmcmGCjWgtMFERxhIr4Vhh0TTBbCxX4Q",
    "ISxBDaBkMZ7GPZILbCJ8q2tsdYdxOqZ11QgaRpRVQNVh22oZ5NqFkKx3zMxZR7UiR+0eNz9wJgt",
    "hHJKY862L/kzMPdq0Jh59ld52Ke/fgZ8+xcrvy8s8DTquBxFp7lfTfbzfu28b9WIbe7IHejtM9G",
    "Sc7itvF+u+s9UH/+M3jV++PDu+dv1tr/9/bl5v9Wsb553mjnhTNZyleL3VvQa6OC/5cF/u1irdw",
    "X03CvdxJ5cXrwdPjbEFQUm72M7+9Ws77tkr7n73dsx8csy/JTBv2wOJjYNTH5uM7OQwv6Xl/hj8",
    "3ifX799Wg9+Z93y3HcWGHfNq46zz7N2y/ff2d3Pfl8/8MV+u+U4r2TzfVTYrsFnAb3TkeMRrFt9",
    "FoK5s+UhmTrK9TZZeWcK5b7t+j5v1++vX2fM7euWs65Yrl17bvs/P7e8E1zwCnht79jO9Y9V31r",
    "/HvncuefW8X64fwnjhtTFlacdovPeHQdVX39D+TpR0GFtGU=",
    ""
  };

  static char newstr [1249] = "";
  newstr[0] = '\0';
  for (i = 0; i < 18; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c6_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c6_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1028014244U));
  ssSetChecksum1(S,(1291694451U));
  ssSetChecksum2(S,(4272768385U));
  ssSetChecksum3(S,(9525457U));
}

static void mdlRTW_c6_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c6_flightControlSystem(SimStruct *S)
{
  SFc6_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc6_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc6_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c6_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c6_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c6_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c6_JITStateAnimation,
    chartInstance->c6_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c6_flightControlSystem(chartInstance);
}

void c6_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c6_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
