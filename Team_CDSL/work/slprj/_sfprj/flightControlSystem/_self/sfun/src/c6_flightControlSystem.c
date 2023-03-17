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
#define c6_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c6_IN_new_track_generation     (1U)
#define c6_IN_straight_line_reference_generation (2U)
#define c6_IN_take_off                 (3U)
#define c6_IN_take_off_complete        (4U)
#define c6_IN_calculate_previus_point  (1U)
#define c6_IN_track_generation         (2U)
#define c6_const_COG_X                 (60.0)
#define c6_const_COG_Y                 (80.0)
#define c6_const_k1                    (1.6)
#define c6_const_k2                    (0.9)
#define c6_const_k3                    (0.5)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c6_emlrtMCI = { 159,/* lineNo */
  13,                                  /* colNo */
  "CoderTimeAPI",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\+time\\CoderTimeAPI.m"/* pName */
};

static emlrtMCInfo c6_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c6_c_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c6_d_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c6_e_emlrtMCI = { 88,/* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c6_f_emlrtMCI = { 11,/* lineNo */
  9,                                   /* colNo */
  "timeKeeper",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\+time\\+impl\\timeKeeper.m"/* pName */
};

static emlrtMCInfo c6_g_emlrtMCI = { 83,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static const char_T c6_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'C', 'o', 'd', 'e', 'r', 'T', 'i', 'm', 'e', 'C', 'a',
  'l', 'l', 'F', 'a', 'i', 'l', 'e', 'd' };

static const char_T c6_cv1[26] = { 'e', 'm', 'l', 'r', 't', 'C', 'l', 'o', 'c',
  'k', 'G', 'e', 't', 't', 'i', 'm', 'e', 'M', 'o', 'n', 'o', 't', 'o', 'n', 'i',
  'c' };

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
static void c6_set_sim_state_side_effects_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
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
static void c6_chartstep_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_enter_atomic_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static real_T c6_mod(SFc6_flightControlSystemInstanceStruct *chartInstance,
                     real_T c6_x);
static void c6_tic(SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_timeKeeper(SFc6_flightControlSystemInstanceStruct *chartInstance,
  emlrtTimespec c6_newTime);
static void c6_imdilate(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_A[19200], c6_strel c6_se, real_T c6_b_B[19200]);
static real_T c6_norm(SFc6_flightControlSystemInstanceStruct *chartInstance,
                      real_T c6_x[2]);
static void c6_bwlabel(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_varargin_1[19200], real_T c6_L[19200]);
static void c6_check_forloop_overflow_error
  (SFc6_flightControlSystemInstanceStruct *chartInstance, boolean_T c6_overflow);
static void c6_mean(SFc6_flightControlSystemInstanceStruct *chartInstance,
                    real_T c6_x[2400], real_T c6_y[2]);
static void c6_toc(SFc6_flightControlSystemInstanceStruct *chartInstance);
static emlrtTimespec c6_b_timeKeeper(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static real_T c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_a__output_of_feval_, const char_T
  *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_init(SFc6_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c6_image[19200], real_T c6_initial_ref[2], real_T *
                    c6_initial_theta);
static void c6_sector_form(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_points[2400], real_T c6_prev_theta, real_T *c6_state, real_T c6_ref
  [2], real_T c6_c_MAP[19200]);
static void c6_track_generator(SFc6_flightControlSystemInstanceStruct
  *chartInstance, real_T c6_points[2400], real_T c6_prev_point[2], real_T
  c6_ref[2]);
static void c6_c_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_d_cutting_image, const char_T *c6_identifier,
  real_T c6_y[19200]);
static void c6_d_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[19200]);
static void c6_e_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_refPosition, const char_T *c6_identifier,
  real_T c6_y[2]);
static void c6_f_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[2]);
static emlrtTimespec c6_g_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c6_b_savedTime, const char_T *c6_identifier, boolean_T *c6_svPtr);
static emlrtTimespec c6_h_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_u,
   const emlrtMsgIdentifier *c6_parentId, boolean_T *c6_svPtr);
static uint8_T c6_i_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_flightControlSystem, const
  char_T *c6_identifier);
static uint8_T c6_j_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static uint32_T c6_k_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_c6_flightControlSystem, const char_T
  *c6_identifier);
static uint32_T c6_l_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_m_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_dataWrittenToVector, const char_T
  *c6_identifier, boolean_T c6_y[15]);
static void c6_n_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[15]);
static const mxArray *c6_o_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier);
static const mxArray *c6_p_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_u,
   const emlrtMsgIdentifier *c6_parentId);
static void c6_init_sf_message_store_memory
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_chart_data_browse_helper(SFc6_flightControlSystemInstanceStruct
  *chartInstance, int32_T c6_ssIdNumber, const mxArray **c6_mxData, uint8_T
  *c6_isValueTooBig);
static const mxArray *c6_feval(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_input0, const mxArray *c6_input1, const
  mxArray *c6_input2, const mxArray *c6_input3);
static void init_dsm_address_info(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  emlrtLicenseCheckR2012b(chartInstance->c6_fEmlrtCtx, (const char_T *)
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_savedTime_not_empty = false;
  chartInstance->c6_doSetSimStateSideEffects = 0U;
  chartInstance->c6_setSimStateSideEffectsInfo = NULL;
  chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_is_active_c6_flightControlSystem = 0U;
  chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_takeOffFlag = 0.0;
  chartInstance->c6_isLine = 0.0;
  chartInstance->c6_i = 0.0;
  for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
    chartInstance->c6_tempPoint[c6_b_i] = 0.0;
  }

  chartInstance->c6_theta = 0.0;
  chartInstance->c6_COG_X = 60.0;
  chartInstance->c6_COG_Y = 80.0;
  chartInstance->c6_k1 = 1.6;
  chartInstance->c6_k2 = 0.9;
  chartInstance->c6_k3 = 0.5;
  if (sf_get_output_port_reusable(chartInstance->S, 1) == 0) {
    for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
      (*chartInstance->c6_refPosition)[c6_i1] = 0.0;
    }
  }

  if (sf_get_output_port_reusable(chartInstance->S, 2) == 0) {
    for (c6_i2 = 0; c6_i2 < 19200; c6_i2++) {
      (*chartInstance->c6_c_cutting_image)[c6_i2] = 0.0;
    }
  }

  if (sf_get_output_port_reusable(chartInstance->S, 3) == 0) {
    for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
      (*chartInstance->c6_weightMeanPoint)[c6_i3] = 0.0;
    }
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 2U,
                    chartInstance->c6_takeOffFlag);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                    chartInstance->c6_isLine);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                      chartInstance->c6_tempPoint[c6_i4]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U, chartInstance->c6_theta);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 13U,
                    chartInstance->c6_COG_X);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 14U,
                    chartInstance->c6_COG_Y);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 15U, chartInstance->c6_k1);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 16U, chartInstance->c6_k2);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 17U, chartInstance->c6_k3);
  for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                      (*chartInstance->c6_refPosition)[c6_i5]);
  }

  for (c6_i6 = 0; c6_i6 < 19200; c6_i6++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                      (*chartInstance->c6_c_cutting_image)[c6_i6]);
  }

  for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 12U,
                      (*chartInstance->c6_weightMeanPoint)[c6_i7]);
  }
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
  chartInstance->c6_JITStateAnimation[0U] = (uint8_T)
    (chartInstance->c6_is_c6_flightControlSystem == c6_IN_take_off);
  chartInstance->c6_JITStateAnimation[1U] = (uint8_T)
    (chartInstance->c6_is_c6_flightControlSystem == c6_IN_take_off_complete);
  chartInstance->c6_JITStateAnimation[2U] = (uint8_T)
    (chartInstance->c6_is_c6_flightControlSystem ==
     c6_IN_straight_line_reference_generation);
  chartInstance->c6_JITStateAnimation[3U] = (uint8_T)
    (chartInstance->c6_is_c6_flightControlSystem == c6_IN_new_track_generation);
  chartInstance->c6_JITStateAnimation[4U] = (uint8_T)
    (chartInstance->c6_is_new_track_generation == c6_IN_calculate_previus_point);
  chartInstance->c6_JITStateAnimation[5U] = (uint8_T)
    (chartInstance->c6_is_new_track_generation == c6_IN_track_generation);
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
  static const char_T *c6_sv[2] = { "tv_sec", "tv_nsec" };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  const mxArray *c6_h_y = NULL;
  const mxArray *c6_i_y = NULL;
  const mxArray *c6_j_y = NULL;
  const mxArray *c6_k_y = NULL;
  const mxArray *c6_l_y = NULL;
  const mxArray *c6_m_y = NULL;
  const mxArray *c6_n_y = NULL;
  const mxArray *c6_o_y = NULL;
  const mxArray *c6_p_y = NULL;
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  real_T c6_u;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(13, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", *chartInstance->c6_c_cutting_image,
    0, 0U, 1U, 0U, 2, 120, 160), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", *chartInstance->c6_refPosition, 0,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", *chartInstance->c6_weightMeanPoint,
    0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &chartInstance->c6_i, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &chartInstance->c6_isLine, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &chartInstance->c6_takeOffFlag, 0,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", chartInstance->c6_tempPoint, 0, 0U,
    1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  c6_i_y = NULL;
  sf_mex_assign(&c6_i_y, sf_mex_create("y", &chartInstance->c6_theta, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c6_y, 7, c6_i_y);
  c6_j_y = NULL;
  if (!chartInstance->c6_savedTime_not_empty) {
    sf_mex_assign(&c6_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_j_y, sf_mex_createstruct("structure", 2, c6_sv, 2, 1, 1),
                  false);
    c6_u = chartInstance->c6_savedTime.tv_sec;
    c6_k_y = NULL;
    sf_mex_assign(&c6_k_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c6_j_y, 0, "tv_sec", c6_k_y, 0);
    c6_b_u = chartInstance->c6_savedTime.tv_nsec;
    c6_m_y = NULL;
    sf_mex_assign(&c6_m_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c6_j_y, 0, "tv_nsec", c6_m_y, 1);
  }

  sf_mex_setcell(c6_y, 8, c6_j_y);
  c6_l_y = NULL;
  sf_mex_assign(&c6_l_y, sf_mex_create("y",
    &chartInstance->c6_is_active_c6_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_y, 9, c6_l_y);
  c6_n_y = NULL;
  sf_mex_assign(&c6_n_y, sf_mex_create("y",
    &chartInstance->c6_is_c6_flightControlSystem, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 10, c6_n_y);
  c6_o_y = NULL;
  sf_mex_assign(&c6_o_y, sf_mex_create("y",
    &chartInstance->c6_is_new_track_generation, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 11, c6_o_y);
  c6_p_y = NULL;
  sf_mex_assign(&c6_p_y, sf_mex_create("y",
    chartInstance->c6_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 15), false);
  sf_mex_setcell(c6_y, 12, c6_p_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv1[2];
  real_T c6_dv2[2];
  real_T c6_dv3[2];
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  boolean_T c6_bv[15];
  c6_u = sf_mex_dup(c6_st);
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                        "cutting_image", chartInstance->c6_dv);
  for (c6_b_i = 0; c6_b_i < 19200; c6_b_i++) {
    (*chartInstance->c6_c_cutting_image)[c6_b_i] = chartInstance->c6_dv[c6_b_i];
  }

  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
                        "refPosition", c6_dv1);
  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    (*chartInstance->c6_refPosition)[c6_i1] = c6_dv1[c6_i1];
  }

  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
                        "weightMeanPoint", c6_dv2);
  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    (*chartInstance->c6_weightMeanPoint)[c6_i2] = c6_dv2[c6_i2];
  }

  chartInstance->c6_i = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 3)), "i");
  chartInstance->c6_isLine = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 4)), "isLine");
  chartInstance->c6_takeOffFlag = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 5)), "takeOffFlag");
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 6)),
                        "tempPoint", c6_dv3);
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    chartInstance->c6_tempPoint[c6_i3] = c6_dv3[c6_i3];
  }

  chartInstance->c6_theta = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 7)), "theta");
  chartInstance->c6_savedTime = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 8)), "savedTime",
    &chartInstance->c6_savedTime_not_empty);
  chartInstance->c6_is_active_c6_flightControlSystem = c6_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 9)),
     "is_active_c6_flightControlSystem");
  chartInstance->c6_is_c6_flightControlSystem = c6_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 10)),
     "is_c6_flightControlSystem");
  chartInstance->c6_is_new_track_generation = c6_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 11)),
     "is_new_track_generation");
  c6_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 12)),
                        "dataWrittenToVector", c6_bv);
  for (c6_i4 = 0; c6_i4 < 15; c6_i4++) {
    chartInstance->c6_dataWrittenToVector[c6_i4] = c6_bv[c6_i4];
  }

  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 13)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c6_u);
  chartInstance->c6_doSetSimStateSideEffects = 1U;
  c6_update_jit_animation_state_c6_flightControlSystem(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void c6_set_sim_state_side_effects_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  if (chartInstance->c6_doSetSimStateSideEffects != 0) {
    chartInstance->c6_doSetSimStateSideEffects = 0U;
  }
}

static void sf_gateway_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i2;
  c6_set_sim_state_side_effects_c6_flightControlSystem(chartInstance);
  chartInstance->c6_JITTransitionAnimation[0] = 0U;
  chartInstance->c6_JITTransitionAnimation[1] = 0U;
  chartInstance->c6_JITTransitionAnimation[2] = 0U;
  chartInstance->c6_JITTransitionAnimation[3] = 0U;
  chartInstance->c6_JITTransitionAnimation[4] = 0U;
  chartInstance->c6_JITTransitionAnimation[5] = 0U;
  chartInstance->c6_JITTransitionAnimation[6] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 9U,
                    *chartInstance->c6_ladingFlag);
  for (c6_b_i = 0; c6_b_i < 6; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 8U,
                      (*chartInstance->c6_prev_points)[c6_b_i]);
  }

  for (c6_i1 = 0; c6_i1 < 2400; c6_i1++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 7U,
                      (*chartInstance->c6_dots)[c6_i1]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 6U, (real_T)
                    *chartInstance->c6_Z);
  for (c6_i2 = 0; c6_i2 < 19200; c6_i2++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U, (real_T)
                      (*chartInstance->c6_bin_image)[c6_i2]);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_flightControlSystem(chartInstance);
  c6_update_jit_animation_state_c6_flightControlSystem(chartInstance);
  c6_do_animation_call_c6_flightControlSystem(chartInstance);
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
  static const int32_T c6_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c6_condTxtEndIdx[2] = { 1418, 1432 };

  static const int32_T c6_condTxtStartIdx[2] = { 1384, 1422 };

  static const uint32_T c6_b_decisionTxtEndIdx = 0U;
  static const uint32_T c6_b_decisionTxtStartIdx = 0U;
  static const uint32_T c6_c_decisionTxtEndIdx = 0U;
  static const uint32_T c6_c_decisionTxtStartIdx = 0U;
  static const uint32_T c6_d_decisionTxtEndIdx = 0U;
  static const uint32_T c6_d_decisionTxtStartIdx = 0U;
  static const uint32_T c6_decisionTxtEndIdx = 0U;
  static const uint32_T c6_decisionTxtStartIdx = 0U;
  static const uint32_T c6_e_decisionTxtEndIdx = 0U;
  static const uint32_T c6_e_decisionTxtStartIdx = 0U;
  static const uint32_T c6_f_decisionTxtEndIdx = 0U;
  static const uint32_T c6_f_decisionTxtStartIdx = 0U;
  static const uint32_T c6_g_decisionTxtEndIdx = 0U;
  static const uint32_T c6_g_decisionTxtStartIdx = 0U;
  static const uint32_T c6_h_decisionTxtEndIdx = 0U;
  static const uint32_T c6_h_decisionTxtStartIdx = 0U;
  static const uint32_T c6_i_decisionTxtEndIdx = 0U;
  static const uint32_T c6_i_decisionTxtStartIdx = 0U;
  static const uint32_T c6_j_decisionTxtEndIdx = 0U;
  static const uint32_T c6_j_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c6_chart_data_browse_helper);
  chartInstance->c6_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c6_RuntimeVar,
    &chartInstance->c6_IsDebuggerActive,
    &chartInstance->c6_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c6_mlFcnLineNumber, &chartInstance->c6_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c6_covrtInstance, 10U, 0U, 7U,
    143U);
  covrtChartInitFcn(chartInstance->c6_covrtInstance, 4U, true, false, false);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 2U, 2U, true, true, false,
                    0U, &c6_decisionTxtStartIdx, &c6_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 3U, 0U, false, false, false,
                    0U, &c6_b_decisionTxtStartIdx, &c6_b_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, false, false, false,
                    0U, &c6_c_decisionTxtStartIdx, &c6_c_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 6U, 0U, false, false, false,
                    0U, &c6_d_decisionTxtStartIdx, &c6_d_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 7U, 0U, false, false, false,
                    0U, &c6_e_decisionTxtStartIdx, &c6_e_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 8U, 0U, false, false, false,
                    0U, &c6_f_decisionTxtStartIdx, &c6_f_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c6_g_decisionTxtStartIdx, &c6_g_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 1U, 0U, false, false, false,
                    0U, &c6_h_decisionTxtStartIdx, &c6_h_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 5U, 0U, false, false, false,
                    0U, &c6_i_decisionTxtStartIdx, &c6_i_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 9U, 0U, false, false, false,
                    0U, &c6_j_decisionTxtStartIdx, &c6_j_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 1U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 3U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 2U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 4U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 5U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 6U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, "init", 0, -1,
                     472);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 138, 156, -1,
                    235);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 101, 114, 246);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 1U, 118, 131, 242);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 141,
    156, -1, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 9U, 1U, 0U, 4U, 0U,
                  0U, 0U, 2U, 0U, 2U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U,
                     "track_generator", 0, -1, 1732);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 977, 996, 1197,
                    1256);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 1U, 1197, 1210, -1,
                    1256);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 2U, 1380, 1432, -1,
                    1563);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 3U, 1581, 1597, -1,
                    1720);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 870, 882, 1729);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 1U, 938, 954, 1571);
  covrtEmlMCDCInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 1384, 1432,
                      2U, 0U, c6_condTxtStartIdx, c6_condTxtEndIdx, 3U,
                      c6_postfixPredicateTree);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 980,
    996, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 1U, 1200,
    1210, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 2U, 1384,
    1418, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 3U, 1422,
    1432, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 4U, 1584,
    1597, -1, 4U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 5U, 1U, 0U, 6U, 0U,
                  0U, 0U, 4U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, "sector_form",
                     0, -1, 3585);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, 378, 397, 536,
                    587);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 1U, 536, 549, -1,
                    587);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 2U, 597, 635, -1,
                    799);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 3U, 1621, 1639, -1,
                    1708);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 4U, 1892, 1915, -1,
                    2018);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 5U, 3026, 3048,
                    3092, 3115);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, 347, 363, 803);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 1U, 1549, 1562,
                     1712);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 2U, 1855, 1868,
                     2029);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 3U, 1872, 1885,
                     2025);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, 381,
    397, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 1U, 539,
    549, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 2U, 601,
    635, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 3U, 1624,
    1639, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 4U, 1896,
    1915, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 5U, 3029,
    3048, -1, 4U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 1U, 1U, 0U, 6U, 0U,
                  0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 0U, "means_circle",
                     0, -1, 910);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 0U, 148, 164, 180,
                    212);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 1U, 218, 234, 250,
                    282);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 2U, 284, 303, 320,
                    351);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 3U, 353, 372, 389,
                    420);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 4U, 610, 628, -1,
                    833);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 5U, 700, 712, -1,
                    822);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 0U, 527, 562, 845);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 1U, 567, 602, 841);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 7U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 8U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 6U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 2U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 3U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 4U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 6U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 6U, 0U, 1, 2, 1, 2);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 1U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 1U, 0U, 1, 13, 12, 13);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 1U, 0U, 1, 13,
    -1, 4U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 3U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 3U, 0U, 1, 2, 1, 2);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 2U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 2U, 0U, 1, 12, 11, 12);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 2U, 0U, 1, 12,
    -1, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 4U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 4U, 0U, 1, 12, 11, 12);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 4U, 0U, 1, 12,
    -1, 0U);
}

