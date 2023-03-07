/* Include files */

#include "flightControlSystem_sfun.h"
#include "c7_flightControlSystem.h"
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
static emlrtMCInfo c7_emlrtMCI = { 13, /* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtRSInfo c7_emlrtRSI = { 4,  /* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2937"          /* pathName */
};

static emlrtRSInfo c7_b_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwmorph.m"/* pathName */
};

static emlrtRSInfo c7_c_emlrtRSI = { 24,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c7_d_emlrtRSI = { 142,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c7_e_emlrtRSI = { 143,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c7_f_emlrtRSI = { 27,/* lineNo */
  "lutendpoints",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+internal\\lutendpoints.m"/* pathName */
};

static emlrtRSInfo c7_g_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwlookup.m"/* pathName */
};

/* Function Declarations */
static void initialize_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void enable_c7_flightControlSystem(SFc7_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void c7_update_jit_animation_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void c7_do_animation_call_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance, const mxArray *c7_st);
static void sf_gateway_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void c7_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_b_BW, const char_T *c7_identifier, boolean_T
  c7_y[19200]);
static void c7_b_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  boolean_T c7_y[19200]);
static uint8_T c7_c_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_flightControlSystem, const
  char_T *c7_identifier);
static uint8_T c7_d_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_chart_data_browse_helper(SFc7_flightControlSystemInstanceStruct
  *chartInstance, int32_T c7_ssIdNumber, const mxArray **c7_mxData, uint8_T
  *c7_isValueTooBig);
static void init_dsm_address_info(SFc7_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c7_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c7_st.tls = chartInstance->c7_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c7_st, (const char_T *)"image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_flightControlSystem = 0U;
}

static void initialize_params_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_flightControlSystem(SFc7_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_jit_animation_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_do_animation_call_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  const mxArray *c7_c_y = NULL;
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(2, 1), false);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", *chartInstance->c7_BW, 11, 0U, 1U,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y",
    &chartInstance->c7_is_active_c7_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  int32_T c7_i;
  boolean_T c7_bv[19200];
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "BW",
                      c7_bv);
  for (c7_i = 0; c7_i < 19200; c7_i++) {
    (*chartInstance->c7_BW)[c7_i] = c7_bv[c7_i];
  }

  chartInstance->c7_is_active_c7_flightControlSystem = c7_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_flightControlSystem");
  sf_mex_destroy(&c7_u);
  sf_mex_destroy(&c7_st);
}

static void sf_gateway_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  static real_T c7_dv[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };

  static char_T c7_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static boolean_T c7_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, false, true, true, true, true, false, true, false,
    false, false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    false, true, false, true, true, false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, false,
    false, false, false, false, true, true, false, true, false, false, false,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, false, false, false, false, false, false, false,
    true, true, false, true, false, false, false, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, false, false, false, true, false, true, true, false, false, false,
    false, false, false, false, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, false,
    true, false, true, true, false, false, false, false, false, false, false,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, true, true, false, true, false, false, false, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, false, false, false, true, false,
    true, true, true, true, false, true, true, true, true, false };

  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_e_st;
  emlrtStack c7_f_st;
  emlrtStack c7_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c7_b_y = NULL;
  const mxArray *c7_y = NULL;
  real_T c7_sizeIn[2];
  real_T c7_b_k;
  real_T c7_x;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_k;
  boolean_T c7_in[19200];
  boolean_T c7_b;
  c7_st.tls = chartInstance->c7_fEmlrtCtx;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_e_st.prev = &c7_d_st;
  c7_e_st.tls = c7_d_st.tls;
  c7_f_st.prev = &c7_e_st;
  c7_f_st.tls = c7_e_st.tls;
  chartInstance->c7_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c7_i = 0; c7_i < 19200; c7_i++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 0U, (real_T)
                      (*chartInstance->c7_bin_image)[c7_i]);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c7_covrtInstance, 4U, 0, 0);
  c7_b_st.site = &c7_emlrtRSI;
  c7_c_st.site = &c7_b_emlrtRSI;
  c7_d_st.site = &c7_c_emlrtRSI;
  for (c7_i1 = 0; c7_i1 < 19200; c7_i1++) {
    (*chartInstance->c7_BW)[c7_i1] = (*chartInstance->c7_bin_image)[c7_i1];
  }

  c7_e_st.site = &c7_d_emlrtRSI;
  c7_f_st.site = &c7_f_emlrtRSI;
  for (c7_k = 0; c7_k < 512; c7_k++) {
    c7_b_k = 1.0 + (real_T)c7_k;
    c7_x = c7_dv[(int32_T)c7_b_k - 1];
    c7_b = muDoubleScalarIsNaN(c7_x);
    if (c7_b) {
      c7_y = NULL;
      sf_mex_assign(&c7_y, sf_mex_create("y", c7_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c7_f_st, &c7_emlrtMCI, "error", 0U, 2U, 14, c7_y, 14,
                  sf_mex_call(&c7_f_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c7_f_st, NULL, "message", 1U, 1U, 14, c7_b_y)));
    }
  }

  c7_e_st.site = &c7_e_emlrtRSI;
  c7_f_st.site = &c7_g_emlrtRSI;
  for (c7_i2 = 0; c7_i2 < 19200; c7_i2++) {
    c7_in[c7_i2] = (*chartInstance->c7_BW)[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 2; c7_i3++) {
    c7_sizeIn[c7_i3] = 120.0 + 40.0 * (real_T)c7_i3;
  }

  bwlookup_tbb_boolean(&c7_in[0], &c7_sizeIn[0], 2.0, &c7_lut[0], 512.0,
                       &(*chartInstance->c7_BW)[0]);
  c7_do_animation_call_c7_flightControlSystem(chartInstance);
  for (c7_i4 = 0; c7_i4 < 19200; c7_i4++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 1U, (real_T)
                      (*chartInstance->c7_BW)[c7_i4]);
  }
}

static void mdl_start_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c7_decisionTxtEndIdx = 0U;
  static const uint32_T c7_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c7_chart_data_browse_helper);
  chartInstance->c7_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c7_RuntimeVar,
    &chartInstance->c7_IsDebuggerActive,
    &chartInstance->c7_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c7_mlFcnLineNumber, &chartInstance->c7_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c7_covrtInstance, 1U, 0U, 1U,
    57U);
  covrtChartInitFcn(chartInstance->c7_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c7_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c7_decisionTxtStartIdx, &c7_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c7_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c7_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c7_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 69);
}

static void mdl_cleanup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c7_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c7_covrtInstance);
}

static void initSimStructsc7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c7_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static void c7_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_b_BW, const char_T *c7_identifier, boolean_T
  c7_y[19200])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = (const char_T *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_BW), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_b_BW);
}

static void c7_b_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  boolean_T c7_y[19200])
{
  int32_T c7_i;
  boolean_T c7_bv[19200];
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c7_i = 0; c7_i < 19200; c7_i++) {
    c7_y[c7_i] = c7_bv[c7_i];
  }

  sf_mex_destroy(&c7_u);
}

static uint8_T c7_c_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_flightControlSystem, const
  char_T *c7_identifier)
{
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y;
  c7_thisId.fIdentifier = (const char_T *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_flightControlSystem), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_flightControlSystem);
  return c7_y;
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_b_u;
  uint8_T c7_y;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_b_u, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_b_u;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_chart_data_browse_helper(SFc7_flightControlSystemInstanceStruct
  *chartInstance, int32_T c7_ssIdNumber, const mxArray **c7_mxData, uint8_T
  *c7_isValueTooBig)
{
  *c7_mxData = NULL;
  *c7_mxData = NULL;
  *c7_isValueTooBig = 0U;
  switch (c7_ssIdNumber) {
   case 4U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData",
      *chartInstance->c7_bin_image, 11, 0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", *chartInstance->c7_BW, 11,
      0U, 1U, 0U, 2, 120, 160), false);
    break;
  }
}