static void mdl_cleanup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c6_RuntimeVar);
  sf_mex_destroy(&chartInstance->c6_setSimStateSideEffectsInfo);
  covrtDeleteStateflowInstanceData(chartInstance->c6_covrtInstance);
}

static void c6_chartstep_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c6_c_y = NULL;
  real_T c6_b_dv[2400];
  real_T c6_dv3[2400];
  real_T c6_b_refPosition[2];
  real_T c6_dv1[2];
  real_T c6_dv2[2];
  real_T c6_dv4[2];
  real_T c6_dv5[2];
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_b_r;
  real_T c6_b_theta;
  real_T c6_d_y;
  real_T c6_e_y;
  real_T c6_f_y;
  real_T c6_g_x;
  real_T c6_g_y;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_r;
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  real32_T c6_b_x;
  real32_T c6_b_y;
  real32_T c6_c_x;
  real32_T c6_d_x;
  real32_T c6_e_x;
  real32_T c6_f_x;
  real32_T c6_x;
  real32_T c6_y;
  boolean_T c6_bv[19200];
  boolean_T c6_b_out;
  boolean_T c6_out;
  if (chartInstance->c6_is_active_c6_flightControlSystem == 0U) {
    chartInstance->c6_is_active_c6_flightControlSystem = 1U;
    chartInstance->c6_JITTransitionAnimation[0U] = 1U;
    chartInstance->c6_is_c6_flightControlSystem = c6_IN_take_off;
    chartInstance->c6_takeOffFlag = 0.0;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 2U,
                      chartInstance->c6_takeOffFlag);
    for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
      (*chartInstance->c6_refPosition)[c6_b_i] = 0.0;
    }

    chartInstance->c6_dataWrittenToVector[1U] = true;
    for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                        (*chartInstance->c6_refPosition)[c6_i1]);
    }
  } else {
    switch (chartInstance->c6_is_c6_flightControlSystem) {
     case c6_IN_new_track_generation:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 1, 0,
                        c6_IN_new_track_generation);
      if (!chartInstance->c6_dataWrittenToVector[2U]) {
        sf_read_before_write_error(chartInstance->S, 1U, 95U, 1, 6);
      }

      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 4, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 5U, 4U, 0U,
                          chartInstance->c6_isLine, 1.0, -1, 0U,
                          chartInstance->c6_isLine == 1.0))) {
        c6_out = true;
      } else {
        c6_out = false;
      }

      if (c6_out) {
        chartInstance->c6_JITTransitionAnimation[4U] = 1U;
        chartInstance->c6_isLine = 0.0;
        chartInstance->c6_dataWrittenToVector[2U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                          chartInstance->c6_isLine);
        if (!chartInstance->c6_dataWrittenToVector[2U]) {
          sf_read_before_write_error(chartInstance->S, 1U, 95U, 14, 6);
        }

        sf_mex_printf("%s =\\n", "isLine");
        c6_c_y = NULL;
        sf_mex_assign(&c6_c_y, sf_mex_create("y", &chartInstance->c6_isLine, 0,
          0U, 0U, 0U, 0), false);
        sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL, "disp", 0U, 1U, 14,
                    c6_c_y);
        switch (chartInstance->c6_is_new_track_generation) {
         case c6_IN_calculate_previus_point:
          covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 1,
                            c6_IN_calculate_previus_point);
          chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
          break;

         case c6_IN_track_generation:
          covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 1,
                            c6_IN_track_generation);
          chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
          break;

         default:
          covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 1, 0);
          chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
          break;
        }

        chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
        chartInstance->c6_is_c6_flightControlSystem =
          c6_IN_straight_line_reference_generation;
        c6_enter_atomic_straight_line_reference_generation(chartInstance);
      } else {
        switch (chartInstance->c6_is_new_track_generation) {
         case c6_IN_calculate_previus_point:
          covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 0,
                            c6_IN_calculate_previus_point);
          covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 6, 0, true);
          chartInstance->c6_JITTransitionAnimation[6U] = 1U;
          chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
          chartInstance->c6_is_new_track_generation = c6_IN_track_generation;
          if (!chartInstance->c6_dataWrittenToVector[7U]) {
            sf_read_before_write_error(chartInstance->S, 12U, 98U, 50, 15);
          }

          for (c6_i4 = 0; c6_i4 < 2400; c6_i4++) {
            c6_dv3[c6_i4] = (*chartInstance->c6_dots)[c6_i4];
          }

          for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
            c6_dv4[c6_i7] = (*chartInstance->c6_weightMeanPoint)[c6_i7];
          }

          c6_track_generator(chartInstance, c6_dv3, c6_dv4, c6_dv5);
          for (c6_i10 = 0; c6_i10 < 2; c6_i10++) {
            chartInstance->c6_tempPoint[c6_i10] = c6_dv5[c6_i10];
          }

          chartInstance->c6_dataWrittenToVector[5U] = true;
          for (c6_i12 = 0; c6_i12 < 2; c6_i12++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                              chartInstance->c6_tempPoint[c6_i12]);
          }

          if (!chartInstance->c6_dataWrittenToVector[5U]) {
            sf_read_before_write_error(chartInstance->S, 3U, 98U, 93, 9);
          }

          (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
            chartInstance->c6_tempPoint[0];
          chartInstance->c6_dataWrittenToVector[1U] = true;
          for (c6_i14 = 0; c6_i14 < 2; c6_i14++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                              (*chartInstance->c6_refPosition)[c6_i14]);
          }

          if (!chartInstance->c6_dataWrittenToVector[5U]) {
            sf_read_before_write_error(chartInstance->S, 3U, 98U, 124, 9);
          }

          (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
            c6_const_COG_Y;
          chartInstance->c6_dataWrittenToVector[1U] = true;
          for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                              (*chartInstance->c6_refPosition)[c6_i16]);
          }

          if (!chartInstance->c6_dataWrittenToVector[1U]) {
            sf_read_before_write_error(chartInstance->S, 10U, 98U, 164, 11);
          }

          c6_e_y = (*chartInstance->c6_refPosition)[1];
          c6_h_x = (*chartInstance->c6_refPosition)[0];
          c6_b_a = c6_e_y;
          c6_b_b = c6_h_x;
          c6_g_y = c6_b_a;
          c6_j_x = c6_b_b;
          c6_b_r = muDoubleScalarAtan2(c6_g_y, c6_j_x);
          chartInstance->c6_theta = c6_mod(chartInstance, c6_b_r);
          chartInstance->c6_dataWrittenToVector[1U] = true;
          chartInstance->c6_dataWrittenToVector[6U] = true;
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                            chartInstance->c6_theta);
          chartInstance->c6_isLine = 1.0;
          chartInstance->c6_dataWrittenToVector[2U] = true;
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                            chartInstance->c6_isLine);
          break;

         case c6_IN_track_generation:
          covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 0,
                            c6_IN_track_generation);
          if (!chartInstance->c6_dataWrittenToVector[7U]) {
            sf_read_before_write_error(chartInstance->S, 12U, 98U, 50, 15);
          }

          for (c6_i2 = 0; c6_i2 < 2400; c6_i2++) {
            c6_b_dv[c6_i2] = (*chartInstance->c6_dots)[c6_i2];
          }

          for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
            c6_dv1[c6_i3] = (*chartInstance->c6_weightMeanPoint)[c6_i3];
          }

          c6_track_generator(chartInstance, c6_b_dv, c6_dv1, c6_dv2);
          for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
            chartInstance->c6_tempPoint[c6_i5] = c6_dv2[c6_i5];
          }

          chartInstance->c6_dataWrittenToVector[5U] = true;
          for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                              chartInstance->c6_tempPoint[c6_i8]);
          }

          if (!chartInstance->c6_dataWrittenToVector[5U]) {
            sf_read_before_write_error(chartInstance->S, 3U, 98U, 93, 9);
          }

          (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
            chartInstance->c6_tempPoint[0];
          chartInstance->c6_dataWrittenToVector[1U] = true;
          for (c6_i13 = 0; c6_i13 < 2; c6_i13++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                              (*chartInstance->c6_refPosition)[c6_i13]);
          }

          if (!chartInstance->c6_dataWrittenToVector[5U]) {
            sf_read_before_write_error(chartInstance->S, 3U, 98U, 124, 9);
          }

          (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
            c6_const_COG_Y;
          chartInstance->c6_dataWrittenToVector[1U] = true;
          for (c6_i15 = 0; c6_i15 < 2; c6_i15++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                              (*chartInstance->c6_refPosition)[c6_i15]);
          }

          if (!chartInstance->c6_dataWrittenToVector[1U]) {
            sf_read_before_write_error(chartInstance->S, 10U, 98U, 164, 11);
          }

          c6_d_y = (*chartInstance->c6_refPosition)[1];
          c6_g_x = (*chartInstance->c6_refPosition)[0];
          c6_a = c6_d_y;
          c6_b = c6_g_x;
          c6_f_y = c6_a;
          c6_i_x = c6_b;
          c6_r = muDoubleScalarAtan2(c6_f_y, c6_i_x);
          chartInstance->c6_theta = c6_mod(chartInstance, c6_r);
          chartInstance->c6_dataWrittenToVector[1U] = true;
          chartInstance->c6_dataWrittenToVector[6U] = true;
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                            chartInstance->c6_theta);
          chartInstance->c6_isLine = 1.0;
          chartInstance->c6_dataWrittenToVector[2U] = true;
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                            chartInstance->c6_isLine);
          break;

         default:
          covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 0, 0);

          /* Unreachable state, for coverage only */
          chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
          break;
        }
      }
      break;

     case c6_IN_straight_line_reference_generation:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 1, 0,
                        c6_IN_straight_line_reference_generation);
      c6_straight_line_reference_generation(chartInstance);
      break;

     case c6_IN_take_off:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 1, 0,
                        c6_IN_take_off);
      c6_x = *chartInstance->c6_Z;
      c6_b_x = c6_x;
      c6_c_x = c6_b_x;
      c6_y = muSingleScalarAbs(c6_c_x);
      c6_d_x = *chartInstance->c6_Z;
      c6_e_x = c6_d_x;
      c6_f_x = c6_e_x;
      c6_b_y = muSingleScalarAbs(c6_f_x);
      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 1, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 5U, 1U, 0U, (real_T)
                          c6_y, 1.0, -1, 4U, c6_b_y > 1.0F))) {
        c6_b_out = true;
      } else {
        c6_b_out = false;
      }

      if (c6_b_out) {
        chartInstance->c6_JITTransitionAnimation[1U] = 1U;
        chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
        chartInstance->c6_is_c6_flightControlSystem = c6_IN_take_off_complete;
        for (c6_i6 = 0; c6_i6 < 19200; c6_i6++) {
          c6_bv[c6_i6] = (*chartInstance->c6_bin_image)[c6_i6];
        }

        c6_init(chartInstance, c6_bv, c6_b_refPosition, &c6_b_theta);
        for (c6_i9 = 0; c6_i9 < 2; c6_i9++) {
          (*chartInstance->c6_refPosition)[c6_i9] = c6_b_refPosition[c6_i9];
        }

        chartInstance->c6_dataWrittenToVector[1U] = true;
        for (c6_i11 = 0; c6_i11 < 2; c6_i11++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                            (*chartInstance->c6_refPosition)[c6_i11]);
        }

        chartInstance->c6_theta = c6_b_theta;
        chartInstance->c6_dataWrittenToVector[6U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                          chartInstance->c6_theta);
      }
      break;

     case c6_IN_take_off_complete:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 1, 0,
                        c6_IN_take_off_complete);
      covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 3, 0, true);
      chartInstance->c6_JITTransitionAnimation[3U] = 1U;
      chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
      chartInstance->c6_is_c6_flightControlSystem =
        c6_IN_straight_line_reference_generation;
      c6_enter_atomic_straight_line_reference_generation(chartInstance);
      break;

     default:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 1, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
      break;
    }
  }
}

static void initSimStructsc6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_enter_atomic_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  real_T c6_b_dv[2400];
  real_T c6_b_tempPoint[2];
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_isLine;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
    chartInstance->c6_tempPoint[c6_b_i] = 0.0;
  }

  chartInstance->c6_dataWrittenToVector[5U] = true;
  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                      chartInstance->c6_tempPoint[c6_i1]);
  }

  if (!chartInstance->c6_dataWrittenToVector[6U]) {
    sf_read_before_write_error(chartInstance->S, 4U, 34U, 129, 5);
  }

  for (c6_i2 = 0; c6_i2 < 2400; c6_i2++) {
    c6_b_dv[c6_i2] = (*chartInstance->c6_dots)[c6_i2];
  }

  c6_sector_form(chartInstance, c6_b_dv, chartInstance->c6_theta, &c6_b_isLine,
                 c6_b_tempPoint, chartInstance->c6_b_cutting_image);
  chartInstance->c6_isLine = c6_b_isLine;
  chartInstance->c6_dataWrittenToVector[2U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                    chartInstance->c6_isLine);
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    chartInstance->c6_tempPoint[c6_i3] = c6_b_tempPoint[c6_i3];
  }

  chartInstance->c6_dataWrittenToVector[5U] = true;
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                      chartInstance->c6_tempPoint[c6_i4]);
  }

  for (c6_i5 = 0; c6_i5 < 19200; c6_i5++) {
    (*chartInstance->c6_c_cutting_image)[c6_i5] =
      chartInstance->c6_b_cutting_image[c6_i5];
  }

  chartInstance->c6_dataWrittenToVector[3U] = true;
  for (c6_i6 = 0; c6_i6 < 19200; c6_i6++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                      (*chartInstance->c6_c_cutting_image)[c6_i6]);
  }

  if (!chartInstance->c6_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 3U, 34U, 162, 9);
  }

  (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
    chartInstance->c6_tempPoint[0];
  chartInstance->c6_dataWrittenToVector[1U] = true;
  for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                      (*chartInstance->c6_refPosition)[c6_i7]);
  }

  if (!chartInstance->c6_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 3U, 34U, 193, 9);
  }

  (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
    c6_const_COG_Y;
  chartInstance->c6_dataWrittenToVector[1U] = true;
  for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                      (*chartInstance->c6_refPosition)[c6_i8]);
  }

  if (!chartInstance->c6_dataWrittenToVector[1U]) {
    sf_read_before_write_error(chartInstance->S, 10U, 34U, 233, 11);
  }

  c6_y = (*chartInstance->c6_refPosition)[1];
  c6_x = (*chartInstance->c6_refPosition)[0];
  c6_a = c6_y;
  c6_b = c6_x;
  c6_b_y = c6_a;
  c6_b_x = c6_b;
  c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
  chartInstance->c6_theta = c6_mod(chartInstance, c6_r);
  chartInstance->c6_dataWrittenToVector[1U] = true;
  chartInstance->c6_dataWrittenToVector[6U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U, chartInstance->c6_theta);
}

static void c6_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  real_T c6_b_dv[2400];
  real_T c6_b[2];
  real_T c6_b_tempPoint[2];
  real_T c6_a;
  real_T c6_b_b;
  real_T c6_b_isLine;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  boolean_T c6_out;
  if (!chartInstance->c6_dataWrittenToVector[2U]) {
    sf_read_before_write_error(chartInstance->S, 1U, 56U, 1, 6);
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 2, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        5U, 2U, 0U, chartInstance->c6_isLine, 0.0, -1, 0U,
        chartInstance->c6_isLine == 0.0))) {
    c6_out = true;
  } else {
    c6_out = false;
  }

  if (c6_out) {
    chartInstance->c6_JITTransitionAnimation[2U] = 1U;
    chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
    chartInstance->c6_is_c6_flightControlSystem = c6_IN_new_track_generation;
    chartInstance->c6_JITTransitionAnimation[5U] = 1U;
    chartInstance->c6_is_new_track_generation = c6_IN_calculate_previus_point;
    c6_i2 = 0;
    for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
      (*chartInstance->c6_weightMeanPoint)[c6_i3] =
        (*chartInstance->c6_prev_points)[c6_i2];
      c6_i2 += 3;
    }

    for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
      (*chartInstance->c6_weightMeanPoint)[c6_i5] *= c6_const_k1;
    }

    c6_i6 = 0;
    for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
      c6_b_tempPoint[c6_i7] = (*chartInstance->c6_prev_points)[c6_i6 + 1];
      c6_i6 += 3;
    }

    for (c6_i9 = 0; c6_i9 < 2; c6_i9++) {
      c6_b_tempPoint[c6_i9] *= c6_const_k2;
    }

    c6_i10 = 0;
    for (c6_i12 = 0; c6_i12 < 2; c6_i12++) {
      c6_b[c6_i12] = (*chartInstance->c6_prev_points)[c6_i10 + 2];
      c6_i10 += 3;
    }

    for (c6_i14 = 0; c6_i14 < 2; c6_i14++) {
      c6_b[c6_i14] *= c6_const_k3;
    }

    for (c6_i15 = 0; c6_i15 < 2; c6_i15++) {
      (*chartInstance->c6_weightMeanPoint)[c6_i15] =
        (((*chartInstance->c6_weightMeanPoint)[c6_i15] + c6_b_tempPoint[c6_i15])
         + c6_b[c6_i15]) / 3.0;
    }

    chartInstance->c6_dataWrittenToVector[7U] = true;
    for (c6_i17 = 0; c6_i17 < 2; c6_i17++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 12U,
                        (*chartInstance->c6_weightMeanPoint)[c6_i17]);
    }
  } else {
    for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
      chartInstance->c6_tempPoint[c6_b_i] = 0.0;
    }

    chartInstance->c6_dataWrittenToVector[5U] = true;
    for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                        chartInstance->c6_tempPoint[c6_i1]);
    }

    if (!chartInstance->c6_dataWrittenToVector[6U]) {
      sf_read_before_write_error(chartInstance->S, 4U, 34U, 129, 5);
    }

    for (c6_i4 = 0; c6_i4 < 2400; c6_i4++) {
      c6_b_dv[c6_i4] = (*chartInstance->c6_dots)[c6_i4];
    }

    c6_sector_form(chartInstance, c6_b_dv, chartInstance->c6_theta, &c6_b_isLine,
                   c6_b_tempPoint, chartInstance->c6_cutting_image);
    chartInstance->c6_isLine = c6_b_isLine;
    chartInstance->c6_dataWrittenToVector[2U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                      chartInstance->c6_isLine);
    for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
      chartInstance->c6_tempPoint[c6_i8] = c6_b_tempPoint[c6_i8];
    }

    chartInstance->c6_dataWrittenToVector[5U] = true;
    for (c6_i11 = 0; c6_i11 < 2; c6_i11++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                        chartInstance->c6_tempPoint[c6_i11]);
    }

    for (c6_i13 = 0; c6_i13 < 19200; c6_i13++) {
      (*chartInstance->c6_c_cutting_image)[c6_i13] =
        chartInstance->c6_cutting_image[c6_i13];
    }

    chartInstance->c6_dataWrittenToVector[3U] = true;
    for (c6_i16 = 0; c6_i16 < 19200; c6_i16++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                        (*chartInstance->c6_c_cutting_image)[c6_i16]);
    }

    if (!chartInstance->c6_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 3U, 34U, 162, 9);
    }

    (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
      chartInstance->c6_tempPoint[0];
    chartInstance->c6_dataWrittenToVector[1U] = true;
    for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                        (*chartInstance->c6_refPosition)[c6_i18]);
    }

    if (!chartInstance->c6_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 3U, 34U, 193, 9);
    }

    (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
      c6_const_COG_Y;
    chartInstance->c6_dataWrittenToVector[1U] = true;
    for (c6_i19 = 0; c6_i19 < 2; c6_i19++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                        (*chartInstance->c6_refPosition)[c6_i19]);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      sf_read_before_write_error(chartInstance->S, 10U, 34U, 233, 11);
    }

    c6_y = (*chartInstance->c6_refPosition)[1];
    c6_x = (*chartInstance->c6_refPosition)[0];
    c6_a = c6_y;
    c6_b_b = c6_x;
    c6_b_y = c6_a;
    c6_b_x = c6_b_b;
    c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
    chartInstance->c6_theta = c6_mod(chartInstance, c6_r);
    chartInstance->c6_dataWrittenToVector[1U] = true;
    chartInstance->c6_dataWrittenToVector[6U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                      chartInstance->c6_theta);
  }
}

static real_T c6_mod(SFc6_flightControlSystemInstanceStruct *chartInstance,
                     real_T c6_x)
{
  real_T c6_a;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_q;
  real_T c6_r;
  boolean_T c6_b;
  boolean_T c6_b_b;
  boolean_T c6_rEQ0;
  (void)chartInstance;
  c6_a = c6_x;
  c6_b_x = c6_a;
  c6_c_x = c6_b_x;
  c6_d_x = c6_c_x;
  c6_b = muDoubleScalarIsNaN(c6_d_x);
  if (c6_b) {
    c6_r = rtNaN;
  } else {
    c6_e_x = c6_c_x;
    c6_b_b = muDoubleScalarIsInf(c6_e_x);
    if (c6_b_b) {
      c6_r = rtNaN;
    } else if (c6_c_x == 0.0) {
      c6_r = 0.0;
    } else {
      c6_r = muDoubleScalarRem(c6_c_x, 6.2831853071795862);
      c6_rEQ0 = (c6_r == 0.0);
      if (!c6_rEQ0) {
        c6_q = muDoubleScalarAbs(c6_c_x / 6.2831853071795862);
        c6_rEQ0 = !(muDoubleScalarAbs(c6_q - muDoubleScalarFloor(c6_q + 0.5)) >
                    2.2204460492503131E-16 * c6_q);
      }

      if (c6_rEQ0) {
        c6_r = 0.0;
      } else if (c6_c_x < 0.0) {
        c6_r += 6.2831853071795862;
      }
    }
  }

  return c6_r;
}

static void c6_tic(SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtTimespec c6_t;
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_b_status;
  int32_T c6_status;
  c6_status = emlrtClockGettimeMonotonic(&c6_t);
  c6_b_status = c6_status;
  if (c6_b_status != 0) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    c6_d_y = NULL;
    sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_b_status, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_emlrtMCI, "error", 0U, 2U, 14,
                c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "message", 1U, 3U, 14, c6_b_y, 14, c6_c_y, 14, c6_d_y)));
  }

  c6_timeKeeper(chartInstance, c6_t);
}

static void c6_timeKeeper(SFc6_flightControlSystemInstanceStruct *chartInstance,
  emlrtTimespec c6_newTime)
{
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_b_status;
  int32_T c6_status;
  if (!chartInstance->c6_savedTime_not_empty) {
    c6_status = emlrtClockGettimeMonotonic(&chartInstance->c6_savedTime);
    c6_b_status = c6_status;
    if (c6_b_status != 0) {
      c6_y = NULL;
      sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                    false);
      c6_b_y = NULL;
      sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                    false);
      c6_c_y = NULL;
      sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 26),
                    false);
      c6_d_y = NULL;
      sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_b_status, 6, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_emlrtMCI, "error", 0U, 2U, 14,
                  c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
        "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
        "message", 1U, 3U, 14, c6_b_y, 14, c6_c_y, 14, c6_d_y)));
    }

    chartInstance->c6_savedTime_not_empty = true;
  }

  chartInstance->c6_savedTime = c6_newTime;
}

static void c6_imdilate(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_A[19200], c6_strel c6_se, real_T c6_b_B[19200])
{
  real_T c6_asizeT[2];
  real_T c6_nsizeT[2];
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_c_j;
  real_T c6_d_i;
  real_T c6_g_i;
  real_T c6_h_j;
  int32_T c6_b_c;
  int32_T c6_b_i;
  int32_T c6_b_j;
  int32_T c6_c;
  int32_T c6_c_i;
  int32_T c6_d_j;
  int32_T c6_e_i;
  int32_T c6_e_j;
  int32_T c6_f_i;
  int32_T c6_f_j;
  int32_T c6_g_j;
  int32_T c6_h_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i2;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i_i;
  int32_T c6_j;
  int32_T c6_j_i;
  boolean_T c6_nhood[3];
  boolean_T c6_b_nhood;
  boolean_T c6_c_nhood;
  (void)c6_se;
  for (c6_j = 0; c6_j < 2; c6_j++) {
    c6_c_j = (real_T)c6_j + 1.0;
    for (c6_b_i = 0; c6_b_i < 122; c6_b_i++) {
      c6_d_i = (real_T)c6_b_i + 1.0;
      chartInstance->c6_Apadpre[((int32_T)c6_d_i + 122 * ((int32_T)c6_c_j - 1))
        - 1] = rtMinusInf;
    }
  }

  for (c6_b_j = 0; c6_b_j < 160; c6_b_j++) {
    for (c6_c_i = 0; c6_c_i < 2; c6_c_i++) {
      c6_d_i = (real_T)c6_c_i + 1.0;
      chartInstance->c6_Apadpre[((int32_T)c6_d_i + 122 * (c6_b_j + 2)) - 1] =
        rtMinusInf;
    }
  }

  for (c6_d_j = 0; c6_d_j < 160; c6_d_j++) {
    c6_c_j = (real_T)c6_d_j + 1.0;
    for (c6_e_i = 0; c6_e_i < 120; c6_e_i++) {
      c6_d_i = (real_T)c6_e_i + 1.0;
      c6_a = c6_d_i;
      c6_c = (int32_T)c6_a;
      c6_b_a = c6_c_j;
      c6_b_c = (int32_T)c6_b_a;
      chartInstance->c6_Apadpre[(c6_c + 122 * (c6_b_c + 1)) + 1] = c6_A
        [((int32_T)c6_d_i + 120 * ((int32_T)c6_c_j - 1)) - 1];
    }
  }

  for (c6_e_j = 0; c6_e_j < 2; c6_e_j++) {
    for (c6_f_i = 0; c6_f_i < 124; c6_f_i++) {
      c6_g_i = (real_T)c6_f_i + 1.0;
      chartInstance->c6_Apad[((int32_T)c6_g_i + 124 * (c6_e_j + 162)) - 1] =
        rtMinusInf;
    }
  }

  for (c6_f_j = 0; c6_f_j < 162; c6_f_j++) {
    c6_h_j = (real_T)c6_f_j + 1.0;
    for (c6_h_i = 0; c6_h_i < 2; c6_h_i++) {
      chartInstance->c6_Apad[(c6_h_i + 124 * ((int32_T)c6_h_j - 1)) + 122] =
        rtMinusInf;
    }
  }

  for (c6_g_j = 0; c6_g_j < 162; c6_g_j++) {
    c6_h_j = (real_T)c6_g_j + 1.0;
    for (c6_j_i = 0; c6_j_i < 122; c6_j_i++) {
      c6_g_i = (real_T)c6_j_i + 1.0;
      chartInstance->c6_Apad[((int32_T)c6_g_i + 124 * ((int32_T)c6_h_j - 1)) - 1]
        = chartInstance->c6_Apadpre[((int32_T)c6_g_i + 122 * ((int32_T)c6_h_j -
        1)) - 1];
    }
  }

  for (c6_i_i = 0; c6_i_i < 3; c6_i_i++) {
    c6_nhood[c6_i_i] = true;
  }

  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    c6_asizeT[c6_i1] = 124.0 + 40.0 * (real_T)c6_i1;
  }

  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    c6_nsizeT[c6_i2] = 3.0 + -2.0 * (real_T)c6_i2;
  }

  dilate_flat_real64_tbb(&chartInstance->c6_Apad[0], &c6_asizeT[0], 2.0,
    &c6_nhood[0], &c6_nsizeT[0], 2.0, &chartInstance->c6_B[0]);
  for (c6_i3 = 0; c6_i3 < 20336; c6_i3++) {
    chartInstance->c6_Apad[c6_i3] = chartInstance->c6_B[c6_i3];
  }

  c6_b_nhood = true;
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    c6_asizeT[c6_i4] = 124.0 + 40.0 * (real_T)c6_i4;
  }

  for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
    c6_nsizeT[c6_i5] = 1.0;
  }

  dilate_flat_real64_tbb(&chartInstance->c6_Apad[0], &c6_asizeT[0], 2.0,
    &c6_b_nhood, &c6_nsizeT[0], 2.0, &chartInstance->c6_B[0]);
  for (c6_i6 = 0; c6_i6 < 20336; c6_i6++) {
    chartInstance->c6_Apad[c6_i6] = chartInstance->c6_B[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_nhood[c6_i7] = true;
  }

  for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
    c6_asizeT[c6_i8] = 124.0 + 40.0 * (real_T)c6_i8;
  }

  for (c6_i9 = 0; c6_i9 < 2; c6_i9++) {
    c6_nsizeT[c6_i9] = 1.0 + 2.0 * (real_T)c6_i9;
  }

  dilate_flat_real64_tbb(&chartInstance->c6_Apad[0], &c6_asizeT[0], 2.0,
    &c6_nhood[0], &c6_nsizeT[0], 2.0, &chartInstance->c6_B[0]);
  for (c6_i10 = 0; c6_i10 < 20336; c6_i10++) {
    chartInstance->c6_Apad[c6_i10] = chartInstance->c6_B[c6_i10];
  }

  c6_c_nhood = true;
  for (c6_i11 = 0; c6_i11 < 2; c6_i11++) {
    c6_asizeT[c6_i11] = 124.0 + 40.0 * (real_T)c6_i11;
  }

  for (c6_i12 = 0; c6_i12 < 2; c6_i12++) {
    c6_nsizeT[c6_i12] = 1.0;
  }

  dilate_flat_real64_tbb(&chartInstance->c6_Apad[0], &c6_asizeT[0], 2.0,
    &c6_c_nhood, &c6_nsizeT[0], 2.0, &chartInstance->c6_B[0]);
  for (c6_i13 = 0; c6_i13 < 20336; c6_i13++) {
    chartInstance->c6_Apad[c6_i13] = chartInstance->c6_B[c6_i13];
  }

  for (c6_i14 = 0; c6_i14 < 3; c6_i14++) {
    c6_nhood[c6_i14] = true;
  }

  for (c6_i15 = 0; c6_i15 < 2; c6_i15++) {
    c6_asizeT[c6_i15] = 124.0 + 40.0 * (real_T)c6_i15;
  }

  for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
    c6_nsizeT[c6_i16] = 1.0 + 2.0 * (real_T)c6_i16;
  }

  dilate_flat_real64_tbb(&chartInstance->c6_Apad[0], &c6_asizeT[0], 2.0,
    &c6_nhood[0], &c6_nsizeT[0], 2.0, &chartInstance->c6_B[0]);
  for (c6_i17 = 0; c6_i17 < 20336; c6_i17++) {
    chartInstance->c6_Apad[c6_i17] = chartInstance->c6_B[c6_i17];
  }

  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    c6_nhood[c6_i18] = true;
  }

  for (c6_i19 = 0; c6_i19 < 2; c6_i19++) {
    c6_asizeT[c6_i19] = 124.0 + 40.0 * (real_T)c6_i19;
  }

  for (c6_i20 = 0; c6_i20 < 2; c6_i20++) {
    c6_nsizeT[c6_i20] = 3.0 + -2.0 * (real_T)c6_i20;
  }

  dilate_flat_real64_tbb(&chartInstance->c6_Apad[0], &c6_asizeT[0], 2.0,
    &c6_nhood[0], &c6_nsizeT[0], 2.0, &chartInstance->c6_B[0]);
  c6_i21 = 0;
  c6_i22 = 0;
  for (c6_i23 = 0; c6_i23 < 160; c6_i23++) {
    for (c6_i24 = 0; c6_i24 < 120; c6_i24++) {
      c6_b_B[c6_i24 + c6_i21] = chartInstance->c6_B[(c6_i24 + c6_i22) + 250];
    }

    c6_i21 += 120;
    c6_i22 += 124;
  }
}

static real_T c6_norm(SFc6_flightControlSystemInstanceStruct *chartInstance,
                      real_T c6_x[2])
{
  real_T c6_absxk;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_scale;
  real_T c6_t;
  real_T c6_y;
  int32_T c6_b_k;
  int32_T c6_k;
  (void)chartInstance;
  c6_y = 0.0;
  c6_scale = 3.3121686421112381E-170;
  for (c6_k = 0; c6_k < 2; c6_k++) {
    c6_b_k = c6_k;
    c6_b_x = c6_x[c6_b_k];
    c6_c_x = c6_b_x;
    c6_d_x = c6_c_x;
    c6_absxk = muDoubleScalarAbs(c6_d_x);
    if (c6_absxk > c6_scale) {
      c6_t = c6_scale / c6_absxk;
      c6_y = 1.0 + c6_y * c6_t * c6_t;
      c6_scale = c6_absxk;
    } else {
      c6_t = c6_absxk / c6_scale;
      c6_y += c6_t * c6_t;
    }
  }

  return c6_scale * muDoubleScalarSqrt(c6_y);
}