static void init_dsm_address_info(SFc7_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c7_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c7_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c7_bin_image = (boolean_T (*)[19200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c7_BW = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c7_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2459286328U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2411523677U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(702825455U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1665014915U);
}

mxArray *sf_c7_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c7_flightControlSystem_jit_fallback_info(void)
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

mxArray *sf_c7_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI+E8AyHMKh4QLLHzIt1/BgTL9EP"
    "sDCLhfAcX9EH5mcXxicklmWWp8snl8Wk5mekaJc35eSVF+TnBlcUlqLsx/AIYmHN0="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "silW2YVVF5akFryGzhssKbE";
}

static void sf_opaque_initialize_c7_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c7_flightControlSystem
    ((SFc7_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_flightControlSystem(void *chartInstanceVar)
{
  enable_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_flightControlSystem(void *chartInstanceVar)
{
  disable_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c7_flightControlSystem
    ((SFc7_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c7_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c7_flightControlSystem
      ((SFc7_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c7_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c7_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_flightControlSystem
      ((SFc7_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c7_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [18] = {
    "eNrtV8tu20YUpQQniIHWMIIA2QSNd80iiyBAkawaWw82QqXYCGUbXRnj4ZU40HCGmYdsFeiiH+D",
    "/6L5/0K/oZ7S7LnOHpGWFIqk4SowkKAGaHvLcM/d9R16jN/Dw2sL7+V3Pu43PO3g3vey6la8bC3",
    "f2fsP7Pl9foJCw8QFRJNZe7SVIDK9BS24Nk6InRrIUxsQIFAiK2EQqU8WmWWw5ExPfCur49HHEa",
    "BRE0vKwhbIk3Bd8hmyJNQfI02EKqPEBQhMpaceRz8l4rrEyZ+0I6ETbuM4EDSawiVNLDyw3LOHQ",
    "PQfaE9oQ1Fhf6RYYYqBtzivNdJbq4BIo44QzIkqtjYgOIEEHGzhMQvy7bw0aVYTRiCjTgohMQff",
    "ZJOWUAoqcTOOHUyaIkYoR3o152wku63bAUZ+BDIHXOAR1aykgk0QyYarjH/hoaVeQUw4dOLXjar",
    "YA3lgX/CMGZ6Aq/TZqyykoMoZ9Ublp6pDueRqteZYswwyL4YioPYrx0xBWZi9mjg4IxgmGKFEFg",
    "9TInh4qNkX3VrLZuOcyc1XJ2DgLtl4FS9m6U6iLwpzNp6JNONeVsKFM+jAFnrJ2iCH1sIy1HKc1",
    "C4cSHezSu7oarGAY+BzWliJkpeGaFgBp33mFjeVdJLXayLiNydvp95c/L8N6woAaEQplXUARpgF",
    "9lrq3mi1k2sUegaiVSdUrA2cZsgrl6ZEVnTOpJuiTmiZyZYKLaCUw1mOMJVbCocaiqYO5WK7CUU",
    "IjCF2DYRwGWDaILfGJdq1tD+tuysysA5oqlpRE1WLVYRvquoSaJXAoJkKeCV/JOMh7fOZeAMw2o",
    "gQT4xb2LzXzcfeyULh59sS7mmffvMc8u5QrPh8t8DRKeLyFZ3HfzWb9vk38r5HL7S7IfVvYZ6Mg",
    "53DbDkf/FHu/Xfw7/r31+PCvZ9+ts/8fzevN/618/eCy0c4LZ7qUrw77ckGvjRL++wv82/laM37",
    "89JejI/8HMvHV7KdfI61/Pu2mfP816vVtFvS9fL/jOj5mWZqfivbC/GDi1sRm4zo9Dy3oe3uFPz",
    "bz99n1z4v15O/tFuO4scK+bVy1jt/N2w/ff2d3Pfls/4MV+u8U4r2TzvUT4roFnNBnJyPOxpFr9",
    "EZJHsy0gXjrI9TZdeW8G5b7UvT83y+f3r73mVs3LefdsNy69l13fn9u+Lo54BXw25+xHeueqz41",
    "/m/veuefh/n6x/lPnHbEeFhy2s0/49F1VPb1K8jTtyxlssA=",
    ""
  };

  static char newstr [1249] = "";
  newstr[0] = '\0';
  for (i = 0; i < 18; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c7_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c7_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1857250061U));
  ssSetChecksum1(S,(4052581697U));
  ssSetChecksum2(S,(742556007U));
  ssSetChecksum3(S,(506970709U));
}

static void mdlRTW_c7_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c7_flightControlSystem(SimStruct *S)
{
  SFc7_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc7_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc7_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c7_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c7_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c7_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_flightControlSystem;
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
    chartInstance->c7_JITStateAnimation,
    chartInstance->c7_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c7_flightControlSystem(chartInstance);
}

void c7_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c7_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