static void c6_bwlabel(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_varargin_1[19200], real_T c6_L[19200])
{
  static char_T c6_b_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_b_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv10[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv4[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv5[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv6[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv7[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv8[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv9[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  const mxArray *c6_h_y = NULL;
  const mxArray *c6_j_y = NULL;
  const mxArray *c6_k_y = NULL;
  const mxArray *c6_l_y = NULL;
  const mxArray *c6_m_y = NULL;
  const mxArray *c6_n_y = NULL;
  const mxArray *c6_o_y = NULL;
  const mxArray *c6_p_y = NULL;
  const mxArray *c6_q_y = NULL;
  const mxArray *c6_r_y = NULL;
  const mxArray *c6_s_y = NULL;
  const mxArray *c6_t_y = NULL;
  const mxArray *c6_u_y = NULL;
  const mxArray *c6_v_y = NULL;
  const mxArray *c6_w_y = NULL;
  const mxArray *c6_y = NULL;
  int64_T c6_i2;
  real_T c6_P[9601];
  real_T c6_a;
  real_T c6_ab_x;
  real_T c6_b_c;
  real_T c6_b_j;
  real_T c6_b_r;
  real_T c6_b_root;
  real_T c6_b_rootj;
  real_T c6_b_thread;
  real_T c6_b_varargin_1;
  real_T c6_b_x;
  real_T c6_bb_x;
  real_T c6_c_i;
  real_T c6_c_j;
  real_T c6_c_root;
  real_T c6_c_rootj;
  real_T c6_c_varargin_1;
  real_T c6_c_x;
  real_T c6_cb_x;
  real_T c6_d;
  real_T c6_d1;
  real_T c6_d10;
  real_T c6_d11;
  real_T c6_d12;
  real_T c6_d13;
  real_T c6_d14;
  real_T c6_d15;
  real_T c6_d16;
  real_T c6_d17;
  real_T c6_d18;
  real_T c6_d2;
  real_T c6_d3;
  real_T c6_d4;
  real_T c6_d5;
  real_T c6_d6;
  real_T c6_d7;
  real_T c6_d8;
  real_T c6_d9;
  real_T c6_d_a;
  real_T c6_d_c;
  real_T c6_d_i;
  real_T c6_d_j;
  real_T c6_d_root;
  real_T c6_d_rootj;
  real_T c6_d_x;
  real_T c6_db_x;
  real_T c6_e_i;
  real_T c6_e_j;
  real_T c6_e_root;
  real_T c6_e_x;
  real_T c6_eb_x;
  real_T c6_f_i;
  real_T c6_f_j;
  real_T c6_f_root;
  real_T c6_f_x;
  real_T c6_fb_x;
  real_T c6_firstLabel;
  real_T c6_g_i;
  real_T c6_g_j;
  real_T c6_g_x;
  real_T c6_gb_x;
  real_T c6_h_i;
  real_T c6_h_j;
  real_T c6_hb_x;
  real_T c6_i_i;
  real_T c6_i_j;
  real_T c6_ib_x;
  real_T c6_j;
  real_T c6_j_i;
  real_T c6_j_j;
  real_T c6_jb_x;
  real_T c6_k_i;
  real_T c6_kb_x;
  real_T c6_l_i;
  real_T c6_l_x;
  real_T c6_label;
  real_T c6_lb_x;
  real_T c6_m_i;
  real_T c6_mb_x;
  real_T c6_minval;
  real_T c6_n_i;
  real_T c6_n_x;
  real_T c6_nb_x;
  real_T c6_numComponents;
  real_T c6_o_i;
  real_T c6_o_x;
  real_T c6_ob_x;
  real_T c6_p_i;
  real_T c6_p_x;
  real_T c6_q_i;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_root;
  real_T c6_rootj;
  real_T c6_s_x;
  real_T c6_startC;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_x;
  real_T c6_x_x;
  real_T c6_y_x;
  real_T c6_z;
  int32_T c6_chunksSizeAndLabels[168];
  int32_T c6_b_a;
  int32_T c6_b_i;
  int32_T c6_b_q0;
  int32_T c6_b_q1;
  int32_T c6_b_qY;
  int32_T c6_b_z;
  int32_T c6_c;
  int32_T c6_c_a;
  int32_T c6_c_c;
  int32_T c6_c_q0;
  int32_T c6_c_q1;
  int32_T c6_c_qY;
  int32_T c6_c_r;
  int32_T c6_d_q0;
  int32_T c6_d_q1;
  int32_T c6_d_qY;
  int32_T c6_d_r;
  int32_T c6_e_a;
  int32_T c6_e_c;
  int32_T c6_e_q0;
  int32_T c6_e_q1;
  int32_T c6_e_qY;
  int32_T c6_f_a;
  int32_T c6_f_q0;
  int32_T c6_f_q1;
  int32_T c6_f_qY;
  int32_T c6_g_q0;
  int32_T c6_g_q1;
  int32_T c6_g_qY;
  int32_T c6_h_q0;
  int32_T c6_h_q1;
  int32_T c6_h_qY;
  int32_T c6_h_x;
  int32_T c6_i1;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i_b;
  int32_T c6_i_q0;
  int32_T c6_i_q1;
  int32_T c6_i_qY;
  int32_T c6_i_x;
  int32_T c6_i_y;
  int32_T c6_j_q0;
  int32_T c6_j_q1;
  int32_T c6_j_qY;
  int32_T c6_j_x;
  int32_T c6_k_b;
  int32_T c6_k_q0;
  int32_T c6_k_q1;
  int32_T c6_k_qY;
  int32_T c6_k_x;
  int32_T c6_l_q0;
  int32_T c6_l_q1;
  int32_T c6_l_qY;
  int32_T c6_m_x;
  int32_T c6_q0;
  int32_T c6_q1;
  int32_T c6_qY;
  int32_T c6_r;
  int32_T c6_r_i;
  int32_T c6_stripeFirstLabel;
  int32_T c6_thread;
  int32_T c6_w_x;
  boolean_T c6_b;
  boolean_T c6_b_b;
  boolean_T c6_c_b;
  boolean_T c6_d_b;
  boolean_T c6_e_b;
  boolean_T c6_f_b;
  boolean_T c6_g_b;
  boolean_T c6_guard1 = false;
  boolean_T c6_guard2 = false;
  boolean_T c6_guard3 = false;
  boolean_T c6_guard4 = false;
  boolean_T c6_guard5 = false;
  boolean_T c6_h_b;
  boolean_T c6_j_b;
  boolean_T c6_l_b;
  boolean_T c6_m_b;
  boolean_T c6_overflow;
  c6_P[0] = 0.0;
  for (c6_thread = 0; c6_thread < 8; c6_thread++) {
    c6_b_thread = (real_T)c6_thread;
    c6_b_c = c6_b_thread * 20.0 + 1.0;
    c6_b_varargin_1 = (c6_b_thread + 1.0) * 20.0 + 1.0;
    c6_x = c6_b_varargin_1;
    c6_b_x = c6_x;
    c6_c_x = c6_b_x;
    c6_a = c6_c_x;
    c6_e_x = c6_a;
    c6_g_x = c6_e_x;
    c6_minval = muDoubleScalarMin(c6_g_x, 161.0);
    c6_d1 = muDoubleScalarRound(c6_minval);
    if (c6_d1 < 2.147483648E+9) {
      if (c6_d1 >= -2.147483648E+9) {
        c6_b_i = (int32_T)c6_d1;
      } else {
        c6_b_i = MIN_int32_T;
        sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
      }
    } else if (c6_d1 >= 2.147483648E+9) {
      c6_b_i = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_b_i = 0;
    }

    c6_chunksSizeAndLabels[(int32_T)c6_b_c - 1] = c6_b_i;
    c6_l_x = c6_b_c / 2.0;
    c6_n_x = c6_l_x;
    c6_n_x = muDoubleScalarFloor(c6_n_x);
    c6_label = c6_n_x * 60.0 + 1.0;
    c6_firstLabel = c6_label;
    c6_startC = c6_b_c;
    c6_d6 = c6_b_thread * 20.0 + 1.0;
    c6_c_varargin_1 = (c6_b_thread + 1.0) * 20.0;
    c6_u_x = c6_c_varargin_1;
    c6_v_x = c6_u_x;
    c6_x_x = c6_v_x;
    c6_d_a = c6_x_x;
    c6_y_x = c6_d_a;
    c6_ab_x = c6_y_x;
    c6_d7 = muDoubleScalarMin(c6_ab_x, 160.0);
    c6_i3 = (int32_T)(c6_d7 + (1.0 - c6_d6)) - 1;
    for (c6_e_c = 0; c6_e_c <= c6_i3; c6_e_c++) {
      c6_b_c = c6_d6 + (real_T)c6_e_c;
      for (c6_d_r = 0; c6_d_r < 120; c6_d_r++) {
        c6_b_r = (real_T)c6_d_r + 1.0;
        c6_d12 = c6_varargin_1[((int32_T)c6_b_r + 120 *
          (sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
          MAX_uint32_T, (int32_T)c6_b_c, 1, 160) - 1)) - 1];
        c6_bb_x = c6_d12;
        c6_cb_x = c6_bb_x;
        c6_e_b = muDoubleScalarIsNaN(c6_cb_x);
        if (c6_e_b) {
          c6_j_y = NULL;
          sf_mex_assign(&c6_j_y, sf_mex_create("y", c6_cv4, 10, 0U, 1U, 0U, 2, 1,
            19), false);
          c6_k_y = NULL;
          sf_mex_assign(&c6_k_y, sf_mex_create("y", c6_cv4, 10, 0U, 1U, 0U, 2, 1,
            19), false);
          sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error", 0U,
                      2U, 14, c6_j_y, 14, sf_mex_call
                      (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U, 1U,
                       14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
            "message", 1U, 1U, 14, c6_k_y)));
        }

        if (c6_d12 != 0.0) {
          c6_guard1 = false;
          c6_guard2 = false;
          c6_guard3 = false;
          c6_guard4 = false;
          c6_guard5 = false;
          if (c6_b_c > c6_startC) {
            c6_d13 = c6_varargin_1[((int32_T)c6_b_r + 120 * ((int32_T)(c6_b_c -
              1.0) - 1)) - 1];
            c6_db_x = c6_d13;
            c6_eb_x = c6_db_x;
            c6_f_b = muDoubleScalarIsNaN(c6_eb_x);
            if (c6_f_b) {
              c6_l_y = NULL;
              sf_mex_assign(&c6_l_y, sf_mex_create("y", c6_cv5, 10, 0U, 1U, 0U,
                2, 1, 19), false);
              c6_m_y = NULL;
              sf_mex_assign(&c6_m_y, sf_mex_create("y", c6_cv5, 10, 0U, 1U, 0U,
                2, 1, 19), false);
              sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error",
                          0U, 2U, 14, c6_l_y, 14, sf_mex_call
                          (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                           1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
                "message", 1U, 1U, 14, c6_m_y)));
            }

            if (c6_d13 != 0.0) {
              c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] = c6_L
                [((int32_T)c6_b_r + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1];
            } else {
              c6_guard5 = true;
            }
          } else {
            c6_guard5 = true;
          }

          if (c6_guard5) {
            if ((c6_b_r < 120.0) && (c6_b_c > c6_startC)) {
              c6_d14 = c6_varargin_1[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                (c6_b_c - 1.0) - 1)) - 1];
              c6_fb_x = c6_d14;
              c6_gb_x = c6_fb_x;
              c6_g_b = muDoubleScalarIsNaN(c6_gb_x);
              if (c6_g_b) {
                c6_n_y = NULL;
                sf_mex_assign(&c6_n_y, sf_mex_create("y", c6_cv6, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                c6_p_y = NULL;
                sf_mex_assign(&c6_p_y, sf_mex_create("y", c6_cv6, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error",
                            0U, 2U, 14, c6_n_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_p_y)));
              }

              if (c6_d14 != 0.0) {
                if ((c6_b_c > c6_startC) && (c6_b_r > 1.0)) {
                  c6_d18 = c6_varargin_1[((int32_T)(c6_b_r - 1.0) + 120 *
                    ((int32_T)(c6_b_c - 1.0) - 1)) - 1];
                  c6_nb_x = c6_d18;
                  c6_ob_x = c6_nb_x;
                  c6_m_b = muDoubleScalarIsNaN(c6_ob_x);
                  if (c6_m_b) {
                    c6_v_y = NULL;
                    sf_mex_assign(&c6_v_y, sf_mex_create("y", c6_cv10, 10, 0U,
                      1U, 0U, 2, 1, 19), false);
                    c6_w_y = NULL;
                    sf_mex_assign(&c6_w_y, sf_mex_create("y", c6_cv10, 10, 0U,
                      1U, 0U, 2, 1, 19), false);
                    sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI,
                                "error", 0U, 2U, 14, c6_v_y, 14, sf_mex_call
                                (chartInstance->c6_fEmlrtCtx, NULL, "getString",
                                 1U, 1U, 14, sf_mex_call
                                 (chartInstance->c6_fEmlrtCtx, NULL, "message",
                                  1U, 1U, 14, c6_w_y)));
                  }

                  if (c6_d18 != 0.0) {
                    c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                      c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c -
                              1.0) - 1)) - 1];
                    while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                            34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)
                              c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] + 1.0),
                            1, 9601) - 1] < c6_L[((int32_T)c6_b_r + 120 *
                            ((int32_T)c6_b_c - 1)) - 1]) {
                      c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                        c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                        34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)c6_b_r
                        + 120 * ((int32_T)c6_b_c - 1)) - 1] + 1.0), 1, 9601) - 1];
                    }

                    if (c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c
                           - 1.0) - 1)) - 1] != c6_L[((int32_T)(c6_b_r + 1.0) +
                         120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1]) {
                      c6_d_rootj = c6_L[((int32_T)(c6_b_r + 1.0) + 120 *
                                         ((int32_T)(c6_b_c - 1.0) - 1)) - 1];
                      while (c6_P[sf_eml_array_bounds_check(NULL,
                              chartInstance->S, 34U, 0, 0, MAX_uint32_T,
                              (int32_T)(c6_d_rootj + 1.0), 1, 9601) - 1] <
                             c6_d_rootj) {
                        c6_d_rootj = c6_P[sf_eml_array_bounds_check(NULL,
                          chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                          (c6_d_rootj + 1.0), 1, 9601) - 1];
                      }

                      if (c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) -
                          1] > c6_d_rootj) {
                        c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1]
                          = c6_d_rootj;
                      }

                      while (c6_P[sf_eml_array_bounds_check(NULL,
                              chartInstance->S, 34U, 0, 0, MAX_uint32_T,
                              (int32_T)(c6_L[((int32_T)(c6_b_r + 1.0) + 120 *
                                              ((int32_T)(c6_b_c - 1.0) - 1)) - 1]
                                        + 1.0), 1, 9601) - 1] < c6_L[((int32_T)
                              (c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) -
                               1)) - 1]) {
                        c6_j_j = c6_P[sf_eml_array_bounds_check(NULL,
                          chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                          (c6_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                          (c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1];
                        c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                          34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)
                          (c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1))
                          - 1] + 1.0), 1, 9601) - 1] = c6_L[((int32_T)c6_b_r +
                          120 * ((int32_T)c6_b_c - 1)) - 1];
                        c6_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c
                                - 1.0) - 1)) - 1] = c6_j_j;
                      }

                      c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                        0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r +
                        1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1] + 1.0),
                        1, 9601) - 1] = c6_L[((int32_T)c6_b_r + 120 * ((int32_T)
                        c6_b_c - 1)) - 1];
                    }

                    while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                            34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)
                              (c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) -
                               1)) - 1] + 1.0), 1, 9601) - 1] < c6_L[((int32_T)
                            (c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1))
                           - 1]) {
                      c6_j_j = c6_P[sf_eml_array_bounds_check(NULL,
                        chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                        (c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c
                        - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1];
                      c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                        0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r -
                        1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1] + 1.0),
                        1, 9601) - 1] = c6_L[((int32_T)c6_b_r + 120 * ((int32_T)
                        c6_b_c - 1)) - 1];
                      c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c -
                              1.0) - 1)) - 1] = c6_j_j;
                    }

                    c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                      0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r - 1.0)
                      + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1] + 1.0), 1,
                      9601) - 1] = c6_L[((int32_T)c6_b_r + 120 * ((int32_T)
                      c6_b_c - 1)) - 1];
                  } else {
                    c6_guard3 = true;
                  }
                } else {
                  c6_guard3 = true;
                }
              } else {
                c6_guard4 = true;
              }
            } else {
              c6_guard4 = true;
            }
          }

          if (c6_guard4) {
            if ((c6_b_c > c6_startC) && (c6_b_r > 1.0)) {
              c6_d15 = c6_varargin_1[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                (c6_b_c - 1.0) - 1)) - 1];
              c6_hb_x = c6_d15;
              c6_ib_x = c6_hb_x;
              c6_h_b = muDoubleScalarIsNaN(c6_ib_x);
              if (c6_h_b) {
                c6_o_y = NULL;
                sf_mex_assign(&c6_o_y, sf_mex_create("y", c6_cv7, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                c6_r_y = NULL;
                sf_mex_assign(&c6_r_y, sf_mex_create("y", c6_cv7, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error",
                            0U, 2U, 14, c6_o_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_r_y)));
              }

              if (c6_d15 != 0.0) {
                c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c - 1.0)
                         - 1)) - 1];
              } else {
                c6_guard2 = true;
              }
            } else {
              c6_guard2 = true;
            }
          }

          if (c6_guard3) {
            if (c6_b_r > 1.0) {
              c6_d16 = c6_varargin_1[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                c6_b_c - 1)) - 1];
              c6_jb_x = c6_d16;
              c6_kb_x = c6_jb_x;
              c6_j_b = muDoubleScalarIsNaN(c6_kb_x);
              if (c6_j_b) {
                c6_q_y = NULL;
                sf_mex_assign(&c6_q_y, sf_mex_create("y", c6_cv8, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                c6_t_y = NULL;
                sf_mex_assign(&c6_t_y, sf_mex_create("y", c6_cv8, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error",
                            0U, 2U, 14, c6_q_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_t_y)));
              }

              if (c6_d16 != 0.0) {
                c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) -
                  1];
                while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                        34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)c6_b_r
                          + 120 * ((int32_T)c6_b_c - 1)) - 1] + 1.0), 1, 9601) -
                       1] < c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1))
                       - 1]) {
                  c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                    c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                    0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)c6_b_r + 120 *
                    ((int32_T)c6_b_c - 1)) - 1] + 1.0), 1, 9601) - 1];
                }

                if (c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1))
                    - 1] != c6_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                      (c6_b_c - 1.0) - 1)) - 1]) {
                  c6_d_rootj = c6_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                    (c6_b_c - 1.0) - 1)) - 1];
                  while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                          34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d_rootj + 1.0),
                          1, 9601) - 1] < c6_d_rootj) {
                    c6_d_rootj = c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_d_rootj + 1.0), 1, 9601) - 1];
                  }

                  if (c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] >
                      c6_d_rootj) {
                    c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                      c6_d_rootj;
                  }

                  while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                          34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)
                            (c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1))
                           - 1] + 1.0), 1, 9601) - 1] < c6_L[((int32_T)(c6_b_r +
                           1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1]) {
                    c6_j_j = c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L
                      [((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0)
                      - 1)) - 1] + 1.0), 1, 9601) - 1];
                    c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                      0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r + 1.0)
                      + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1] + 1.0), 1,
                      9601) - 1] = c6_L[((int32_T)c6_b_r + 120 * ((int32_T)
                      c6_b_c - 1)) - 1];
                    c6_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c -
                            1.0) - 1)) - 1] = c6_j_j;
                  }

                  c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r + 1.0) +
                    120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) -
                    1] = c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) -
                    1];
                }

                while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                        34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)
                          (c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) - 1] +
                         1.0), 1, 9601) - 1] < c6_L[((int32_T)(c6_b_r - 1.0) +
                        120 * ((int32_T)c6_b_c - 1)) - 1]) {
                  c6_j_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                    34U, 0, 0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r -
                    1.0) + 120 * ((int32_T)c6_b_c - 1)) - 1] + 1.0), 1, 9601) -
                    1];
                  c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r - 1.0) +
                    120 * ((int32_T)c6_b_c - 1)) - 1] + 1.0), 1, 9601) - 1] =
                    c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1];
                  c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) -
                    1] = c6_j_j;
                }

                c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                  MAX_uint32_T, (int32_T)(c6_L[((int32_T)(c6_b_r - 1.0) + 120 *
                  ((int32_T)c6_b_c - 1)) - 1] + 1.0), 1, 9601) - 1] = c6_L
                  [((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1];
              } else {
                c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0)
                         - 1)) - 1];
              }
            } else {
              c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] = c6_L
                [((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1))
                - 1];
            }
          }

          if (c6_guard2) {
            if (c6_b_r > 1.0) {
              c6_d17 = c6_varargin_1[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                c6_b_c - 1)) - 1];
              c6_lb_x = c6_d17;
              c6_mb_x = c6_lb_x;
              c6_l_b = muDoubleScalarIsNaN(c6_mb_x);
              if (c6_l_b) {
                c6_s_y = NULL;
                sf_mex_assign(&c6_s_y, sf_mex_create("y", c6_cv9, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                c6_u_y = NULL;
                sf_mex_assign(&c6_u_y, sf_mex_create("y", c6_cv9, 10, 0U, 1U, 0U,
                  2, 1, 19), false);
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error",
                            0U, 2U, 14, c6_s_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_u_y)));
              }

              if (c6_d17 != 0.0) {
                c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) -
                  1];
              } else {
                c6_guard1 = true;
              }
            } else {
              c6_guard1 = true;
            }
          }

          if (c6_guard1) {
            c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] = c6_label;
            c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
              MAX_uint32_T, (int32_T)(c6_label + 1.0), 1, 9601) - 1] = c6_label;
            c6_label++;
          }
        } else {
          c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] = 0.0;
        }
      }
    }

    c6_d9 = muDoubleScalarRound(c6_label - c6_firstLabel);
    if (c6_d9 < 2.147483648E+9) {
      if (c6_d9 >= -2.147483648E+9) {
        c6_i4 = (int32_T)c6_d9;
      } else {
        c6_i4 = MIN_int32_T;
        sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
      }
    } else if (c6_d9 >= 2.147483648E+9) {
      c6_i4 = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_i4 = 0;
    }

    c6_chunksSizeAndLabels[(int32_T)(c6_startC + 1.0) - 1] = c6_i4;
  }

  c6_c = c6_chunksSizeAndLabels[0];
  while ((real_T)c6_c <= 160.0) {
    for (c6_r = 0; c6_r < 120; c6_r++) {
      c6_b_r = (real_T)c6_r + 1.0;
      c6_d = c6_L[((int32_T)c6_b_r + 120 * (sf_eml_array_bounds_check(NULL,
        chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_c, 1, 160) - 1)) - 1];
      c6_d_x = c6_d;
      c6_f_x = c6_d_x;
      c6_b = muDoubleScalarIsNaN(c6_f_x);
      if (c6_b) {
        c6_y = NULL;
        sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c6_b_y = NULL;
        sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error", 0U, 2U,
                    14, c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
          "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
          "message", 1U, 1U, 14, c6_b_y)));
      }

      if (c6_d != 0.0) {
        if (c6_b_r > 1.0) {
          c6_b_q0 = c6_c;
          c6_b_q1 = 1;
          if ((c6_b_q1 < 0) && (c6_b_q0 > c6_b_q1 + MAX_int32_T)) {
            c6_b_qY = MAX_int32_T;
            sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
          } else if ((c6_b_q1 > 0) && (c6_b_q0 < c6_b_q1 + MIN_int32_T)) {
            c6_b_qY = MIN_int32_T;
            sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
          } else {
            c6_b_qY = c6_b_q0 - c6_b_q1;
          }

          c6_d3 = c6_L[((int32_T)(c6_b_r - 1.0) + 120 *
                        (sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
            0, 0, MAX_uint32_T, c6_b_qY, 1, 160) - 1)) - 1];
          c6_o_x = c6_d3;
          c6_p_x = c6_o_x;
          c6_b_b = muDoubleScalarIsNaN(c6_p_x);
          if (c6_b_b) {
            c6_c_y = NULL;
            sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_b_cv1, 10, 0U, 1U, 0U,
              2, 1, 19), false);
            c6_e_y = NULL;
            sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_b_cv1, 10, 0U, 1U, 0U,
              2, 1, 19), false);
            sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error", 0U,
                        2U, 14, c6_c_y, 14, sf_mex_call
                        (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U, 1U,
                         14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
              "message", 1U, 1U, 14, c6_e_y)));
          }

          if (c6_d3 != 0.0) {
            c6_e_q0 = c6_c;
            c6_e_q1 = 1;
            if ((c6_e_q1 < 0) && (c6_e_q0 > c6_e_q1 + MAX_int32_T)) {
              c6_e_qY = MAX_int32_T;
              sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
            } else if ((c6_e_q1 > 0) && (c6_e_q0 < c6_e_q1 + MIN_int32_T)) {
              c6_e_qY = MIN_int32_T;
              sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
            } else {
              c6_e_qY = c6_e_q0 - c6_e_q1;
            }

            c6_c_i = c6_L[((int32_T)(c6_b_r - 1.0) + 120 *
                           (sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, c6_e_qY, 1, 160) - 1)) - 1];
            c6_j = c6_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1];
            c6_e_i = c6_c_i;
            c6_d8 = c6_e_i;
            while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_d8 + 1.0), 1, 9601) - 1] <
                   c6_d8) {
              c6_d8 = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                0, 0, MAX_uint32_T, (int32_T)(c6_d8 + 1.0), 1, 9601) - 1];
            }

            if (c6_c_i != c6_j) {
              c6_i_i = c6_j;
              c6_rootj = c6_i_i;
              while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                      0, 0, MAX_uint32_T, (int32_T)(c6_rootj + 1.0), 1, 9601) -
                     1] < c6_rootj) {
                c6_rootj = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                  34U, 0, 0, MAX_uint32_T, (int32_T)(c6_rootj + 1.0), 1, 9601) -
                  1];
              }

              if (c6_d8 > c6_rootj) {
                c6_d8 = c6_rootj;
              }

              c6_o_i = c6_j;
              c6_d_root = c6_d8;
              while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                      0, 0, MAX_uint32_T, (int32_T)(c6_o_i + 1.0), 1, 9601) - 1]
                     < c6_o_i) {
                c6_g_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                  34U, 0, 0, MAX_uint32_T, (int32_T)(c6_o_i + 1.0), 1, 9601) - 1];
                c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                  MAX_uint32_T, (int32_T)(c6_o_i + 1.0), 1, 9601) - 1] =
                  c6_d_root;
                c6_o_i = c6_g_j;
              }

              c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                MAX_uint32_T, (int32_T)(c6_o_i + 1.0), 1, 9601) - 1] = c6_d_root;
            }

            c6_j_i = c6_c_i;
            c6_root = c6_d8;
            while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_j_i + 1.0), 1, 9601) - 1] <
                   c6_j_i) {
              c6_d_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                34U, 0, 0, MAX_uint32_T, (int32_T)(c6_j_i + 1.0), 1, 9601) - 1];
              c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                MAX_uint32_T, (int32_T)(c6_j_i + 1.0), 1, 9601) - 1] = c6_root;
              c6_j_i = c6_d_j;
            }

            c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
              MAX_uint32_T, (int32_T)(c6_j_i + 1.0), 1, 9601) - 1] = c6_root;
            c6_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1] = c6_d8;
          }
        }

        if (c6_b_r < 120.0) {
          c6_c_q0 = c6_c;
          c6_c_q1 = 1;
          if ((c6_c_q1 < 0) && (c6_c_q0 > c6_c_q1 + MAX_int32_T)) {
            c6_c_qY = MAX_int32_T;
            sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
          } else if ((c6_c_q1 > 0) && (c6_c_q0 < c6_c_q1 + MIN_int32_T)) {
            c6_c_qY = MIN_int32_T;
            sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
          } else {
            c6_c_qY = c6_c_q0 - c6_c_q1;
          }

          c6_d4 = c6_L[((int32_T)(c6_b_r + 1.0) + 120 *
                        (sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
            0, 0, MAX_uint32_T, c6_c_qY, 1, 160) - 1)) - 1];
          c6_q_x = c6_d4;
          c6_s_x = c6_q_x;
          c6_c_b = muDoubleScalarIsNaN(c6_s_x);
          if (c6_c_b) {
            c6_d_y = NULL;
            sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_cv2, 10, 0U, 1U, 0U, 2,
              1, 19), false);
            c6_g_y = NULL;
            sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_cv2, 10, 0U, 1U, 0U, 2,
              1, 19), false);
            sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error", 0U,
                        2U, 14, c6_d_y, 14, sf_mex_call
                        (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U, 1U,
                         14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
              "message", 1U, 1U, 14, c6_g_y)));
          }

          if (c6_d4 != 0.0) {
            c6_f_q0 = c6_c;
            c6_f_q1 = 1;
            if ((c6_f_q1 < 0) && (c6_f_q0 > c6_f_q1 + MAX_int32_T)) {
              c6_f_qY = MAX_int32_T;
              sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
            } else if ((c6_f_q1 > 0) && (c6_f_q0 < c6_f_q1 + MIN_int32_T)) {
              c6_f_qY = MIN_int32_T;
              sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
            } else {
              c6_f_qY = c6_f_q0 - c6_f_q1;
            }

            c6_d_i = c6_L[((int32_T)(c6_b_r + 1.0) + 120 *
                           (sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, c6_f_qY, 1, 160) - 1)) - 1];
            c6_b_j = c6_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1];
            c6_g_i = c6_d_i;
            c6_d10 = c6_g_i;
            while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_d10 + 1.0), 1, 9601) - 1] <
                   c6_d10) {
              c6_d10 = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d10 + 1.0), 1, 9601) - 1];
            }

            if (c6_d_i != c6_b_j) {
              c6_k_i = c6_b_j;
              c6_b_rootj = c6_k_i;
              while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                      0, 0, MAX_uint32_T, (int32_T)(c6_b_rootj + 1.0), 1, 9601)
                     - 1] < c6_b_rootj) {
                c6_b_rootj = c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                  (c6_b_rootj + 1.0), 1, 9601) - 1];
              }

              if (c6_d10 > c6_b_rootj) {
                c6_d10 = c6_b_rootj;
              }

              c6_p_i = c6_b_j;
              c6_e_root = c6_d10;
              while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
                      0, 0, MAX_uint32_T, (int32_T)(c6_p_i + 1.0), 1, 9601) - 1]
                     < c6_p_i) {
                c6_h_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                  34U, 0, 0, MAX_uint32_T, (int32_T)(c6_p_i + 1.0), 1, 9601) - 1];
                c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                  MAX_uint32_T, (int32_T)(c6_p_i + 1.0), 1, 9601) - 1] =
                  c6_e_root;
                c6_p_i = c6_h_j;
              }

              c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                MAX_uint32_T, (int32_T)(c6_p_i + 1.0), 1, 9601) - 1] = c6_e_root;
            }

            c6_m_i = c6_d_i;
            c6_b_root = c6_d10;
            while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_m_i + 1.0), 1, 9601) - 1] <
                   c6_m_i) {
              c6_e_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                34U, 0, 0, MAX_uint32_T, (int32_T)(c6_m_i + 1.0), 1, 9601) - 1];
              c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                MAX_uint32_T, (int32_T)(c6_m_i + 1.0), 1, 9601) - 1] = c6_b_root;
              c6_m_i = c6_e_j;
            }

            c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
              MAX_uint32_T, (int32_T)(c6_m_i + 1.0), 1, 9601) - 1] = c6_b_root;
            c6_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1] = c6_d10;
          }
        }

        c6_d_q0 = c6_c;
        c6_d_q1 = 1;
        if ((c6_d_q1 < 0) && (c6_d_q0 > c6_d_q1 + MAX_int32_T)) {
          c6_d_qY = MAX_int32_T;
          sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
        } else if ((c6_d_q1 > 0) && (c6_d_q0 < c6_d_q1 + MIN_int32_T)) {
          c6_d_qY = MIN_int32_T;
          sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
        } else {
          c6_d_qY = c6_d_q0 - c6_d_q1;
        }

        c6_d5 = c6_L[((int32_T)c6_b_r + 120 * (sf_eml_array_bounds_check(NULL,
          chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_d_qY, 1, 160) - 1)) - 1];
        c6_r_x = c6_d5;
        c6_t_x = c6_r_x;
        c6_d_b = muDoubleScalarIsNaN(c6_t_x);
        if (c6_d_b) {
          c6_f_y = NULL;
          sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_cv3, 10, 0U, 1U, 0U, 2, 1,
            19), false);
          c6_h_y = NULL;
          sf_mex_assign(&c6_h_y, sf_mex_create("y", c6_cv3, 10, 0U, 1U, 0U, 2, 1,
            19), false);
          sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error", 0U,
                      2U, 14, c6_f_y, 14, sf_mex_call
                      (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U, 1U,
                       14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
            "message", 1U, 1U, 14, c6_h_y)));
        }

        if (c6_d5 != 0.0) {
          c6_g_q0 = c6_c;
          c6_g_q1 = 1;
          if ((c6_g_q1 < 0) && (c6_g_q0 > c6_g_q1 + MAX_int32_T)) {
            c6_g_qY = MAX_int32_T;
            sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
          } else if ((c6_g_q1 > 0) && (c6_g_q0 < c6_g_q1 + MIN_int32_T)) {
            c6_g_qY = MIN_int32_T;
            sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
          } else {
            c6_g_qY = c6_g_q0 - c6_g_q1;
          }

          c6_f_i = c6_L[((int32_T)c6_b_r + 120 * (sf_eml_array_bounds_check(NULL,
            chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_g_qY, 1, 160) - 1)) -
            1];
          c6_c_j = c6_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1];
          c6_h_i = c6_f_i;
          c6_d11 = c6_h_i;
          while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                  0, MAX_uint32_T, (int32_T)(c6_d11 + 1.0), 1, 9601) - 1] <
                 c6_d11) {
            c6_d11 = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
              0, 0, MAX_uint32_T, (int32_T)(c6_d11 + 1.0), 1, 9601) - 1];
          }

          if (c6_f_i != c6_c_j) {
            c6_l_i = c6_c_j;
            c6_c_rootj = c6_l_i;
            while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_c_rootj + 1.0), 1, 9601) - 1] <
                   c6_c_rootj) {
              c6_c_rootj = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                34U, 0, 0, MAX_uint32_T, (int32_T)(c6_c_rootj + 1.0), 1, 9601) -
                1];
            }

            if (c6_d11 > c6_c_rootj) {
              c6_d11 = c6_c_rootj;
            }

            c6_q_i = c6_c_j;
            c6_f_root = c6_d11;
            while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                    0, MAX_uint32_T, (int32_T)(c6_q_i + 1.0), 1, 9601) - 1] <
                   c6_q_i) {
              c6_i_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                34U, 0, 0, MAX_uint32_T, (int32_T)(c6_q_i + 1.0), 1, 9601) - 1];
              c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
                MAX_uint32_T, (int32_T)(c6_q_i + 1.0), 1, 9601) - 1] = c6_f_root;
              c6_q_i = c6_i_j;
            }

            c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
              MAX_uint32_T, (int32_T)(c6_q_i + 1.0), 1, 9601) - 1] = c6_f_root;
          }

          c6_n_i = c6_f_i;
          c6_c_root = c6_d11;
          while (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0,
                  0, MAX_uint32_T, (int32_T)(c6_n_i + 1.0), 1, 9601) - 1] <
                 c6_n_i) {
            c6_f_j = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
              0, 0, MAX_uint32_T, (int32_T)(c6_n_i + 1.0), 1, 9601) - 1];
            c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
              MAX_uint32_T, (int32_T)(c6_n_i + 1.0), 1, 9601) - 1] = c6_c_root;
            c6_n_i = c6_f_j;
          }

          c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
            MAX_uint32_T, (int32_T)(c6_n_i + 1.0), 1, 9601) - 1] = c6_c_root;
          c6_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1] = c6_d11;
        }
      }
    }

    c6_c = c6_chunksSizeAndLabels[sf_eml_array_bounds_check(NULL,
      chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_c, 1, 168) - 1];
  }

  c6_numComponents = 1.0;
  c6_c = 1;
  while ((real_T)c6_c <= 160.0) {
    c6_q0 = c6_c;
    c6_q1 = 1;
    if ((c6_q1 < 0) && (c6_q0 > c6_q1 + MAX_int32_T)) {
      c6_qY = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else if ((c6_q1 > 0) && (c6_q0 < c6_q1 + MIN_int32_T)) {
      c6_qY = MIN_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_qY = c6_q0 - c6_q1;
    }

    c6_h_x = c6_qY;
    c6_i_x = c6_h_x;
    c6_j_x = c6_i_x;
    c6_k_x = c6_j_x;
    c6_b_a = c6_k_x;
    c6_m_x = c6_b_a;
    c6_z = (real_T)c6_m_x / 2.0;
    c6_d2 = muDoubleScalarRound(c6_z);
    if (c6_d2 < 2.147483648E+9) {
      if (c6_d2 >= -2.147483648E+9) {
        c6_i1 = (int32_T)c6_d2;
      } else {
        c6_i1 = MIN_int32_T;
        sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
      }
    } else if (c6_d2 >= 2.147483648E+9) {
      c6_i1 = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_i1 = 0;
    }

    c6_b_z = c6_i1;
    c6_w_x = c6_b_z;
    c6_c_a = c6_w_x;
    c6_i2 = (int64_T)c6_c_a * 60LL;
    if (c6_i2 > 2147483647LL) {
      c6_i2 = 2147483647LL;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else if (c6_i2 < -2147483648LL) {
      c6_i2 = -2147483648LL;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    }

    c6_i_y = (int32_T)c6_i2;
    c6_h_q0 = c6_i_y;
    c6_h_q1 = 1;
    if ((c6_h_q1 < 0) && (c6_h_q0 < MIN_int32_T - c6_h_q1)) {
      c6_h_qY = MIN_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else if ((c6_h_q1 > 0) && (c6_h_q0 > MAX_int32_T - c6_h_q1)) {
      c6_h_qY = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_h_qY = c6_h_q0 + c6_h_q1;
    }

    c6_stripeFirstLabel = c6_h_qY;
    c6_i_q0 = c6_stripeFirstLabel;
    c6_i_q1 = 1;
    if ((c6_i_q1 < 0) && (c6_i_q0 < MIN_int32_T - c6_i_q1)) {
      c6_i_qY = MIN_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else if ((c6_i_q1 > 0) && (c6_i_q0 > MAX_int32_T - c6_i_q1)) {
      c6_i_qY = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_i_qY = c6_i_q0 + c6_i_q1;
    }

    c6_i5 = c6_i_qY;
    c6_j_q0 = c6_stripeFirstLabel;
    c6_k_q0 = c6_c;
    c6_j_q1 = 1;
    if ((c6_j_q1 < 0) && (c6_k_q0 < MIN_int32_T - c6_j_q1)) {
      c6_j_qY = MIN_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else if ((c6_j_q1 > 0) && (c6_k_q0 > MAX_int32_T - c6_j_q1)) {
      c6_j_qY = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_j_qY = c6_k_q0 + c6_j_q1;
    }

    c6_k_q1 = c6_chunksSizeAndLabels[sf_eml_array_bounds_check(NULL,
      chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_j_qY, 1, 168) - 1];
    if ((c6_j_q0 < 0) && (c6_k_q1 < MIN_int32_T - c6_j_q0)) {
      c6_k_qY = MIN_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else if ((c6_j_q0 > 0) && (c6_k_q1 > MAX_int32_T - c6_j_q0)) {
      c6_k_qY = MAX_int32_T;
      sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
    } else {
      c6_k_qY = c6_j_q0 + c6_k_q1;
    }

    c6_i6 = c6_k_qY;
    c6_e_a = c6_i5;
    c6_i_b = c6_i6;
    c6_f_a = c6_e_a;
    c6_k_b = c6_i_b;
    if (c6_f_a > c6_k_b) {
      c6_overflow = false;
    } else {
      c6_overflow = (c6_k_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, true);
    }

    for (c6_r_i = c6_i5; c6_r_i <= c6_i6; c6_r_i++) {
      c6_l_q0 = c6_r_i;
      c6_l_q1 = 1;
      if ((c6_l_q1 < 0) && (c6_l_q0 > c6_l_q1 + MAX_int32_T)) {
        c6_l_qY = MAX_int32_T;
        sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
      } else if ((c6_l_q1 > 0) && (c6_l_q0 < c6_l_q1 + MIN_int32_T)) {
        c6_l_qY = MIN_int32_T;
        sf_data_saturate_error(chartInstance->S, 34U, 0, 0);
      } else {
        c6_l_qY = c6_l_q0 - c6_l_q1;
      }

      if (c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
           MAX_uint32_T, c6_r_i, 1, 9601) - 1] < (real_T)c6_l_qY) {
        c6_P[c6_r_i - 1] = c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
          34U, 0, 0, MAX_uint32_T, (int32_T)(c6_P[c6_r_i - 1] + 1.0), 1, 9601) -
          1];
      } else {
        c6_P[c6_r_i - 1] = c6_numComponents;
        c6_numComponents++;
      }
    }

    c6_c = c6_chunksSizeAndLabels[sf_eml_array_bounds_check(NULL,
      chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_c, 1, 168) - 1];
  }

  for (c6_c_c = 0; c6_c_c < 160; c6_c_c++) {
    c6_d_c = (real_T)c6_c_c + 1.0;
    for (c6_c_r = 0; c6_c_r < 120; c6_c_r++) {
      c6_b_r = (real_T)c6_c_r + 1.0;
      c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_d_c - 1)) - 1] =
        c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
        MAX_uint32_T, (int32_T)(c6_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_d_c -
        1)) - 1] + 1.0), 1, 9601) - 1];
    }
  }
}

static void c6_check_forloop_overflow_error
  (SFc6_flightControlSystemInstanceStruct *chartInstance, boolean_T c6_overflow)
{
  static char_T c6_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c6_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  (void)c6_overflow;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_e_emlrtMCI, "error", 0U, 2U, 14,
              c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
    "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
    "message", 1U, 2U, 14, c6_b_y, 14, c6_c_y)));
}

static void c6_mean(SFc6_flightControlSystemInstanceStruct *chartInstance,
                    real_T c6_x[2400], real_T c6_y[2])
{
  real_T c6_b_x;
  real_T c6_bsum;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  int32_T c6_counts[2];
  int32_T c6_b_i;
  int32_T c6_b_k;
  int32_T c6_b_xi;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  int32_T c6_xblockoffset;
  int32_T c6_xi;
  int32_T c6_xoffset;
  int32_T c6_xpageoffset;
  int32_T c6_ypageoffset;
  boolean_T c6_b;
  boolean_T c6_b1;
  boolean_T c6_b_b;
  boolean_T c6_c_b;
  boolean_T c6_d_b;
  boolean_T c6_e_b;
  (void)chartInstance;
  for (c6_xi = 0; c6_xi < 2; c6_xi++) {
    c6_b_xi = c6_xi;
    c6_xpageoffset = c6_b_xi * 1200 + 1;
    c6_ypageoffset = c6_b_xi + 1;
    c6_ix = c6_xpageoffset - 1;
    c6_iy = c6_ypageoffset - 1;
    c6_b_x = c6_x[c6_ix];
    c6_b = muDoubleScalarIsNaN(c6_b_x);
    if (c6_b) {
      c6_y[c6_iy] = 0.0;
      c6_counts[c6_iy] = 0;
    } else {
      c6_y[c6_iy] = c6_x[c6_ix];
      c6_counts[c6_iy] = 1;
    }

    for (c6_k = 0; c6_k < 1023; c6_k++) {
      c6_xoffset = (c6_xpageoffset + c6_k) + 1;
      c6_ix = c6_xoffset - 1;
      c6_iy = c6_ypageoffset - 1;
      c6_d_x = c6_x[c6_ix];
      c6_c_b = muDoubleScalarIsNaN(c6_d_x);
      if (c6_c_b) {
        c6_d_b = true;
      } else {
        c6_d_b = false;
      }

      if (!c6_d_b) {
        c6_y[c6_iy] += c6_x[c6_ix];
        c6_counts[c6_iy]++;
      }
    }

    c6_xblockoffset = c6_xpageoffset + 1024;
    c6_ix = c6_xblockoffset - 1;
    c6_c_x = c6_x[c6_ix];
    c6_b_b = muDoubleScalarIsNaN(c6_c_x);
    if (c6_b_b) {
      c6_bsum = 0.0;
    } else {
      c6_bsum = c6_x[c6_ix];
      c6_iy = c6_ypageoffset - 1;
      c6_counts[c6_iy]++;
    }

    for (c6_b_k = 0; c6_b_k < 175; c6_b_k++) {
      c6_xoffset = (c6_xblockoffset + c6_b_k) + 1;
      c6_ix = c6_xoffset - 1;
      c6_e_x = c6_x[c6_ix];
      c6_e_b = muDoubleScalarIsNaN(c6_e_x);
      if (c6_e_b) {
        c6_b1 = true;
      } else {
        c6_b1 = false;
      }

      if (!c6_b1) {
        c6_bsum += c6_x[c6_ix];
        c6_iy = c6_ypageoffset - 1;
        c6_counts[c6_iy]++;
      }
    }

    c6_iy = c6_ypageoffset - 1;
    c6_y[c6_iy] += c6_bsum;
  }

  for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
    c6_y[c6_b_i] /= (real_T)c6_counts[c6_b_i];
  }
}

static void c6_toc(SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c6_b_cv1[28] = { 'E', 'l', 'a', 'p', 's', 'e', 'd', ' ', 't',
    'i', 'm', 'e', ' ', 'i', 's', ' ', '%', 'f', ' ', 's', 'e', 'c', 'o', 'n',
    'd', 's', '\\', 'n' };

  static char_T c6_b_cv[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  emlrtTimespec c6_tnow;
  emlrtTimespec c6_tstart;
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  const mxArray *c6_h_y = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_formatSpec;
  real_T c6_tdiff;
  real_T c6_tdiff_nsec;
  real_T c6_tdiff_sec;
  real_T c6_u;
  real_T c6_varargin_1;
  int32_T c6_b_status;
  int32_T c6_status;
  c6_tstart = c6_b_timeKeeper(chartInstance);
  c6_status = emlrtClockGettimeMonotonic(&c6_tnow);
  c6_b_status = c6_status;
  if (c6_b_status != 0) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    c6_e_y = NULL;
    sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_b_status, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_emlrtMCI, "error", 0U, 2U, 14,
                c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "message", 1U, 3U, 14, c6_b_y, 14, c6_c_y, 14, c6_e_y)));
  }

  c6_tdiff_sec = c6_tnow.tv_sec - c6_tstart.tv_sec;
  c6_tdiff_nsec = c6_tnow.tv_nsec - c6_tstart.tv_nsec;
  c6_tdiff = c6_tdiff_sec + c6_tdiff_nsec / 1.0E+9;
  c6_formatSpec = c6_tdiff;
  c6_varargin_1 = c6_formatSpec;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c6_u = 1.0;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_b_cv1, 10, 0U, 1U, 0U, 2, 1, 28),
                false);
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_varargin_1, 0, 0U, 0U, 0U, 0),
                false);
  c6_emlrt_marshallIn(chartInstance, c6_feval(chartInstance, c6_d_y, c6_f_y,
    c6_g_y, c6_h_y), "<output of feval>");
}

static emlrtTimespec c6_b_timeKeeper(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  static char_T c6_b_cv[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 't', 'o', 'c',
    ':', 'c', 'a', 'l', 'l', 'T', 'i', 'c', 'F', 'i', 'r', 's', 't', 'N', 'o',
    'I', 'n', 'p', 'u', 't', 's' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_y = NULL;
  if (!chartInstance->c6_savedTime_not_empty) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_f_emlrtMCI, "error", 0U, 2U, 14,
                c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "message", 1U, 1U, 14, c6_b_y)));
  }

  return chartInstance->c6_savedTime;
}

static real_T c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_a__output_of_feval_, const char_T
  *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_a__output_of_feval_),
    &c6_thisId);
  sf_mex_destroy(&c6_a__output_of_feval_);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_d;
  real_T c6_y;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

const mxArray *sf_c6_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static void c6_init(SFc6_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c6_image[19200], real_T c6_initial_ref[2], real_T *
                    c6_initial_theta)
{
  real_T c6_b_initial_ref[2];
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_j;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_cnt;
  real_T c6_d;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_c_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_j;
  for (c6_b_i = 0; c6_b_i < 19200; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 18U, (real_T)
                      c6_image[c6_b_i]);
  }

  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 0, 0);
  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    c6_initial_ref[c6_i1] = 0.0;
  }

  c6_cnt = 1.0;
  chartInstance->c6_i = 1.0;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  for (c6_c_i = 0; c6_c_i < 120; c6_c_i++) {
    chartInstance->c6_i = 1.0 + (real_T)c6_c_i;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 0, 0, 1);
    for (c6_j = 0; c6_j < 160; c6_j++) {
      c6_b_j = 1.0 + (real_T)c6_j;
      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 0, 1, 1);
      if (!chartInstance->c6_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 15U, 147, 1);
      }

      c6_d = (real_T)c6_image[(sf_eml_array_bounds_check(NULL, chartInstance->S,
        15U, 141, 10, 18U, (int32_T)sf_integer_check(chartInstance->S, 15U, 141U,
        10U, chartInstance->c6_i), 1, 120) + 120 * (sf_eml_array_bounds_check
        (NULL, chartInstance->S, 15U, 141, 10, 18U, (int32_T)sf_integer_check
         (chartInstance->S, 15U, 141U, 10U, c6_b_j), 1, 160) - 1)) - 1];
      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 4U, 0U, 0U, c6_d, 1.0,
                          -1, 0U, c6_d == 1.0))) {
        c6_b_initial_ref[0] = c6_initial_ref[0] + chartInstance->c6_i;
        c6_b_initial_ref[1] = c6_initial_ref[1] + c6_b_j;
        for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
          c6_initial_ref[c6_i5] = c6_b_initial_ref[c6_i5];
        }

        c6_cnt++;
      } else if (!chartInstance->c6_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 15U, 195, 1);
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 0, 1, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 0, 0, 0);
  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    c6_initial_ref[c6_i2] /= c6_cnt;
  }

  chartInstance->c6_dataWrittenToVector[8U] = true;
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 26U, c6_initial_ref[c6_i3]);
  }

  if (!chartInstance->c6_dataWrittenToVector[8U]) {
    sf_read_before_write_error(chartInstance->S, 26U, 15U, 323, 11);
  }

  c6_initial_ref[0] = c6_const_COG_X - c6_initial_ref[0];
  chartInstance->c6_dataWrittenToVector[8U] = true;
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 26U, c6_initial_ref[c6_i4]);
  }

  if (!chartInstance->c6_dataWrittenToVector[8U]) {
    sf_read_before_write_error(chartInstance->S, 26U, 15U, 356, 11);
  }

  c6_initial_ref[1] -= c6_const_COG_Y;
  chartInstance->c6_dataWrittenToVector[8U] = true;
  for (c6_i6 = 0; c6_i6 < 2; c6_i6++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 26U, c6_initial_ref[c6_i6]);
  }

  if (!chartInstance->c6_dataWrittenToVector[8U]) {
    sf_read_before_write_error(chartInstance->S, 26U, 15U, 433, 11);
  }

  c6_y = c6_initial_ref[1];
  c6_x = c6_initial_ref[0];
  c6_a = c6_y;
  c6_b = c6_x;
  c6_b_y = c6_a;
  c6_b_x = c6_b;
  c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
  *c6_initial_theta = c6_mod(chartInstance, c6_r);
  chartInstance->c6_dataWrittenToVector[8U] = true;
  chartInstance->c6_dataWrittenToVector[9U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 30U, *c6_initial_theta);
}

static void c6_sector_form(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_points[2400], real_T c6_prev_theta, real_T *c6_state, real_T c6_ref
  [2], real_T c6_c_MAP[19200])
{
  c6_strel c6_se;
  real_T c6_cutting_dots[2400];
  real_T c6_b_cutting_dots[2];
  real_T c6_center[2];
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_cnt;
  real_T c6_b_j;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_cnt;
  real_T c6_d;
  real_T c6_d1;
  real_T c6_d_x;
  real_T c6_delta;
  real_T c6_dist;
  real_T c6_e_x;
  real_T c6_label;
  real_T c6_pre_dist;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_c_i;
  int32_T c6_d_i;
  int32_T c6_e_i;
  int32_T c6_exitg1;
  int32_T c6_f_i;
  int32_T c6_g_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_j;
  boolean_T c6_seg_image[19200];
  for (c6_b_i = 0; c6_b_i < 2400; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 19U, c6_points[c6_b_i]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 24U, c6_prev_theta);
  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 5, 0);
  c6_tic(chartInstance);
  for (c6_i1 = 0; c6_i1 < 2400; c6_i1++) {
    c6_cutting_dots[c6_i1] = 0.0;
  }

  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    c6_ref[c6_i2] = 0.0;
  }

  chartInstance->c6_dataWrittenToVector[12U] = true;
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 29U, c6_ref[c6_i3]);
  }

  c6_cnt = 0.0;
  for (c6_i4 = 0; c6_i4 < 19200; c6_i4++) {
    c6_c_MAP[c6_i4] = 0.0;
  }

  chartInstance->c6_dataWrittenToVector[13U] = true;
  for (c6_i5 = 0; c6_i5 < 19200; c6_i5++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 31U, c6_c_MAP[c6_i5]);
  }

  chartInstance->c6_i = 1.0;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  c6_c_i = 0;
  do {
    c6_exitg1 = 0;
    if (c6_c_i < 1200) {
      chartInstance->c6_i = 1.0 + (real_T)c6_c_i;
      chartInstance->c6_dataWrittenToVector[4U] = true;
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 0, 1);
      if (!chartInstance->c6_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 44U, 388, 1);
      }

      c6_d = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
        381, 11, 19U, (int32_T)sf_integer_check(chartInstance->S, 44U, 381U, 11U,
        chartInstance->c6_i), 1, 1200) - 1];
      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 4U, 5U, 0U, c6_d, 0.0,
                          -1, 0U, c6_d == 0.0))) {
        c6_exitg1 = 1;
      } else {
        if (!chartInstance->c6_dataWrittenToVector[4U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 44U, 478, 1);
        }

        c6_y = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
          471, 11, 19U, (int32_T)sf_integer_check(chartInstance->S, 44U, 471U,
          11U, chartInstance->c6_i), 1, 1200) + 1199] - c6_const_COG_Y;
        c6_x = c6_const_COG_X - c6_points[sf_eml_array_bounds_check(NULL,
          chartInstance->S, 44U, 496, 11, 19U, (int32_T)sf_integer_check
          (chartInstance->S, 44U, 496U, 11U, chartInstance->c6_i), 1, 1200) - 1];
        c6_a = c6_y;
        c6_b = c6_x;
        c6_b_y = c6_a;
        c6_b_x = c6_b;
        c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
        c6_c_x = c6_mod(chartInstance, c6_r) - c6_prev_theta;
        c6_d_x = c6_c_x;
        c6_e_x = c6_d_x;
        c6_delta = muDoubleScalarAbs(c6_e_x);
        chartInstance->c6_dataWrittenToVector[4U] = true;
        if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 1,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 4U, 5U, 1U,
                            c6_delta, 3.1415926535897931, -1, 4U, c6_delta >
                            3.1415926535897931))) {
          c6_delta = 6.2831853071795862 - c6_delta;
        }

        if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 2,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 4U, 5U, 2U,
                            c6_delta, 0.39269908169872414, -1, 2U, c6_delta <
                            0.39269908169872414))) {
          c6_cnt++;
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 44U, 694, 1);
          }

          c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
            665, 19, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
            44U, 665U, 19U, c6_cnt), 1, 1200) - 1] =
            c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 687,
            11, 19U, (int32_T)sf_integer_check(chartInstance->S, 44U, 687U, 11U,
            chartInstance->c6_i), 1, 1200) - 1];
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 44U, 737, 1);
          }

          c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
            708, 19, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
            44U, 708U, 19U, c6_cnt), 1, 1200) + 1199] =
            c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 730,
            11, 19U, (int32_T)sf_integer_check(chartInstance->S, 44U, 730U, 11U,
            chartInstance->c6_i), 1, 1200) + 1199];
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 44U, 762, 1);
          }

          c6_c_MAP[(sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 751,
                     28, 31U, (int32_T)sf_integer_check(chartInstance->S, 44U,
                      751U, 28U, c6_points[sf_eml_array_bounds_check(NULL,
            chartInstance->S, 44U, 751, 28, 19U, (int32_T)sf_integer_check
            (chartInstance->S, 44U, 751U, 28U, chartInstance->c6_i), 1, 1200) -
                      1]), 1, 120) + 120 * (sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 44U, 751, 28, 31U, (int32_T)
                      sf_integer_check(chartInstance->S, 44U, 751U, 28U,
            c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 751,
            28, 19U, (int32_T)sf_integer_check(chartInstance->S, 44U, 751U, 28U,
            chartInstance->c6_i), 1, 1200) + 1199]), 1, 160) - 1)) - 1] = 1.0;
          chartInstance->c6_dataWrittenToVector[4U] = true;
          chartInstance->c6_dataWrittenToVector[13U] = true;
          for (c6_i17 = 0; c6_i17 < 19200; c6_i17++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 31U,
                              c6_c_MAP[c6_i17]);
          }
        }

        c6_c_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 0, 0);
      c6_exitg1 = 1;
    }
  } while (c6_exitg1 == 0);

  c6_se.__dummy = 0;
  if (!chartInstance->c6_dataWrittenToVector[13U]) {
    sf_read_before_write_error(chartInstance->S, 31U, 44U, 1503, 3);
  }

  for (c6_i6 = 0; c6_i6 < 19200; c6_i6++) {
    chartInstance->c6_MAP[c6_i6] = c6_c_MAP[c6_i6];
  }

  c6_imdilate(chartInstance, chartInstance->c6_MAP, c6_se, c6_c_MAP);
  chartInstance->c6_dataWrittenToVector[13U] = true;
  for (c6_i7 = 0; c6_i7 < 19200; c6_i7++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 31U, c6_c_MAP[c6_i7]);
  }

  c6_pre_dist = rtInf;
  for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
    c6_center[c6_i8] = 1.0;
  }

  c6_b_cnt = c6_cnt;
  c6_i9 = (int32_T)c6_b_cnt;
  sf_mex_lw_for_loop_vector_check(1.0, 1.0, c6_b_cnt, mxDOUBLE_CLASS, c6_i9);
  chartInstance->c6_i = 1.0;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  c6_d_i = 0;
  while (c6_d_i <= c6_i9 - 1) {
    chartInstance->c6_i = 1.0 + (real_T)c6_d_i;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 1, 1);
    if (!chartInstance->c6_dataWrittenToVector[4U]) {
      sf_read_before_write_error(chartInstance->S, 0U, 44U, 1593, 1);
    }

    c6_i11 = sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 1593, 1,
      MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 1593U, 1U,
      chartInstance->c6_i), 1, 1200) - 1;
    for (c6_i13 = 0; c6_i13 < 2; c6_i13++) {
      c6_b_cutting_dots[c6_i13] = c6_cutting_dots[c6_i11 + 1200 * c6_i13] -
        (60.0 + 20.0 * (real_T)c6_i13);
    }

    c6_dist = c6_norm(chartInstance, c6_b_cutting_dots);
    if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 3,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c6_covrtInstance, 4U, 5U, 3U, c6_dist,
                        c6_pre_dist, -1, 2U, c6_dist < c6_pre_dist))) {
      c6_i15 = sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 1670, 1,
        MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 1670U, 1U,
        chartInstance->c6_i), 1, 1200) - 1;
      for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
        c6_center[c6_i16] = c6_cutting_dots[c6_i15 + 1200 * c6_i16];
      }

      c6_pre_dist = c6_dist;
    } else if (!chartInstance->c6_dataWrittenToVector[4U]) {
      sf_read_before_write_error(chartInstance->S, 0U, 44U, 1670, 1);
    }

    c6_d_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 1, 0);
  if (!chartInstance->c6_dataWrittenToVector[13U]) {
    sf_read_before_write_error(chartInstance->S, 31U, 44U, 1731, 3);
  }

  for (c6_i10 = 0; c6_i10 < 19200; c6_i10++) {
    chartInstance->c6_b_MAP[c6_i10] = c6_c_MAP[c6_i10];
  }

  c6_bwlabel(chartInstance, chartInstance->c6_b_MAP, chartInstance->c6_L_image);
  c6_label = chartInstance->c6_L_image[(sf_eml_array_bounds_check(NULL,
    chartInstance->S, 44U, 1747, 34, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 44U, 1747U, 34U, c6_center[0]), 1, 120) + 120 *
    (sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 1747, 34,
    MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 1747U, 34U,
    c6_center[1]), 1, 160) - 1)) - 1];
  for (c6_i12 = 0; c6_i12 < 19200; c6_i12++) {
    c6_seg_image[c6_i12] = (chartInstance->c6_L_image[c6_i12] == c6_label);
  }

  c6_cnt = 0.0;
  for (c6_i14 = 0; c6_i14 < 2400; c6_i14++) {
    c6_cutting_dots[c6_i14] = 0.0;
  }

  chartInstance->c6_i = 1.0;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  for (c6_e_i = 0; c6_e_i < 120; c6_e_i++) {
    chartInstance->c6_i = 1.0 + (real_T)c6_e_i;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 2, 1);
    for (c6_j = 0; c6_j < 160; c6_j++) {
      c6_b_j = 1.0 + (real_T)c6_j;
      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 3, 1);
      if (!chartInstance->c6_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 44U, 1906, 1);
      }

      c6_d1 = (real_T)c6_seg_image[(sf_eml_array_bounds_check(NULL,
        chartInstance->S, 44U, 1896, 14, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 44U, 1896U, 14U, chartInstance->c6_i), 1, 120) + 120 *
        (sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 1896, 14,
        MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 1896U,
        14U, c6_b_j), 1, 160) - 1)) - 1];
      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 4U, 5U, 4U, c6_d1,
                          1.0, -1, 0U, c6_d1 == 1.0))) {
        c6_cnt++;
        if (!chartInstance->c6_dataWrittenToVector[4U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 44U, 1971, 1);
        }

        c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
          1962, 3, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U,
          1962U, 3U, c6_cnt), 1, 1200) - 1] = chartInstance->c6_i;
        c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
          1997, 3, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U,
          1997U, 3U, c6_cnt), 1, 1200) + 1199] = c6_b_j;
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 3, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 2, 0);
  c6_f_i = 0;
  while (c6_f_i <= 2399) {
    c6_f_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c6_g_i = 0;
  while (c6_g_i <= 2399) {
    if (c6_cutting_dots[c6_g_i] == 0.0) {
      c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
        2030, 29, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U,
        2030U, 29U, (real_T)(c6_g_i + 1)), 1, 2400) - 1] = rtNaN;
    }

    c6_g_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c6_mean(chartInstance, c6_cutting_dots, c6_ref);
  chartInstance->c6_dataWrittenToVector[12U] = true;
  for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 29U, c6_ref[c6_i18]);
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 5,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 5U, 5U, c6_cnt, 10.0, -1, 4U, c6_cnt > 10.0))) {
    *c6_state = 1.0;
    chartInstance->c6_dataWrittenToVector[11U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 27U, *c6_state);
  } else {
    *c6_state = 0.0;
    chartInstance->c6_dataWrittenToVector[11U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 27U, *c6_state);
  }

  c6_toc(chartInstance);
}

static void c6_track_generator(SFc6_flightControlSystemInstanceStruct
  *chartInstance, real_T c6_points[2400], real_T c6_prev_point[2], real_T
  c6_ref[2])
{
  static char_T c6_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c6_b_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c6_e_y = NULL;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  real_T c6_cutting_dots[2400];
  real_T c6_R;
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_b_c;
  real_T c6_b_j;
  real_T c6_b_r;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c;
  real_T c6_c_a;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_cnt;
  real_T c6_d;
  real_T c6_d_a;
  real_T c6_d_x;
  real_T c6_d_y;
  real_T c6_delta;
  real_T c6_e_a;
  real_T c6_e_x;
  real_T c6_f_a;
  real_T c6_f_x;
  real_T c6_g_a;
  real_T c6_g_x;
  real_T c6_h_a;
  real_T c6_h_x;
  real_T c6_i_a;
  real_T c6_i_x;
  real_T c6_j_a;
  real_T c6_k_a;
  real_T c6_l_a;
  real_T c6_pre_cnt;
  real_T c6_prev_theta;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_c_i;
  int32_T c6_d_i;
  int32_T c6_e_i;
  int32_T c6_exitg1;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_j;
  boolean_T c6_b_p;
  boolean_T c6_p;
  for (c6_b_i = 0; c6_b_i < 2400; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 21U, c6_points[c6_b_i]);
  }

  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 23U, c6_prev_point[c6_i1]);
  }

  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 9, 0);
  c6_y = c6_prev_point[1] - c6_const_COG_Y;
  c6_x = c6_const_COG_X - c6_prev_point[0];
  c6_a = c6_y;
  c6_b = c6_x;
  c6_b_y = c6_a;
  c6_b_x = c6_b;
  c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
  c6_prev_theta = c6_mod(chartInstance, c6_r);
  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    c6_ref[c6_i2] = 0.0;
  }

  chartInstance->c6_dataWrittenToVector[14U] = true;
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 28U, c6_ref[c6_i3]);
  }

  c6_pre_cnt = 0.0;
  chartInstance->c6_i = 3.0;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  for (c6_c_i = 0; c6_c_i < 31; c6_c_i++) {
    chartInstance->c6_i = 3.0 + (real_T)c6_c_i;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 9, 0, 1);
    for (c6_i4 = 0; c6_i4 < 2400; c6_i4++) {
      c6_cutting_dots[c6_i4] = 0.0;
    }

    c6_cnt = 1.0;
    c6_j = 0;
    do {
      c6_exitg1 = 0;
      if (c6_j < 1200) {
        c6_b_j = 1.0 + (real_T)c6_j;
        covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 9, 1, 1);
        c6_d = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 82U,
          980, 11, 21U, (int32_T)sf_integer_check(chartInstance->S, 82U, 980U,
          11U, c6_b_j), 1, 1200) - 1];
        if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 4U, 9U, 0U, c6_d,
                            0.0, -1, 0U, c6_d == 0.0))) {
          c6_exitg1 = 1;
        } else {
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 82U, 1151, 1);
          }

          c6_c_y = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S,
            82U, 1086, 11, 21U, (int32_T)sf_integer_check(chartInstance->S, 82U,
            1086U, 11U, c6_b_j), 1, 1200) + 1199] - c6_const_COG_Y;
          c6_c_x = c6_const_COG_X - c6_points[sf_eml_array_bounds_check(NULL,
            chartInstance->S, 82U, 1111, 11, 21U, (int32_T)sf_integer_check
            (chartInstance->S, 82U, 1111U, 11U, c6_b_j), 1, 1200) - 1];
          c6_b_a = c6_c_y;
          c6_b_b = c6_c_x;
          c6_d_y = c6_b_a;
          c6_d_x = c6_b_b;
          c6_b_r = muDoubleScalarAtan2(c6_d_y, c6_d_x);
          c6_e_x = c6_mod(chartInstance, c6_b_r) - c6_mod(chartInstance,
            c6_prev_theta + chartInstance->c6_i * 0.17453292519943295);
          c6_f_x = c6_e_x;
          c6_g_x = c6_f_x;
          c6_delta = muDoubleScalarAbs(c6_g_x);
          if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 1,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c6_covrtInstance, 4U, 9U, 1U,
                              c6_delta, 3.1415926535897931, -1, 4U, c6_delta >
                              3.1415926535897931))) {
            c6_delta = 6.2831853071795862 - c6_delta;
          }

          c6_c_a = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S,
            82U, 1276, 11, 21U, (int32_T)sf_integer_check(chartInstance->S, 82U,
            1276U, 11U, c6_b_j), 1, 1200) - 1] - c6_const_COG_X;
          c6_d_a = c6_c_a;
          c6_e_a = c6_d_a;
          c6_f_a = c6_e_a;
          c6_g_a = c6_f_a;
          c6_c = c6_g_a * c6_g_a;
          c6_h_a = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S,
            82U, 1302, 11, 21U, (int32_T)sf_integer_check(chartInstance->S, 82U,
            1302U, 11U, c6_b_j), 1, 1200) + 1199] - c6_const_COG_Y;
          c6_i_a = c6_h_a;
          c6_j_a = c6_i_a;
          c6_k_a = c6_j_a;
          c6_l_a = c6_k_a;
          c6_b_c = c6_l_a * c6_l_a;
          c6_h_x = c6_c + c6_b_c;
          c6_R = c6_h_x;
          c6_i_x = c6_R;
          if (c6_i_x < 0.0) {
            c6_p = true;
          } else {
            c6_p = false;
          }

          c6_b_p = c6_p;
          if (c6_b_p) {
            c6_e_y = NULL;
            sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            c6_f_y = NULL;
            sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_b_cv, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            c6_g_y = NULL;
            sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_b_cv1, 10, 0U, 1U, 0U,
              2, 1, 4), false);
            sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_c_emlrtMCI, "error", 0U,
                        2U, 14, c6_e_y, 14, sf_mex_call
                        (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U, 1U,
                         14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
              "message", 1U, 2U, 14, c6_f_y, 14, c6_g_y)));
          }

          c6_R = muDoubleScalarSqrt(c6_R);
          if (covrtEmlCondEval(chartInstance->c6_covrtInstance, 4U, 9, 0,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c6_covrtInstance, 4U, 9U, 2U,
                                c6_delta, 0.26179938779914941, -1, 2U, c6_delta <
                                0.26179938779914941)) && covrtEmlCondEval
              (chartInstance->c6_covrtInstance, 4U, 9, 1,
               covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                9U, 3U, c6_R, 50.0, -1, 2U, c6_R < 50.0))) {
            covrtEmlMcdcEval(chartInstance->c6_covrtInstance, 4U, 9, 0, true);
            covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 2, true);
            c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S,
              82U, 1445, 19, MAX_uint32_T, (int32_T)sf_integer_check
              (chartInstance->S, 82U, 1445U, 19U, c6_cnt), 1, 1200) - 1] =
              c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 82U,
              1467, 11, 21U, (int32_T)sf_integer_check(chartInstance->S, 82U,
              1467U, 11U, c6_b_j), 1, 1200) - 1];
            c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S,
              82U, 1492, 19, MAX_uint32_T, (int32_T)sf_integer_check
              (chartInstance->S, 82U, 1492U, 19U, c6_cnt), 1, 1200) + 1199] =
              c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 82U,
              1514, 11, 21U, (int32_T)sf_integer_check(chartInstance->S, 82U,
              1514U, 11U, c6_b_j), 1, 1200) + 1199];
            c6_cnt++;
          } else {
            covrtEmlMcdcEval(chartInstance->c6_covrtInstance, 4U, 9, 0, false);
            covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 2, false);
          }

          c6_j++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }
      } else {
        covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 9, 1, 0);
        c6_exitg1 = 1;
      }
    } while (c6_exitg1 == 0);

    if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 3,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c6_covrtInstance, 4U, 9U, 4U, c6_cnt,
                        c6_pre_cnt, -1, 4U, c6_cnt > c6_pre_cnt))) {
      c6_d_i = 0;
      while (c6_d_i <= 2399) {
        c6_d_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c6_e_i = 0;
      while (c6_e_i <= 2399) {
        if (c6_cutting_dots[c6_e_i] == 0.0) {
          c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 82U,
            1607, 29, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
            82U, 1607U, 29U, (real_T)(c6_e_i + 1)), 1, 2400) - 1] = rtNaN;
        }

        c6_e_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c6_mean(chartInstance, c6_cutting_dots, c6_ref);
      chartInstance->c6_dataWrittenToVector[14U] = true;
      for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 28U, c6_ref[c6_i5]);
      }

      c6_pre_cnt = c6_cnt;
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 9, 0, 0);
}

static void c6_c_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_d_cutting_image, const char_T *c6_identifier,
  real_T c6_y[19200])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_d_cutting_image),
                        &c6_thisId, c6_y);
  sf_mex_destroy(&c6_d_cutting_image);
}

static void c6_d_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[19200])
{
  real_T c6_b_dv[19200];
  int32_T c6_b_i;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_b_dv, 1, 0, 0U, 1, 0U, 2, 120,
                160);
  for (c6_b_i = 0; c6_b_i < 19200; c6_b_i++) {
    c6_y[c6_b_i] = c6_b_dv[c6_b_i];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_e_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_refPosition, const char_T *c6_identifier,
  real_T c6_y[2])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_refPosition), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_refPosition);
}

static void c6_f_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[2])
{
  real_T c6_b_dv[2];
  int32_T c6_b_i;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_b_dv, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
    c6_y[c6_b_i] = c6_b_dv[c6_b_i];
  }

  sf_mex_destroy(&c6_u);
}

static emlrtTimespec c6_g_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c6_b_savedTime, const char_T *c6_identifier, boolean_T *c6_svPtr)
{
  emlrtMsgIdentifier c6_thisId;
  emlrtTimespec c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_savedTime),
    &c6_thisId, c6_svPtr);
  sf_mex_destroy(&c6_b_savedTime);
  return c6_y;
}

static emlrtTimespec c6_h_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_u,
   const emlrtMsgIdentifier *c6_parentId, boolean_T *c6_svPtr)
{
  static const char_T *c6_fieldNames[2] = { "tv_sec", "tv_nsec" };

  emlrtMsgIdentifier c6_thisId;
  emlrtTimespec c6_y;
  c6_thisId.fParent = c6_parentId;
  c6_thisId.bParentIsCell = false;
  if (mxIsEmpty(c6_u)) {
    *c6_svPtr = false;
  } else {
    *c6_svPtr = true;
    sf_mex_check_struct(c6_parentId, c6_u, 2, c6_fieldNames, 0U, NULL);
    c6_thisId.fIdentifier = "tv_sec";
    c6_y.tv_sec = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c6_u, "tv_sec", "tv_sec", 0)), &c6_thisId);
    c6_thisId.fIdentifier = "tv_nsec";
    c6_y.tv_nsec = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c6_u, "tv_nsec", "tv_nsec", 0)), &c6_thisId);
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static uint8_T c6_i_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_flightControlSystem, const
  char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_flightControlSystem), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_flightControlSystem);
  return c6_y;
}

static uint8_T c6_j_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
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

static uint32_T c6_k_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_c6_flightControlSystem, const char_T
  *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  uint32_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_c6_flightControlSystem), &c6_thisId);
  sf_mex_destroy(&c6_b_is_c6_flightControlSystem);
  return c6_y;
}

static uint32_T c6_l_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint32_T c6_b_u;
  uint32_T c6_y;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b_u, 1, 7, 0U, 0, 0U, 0);
  c6_y = c6_b_u;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_m_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_dataWrittenToVector, const char_T
  *c6_identifier, boolean_T c6_y[15])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_dataWrittenToVector),
                        &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_dataWrittenToVector);
}

static void c6_n_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[15])
{
  int32_T c6_b_i;
  boolean_T c6_bv[15];
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv, 1, 11, 0U, 1, 0U, 1, 15);
  for (c6_b_i = 0; c6_b_i < 15; c6_b_i++) {
    c6_y[c6_b_i] = c6_bv[c6_b_i];
  }

  sf_mex_destroy(&c6_u);
}

static const mxArray *c6_o_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  sf_mex_assign(&c6_y, c6_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), true);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_p_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_u,
   const emlrtMsgIdentifier *c6_parentId)
{
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  (void)c6_parentId;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_duplicatearraysafe(&c6_u), true);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_init_sf_message_store_memory
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_chart_data_browse_helper(SFc6_flightControlSystemInstanceStruct
  *chartInstance, int32_T c6_ssIdNumber, const mxArray **c6_mxData, uint8_T
  *c6_isValueTooBig)
{
  real_T c6_d;
  real32_T c6_f;
  *c6_mxData = NULL;
  *c6_mxData = NULL;
  *c6_isValueTooBig = 0U;
  switch (c6_ssIdNumber) {
   case 13U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      &chartInstance->c6_takeOffFlag, 0, 0U, 0U, 0U, 0), false);
    break;

   case 14U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      *chartInstance->c6_refPosition, 0, 0U, 1U, 0U, 2, 1, 2), false);
    break;

   case 26U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      *chartInstance->c6_bin_image, 11, 0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 27U:
    c6_f = *chartInstance->c6_Z;
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &c6_f, 1, 0U, 0U, 0U, 0),
                  false);
    break;

   case 47U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", *chartInstance->c6_dots, 0,
      0U, 1U, 0U, 2, 1200, 2), false);
    break;

   case 51U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_isLine,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 52U:
    *c6_isValueTooBig = 1U;
    break;

   case 70U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_i, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 72U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_COG_X, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 73U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_COG_Y, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 71U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", chartInstance->c6_tempPoint,
      0, 0U, 1U, 0U, 2, 1, 2), false);
    break;

   case 75U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      *chartInstance->c6_prev_points, 0, 0U, 1U, 0U, 2, 3, 2), false);
    break;

   case 77U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_k1, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 78U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_k2, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 79U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_k3, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 103U:
    c6_d = *chartInstance->c6_ladingFlag;
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &c6_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 25U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_theta, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 118U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      *chartInstance->c6_weightMeanPoint, 0, 0U, 1U, 0U, 2, 1, 2), false);
    break;
  }
}

static const mxArray *c6_feval(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_input0, const mxArray *c6_input1, const
  mxArray *c6_input2, const mxArray *c6_input3)
{
  const mxArray *c6_ = NULL;
  c6_ = NULL;
  sf_mex_assign(&c6_, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL, "feval", 1U,
    4U, 14, sf_mex_dup(c6_input0), 14, sf_mex_dup(c6_input1), 14, sf_mex_dup
    (c6_input2), 14, sf_mex_dup(c6_input3)), false);
  sf_mex_destroy(&c6_input0);
  sf_mex_destroy(&c6_input1);
  sf_mex_destroy(&c6_input2);
  sf_mex_destroy(&c6_input3);
  return c6_;
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
  chartInstance->c6_refPosition = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_bin_image = (boolean_T (*)[19200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c6_Z = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_dots = (real_T (*)[2400])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c6_c_cutting_image = (real_T (*)[19200])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c6_prev_points = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c6_ladingFlag = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c6_weightMeanPoint = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c6_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2233975088U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4057658977U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3878847537U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4123205636U);
}

mxArray *sf_c6_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.time.CoderTimeAPI"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Morphop_flat_tbb_Buildable"));
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
  mxArray *incompatibleSymbol = mxCreateString("dilate_flat_real64_tbb");
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
    "eNrNls1O3DAQx50VrED9WqkHxC3i2K2qLYeq7aUBJNQFVl3aVXtJFUx2krVI7MgZvm48Rh+nj9R"
    "HqJ0EurhRsyJWwZLj/C3NxL+xxxPiDEdEtaeqHz0mpKvGFdU7pGzLlXZUf1KN5fzSzbyrOl5moO"
    "dzGQ6nauQ0LTQ9vRjySBT+35I//rs1/p05/6vVfNl+fWhnv+dpe2/OfqmBr1fp8BSR8ThgKY2hi"
    "tN1vO6P5+VCPI8MHq0lRGORM2SC33DcO8/V94V4nhk8Wp8Di2c4AsrHgnG0xLPiteM5LOwHDTzO"
    "LR6HMGv70Xb9w7/s69bfNfZDa5YfMA4PhIO8uHOeID2BT1G0m9DYYp605Pl5uBDPqsGjNUKalRl"
    "CHg4PebfQOVs2eLTGGSC1xtFryVF+/y77ktMzmE5YWSwrPzPn33XYMepwZy4fE3WLZDXrqePpGD"
    "y9axgPvGI8ijwbdeFHQ1xiIy5a77z3x1LEkqbuLksg90dbk4Otbf/z5mDzNfVRiORYXPj5jEqY+"
    "qGYgqyeCTv2++VrX513kJwmfh9ViJVOs8TXr/sAGchXactz41o5N+OG+LhGfNzing1oiOwMgvBN"
    "ECW6CO4IjlIkXy5zlex28mLjv/CtG3zrJV89mNX7qyXf1X5h/7GBb83gWyv5OJwHKGl4EsTAQdL"
    "in8wO18DKvjVxPTe4tJ5SpN8kQwQ+EV8hRCFv7ddv1QGjoQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sud5dIsLI1cFuZ6rc0EqueH";
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
  const char* encStrCodegen [35] = {
    "eNrtWk9vG8cVX9KUKqdxwqRBgwAGshBgyI0NVU5QuxESRxIlImyoSjEppwlYMMPdt+SUuzPbmVl",
    "KuvmYSxD0UgS9tMfe8hXyEfIxip567Sl9s7uUqeHyPx2rSBZYkrP75s37vX8zb4ZWrnJo4fUS3v",
    "+6bVmr+L2Gd95KrpW0nRu4k+cFayNtf4mdWBQcE0ECaY29GAngEUjuR4pyVmEezySjzAMBzEHak",
    "As1ipukQeRT1i1HzNH85Ccd6nRqHR757h72Je4R88+RWxipY+SzTwU4qgzgqo7gUbtT9kn7QmKh",
    "TksdcLoyCsZBkKBqUajFkoeRr2jow8EZOBUmFUGJ5VPZaoooKKmzkTA1UlnrE/Ig9ClhmWg7RNY",
    "gRAUrOAld/DyKFIIyyZwOEWoPOqQHskq7MU/OwORJJb5oUUYUF5T4B4Ff0h2HZTv2UZ5D7oI/Ri",
    "Eo254A0g05ZWq0/WtlRHrASMuHfWhF7dHcavDnSBv/MYVTECP15pV4DwRpwxEbOWiskIOz2FoXX",
    "jJMpmgAj4nYddB+EtyR3oueI2sE7QR17DGKDGKQFVkXtIfqHcktCiraMyeFTBQkxpaTyGJuBz0Y",
    "Z4ULbmWHlYjvy5FkdR5WoQd+zHWfKDKeLOGaTScldescFazde3Q0RIyi4VOyEmcuzTRXzyCI887",
    "vMbFcpnQiqXhQQufdr1aHXw+TVZgC4REHsrKAIFQC6ixW72huLpXa9kiIUqlYvCzixEMmUVnSi9",
    "j+KRdd1MmYJPIUgrboSMJAttGWGAknEoNmHJm25SQ6hzgdcHWCoT4cYtggbYZOpE5tuxh3ParO9",
    "0E6goYZVo0w6jANHWiHOg/hhHUZP2VlwYNamuMT9QKgtxHBKGvvYf4S52UcPcsUej7bsp7OZy9O",
    "MZ/1+5nftwf45DL4WAPfmv63A/TX85fpV4xx8/1n+kr77wz0v2GMVzD6a7oi3l9/8OAvf/3qm3/",
    "/97PW479H3e9N/KYcuSE5clZ//OKN2dYBL6Xtm/2EexFAvSG/1bQfDshVyOD/+gD/YtqWkfsbty",
    "KrlXtOOfrsvnC2DjBXfBjz+/zF8fLeMOTtP7d15kdvi/1UOBU3XaDoNomSadu05+oEfVxPnyfXf",
    "z5YrP/vdkx/KEzAV0zbTqQUBkmTBhiXhj8/Pzx3p8LzcwOPbgvwjrmMU+VQfD43PE/+OBWelw08",
    "un0KtN1Rh0DYsV42LQnP2s5ieD7eMfNGYUL/Iv6iS7PHovJXhvpnyb9q2GM1Xk9WKYMrgsN6a+4",
    "4UaQLR56nC5slxsmCeL79eCo81w08uq0gCJMIsa4OHuvdqfxsxcCj26oD8Qp5OTiKC+IYXm9Max",
    "eJJaY7UARpPp3cbOuG/EA8+phFwgx5svDkDTzFPpgd2Im/P/d2ljEvfD1BL21DL7pd2m4cC97Gi",
    "sSOl6aNw916dXev8ejtrbfvkYbi3G/xs4bEZRK4DQfX7CL99GmrcSf5eYfqUoQRv3FHV6bYxpKz",
    "oX9+hAtgEJvBgn5jL8Vvjifoxzb0Y8d5tkl0NQBN537T8/UkiIWcEtyvnUsM9uXExfoPgu8NA98",
    "bCb5sYEvNXwvie/LRzrzrcMTH4LSpBHG6zTYwECReky0H19ZS7DYJ1y8MXLrtEkU+EVQpYHX+GB",
    "zFxZC95q2nZu1n/dTvSvTL/QjxTbNPsjJnv2sL7sv8UP0WxTfrftFVox9X/1kGffEK41h0H29W+",
    "m9/Np4+b8pXmG29/Mu0/Te8eetPOEnVahX38qlIuhO7yw6ESKcwK0ie1eFs8IgnfXryqGoNP62n",
    "22KXn1a5E8/2NRWfFhlPq8DaqjPCj25MwLc6Il5nyX//zI2f989yl/1Wt98jdkeA9/56QJRPWtv",
    "SCwXtEQW3N6R3FAI7ihW9d46a3ri7ccs9ZySgzq14n1Ofa9za3t6+t/XOxq/WH274xKWsrWvvjf",
    "d+TR7aVNoueJSBe9duRUq3GVe23uy2KbOxFrTjoz/P56d2zHHT7gtk9yWy+8XApuzTbrqU+LwtN",
    "0+Y5pWIuA8+IOGmIwDJ0tbt8RInVCgISpZ4VCw3FxliDGiGo15wcevRdnLmWyvvU9JmXCrqyI27",
    "D95B1k78PhIQw3Qv3usBNl94YZr19ZtGntHtC31tO67YTvDrQ6cjEZ/MWPPW5fr0RDyn+emLaz/",
    "lgcE88P6i66AJeeB7w/66vZQ8cP9enAYCIAzLQCocH+ZPBJ/yyHYIs4kv+TMPx6nq3ZuG3m6OiM",
    "f+QXtWPfj/EI9PVmaLx36eenhx1F3qUN/NOPVMX1eBeFlv0/G/K4xfRxTGrNdmmWf/kZ8N56tp+",
    "9X4nA8RVtyzOtcn14ckHKy/8+PlX1tQ/tyUdf5rhl+9Fv+FI2PzYk458mm/P0yQY92QYz0+FxdE",
    "7xE1fcwKTQzt5P9OhlTzyXVtyrhbM+RaS88Pmtzz5hm3MKVdXjHGfWVg3Kaj/waFi5IF/ONBf17",
    "NPRv/HpxfnkV8TuvfWftzDvGdyMec3AwF9Ggkm+HF+eK8/j3pfKBoyKFvM8auWn34P+8T1uQ=",
    ""
  };

  static char newstr [2549] = "";
  newstr[0] = '\0';
  for (i = 0; i < 35; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c6_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c6_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2436317080U));
  ssSetChecksum1(S,(3937374102U));
  ssSetChecksum2(S,(1449286393U));
  ssSetChecksum3(S,(4285232543U));
}

static void mdlRTW_c6_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
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
  chartInstance->chartInfo.isEMLChart = 0;
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
