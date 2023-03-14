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
static emlrtMCInfo c6_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c6_b_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c6_c_emlrtMCI = { 88,/* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c6_d_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c6_e_emlrtMCI = { 83,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
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
static void initSimStructsc6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_enter_atomic_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_new_track_generation(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static real_T c6_mod(SFc6_flightControlSystemInstanceStruct *chartInstance,
                     real_T c6_x);
static void c6_mean(SFc6_flightControlSystemInstanceStruct *chartInstance,
                    real_T c6_x[2400], real_T c6_y[2]);
static void c6_imdilate(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_A[19200], c6_strel c6_se, real_T c6_b_B[19200]);
static void c6_bwlabel(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_varargin_1[19200], real_T c6_b_L[19200]);
static void c6_check_forloop_overflow_error
  (SFc6_flightControlSystemInstanceStruct *chartInstance, boolean_T c6_overflow);
static void c6_b_mean(SFc6_flightControlSystemInstanceStruct *chartInstance,
                      real_T c6_x[800], real_T c6_y[2]);
static void c6_init(SFc6_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c6_image[19200], real_T c6_initial_ref[2], real_T *
                    c6_initial_theta);
static void c6_sector_form(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_points[2400], real_T c6_prev_theta, real_T *c6_state, real_T c6_ref
  [2], real_T c6_c_MAP[19200], real_T *c6_segFlag);
static void c6_means_circle(SFc6_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c6_image[19200], real_T c6_dot[2], real_T c6_point[2]);
static void c6_track_generator(SFc6_flightControlSystemInstanceStruct
  *chartInstance, real_T c6_points[2400], real_T c6_prev_point[2], real_T
  c6_ref[2]);
static real_T c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_arc, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
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
static uint8_T c6_g_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_flightControlSystem, const
  char_T *c6_identifier);
static uint8_T c6_h_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static uint32_T c6_i_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_c6_flightControlSystem, const char_T
  *c6_identifier);
static uint32_T c6_j_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_k_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_dataWrittenToVector, const char_T
  *c6_identifier, boolean_T c6_y[20]);
static void c6_l_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[20]);
static const mxArray *c6_m_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier);
static const mxArray *c6_n_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_u,
   const emlrtMsgIdentifier *c6_parentId);
static void c6_init_sf_message_store_memory
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_chart_data_browse_helper(SFc6_flightControlSystemInstanceStruct
  *chartInstance, int32_T c6_ssIdNumber, const mxArray **c6_mxData, uint8_T
  *c6_isValueTooBig);
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

  chartInstance->c6_temp = 0.0;
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
      (*chartInstance->c6_wieghtMeanPoint)[c6_i3] = 0.0;
    }
  }

  if (sf_get_output_port_reusable(chartInstance->S, 4) == 0) {
    *chartInstance->c6_arc = 0.0;
  }

  if (sf_get_output_port_reusable(chartInstance->S, 5) == 0) {
    *chartInstance->c6_seg = 0.0;
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 2U,
                    chartInstance->c6_takeOffFlag);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                    chartInstance->c6_isLine);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                      chartInstance->c6_tempPoint[c6_i4]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U, chartInstance->c6_temp);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U, chartInstance->c6_theta);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 16U,
                    chartInstance->c6_COG_X);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 17U,
                    chartInstance->c6_COG_Y);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 18U, chartInstance->c6_k1);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 19U, chartInstance->c6_k2);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 20U, chartInstance->c6_k3);
  for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                      (*chartInstance->c6_refPosition)[c6_i5]);
  }

  for (c6_i6 = 0; c6_i6 < 19200; c6_i6++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 12U,
                      (*chartInstance->c6_c_cutting_image)[c6_i6]);
  }

  for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 13U,
                      (*chartInstance->c6_wieghtMeanPoint)[c6_i7]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 14U, *chartInstance->c6_arc);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 15U, *chartInstance->c6_seg);
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
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(15, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", chartInstance->c6_arc, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", *chartInstance->c6_c_cutting_image,
    0, 0U, 1U, 0U, 2, 120, 160), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", *chartInstance->c6_refPosition, 0,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", chartInstance->c6_seg, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", *chartInstance->c6_wieghtMeanPoint,
    0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &chartInstance->c6_i, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &chartInstance->c6_isLine, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  c6_i_y = NULL;
  sf_mex_assign(&c6_i_y, sf_mex_create("y", &chartInstance->c6_takeOffFlag, 0,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 7, c6_i_y);
  c6_j_y = NULL;
  sf_mex_assign(&c6_j_y, sf_mex_create("y", &chartInstance->c6_temp, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c6_y, 8, c6_j_y);
  c6_k_y = NULL;
  sf_mex_assign(&c6_k_y, sf_mex_create("y", chartInstance->c6_tempPoint, 0, 0U,
    1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c6_y, 9, c6_k_y);
  c6_l_y = NULL;
  sf_mex_assign(&c6_l_y, sf_mex_create("y", &chartInstance->c6_theta, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c6_y, 10, c6_l_y);
  c6_m_y = NULL;
  sf_mex_assign(&c6_m_y, sf_mex_create("y",
    &chartInstance->c6_is_active_c6_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_y, 11, c6_m_y);
  c6_n_y = NULL;
  sf_mex_assign(&c6_n_y, sf_mex_create("y",
    &chartInstance->c6_is_c6_flightControlSystem, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 12, c6_n_y);
  c6_o_y = NULL;
  sf_mex_assign(&c6_o_y, sf_mex_create("y",
    &chartInstance->c6_is_new_track_generation, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 13, c6_o_y);
  c6_p_y = NULL;
  sf_mex_assign(&c6_p_y, sf_mex_create("y",
    chartInstance->c6_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 20), false);
  sf_mex_setcell(c6_y, 14, c6_p_y);
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
  boolean_T c6_bv[20];
  c6_u = sf_mex_dup(c6_st);
  *chartInstance->c6_arc = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 0)), "arc");
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
                        "cutting_image", chartInstance->c6_dv);
  for (c6_b_i = 0; c6_b_i < 19200; c6_b_i++) {
    (*chartInstance->c6_c_cutting_image)[c6_b_i] = chartInstance->c6_dv[c6_b_i];
  }

  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
                        "refPosition", c6_dv1);
  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    (*chartInstance->c6_refPosition)[c6_i1] = c6_dv1[c6_i1];
  }

  *chartInstance->c6_seg = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 3)), "seg");
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 4)),
                        "wieghtMeanPoint", c6_dv2);
  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    (*chartInstance->c6_wieghtMeanPoint)[c6_i2] = c6_dv2[c6_i2];
  }

  chartInstance->c6_i = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 5)), "i");
  chartInstance->c6_isLine = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 6)), "isLine");
  chartInstance->c6_takeOffFlag = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 7)), "takeOffFlag");
  chartInstance->c6_temp = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 8)), "temp");
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 9)),
                        "tempPoint", c6_dv3);
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    chartInstance->c6_tempPoint[c6_i3] = c6_dv3[c6_i3];
  }

  chartInstance->c6_theta = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 10)), "theta");
  chartInstance->c6_is_active_c6_flightControlSystem = c6_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 11)),
     "is_active_c6_flightControlSystem");
  chartInstance->c6_is_c6_flightControlSystem = c6_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 12)),
     "is_c6_flightControlSystem");
  chartInstance->c6_is_new_track_generation = c6_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 13)),
     "is_new_track_generation");
  c6_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 14)),
                        "dataWrittenToVector", c6_bv);
  for (c6_i4 = 0; c6_i4 < 20; c6_i4++) {
    chartInstance->c6_dataWrittenToVector[c6_i4] = c6_bv[c6_i4];
  }

  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 15)), "setSimStateSideEffectsInfo"), true);
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
  real_T c6_b_refPosition[2];
  real_T c6_b_theta;
  real_T c6_c_theta;
  int32_T c6_b_i;
  int32_T c6_i1;
  int32_T c6_i10;
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
  boolean_T c6_bv1[19200];
  boolean_T c6_b_out;
  boolean_T c6_guard1 = false;
  boolean_T c6_out;
  c6_set_sim_state_side_effects_c6_flightControlSystem(chartInstance);
  chartInstance->c6_JITTransitionAnimation[0] = 0U;
  chartInstance->c6_JITTransitionAnimation[1] = 0U;
  chartInstance->c6_JITTransitionAnimation[2] = 0U;
  chartInstance->c6_JITTransitionAnimation[3] = 0U;
  chartInstance->c6_JITTransitionAnimation[4] = 0U;
  chartInstance->c6_JITTransitionAnimation[5] = 0U;
  chartInstance->c6_JITTransitionAnimation[6] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 10U,
                    *chartInstance->c6_ladingFlag);
  for (c6_b_i = 0; c6_b_i < 6; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 9U,
                      (*chartInstance->c6_prev_points)[c6_b_i]);
  }

  for (c6_i1 = 0; c6_i1 < 2400; c6_i1++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 8U,
                      (*chartInstance->c6_dots)[c6_i1]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 7U, (real_T)
                    *chartInstance->c6_Z);
  for (c6_i2 = 0; c6_i2 < 19200; c6_i2++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 6U, (real_T)
                      (*chartInstance->c6_bin_image)[c6_i2]);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  if (chartInstance->c6_is_active_c6_flightControlSystem == 0U) {
    chartInstance->c6_is_active_c6_flightControlSystem = 1U;
    chartInstance->c6_JITTransitionAnimation[0U] = 1U;
    chartInstance->c6_is_c6_flightControlSystem = c6_IN_take_off;
    chartInstance->c6_takeOffFlag = 0.0;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 2U,
                      chartInstance->c6_takeOffFlag);
    for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
      (*chartInstance->c6_refPosition)[c6_i3] = 0.0;
    }

    chartInstance->c6_dataWrittenToVector[1U] = true;
    for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                        (*chartInstance->c6_refPosition)[c6_i4]);
    }
  } else {
    switch (chartInstance->c6_is_c6_flightControlSystem) {
     case c6_IN_new_track_generation:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 2, 0,
                        c6_IN_new_track_generation);
      c6_new_track_generation(chartInstance);
      break;

     case c6_IN_straight_line_reference_generation:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 2, 0,
                        c6_IN_straight_line_reference_generation);
      c6_straight_line_reference_generation(chartInstance);
      break;

     case c6_IN_take_off:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 2, 0,
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
        for (c6_i7 = 0; c6_i7 < 19200; c6_i7++) {
          c6_bv1[c6_i7] = (*chartInstance->c6_bin_image)[c6_i7];
        }

        c6_init(chartInstance, c6_bv1, c6_b_refPosition, &c6_c_theta);
        for (c6_i9 = 0; c6_i9 < 2; c6_i9++) {
          (*chartInstance->c6_refPosition)[c6_i9] = c6_b_refPosition[c6_i9];
        }

        chartInstance->c6_dataWrittenToVector[1U] = true;
        for (c6_i10 = 0; c6_i10 < 2; c6_i10++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                            (*chartInstance->c6_refPosition)[c6_i10]);
        }

        chartInstance->c6_theta = c6_c_theta;
        chartInstance->c6_dataWrittenToVector[7U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U,
                          chartInstance->c6_theta);
      }
      break;

     case c6_IN_take_off_complete:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 2, 0,
                        c6_IN_take_off_complete);
      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        sf_read_before_write_error(chartInstance->S, 11U, 81U, 1, 11);
      }

      c6_guard1 = false;
      if (covrtEmlCondEval(chartInstance->c6_covrtInstance, 5U, 3, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 5U, 3U, 0U,
                            (*chartInstance->c6_refPosition)[0], 0.0, -1, 4U,
                            (*chartInstance->c6_refPosition)[0] > 0.0))) {
        if (covrtEmlCondEval(chartInstance->c6_covrtInstance, 5U, 3, 1,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c6_covrtInstance, 5U, 3U, 1U,
                              (*chartInstance->c6_refPosition)[1], 0.0, -1, 4U,
                              (*chartInstance->c6_refPosition)[1] > 0.0))) {
          covrtEmlMcdcEval(chartInstance->c6_covrtInstance, 5U, 3, 0, true);
          covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 3, 0, true);
          c6_out = true;
        } else {
          c6_guard1 = true;
        }
      } else {
        if (!chartInstance->c6_dataWrittenToVector[1U]) {
          sf_read_before_write_error(chartInstance->S, 11U, 81U, 23, 11);
        }

        c6_guard1 = true;
      }

      if (c6_guard1) {
        covrtEmlMcdcEval(chartInstance->c6_covrtInstance, 5U, 3, 0, false);
        covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 3, 0, false);
        c6_out = false;
      }

      if (c6_out) {
        chartInstance->c6_JITTransitionAnimation[3U] = 1U;
        chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
        chartInstance->c6_is_c6_flightControlSystem =
          c6_IN_straight_line_reference_generation;
        c6_enter_atomic_straight_line_reference_generation(chartInstance);
      } else {
        for (c6_i5 = 0; c6_i5 < 19200; c6_i5++) {
          c6_bv[c6_i5] = (*chartInstance->c6_bin_image)[c6_i5];
        }

        c6_init(chartInstance, c6_bv, c6_b_refPosition, &c6_b_theta);
        for (c6_i6 = 0; c6_i6 < 2; c6_i6++) {
          (*chartInstance->c6_refPosition)[c6_i6] = c6_b_refPosition[c6_i6];
        }

        chartInstance->c6_dataWrittenToVector[1U] = true;
        for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                            (*chartInstance->c6_refPosition)[c6_i8]);
        }

        chartInstance->c6_theta = c6_b_theta;
        chartInstance->c6_dataWrittenToVector[7U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U,
                          chartInstance->c6_theta);
      }
      break;

     default:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 1U, 2, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c6_is_c6_flightControlSystem = c6_IN_NO_ACTIVE_CHILD;
      break;
    }
  }

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

  static const int32_T c6_condTxtEndIdx[2] = { 19, 41 };

  static const int32_T c6_condTxtStartIdx[2] = { 1, 23 };

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
    129U);
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
                  0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U,
                     "track_generator", 0, -1, 1622);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 964, 983, 1184,
                    1243);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 1U, 1184, 1197, -1,
                    1243);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 2U, 1284, 1322, -1,
                    1453);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 3U, 1471, 1487, -1,
                    1610);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 857, 869, 1619);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 1U, 925, 941, 1461);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 0U, 967,
    983, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 1U, 1187,
    1197, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 2U, 1288,
    1322, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 9U, 3U, 1474,
    1487, -1, 4U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 5U, 1U, 0U, 6U, 0U,
                  0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, "sector_form",
                     0, -1, 2440);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, 342, 361, 500,
                    551);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 1U, 500, 513, -1,
                    551);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 2U, 561, 599, -1,
                    763);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 3U, 1021, 1039, -1,
                    1108);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 4U, 1152, 1165,
                    1183, 1208);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 5U, 1884, 1906,
                    1950, 1973);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, 311, 327, 767);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 1U, 949, 962, 1112);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 0U, 345,
    361, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 1U, 503,
    513, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 2U, 565,
    599, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 3U, 1024,
    1039, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 5U, 5U, 1887,
    1906, -1, 4U);
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
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 0U, 151,
    164, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 1U, 221,
    234, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 2U, 287,
    303, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 3U, 356,
    372, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 4U, 613,
    628, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 1U, 5U, 703,
    712, -1, 3U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 7U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 8U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 6U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 2U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 3U, 0U, 0U, 0U, 0U,
                  0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 3U, 0U, 140, 152, 220);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 3U, 1U, 140, 152, 220);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 4U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 6U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 6U, 0U, 1, 10, 9, 10);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 6U, 0U, 1, 10,
    -1, 0U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 1U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 1U, 0U, 1, 13, 12, 13);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 1U, 0U, 1, 13,
    -1, 4U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 3U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 2U, 1U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 3U, 0U, 1, 41, 40, 41);
  covrtEmlMCDCInitFcn(chartInstance->c6_covrtInstance, 5U, 3U, 0U, 1, 41, 2U, 0U,
                      c6_condTxtStartIdx, c6_condTxtEndIdx, 3U,
                      c6_postfixPredicateTree);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 3U, 0U, 1, 19,
    -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 3U, 1U, 23, 41,
    -1, 4U);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 5U, 2U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 5U, 2U, 0U, 1, 12, 11, 12);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 5U, 2U, 0U, 1, 12,
    -1, 1U);
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
  real_T c6_b_seg;
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
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                      chartInstance->c6_tempPoint[c6_i1]);
  }

  if (!chartInstance->c6_dataWrittenToVector[7U]) {
    sf_read_before_write_error(chartInstance->S, 5U, 34U, 137, 5);
  }

  for (c6_i2 = 0; c6_i2 < 2400; c6_i2++) {
    c6_b_dv[c6_i2] = (*chartInstance->c6_dots)[c6_i2];
  }

  c6_sector_form(chartInstance, c6_b_dv, chartInstance->c6_theta, &c6_b_isLine,
                 c6_b_tempPoint, chartInstance->c6_cutting_image, &c6_b_seg);
  chartInstance->c6_isLine = c6_b_isLine;
  chartInstance->c6_dataWrittenToVector[2U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                    chartInstance->c6_isLine);
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    chartInstance->c6_tempPoint[c6_i3] = c6_b_tempPoint[c6_i3];
  }

  chartInstance->c6_dataWrittenToVector[5U] = true;
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                      chartInstance->c6_tempPoint[c6_i4]);
  }

  for (c6_i5 = 0; c6_i5 < 19200; c6_i5++) {
    (*chartInstance->c6_c_cutting_image)[c6_i5] =
      chartInstance->c6_cutting_image[c6_i5];
  }

  chartInstance->c6_dataWrittenToVector[3U] = true;
  for (c6_i6 = 0; c6_i6 < 19200; c6_i6++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 12U,
                      (*chartInstance->c6_c_cutting_image)[c6_i6]);
  }

  *chartInstance->c6_arc = 0.0;
  chartInstance->c6_dataWrittenToVector[9U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 14U, *chartInstance->c6_arc);
  *chartInstance->c6_seg = c6_b_seg;
  chartInstance->c6_dataWrittenToVector[10U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 15U, *chartInstance->c6_seg);
  if (!chartInstance->c6_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 4U, 34U, 170, 9);
  }

  (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
    chartInstance->c6_tempPoint[0];
  chartInstance->c6_dataWrittenToVector[1U] = true;
  for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                      (*chartInstance->c6_refPosition)[c6_i7]);
  }

  if (!chartInstance->c6_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 4U, 34U, 201, 9);
  }

  (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
    c6_const_COG_Y;
  chartInstance->c6_dataWrittenToVector[1U] = true;
  for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                      (*chartInstance->c6_refPosition)[c6_i8]);
  }

  if (!chartInstance->c6_dataWrittenToVector[1U]) {
    sf_read_before_write_error(chartInstance->S, 11U, 34U, 241, 11);
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
  chartInstance->c6_dataWrittenToVector[7U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U, chartInstance->c6_theta);
}

static void c6_straight_line_reference_generation
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  real_T c6_b_dv[2400];
  real_T c6_b[2];
  real_T c6_b_tempPoint[2];
  real_T c6_dv1[2];
  real_T c6_dv2[2];
  real_T c6_a;
  real_T c6_b_b;
  real_T c6_b_isLine;
  real_T c6_b_seg;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_c_i;
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
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  boolean_T c6_bv[19200];
  boolean_T c6_out;
  if (!chartInstance->c6_dataWrittenToVector[2U]) {
    sf_read_before_write_error(chartInstance->S, 1U, 56U, 1, 6);
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 2, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        5U, 2U, 0U, chartInstance->c6_isLine, 1.0, -1, 1U,
        chartInstance->c6_isLine != 1.0))) {
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
    chartInstance->c6_temp = 0.0;
    chartInstance->c6_dataWrittenToVector[6U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                      chartInstance->c6_temp);
    c6_i3 = 0;
    for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
      (*chartInstance->c6_wieghtMeanPoint)[c6_i4] =
        (*chartInstance->c6_prev_points)[c6_i3];
      c6_i3 += 3;
    }

    for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
      (*chartInstance->c6_wieghtMeanPoint)[c6_i5] *= c6_const_k1;
    }

    c6_i7 = 0;
    for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
      c6_b_tempPoint[c6_i8] = (*chartInstance->c6_prev_points)[c6_i7 + 1];
      c6_i7 += 3;
    }

    for (c6_i10 = 0; c6_i10 < 2; c6_i10++) {
      c6_b_tempPoint[c6_i10] *= c6_const_k2;
    }

    c6_i12 = 0;
    for (c6_i13 = 0; c6_i13 < 2; c6_i13++) {
      c6_b[c6_i13] = (*chartInstance->c6_prev_points)[c6_i12 + 2];
      c6_i12 += 3;
    }

    for (c6_i15 = 0; c6_i15 < 2; c6_i15++) {
      c6_b[c6_i15] *= c6_const_k3;
    }

    for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
      (*chartInstance->c6_wieghtMeanPoint)[c6_i16] =
        (((*chartInstance->c6_wieghtMeanPoint)[c6_i16] + c6_b_tempPoint[c6_i16])
         + c6_b[c6_i16]) / 3.0;
    }

    chartInstance->c6_dataWrittenToVector[8U] = true;
    for (c6_i17 = 0; c6_i17 < 2; c6_i17++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 13U,
                        (*chartInstance->c6_wieghtMeanPoint)[c6_i17]);
    }

    chartInstance->c6_i = 1.0;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    for (c6_c_i = 0; c6_c_i < 10; c6_c_i++) {
      chartInstance->c6_i = 1.0 + (real_T)c6_c_i;
      chartInstance->c6_dataWrittenToVector[4U] = true;
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 3, 0, 1);
      if (!chartInstance->c6_dataWrittenToVector[8U]) {
        sf_read_before_write_error(chartInstance->S, 13U, 96U, 199, 15);
      }

      for (c6_i20 = 0; c6_i20 < 19200; c6_i20++) {
        c6_bv[c6_i20] = (*chartInstance->c6_bin_image)[c6_i20];
      }

      for (c6_i21 = 0; c6_i21 < 2; c6_i21++) {
        c6_dv1[c6_i21] = (*chartInstance->c6_wieghtMeanPoint)[c6_i21];
      }

      c6_means_circle(chartInstance, c6_bv, c6_dv1, c6_dv2);
      for (c6_i22 = 0; c6_i22 < 2; c6_i22++) {
        (*chartInstance->c6_wieghtMeanPoint)[c6_i22] = c6_dv2[c6_i22];
      }

      chartInstance->c6_dataWrittenToVector[8U] = true;
      for (c6_i23 = 0; c6_i23 < 2; c6_i23++) {
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 13U,
                          (*chartInstance->c6_wieghtMeanPoint)[c6_i23]);
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 3, 0, 0);
    chartInstance->c6_temp = 1.0;
    chartInstance->c6_dataWrittenToVector[6U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                      chartInstance->c6_temp);
  } else {
    for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
      chartInstance->c6_tempPoint[c6_b_i] = 0.0;
    }

    chartInstance->c6_dataWrittenToVector[5U] = true;
    for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                        chartInstance->c6_tempPoint[c6_i1]);
    }

    if (!chartInstance->c6_dataWrittenToVector[7U]) {
      sf_read_before_write_error(chartInstance->S, 5U, 34U, 137, 5);
    }

    for (c6_i2 = 0; c6_i2 < 2400; c6_i2++) {
      c6_b_dv[c6_i2] = (*chartInstance->c6_dots)[c6_i2];
    }

    c6_sector_form(chartInstance, c6_b_dv, chartInstance->c6_theta, &c6_b_isLine,
                   c6_b_tempPoint, chartInstance->c6_b_cutting_image, &c6_b_seg);
    chartInstance->c6_isLine = c6_b_isLine;
    chartInstance->c6_dataWrittenToVector[2U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                      chartInstance->c6_isLine);
    for (c6_i6 = 0; c6_i6 < 2; c6_i6++) {
      chartInstance->c6_tempPoint[c6_i6] = c6_b_tempPoint[c6_i6];
    }

    chartInstance->c6_dataWrittenToVector[5U] = true;
    for (c6_i9 = 0; c6_i9 < 2; c6_i9++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                        chartInstance->c6_tempPoint[c6_i9]);
    }

    for (c6_i11 = 0; c6_i11 < 19200; c6_i11++) {
      (*chartInstance->c6_c_cutting_image)[c6_i11] =
        chartInstance->c6_b_cutting_image[c6_i11];
    }

    chartInstance->c6_dataWrittenToVector[3U] = true;
    for (c6_i14 = 0; c6_i14 < 19200; c6_i14++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 12U,
                        (*chartInstance->c6_c_cutting_image)[c6_i14]);
    }

    *chartInstance->c6_arc = 0.0;
    chartInstance->c6_dataWrittenToVector[9U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 14U,
                      *chartInstance->c6_arc);
    *chartInstance->c6_seg = c6_b_seg;
    chartInstance->c6_dataWrittenToVector[10U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 15U,
                      *chartInstance->c6_seg);
    if (!chartInstance->c6_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 4U, 34U, 170, 9);
    }

    (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
      chartInstance->c6_tempPoint[0];
    chartInstance->c6_dataWrittenToVector[1U] = true;
    for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                        (*chartInstance->c6_refPosition)[c6_i18]);
    }

    if (!chartInstance->c6_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 4U, 34U, 201, 9);
    }

    (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
      c6_const_COG_Y;
    chartInstance->c6_dataWrittenToVector[1U] = true;
    for (c6_i19 = 0; c6_i19 < 2; c6_i19++) {
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                        (*chartInstance->c6_refPosition)[c6_i19]);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      sf_read_before_write_error(chartInstance->S, 11U, 34U, 241, 11);
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
    chartInstance->c6_dataWrittenToVector[7U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U,
                      chartInstance->c6_theta);
  }
}

static void c6_new_track_generation(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  real_T c6_b_dv[2400];
  real_T c6_dv3[2400];
  real_T c6_b[2];
  real_T c6_b_b[2];
  real_T c6_dv1[2];
  real_T c6_dv2[2];
  real_T c6_dv4[2];
  real_T c6_dv5[2];
  real_T c6_dv6[2];
  real_T c6_dv7[2];
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_b_r;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_b;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_d_b;
  real_T c6_d_x;
  real_T c6_d_y;
  real_T c6_r;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_c_i;
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
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  boolean_T c6_bv[19200];
  boolean_T c6_b_out;
  boolean_T c6_out;
  if (!chartInstance->c6_dataWrittenToVector[2U]) {
    sf_read_before_write_error(chartInstance->S, 1U, 95U, 1, 6);
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 4, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        5U, 4U, 0U, chartInstance->c6_isLine, 1.0, -1, 0U,
        chartInstance->c6_isLine == 1.0))) {
    c6_out = true;
  } else {
    c6_out = false;
  }

  if (c6_out) {
    chartInstance->c6_JITTransitionAnimation[4U] = 1U;
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
      if (!chartInstance->c6_dataWrittenToVector[6U]) {
        sf_read_before_write_error(chartInstance->S, 3U, 100U, 1, 4);
      }

      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 5U, 6, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 5U, 6U, 0U,
                          chartInstance->c6_temp, 1.0, -1, 0U,
                          chartInstance->c6_temp == 1.0))) {
        c6_b_out = true;
      } else {
        c6_b_out = false;
      }

      if (c6_b_out) {
        chartInstance->c6_JITTransitionAnimation[6U] = 1U;
        chartInstance->c6_is_new_track_generation = c6_IN_NO_ACTIVE_CHILD;
        chartInstance->c6_is_new_track_generation = c6_IN_track_generation;
        if (!chartInstance->c6_dataWrittenToVector[8U]) {
          sf_read_before_write_error(chartInstance->S, 13U, 98U, 50, 15);
        }

        for (c6_i6 = 0; c6_i6 < 2400; c6_i6++) {
          c6_dv3[c6_i6] = (*chartInstance->c6_dots)[c6_i6];
        }

        for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
          c6_dv4[c6_i8] = (*chartInstance->c6_wieghtMeanPoint)[c6_i8];
        }

        c6_track_generator(chartInstance, c6_dv3, c6_dv4, c6_dv5);
        for (c6_i11 = 0; c6_i11 < 2; c6_i11++) {
          chartInstance->c6_tempPoint[c6_i11] = c6_dv5[c6_i11];
        }

        chartInstance->c6_dataWrittenToVector[5U] = true;
        for (c6_i15 = 0; c6_i15 < 2; c6_i15++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                            chartInstance->c6_tempPoint[c6_i15]);
        }

        if (!chartInstance->c6_dataWrittenToVector[5U]) {
          sf_read_before_write_error(chartInstance->S, 4U, 98U, 93, 9);
        }

        (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
          chartInstance->c6_tempPoint[0];
        chartInstance->c6_dataWrittenToVector[1U] = true;
        for (c6_i20 = 0; c6_i20 < 2; c6_i20++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                            (*chartInstance->c6_refPosition)[c6_i20]);
        }

        if (!chartInstance->c6_dataWrittenToVector[5U]) {
          sf_read_before_write_error(chartInstance->S, 4U, 98U, 124, 9);
        }

        (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
          c6_const_COG_Y;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        for (c6_i22 = 0; c6_i22 < 2; c6_i22++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                            (*chartInstance->c6_refPosition)[c6_i22]);
        }

        if (!chartInstance->c6_dataWrittenToVector[1U]) {
          sf_read_before_write_error(chartInstance->S, 11U, 98U, 164, 11);
        }

        c6_c_y = (*chartInstance->c6_refPosition)[1];
        c6_c_x = (*chartInstance->c6_refPosition)[0];
        c6_b_a = c6_c_y;
        c6_d_b = c6_c_x;
        c6_d_y = c6_b_a;
        c6_d_x = c6_d_b;
        c6_b_r = muDoubleScalarAtan2(c6_d_y, c6_d_x);
        chartInstance->c6_theta = c6_mod(chartInstance, c6_b_r);
        chartInstance->c6_dataWrittenToVector[1U] = true;
        chartInstance->c6_dataWrittenToVector[7U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U,
                          chartInstance->c6_theta);
        chartInstance->c6_isLine = 1.0;
        chartInstance->c6_dataWrittenToVector[2U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                          chartInstance->c6_isLine);
      } else {
        chartInstance->c6_temp = 0.0;
        chartInstance->c6_dataWrittenToVector[6U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                          chartInstance->c6_temp);
        c6_i3 = 0;
        for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
          (*chartInstance->c6_wieghtMeanPoint)[c6_i4] =
            (*chartInstance->c6_prev_points)[c6_i3];
          c6_i3 += 3;
        }

        for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
          (*chartInstance->c6_wieghtMeanPoint)[c6_i7] *= c6_const_k1;
        }

        c6_i9 = 0;
        for (c6_i10 = 0; c6_i10 < 2; c6_i10++) {
          c6_b[c6_i10] = (*chartInstance->c6_prev_points)[c6_i9 + 1];
          c6_i9 += 3;
        }

        for (c6_i13 = 0; c6_i13 < 2; c6_i13++) {
          c6_b[c6_i13] *= c6_const_k2;
        }

        c6_i14 = 0;
        for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
          c6_b_b[c6_i16] = (*chartInstance->c6_prev_points)[c6_i14 + 2];
          c6_i14 += 3;
        }

        for (c6_i17 = 0; c6_i17 < 2; c6_i17++) {
          c6_b_b[c6_i17] *= c6_const_k3;
        }

        for (c6_i19 = 0; c6_i19 < 2; c6_i19++) {
          (*chartInstance->c6_wieghtMeanPoint)[c6_i19] =
            (((*chartInstance->c6_wieghtMeanPoint)[c6_i19] + c6_b[c6_i19]) +
             c6_b_b[c6_i19]) / 3.0;
        }

        chartInstance->c6_dataWrittenToVector[8U] = true;
        for (c6_i21 = 0; c6_i21 < 2; c6_i21++) {
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 13U,
                            (*chartInstance->c6_wieghtMeanPoint)[c6_i21]);
        }

        chartInstance->c6_i = 1.0;
        chartInstance->c6_dataWrittenToVector[4U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U,
                          chartInstance->c6_i);
        for (c6_c_i = 0; c6_c_i < 10; c6_c_i++) {
          chartInstance->c6_i = 1.0 + (real_T)c6_c_i;
          chartInstance->c6_dataWrittenToVector[4U] = true;
          covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U,
                            chartInstance->c6_i);
          covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 3, 1, 1);
          if (!chartInstance->c6_dataWrittenToVector[8U]) {
            sf_read_before_write_error(chartInstance->S, 13U, 96U, 199, 15);
          }

          for (c6_i23 = 0; c6_i23 < 19200; c6_i23++) {
            c6_bv[c6_i23] = (*chartInstance->c6_bin_image)[c6_i23];
          }

          for (c6_i24 = 0; c6_i24 < 2; c6_i24++) {
            c6_dv6[c6_i24] = (*chartInstance->c6_wieghtMeanPoint)[c6_i24];
          }

          c6_means_circle(chartInstance, c6_bv, c6_dv6, c6_dv7);
          for (c6_i25 = 0; c6_i25 < 2; c6_i25++) {
            (*chartInstance->c6_wieghtMeanPoint)[c6_i25] = c6_dv7[c6_i25];
          }

          chartInstance->c6_dataWrittenToVector[8U] = true;
          for (c6_i26 = 0; c6_i26 < 2; c6_i26++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 13U,
                              (*chartInstance->c6_wieghtMeanPoint)[c6_i26]);
          }

          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 3, 1, 0);
        chartInstance->c6_temp = 1.0;
        chartInstance->c6_dataWrittenToVector[6U] = true;
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U,
                          chartInstance->c6_temp);
      }
      break;

     case c6_IN_track_generation:
      covrtDecUpdateFcn(chartInstance->c6_covrtInstance, 4U, 2, 0,
                        c6_IN_track_generation);
      if (!chartInstance->c6_dataWrittenToVector[8U]) {
        sf_read_before_write_error(chartInstance->S, 13U, 98U, 50, 15);
      }

      for (c6_b_i = 0; c6_b_i < 2400; c6_b_i++) {
        c6_b_dv[c6_b_i] = (*chartInstance->c6_dots)[c6_b_i];
      }

      for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
        c6_dv1[c6_i1] = (*chartInstance->c6_wieghtMeanPoint)[c6_i1];
      }

      c6_track_generator(chartInstance, c6_b_dv, c6_dv1, c6_dv2);
      for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
        chartInstance->c6_tempPoint[c6_i2] = c6_dv2[c6_i2];
      }

      chartInstance->c6_dataWrittenToVector[5U] = true;
      for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U,
                          chartInstance->c6_tempPoint[c6_i5]);
      }

      if (!chartInstance->c6_dataWrittenToVector[5U]) {
        sf_read_before_write_error(chartInstance->S, 4U, 98U, 93, 9);
      }

      (*chartInstance->c6_refPosition)[0] = c6_const_COG_X -
        chartInstance->c6_tempPoint[0];
      chartInstance->c6_dataWrittenToVector[1U] = true;
      for (c6_i12 = 0; c6_i12 < 2; c6_i12++) {
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                          (*chartInstance->c6_refPosition)[c6_i12]);
      }

      if (!chartInstance->c6_dataWrittenToVector[5U]) {
        sf_read_before_write_error(chartInstance->S, 4U, 98U, 124, 9);
      }

      (*chartInstance->c6_refPosition)[1] = chartInstance->c6_tempPoint[1] -
        c6_const_COG_Y;
      chartInstance->c6_dataWrittenToVector[1U] = true;
      for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 11U,
                          (*chartInstance->c6_refPosition)[c6_i18]);
      }

      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        sf_read_before_write_error(chartInstance->S, 11U, 98U, 164, 11);
      }

      c6_y = (*chartInstance->c6_refPosition)[1];
      c6_x = (*chartInstance->c6_refPosition)[0];
      c6_a = c6_y;
      c6_c_b = c6_x;
      c6_b_y = c6_a;
      c6_b_x = c6_c_b;
      c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
      chartInstance->c6_theta = c6_mod(chartInstance, c6_r);
      chartInstance->c6_dataWrittenToVector[1U] = true;
      chartInstance->c6_dataWrittenToVector[7U] = true;
      covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U,
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

static void c6_imdilate(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_A[19200], c6_strel c6_se, real_T c6_b_B[19200])
{
  static char_T c6_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c6_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'd',
    'i', 'l', 'a', 't', 'e', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
    'o', 'n', 'N', 'a', 'N' };

  static char_T c6_cv2[19] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'I', 'M', ',' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_asizeT[2];
  real_T c6_nsizeT[2];
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_b_k;
  real_T c6_b_x;
  real_T c6_c_j;
  real_T c6_d_i;
  real_T c6_g_i;
  real_T c6_h_j;
  real_T c6_x;
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
  int32_T c6_k;
  boolean_T c6_nhood[3];
  boolean_T c6_b;
  boolean_T c6_b_b;
  boolean_T c6_b_nhood;
  boolean_T c6_b_p;
  boolean_T c6_c_nhood;
  boolean_T c6_exitg1;
  boolean_T c6_p;
  (void)c6_se;
  c6_p = true;
  c6_k = 0;
  c6_exitg1 = false;
  while ((!c6_exitg1) && (c6_k < 19200)) {
    c6_b_k = (real_T)c6_k + 1.0;
    c6_x = c6_A[(int32_T)c6_b_k - 1];
    c6_b_x = c6_x;
    c6_b_b = muDoubleScalarIsNaN(c6_b_x);
    c6_b_p = !c6_b_b;
    if (c6_b_p) {
      c6_k++;
    } else {
      c6_p = false;
      c6_exitg1 = true;
    }
  }

  if (c6_p) {
    c6_b = true;
  } else {
    c6_b = false;
  }

  if (!c6_b) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv2, 10, 0U, 1U, 0U, 2, 1, 19),
                  false);
    sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_emlrtMCI, "error", 0U, 2U, 14,
                c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
      "message", 1U, 2U, 14, c6_b_y, 14, c6_c_y)));
  }

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

static void c6_bwlabel(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_varargin_1[19200], real_T c6_b_L[19200])
{
  static char_T c6_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c6_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

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
  chartInstance->c6_P[0] = 0.0;
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
          sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error", 0U,
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
              sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error",
                          0U, 2U, 14, c6_l_y, 14, sf_mex_call
                          (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                           1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
                "message", 1U, 1U, 14, c6_m_y)));
            }

            if (c6_d13 != 0.0) {
              c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) -
                1];
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
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error",
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
                    sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI,
                                "error", 0U, 2U, 14, c6_v_y, 14, sf_mex_call
                                (chartInstance->c6_fEmlrtCtx, NULL, "getString",
                                 1U, 1U, 14, sf_mex_call
                                 (chartInstance->c6_fEmlrtCtx, NULL, "message",
                                  1U, 1U, 14, c6_w_y)));
                  }

                  if (c6_d18 != 0.0) {
                    c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                      c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c
                                - 1.0) - 1)) - 1];
                    while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                            chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                            (c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c -
                               1)) - 1] + 1.0), 1, 9601) - 1] < c6_b_L[((int32_T)
                            c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1]) {
                      c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1]
                        = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                        chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                        (c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1))
                         - 1] + 1.0), 1, 9601) - 1];
                    }

                    if (c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                          (c6_b_c - 1.0) - 1)) - 1] != c6_b_L[((int32_T)(c6_b_r
                          + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) - 1)) - 1]) {
                      c6_d_rootj = c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 *
                                           ((int32_T)(c6_b_c - 1.0) - 1)) - 1];
                      while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                              chartInstance->S, 34U, 0, 0, MAX_uint32_T,
                              (int32_T)(c6_d_rootj + 1.0), 1, 9601) - 1] <
                             c6_d_rootj) {
                        c6_d_rootj = chartInstance->
                          c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
                          34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d_rootj + 1.0),
                          1, 9601) - 1];
                      }

                      if (c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1))
                          - 1] > c6_d_rootj) {
                        c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) -
                          1] = c6_d_rootj;
                      }

                      while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                              chartInstance->S, 34U, 0, 0, MAX_uint32_T,
                              (int32_T)(c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 *
                                ((int32_T)(c6_b_c - 1.0) - 1)) - 1] + 1.0), 1,
                              9601) - 1] < c6_b_L[((int32_T)(c6_b_r + 1.0) + 120
                              * ((int32_T)(c6_b_c - 1.0) - 1)) - 1]) {
                        c6_j_j = chartInstance->c6_P[sf_eml_array_bounds_check
                          (NULL, chartInstance->S, 34U, 0, 0, MAX_uint32_T,
                           (int32_T)(c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 *
                                             ((int32_T)(c6_b_c - 1.0) - 1)) - 1]
                                     + 1.0), 1, 9601) - 1];
                        chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                          chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                          (c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                          (c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] =
                          c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1))
                          - 1];
                        c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                                 (c6_b_c - 1.0) - 1)) - 1] = c6_j_j;
                      }

                      chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                        chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                        (c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                        (c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] =
                        c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) -
                        1];
                    }

                    while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                            chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                            (c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                               (c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] <
                           c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                             (c6_b_c - 1.0) - 1)) - 1]) {
                      c6_j_j = chartInstance->c6_P[sf_eml_array_bounds_check
                        (NULL, chartInstance->S, 34U, 0, 0, MAX_uint32_T,
                         (int32_T)(c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 *
                                           ((int32_T)(c6_b_c - 1.0) - 1)) - 1] +
                                   1.0), 1, 9601) - 1];
                      chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                        chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                        (c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                        (c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] =
                        c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) -
                        1];
                      c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c
                                - 1.0) - 1)) - 1] = c6_j_j;
                    }

                    chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c
                      - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] = c6_b_L[((int32_T)
                      c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1];
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
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error",
                            0U, 2U, 14, c6_o_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_r_y)));
              }

              if (c6_d15 != 0.0) {
                c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)(c6_b_c -
                            1.0) - 1)) - 1];
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
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error",
                            0U, 2U, 14, c6_q_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_t_y)));
              }

              if (c6_d16 != 0.0) {
                c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1))
                  - 1];
                while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                        chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                        (c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1))
                         - 1] + 1.0), 1, 9601) - 1] < c6_b_L[((int32_T)c6_b_r +
                        120 * ((int32_T)c6_b_c - 1)) - 1]) {
                  c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                    chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_b_L
                    [((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] + 1.0),
                    1, 9601) - 1];
                }

                if (c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1))
                    - 1] != c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                      (c6_b_c - 1.0) - 1)) - 1]) {
                  c6_d_rootj = c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                    (c6_b_c - 1.0) - 1)) - 1];
                  while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                          chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                          (c6_d_rootj + 1.0), 1, 9601) - 1] < c6_d_rootj) {
                    c6_d_rootj = chartInstance->c6_P[sf_eml_array_bounds_check
                      (NULL, chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                       (c6_d_rootj + 1.0), 1, 9601) - 1];
                  }

                  if (c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1]
                      > c6_d_rootj) {
                    c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                      c6_d_rootj;
                  }

                  while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                          chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                          (c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                             (c6_b_c - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] <
                         c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)
                           (c6_b_c - 1.0) - 1)) - 1]) {
                    c6_j_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c
                      - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1];
                    chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c
                      - 1.0) - 1)) - 1] + 1.0), 1, 9601) - 1] = c6_b_L[((int32_T)
                      c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1];
                    c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c -
                              1.0) - 1)) - 1] = c6_j_j;
                  }

                  chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_b_L
                    [((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0) -
                    1)) - 1] + 1.0), 1, 9601) - 1] = c6_b_L[((int32_T)c6_b_r +
                    120 * ((int32_T)c6_b_c - 1)) - 1];
                }

                while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                        chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                        (c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)
                           c6_b_c - 1)) - 1] + 1.0), 1, 9601) - 1] < c6_b_L
                       [((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1))
                       - 1]) {
                  c6_j_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_b_L
                    [((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) - 1]
                    + 1.0), 1, 9601) - 1];
                  chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_b_L
                    [((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) - 1]
                    + 1.0), 1, 9601) - 1] = c6_b_L[((int32_T)c6_b_r + 120 *
                    ((int32_T)c6_b_c - 1)) - 1];
                  c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1))
                    - 1] = c6_j_j;
                }

                chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_b_L
                  [((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1)) - 1]
                  + 1.0), 1, 9601) - 1] = c6_b_L[((int32_T)c6_b_r + 120 *
                  ((int32_T)c6_b_c - 1)) - 1];
              } else {
                c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c -
                            1.0) - 1)) - 1];
              }
            } else {
              c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 * ((int32_T)(c6_b_c - 1.0)
                         - 1)) - 1];
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
                sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error",
                            0U, 2U, 14, c6_s_y, 14, sf_mex_call
                            (chartInstance->c6_fEmlrtCtx, NULL, "getString", 1U,
                             1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
                  NULL, "message", 1U, 1U, 14, c6_u_y)));
              }

              if (c6_d17 != 0.0) {
                c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
                  c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 * ((int32_T)c6_b_c - 1))
                  - 1];
              } else {
                c6_guard1 = true;
              }
            } else {
              c6_guard1 = true;
            }
          }

          if (c6_guard1) {
            c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] =
              c6_label;
            chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, (int32_T)(c6_label + 1.0), 1, 9601) - 1] =
              c6_label;
            c6_label++;
          }
        } else {
          c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_b_c - 1)) - 1] = 0.0;
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
      c6_d = c6_b_L[((int32_T)c6_b_r + 120 * (sf_eml_array_bounds_check(NULL,
        chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_c, 1, 160) - 1)) - 1];
      c6_d_x = c6_d;
      c6_f_x = c6_d_x;
      c6_b = muDoubleScalarIsNaN(c6_f_x);
      if (c6_b) {
        c6_y = NULL;
        sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 19),
                      false);
        c6_b_y = NULL;
        sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error", 0U, 2U,
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

          c6_d3 = c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 *
                          (sf_eml_array_bounds_check(NULL, chartInstance->S, 34U,
            0, 0, MAX_uint32_T, c6_b_qY, 1, 160) - 1)) - 1];
          c6_o_x = c6_d3;
          c6_p_x = c6_o_x;
          c6_b_b = muDoubleScalarIsNaN(c6_p_x);
          if (c6_b_b) {
            c6_c_y = NULL;
            sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2,
              1, 19), false);
            c6_e_y = NULL;
            sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2,
              1, 19), false);
            sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error", 0U,
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

            c6_c_i = c6_b_L[((int32_T)(c6_b_r - 1.0) + 120 *
                             (sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, c6_e_qY, 1, 160) - 1)) - 1];
            c6_j = c6_b_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1];
            c6_e_i = c6_c_i;
            c6_d8 = c6_e_i;
            while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d8 +
                     1.0), 1, 9601) - 1] < c6_d8) {
              c6_d8 = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d8 + 1.0),
                1, 9601) - 1];
            }

            if (c6_c_i != c6_j) {
              c6_i_i = c6_j;
              c6_rootj = c6_i_i;
              while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_rootj + 1.0), 1, 9601) - 1] < c6_rootj) {
                c6_rootj = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_rootj
                  + 1.0), 1, 9601) - 1];
              }

              if (c6_d8 > c6_rootj) {
                c6_d8 = c6_rootj;
              }

              c6_o_i = c6_j;
              c6_d_root = c6_d8;
              while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_o_i + 1.0), 1, 9601) - 1] < c6_o_i) {
                c6_g_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_o_i +
                  1.0), 1, 9601) - 1];
                chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_o_i +
                  1.0), 1, 9601) - 1] = c6_d_root;
                c6_o_i = c6_g_j;
              }

              chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_o_i +
                1.0), 1, 9601) - 1] = c6_d_root;
            }

            c6_j_i = c6_c_i;
            c6_root = c6_d8;
            while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_j_i
                     + 1.0), 1, 9601) - 1] < c6_j_i) {
              c6_d_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_j_i +
                1.0), 1, 9601) - 1];
              chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_j_i +
                1.0), 1, 9601) - 1] = c6_root;
              c6_j_i = c6_d_j;
            }

            chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, (int32_T)(c6_j_i + 1.0), 1, 9601) - 1] =
              c6_root;
            c6_b_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1] = c6_d8;
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

          c6_d4 = c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 *
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
            sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error", 0U,
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

            c6_d_i = c6_b_L[((int32_T)(c6_b_r + 1.0) + 120 *
                             (sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, c6_f_qY, 1, 160) - 1)) - 1];
            c6_b_j = c6_b_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1];
            c6_g_i = c6_d_i;
            c6_d10 = c6_g_i;
            while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d10
                     + 1.0), 1, 9601) - 1] < c6_d10) {
              c6_d10 = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d10 +
                1.0), 1, 9601) - 1];
            }

            if (c6_d_i != c6_b_j) {
              c6_k_i = c6_b_j;
              c6_b_rootj = c6_k_i;
              while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_b_rootj + 1.0), 1, 9601) - 1] < c6_b_rootj) {
                c6_b_rootj = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                  (c6_b_rootj + 1.0), 1, 9601) - 1];
              }

              if (c6_d10 > c6_b_rootj) {
                c6_d10 = c6_b_rootj;
              }

              c6_p_i = c6_b_j;
              c6_e_root = c6_d10;
              while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                      (c6_p_i + 1.0), 1, 9601) - 1] < c6_p_i) {
                c6_h_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_p_i +
                  1.0), 1, 9601) - 1];
                chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_p_i +
                  1.0), 1, 9601) - 1] = c6_e_root;
                c6_p_i = c6_h_j;
              }

              chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_p_i +
                1.0), 1, 9601) - 1] = c6_e_root;
            }

            c6_m_i = c6_d_i;
            c6_b_root = c6_d10;
            while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_m_i
                     + 1.0), 1, 9601) - 1] < c6_m_i) {
              c6_e_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_m_i +
                1.0), 1, 9601) - 1];
              chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_m_i +
                1.0), 1, 9601) - 1] = c6_b_root;
              c6_m_i = c6_e_j;
            }

            chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, (int32_T)(c6_m_i + 1.0), 1, 9601) - 1] =
              c6_b_root;
            c6_b_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1] = c6_d10;
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

        c6_d5 = c6_b_L[((int32_T)c6_b_r + 120 * (sf_eml_array_bounds_check(NULL,
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
          sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_b_emlrtMCI, "error", 0U,
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

          c6_f_i = c6_b_L[((int32_T)c6_b_r + 120 * (sf_eml_array_bounds_check
            (NULL, chartInstance->S, 34U, 0, 0, MAX_uint32_T, c6_g_qY, 1, 160) -
            1)) - 1];
          c6_c_j = c6_b_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1];
          c6_h_i = c6_f_i;
          c6_d11 = c6_h_i;
          while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d11 +
                   1.0), 1, 9601) - 1] < c6_d11) {
            c6_d11 = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
              chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_d11 + 1.0),
              1, 9601) - 1];
          }

          if (c6_f_i != c6_c_j) {
            c6_l_i = c6_c_j;
            c6_c_rootj = c6_l_i;
            while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)
                    (c6_c_rootj + 1.0), 1, 9601) - 1] < c6_c_rootj) {
              c6_c_rootj = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_c_rootj
                + 1.0), 1, 9601) - 1];
            }

            if (c6_d11 > c6_c_rootj) {
              c6_d11 = c6_c_rootj;
            }

            c6_q_i = c6_c_j;
            c6_f_root = c6_d11;
            while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                    chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_q_i
                     + 1.0), 1, 9601) - 1] < c6_q_i) {
              c6_i_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_q_i +
                1.0), 1, 9601) - 1];
              chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_q_i +
                1.0), 1, 9601) - 1] = c6_f_root;
              c6_q_i = c6_i_j;
            }

            chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, (int32_T)(c6_q_i + 1.0), 1, 9601) - 1] =
              c6_f_root;
          }

          c6_n_i = c6_f_i;
          c6_c_root = c6_d11;
          while (chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
                  chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_n_i +
                   1.0), 1, 9601) - 1] < c6_n_i) {
            c6_f_j = chartInstance->c6_P[sf_eml_array_bounds_check(NULL,
              chartInstance->S, 34U, 0, 0, MAX_uint32_T, (int32_T)(c6_n_i + 1.0),
              1, 9601) - 1];
            chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
              34U, 0, 0, MAX_uint32_T, (int32_T)(c6_n_i + 1.0), 1, 9601) - 1] =
              c6_c_root;
            c6_n_i = c6_f_j;
          }

          chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
            34U, 0, 0, MAX_uint32_T, (int32_T)(c6_n_i + 1.0), 1, 9601) - 1] =
            c6_c_root;
          c6_b_L[((int32_T)c6_b_r + 120 * (c6_c - 1)) - 1] = c6_d11;
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

      if (chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
           34U, 0, 0, MAX_uint32_T, c6_r_i, 1, 9601) - 1] < (real_T)c6_l_qY) {
        chartInstance->c6_P[c6_r_i - 1] = chartInstance->
          c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S, 34U, 0, 0,
          MAX_uint32_T, (int32_T)(chartInstance->c6_P[c6_r_i - 1] + 1.0), 1,
          9601) - 1];
      } else {
        chartInstance->c6_P[c6_r_i - 1] = c6_numComponents;
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
      c6_b_L[((int32_T)c6_b_r + 120 * ((int32_T)c6_d_c - 1)) - 1] =
        chartInstance->c6_P[sf_eml_array_bounds_check(NULL, chartInstance->S,
        34U, 0, 0, MAX_uint32_T, (int32_T)(c6_b_L[((int32_T)c6_b_r + 120 *
        ((int32_T)c6_d_c - 1)) - 1] + 1.0), 1, 9601) - 1];
    }
  }
}

static void c6_check_forloop_overflow_error
  (SFc6_flightControlSystemInstanceStruct *chartInstance, boolean_T c6_overflow)
{
  static char_T c6_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c6_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  (void)c6_overflow;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_c_emlrtMCI, "error", 0U, 2U, 14,
              c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
    "getString", 1U, 1U, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx, NULL,
    "message", 1U, 2U, 14, c6_b_y, 14, c6_c_y)));
}

static void c6_b_mean(SFc6_flightControlSystemInstanceStruct *chartInstance,
                      real_T c6_x[800], real_T c6_y[2])
{
  real_T c6_b_x;
  real_T c6_c_x;
  int32_T c6_counts[2];
  int32_T c6_b_i;
  int32_T c6_b_xi;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  int32_T c6_xi;
  int32_T c6_xoffset;
  int32_T c6_xpageoffset;
  int32_T c6_ypageoffset;
  boolean_T c6_b;
  boolean_T c6_b_b;
  boolean_T c6_c_b;
  (void)chartInstance;
  for (c6_xi = 0; c6_xi < 2; c6_xi++) {
    c6_b_xi = c6_xi;
    c6_xpageoffset = c6_b_xi * 400 + 1;
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

    for (c6_k = 0; c6_k < 399; c6_k++) {
      c6_xoffset = (c6_xpageoffset + c6_k) + 1;
      c6_ix = c6_xoffset - 1;
      c6_iy = c6_ypageoffset - 1;
      c6_c_x = c6_x[c6_ix];
      c6_b_b = muDoubleScalarIsNaN(c6_c_x);
      if (c6_b_b) {
        c6_c_b = true;
      } else {
        c6_c_b = false;
      }

      if (!c6_c_b) {
        c6_y[c6_iy] += c6_x[c6_ix];
        c6_counts[c6_iy]++;
      }
    }
  }

  for (c6_b_i = 0; c6_b_i < 2; c6_b_i++) {
    c6_y[c6_b_i] /= (real_T)c6_counts[c6_b_i];
  }
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
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 21U, (real_T)
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
        15U, 141, 10, 21U, (int32_T)sf_integer_check(chartInstance->S, 15U, 141U,
        10U, chartInstance->c6_i), 1, 120) + 120 * (sf_eml_array_bounds_check
        (NULL, chartInstance->S, 15U, 141, 10, 21U, (int32_T)sf_integer_check
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

  chartInstance->c6_dataWrittenToVector[11U] = true;
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 31U, c6_initial_ref[c6_i3]);
  }

  if (!chartInstance->c6_dataWrittenToVector[11U]) {
    sf_read_before_write_error(chartInstance->S, 31U, 15U, 323, 11);
  }

  c6_initial_ref[0] = c6_const_COG_X - c6_initial_ref[0];
  chartInstance->c6_dataWrittenToVector[11U] = true;
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 31U, c6_initial_ref[c6_i4]);
  }

  if (!chartInstance->c6_dataWrittenToVector[11U]) {
    sf_read_before_write_error(chartInstance->S, 31U, 15U, 356, 11);
  }

  c6_initial_ref[1] -= c6_const_COG_Y;
  chartInstance->c6_dataWrittenToVector[11U] = true;
  for (c6_i6 = 0; c6_i6 < 2; c6_i6++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 31U, c6_initial_ref[c6_i6]);
  }

  if (!chartInstance->c6_dataWrittenToVector[11U]) {
    sf_read_before_write_error(chartInstance->S, 31U, 15U, 433, 11);
  }

  c6_y = c6_initial_ref[1];
  c6_x = c6_initial_ref[0];
  c6_a = c6_y;
  c6_b = c6_x;
  c6_b_y = c6_a;
  c6_b_x = c6_b;
  c6_r = muDoubleScalarAtan2(c6_b_y, c6_b_x);
  *c6_initial_theta = c6_mod(chartInstance, c6_r);
  chartInstance->c6_dataWrittenToVector[11U] = true;
  chartInstance->c6_dataWrittenToVector[12U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 32U, *c6_initial_theta);
}

static void c6_sector_form(SFc6_flightControlSystemInstanceStruct *chartInstance,
  real_T c6_points[2400], real_T c6_prev_theta, real_T *c6_state, real_T c6_ref
  [2], real_T c6_c_MAP[19200], real_T *c6_segFlag)
{
  c6_strel c6_se;
  real_T c6_b_cutting_dots[2400];
  real_T c6_cutting_dots[2400];
  real_T c6_center[2];
  real_T c6_g_x[2];
  real_T c6_a;
  real_T c6_absxk;
  real_T c6_b;
  real_T c6_b_cnt;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_cnt;
  real_T c6_d;
  real_T c6_d_x;
  real_T c6_delta;
  real_T c6_dist;
  real_T c6_e_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_label;
  real_T c6_pre_dist;
  real_T c6_r;
  real_T c6_scale;
  real_T c6_t;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_b_i;
  int32_T c6_b_k;
  int32_T c6_c_i;
  int32_T c6_c_k;
  int32_T c6_d_i;
  int32_T c6_d_k;
  int32_T c6_e_i;
  int32_T c6_exitg1;
  int32_T c6_f_i;
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
  int32_T c6_k;
  boolean_T c6_f_x[19200];
  boolean_T c6_c_y;
  boolean_T c6_exitg2;
  for (c6_b_i = 0; c6_b_i < 2400; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 23U, c6_points[c6_b_i]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 26U, c6_prev_theta);
  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 5, 0);
  for (c6_i1 = 0; c6_i1 < 2400; c6_i1++) {
    c6_cutting_dots[c6_i1] = 0.0;
  }

  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    c6_ref[c6_i2] = 0.0;
  }

  chartInstance->c6_dataWrittenToVector[15U] = true;
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 33U, c6_ref[c6_i3]);
  }

  c6_cnt = 0.0;
  for (c6_i4 = 0; c6_i4 < 19200; c6_i4++) {
    c6_c_MAP[c6_i4] = 0.0;
  }

  chartInstance->c6_dataWrittenToVector[16U] = true;
  for (c6_i5 = 0; c6_i5 < 19200; c6_i5++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 34U, c6_c_MAP[c6_i5]);
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
        sf_read_before_write_error(chartInstance->S, 0U, 44U, 352, 1);
      }

      c6_d = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
        345, 11, 23U, (int32_T)sf_integer_check(chartInstance->S, 44U, 345U, 11U,
        chartInstance->c6_i), 1, 1200) - 1];
      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 4U, 5U, 0U, c6_d, 0.0,
                          -1, 0U, c6_d == 0.0))) {
        c6_exitg1 = 1;
      } else {
        if (!chartInstance->c6_dataWrittenToVector[4U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 44U, 442, 1);
        }

        c6_y = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
          435, 11, 23U, (int32_T)sf_integer_check(chartInstance->S, 44U, 435U,
          11U, chartInstance->c6_i), 1, 1200) + 1199] - c6_const_COG_Y;
        c6_x = c6_const_COG_X - c6_points[sf_eml_array_bounds_check(NULL,
          chartInstance->S, 44U, 460, 11, 23U, (int32_T)sf_integer_check
          (chartInstance->S, 44U, 460U, 11U, chartInstance->c6_i), 1, 1200) - 1];
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
            sf_read_before_write_error(chartInstance->S, 0U, 44U, 658, 1);
          }

          c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
            629, 19, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
            44U, 629U, 19U, c6_cnt), 1, 1200) - 1] =
            c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 651,
            11, 23U, (int32_T)sf_integer_check(chartInstance->S, 44U, 651U, 11U,
            chartInstance->c6_i), 1, 1200) - 1];
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 44U, 701, 1);
          }

          c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U,
            672, 19, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
            44U, 672U, 19U, c6_cnt), 1, 1200) + 1199] =
            c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 694,
            11, 23U, (int32_T)sf_integer_check(chartInstance->S, 44U, 694U, 11U,
            chartInstance->c6_i), 1, 1200) + 1199];
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 44U, 726, 1);
          }

          c6_c_MAP[(sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 715,
                     28, 34U, (int32_T)sf_integer_check(chartInstance->S, 44U,
                      715U, 28U, c6_points[sf_eml_array_bounds_check(NULL,
            chartInstance->S, 44U, 715, 28, 23U, (int32_T)sf_integer_check
            (chartInstance->S, 44U, 715U, 28U, chartInstance->c6_i), 1, 1200) -
                      1]), 1, 120) + 120 * (sf_eml_array_bounds_check(NULL,
                      chartInstance->S, 44U, 715, 28, 34U, (int32_T)
                      sf_integer_check(chartInstance->S, 44U, 715U, 28U,
            c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 715,
            28, 23U, (int32_T)sf_integer_check(chartInstance->S, 44U, 715U, 28U,
            chartInstance->c6_i), 1, 1200) + 1199]), 1, 160) - 1)) - 1] = 1.0;
          chartInstance->c6_dataWrittenToVector[4U] = true;
          chartInstance->c6_dataWrittenToVector[16U] = true;
          for (c6_i13 = 0; c6_i13 < 19200; c6_i13++) {
            covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 34U,
                              c6_c_MAP[c6_i13]);
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

  c6_d_i = 0;
  while (c6_d_i <= 2399) {
    c6_d_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c6_e_i = 0;
  while (c6_e_i <= 2399) {
    if (c6_cutting_dots[c6_e_i] == 0.0) {
      c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 769,
        29, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 769U,
        29U, (real_T)(c6_e_i + 1)), 1, 2400) - 1] = rtNaN;
    }

    c6_e_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c6_i6 = 0; c6_i6 < 2400; c6_i6++) {
    c6_b_cutting_dots[c6_i6] = c6_cutting_dots[c6_i6];
  }

  c6_mean(chartInstance, c6_b_cutting_dots, c6_ref);
  chartInstance->c6_dataWrittenToVector[15U] = true;
  for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 33U, c6_ref[c6_i7]);
  }

  c6_se.__dummy = 0;
  if (!chartInstance->c6_dataWrittenToVector[16U]) {
    sf_read_before_write_error(chartInstance->S, 34U, 44U, 882, 3);
  }

  for (c6_i8 = 0; c6_i8 < 19200; c6_i8++) {
    chartInstance->c6_MAP[c6_i8] = c6_c_MAP[c6_i8];
  }

  c6_imdilate(chartInstance, chartInstance->c6_MAP, c6_se, c6_c_MAP);
  chartInstance->c6_dataWrittenToVector[16U] = true;
  for (c6_i9 = 0; c6_i9 < 19200; c6_i9++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 34U, c6_c_MAP[c6_i9]);
  }

  if (!chartInstance->c6_dataWrittenToVector[16U]) {
    sf_read_before_write_error(chartInstance->S, 34U, 44U, 904, 3);
  }

  for (c6_i10 = 0; c6_i10 < 19200; c6_i10++) {
    chartInstance->c6_b_MAP[c6_i10] = c6_c_MAP[c6_i10];
  }

  c6_bwlabel(chartInstance, chartInstance->c6_b_MAP, chartInstance->c6_L);
  c6_pre_dist = rtInf;
  for (c6_i11 = 0; c6_i11 < 2; c6_i11++) {
    c6_center[c6_i11] = 0.0;
  }

  c6_b_cnt = c6_cnt;
  c6_i12 = (int32_T)c6_b_cnt;
  sf_mex_lw_for_loop_vector_check(1.0, 1.0, c6_b_cnt, mxDOUBLE_CLASS, c6_i12);
  chartInstance->c6_i = 1.0;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  c6_f_i = 0;
  while (c6_f_i <= c6_i12 - 1) {
    chartInstance->c6_i = 1.0 + (real_T)c6_f_i;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 1, 1);
    if (!chartInstance->c6_dataWrittenToVector[4U]) {
      sf_read_before_write_error(chartInstance->S, 0U, 44U, 993, 1);
    }

    c6_i15 = sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 993, 1,
      MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 993U, 1U,
      chartInstance->c6_i), 1, 1200) - 1;
    for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
      c6_g_x[c6_i16] = c6_cutting_dots[c6_i15 + 1200 * c6_i16] - (60.0 + 20.0 *
        (real_T)c6_i16);
    }

    c6_dist = 0.0;
    c6_scale = 3.3121686421112381E-170;
    for (c6_c_k = 0; c6_c_k < 2; c6_c_k++) {
      c6_d_k = c6_c_k;
      c6_h_x = c6_g_x[c6_d_k];
      c6_i_x = c6_h_x;
      c6_j_x = c6_i_x;
      c6_absxk = muDoubleScalarAbs(c6_j_x);
      if (c6_absxk > c6_scale) {
        c6_t = c6_scale / c6_absxk;
        c6_dist = 1.0 + c6_dist * c6_t * c6_t;
        c6_scale = c6_absxk;
      } else {
        c6_t = c6_absxk / c6_scale;
        c6_dist += c6_t * c6_t;
      }
    }

    c6_dist = c6_scale * muDoubleScalarSqrt(c6_dist);
    if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 3,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c6_covrtInstance, 4U, 5U, 3U, c6_dist,
                        c6_pre_dist, -1, 2U, c6_dist < c6_pre_dist))) {
      c6_i17 = sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 1070, 1,
        MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 1070U, 1U,
        chartInstance->c6_i), 1, 1200) - 1;
      for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
        c6_center[c6_i18] = c6_cutting_dots[c6_i17 + 1200 * c6_i18];
      }

      c6_pre_dist = c6_dist;
    } else if (!chartInstance->c6_dataWrittenToVector[4U]) {
      sf_read_before_write_error(chartInstance->S, 0U, 44U, 1070, 1);
    }

    c6_f_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 5, 1, 0);
  c6_label = chartInstance->c6_L[(sf_eml_array_bounds_check(NULL,
    chartInstance->S, 44U, 1122, 28, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 44U, 1122U, 28U, c6_center[0]), 1, 120) + 120 *
    (sf_eml_array_bounds_check(NULL, chartInstance->S, 44U, 1122, 28,
    MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 44U, 1122U, 28U,
    c6_center[1]), 1, 160) - 1)) - 1];
  for (c6_i14 = 0; c6_i14 < 19200; c6_i14++) {
    c6_f_x[c6_i14] = (chartInstance->c6_L[c6_i14] == c6_label);
  }

  c6_c_y = true;
  c6_k = 1;
  c6_exitg2 = false;
  while ((!c6_exitg2) && (c6_k - 1 < 19200)) {
    c6_b_k = c6_k - 1;
    if (!c6_f_x[c6_b_k]) {
      c6_c_y = false;
      c6_exitg2 = true;
    } else {
      c6_k++;
    }
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 4, c6_c_y)) {
    *c6_segFlag = 1.0;
    chartInstance->c6_dataWrittenToVector[17U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 35U, *c6_segFlag);
  } else {
    *c6_segFlag = 0.0;
    chartInstance->c6_dataWrittenToVector[17U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 35U, *c6_segFlag);
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 5, 5,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 5U, 5U, c6_cnt, 10.0, -1, 4U, c6_cnt > 10.0))) {
    *c6_state = 1.0;
    chartInstance->c6_dataWrittenToVector[14U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 30U, *c6_state);
  } else {
    *c6_state = 0.0;
    chartInstance->c6_dataWrittenToVector[14U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 30U, *c6_state);
  }
}

static void c6_means_circle(SFc6_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c6_image[19200], real_T c6_dot[2], real_T c6_point[2])
{
  static char_T c6_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c6_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_ROIdots[800];
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_b_c;
  real_T c6_b_j;
  real_T c6_b_x;
  real_T c6_c;
  real_T c6_c_a;
  real_T c6_c_x;
  real_T c6_d;
  real_T c6_d1;
  real_T c6_d2;
  real_T c6_d3;
  real_T c6_d4;
  real_T c6_d_a;
  real_T c6_d_x;
  real_T c6_dist;
  real_T c6_e_a;
  real_T c6_e_x;
  real_T c6_endX;
  real_T c6_endY;
  real_T c6_f_a;
  real_T c6_f_x;
  real_T c6_g_a;
  real_T c6_h_a;
  real_T c6_i_a;
  real_T c6_idx;
  real_T c6_j_a;
  real_T c6_startX;
  real_T c6_startY;
  real_T c6_x;
  int32_T c6_b_i;
  int32_T c6_c_i;
  int32_T c6_d_i;
  int32_T c6_e_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_j;
  boolean_T c6_b_p;
  boolean_T c6_p;
  for (c6_b_i = 0; c6_b_i < 19200; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 22U, (real_T)
                      c6_image[c6_b_i]);
  }

  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 27U, c6_dot[c6_i1]);
  }

  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 1, 0);
  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 1, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 1U, 0U, c6_dot[0] - 10.0, 1.0, -1, 2U, c6_dot[0] - 10.0 < 1.0))) {
    c6_startX = 1.0;
  } else {
    c6_startX = c6_dot[0] - 10.0;
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 1, 1,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 1U, 1U, c6_dot[1] - 10.0, 1.0, -1, 2U, c6_dot[1] - 10.0 < 1.0))) {
    c6_startY = 1.0;
  } else {
    c6_startY = c6_dot[1] - 10.0;
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 1, 2,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 1U, 2U, c6_dot[0] + 10.0, 120.0, -1, 4U, c6_dot[0] + 10.0 > 120.0)))
  {
    c6_endX = 120.0;
  } else {
    c6_endX = c6_dot[0] + 10.0;
  }

  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 1, 3,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 1U, 3U, c6_dot[1] + 10.0, 160.0, -1, 4U, c6_dot[1] + 10.0 > 160.0)))
  {
    c6_endY = 160.0;
  } else {
    c6_endY = c6_dot[1] + 10.0;
  }

  for (c6_i2 = 0; c6_i2 < 800; c6_i2++) {
    c6_ROIdots[c6_i2] = 0.0;
  }

  c6_idx = 1.0;
  c6_x = c6_startX;
  c6_d = c6_x;
  c6_d = muDoubleScalarRound(c6_d);
  c6_b_x = c6_endX;
  c6_d1 = c6_b_x;
  c6_d1 = muDoubleScalarRound(c6_d1);
  c6_i3 = (int32_T)(c6_d1 + (1.0 - c6_d));
  sf_mex_lw_for_loop_vector_check(c6_d, 1.0, c6_d1, mxDOUBLE_CLASS, c6_i3);
  chartInstance->c6_i = c6_d;
  chartInstance->c6_dataWrittenToVector[4U] = true;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
  c6_c_i = 0;
  while (c6_c_i <= c6_i3 - 1) {
    chartInstance->c6_i = c6_d + (real_T)c6_c_i;
    chartInstance->c6_dataWrittenToVector[4U] = true;
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U, chartInstance->c6_i);
    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 1, 0, 1);
    c6_c_x = c6_startY;
    c6_d2 = c6_c_x;
    c6_d2 = muDoubleScalarRound(c6_d2);
    c6_d_x = c6_endY;
    c6_d3 = c6_d_x;
    c6_d3 = muDoubleScalarRound(c6_d3);
    c6_i5 = (int32_T)(c6_d3 + (1.0 - c6_d2));
    sf_mex_lw_for_loop_vector_check(c6_d2, 1.0, c6_d3, mxDOUBLE_CLASS, c6_i5);
    c6_j = 0;
    while (c6_j <= c6_i5 - 1) {
      c6_b_j = c6_d2 + (real_T)c6_j;
      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 1, 1, 1);
      if (!chartInstance->c6_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 61U, 619, 1);
      }

      c6_d4 = (real_T)c6_image[(sf_eml_array_bounds_check(NULL, chartInstance->S,
        61U, 613, 10, 22U, (int32_T)sf_integer_check(chartInstance->S, 61U, 613U,
        10U, chartInstance->c6_i), 1, 120) + 120 * (sf_eml_array_bounds_check
        (NULL, chartInstance->S, 61U, 613, 10, 22U, (int32_T)sf_integer_check
         (chartInstance->S, 61U, 613U, 10U, c6_b_j), 1, 160) - 1)) - 1];
      if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 1, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c6_covrtInstance, 4U, 1U, 4U, c6_d4,
                          1.0, -1, 0U, c6_d4 == 1.0))) {
        c6_a = c6_dot[0] - chartInstance->c6_i;
        c6_b_a = c6_a;
        c6_c_a = c6_b_a;
        c6_d_a = c6_c_a;
        c6_e_a = c6_d_a;
        c6_c = c6_e_a * c6_e_a;
        c6_f_a = c6_dot[1] - c6_b_j;
        c6_g_a = c6_f_a;
        c6_h_a = c6_g_a;
        c6_i_a = c6_h_a;
        c6_j_a = c6_i_a;
        c6_b_c = c6_j_a * c6_j_a;
        c6_e_x = c6_c + c6_b_c;
        c6_dist = c6_e_x;
        c6_f_x = c6_dist;
        if (c6_f_x < 0.0) {
          c6_p = true;
        } else {
          c6_p = false;
        }

        c6_b_p = c6_p;
        if (c6_b_p) {
          c6_y = NULL;
          sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          c6_b_y = NULL;
          sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          c6_c_y = NULL;
          sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1U, 0U, 2, 1,
            4), false);
          sf_mex_call(chartInstance->c6_fEmlrtCtx, &c6_d_emlrtMCI, "error", 0U,
                      2U, 14, c6_y, 14, sf_mex_call(chartInstance->c6_fEmlrtCtx,
            NULL, "getString", 1U, 1U, 14, sf_mex_call
            (chartInstance->c6_fEmlrtCtx, NULL, "message", 1U, 2U, 14, c6_b_y,
             14, c6_c_y)));
        }

        c6_dist = muDoubleScalarSqrt(c6_dist);
        if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 1, 5,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 4U, 1U, 5U, c6_dist,
                            10.0, -1, 3U, c6_dist <= 10.0))) {
          c6_ROIdots[sf_eml_array_bounds_check(NULL, chartInstance->S, 61U, 735,
            3, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 61U,
            735U, 3U, c6_idx), 1, 400) - 1] = chartInstance->c6_i;
          c6_ROIdots[sf_eml_array_bounds_check(NULL, chartInstance->S, 61U, 769,
            3, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 61U,
            769U, 3U, c6_idx), 1, 400) + 399] = c6_b_j;
          c6_idx++;
        } else if (!chartInstance->c6_dataWrittenToVector[4U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 61U, 744, 1);
        }
      } else if (!chartInstance->c6_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 61U, 663, 1);
      }

      c6_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 1, 1, 0);
    c6_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 1, 0, 0);
  c6_d_i = 0;
  while (c6_d_i <= 799) {
    c6_d_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c6_e_i = 0;
  while (c6_e_i <= 799) {
    if (c6_ROIdots[c6_e_i] == 0.0) {
      c6_ROIdots[sf_eml_array_bounds_check(NULL, chartInstance->S, 61U, 847, 19,
        MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 61U, 847U, 19U,
        (real_T)(c6_e_i + 1)), 1, 800) - 1] = rtNaN;
    }

    c6_e_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c6_b_mean(chartInstance, c6_ROIdots, c6_point);
  chartInstance->c6_dataWrittenToVector[13U] = true;
  for (c6_i4 = 0; c6_i4 < 2; c6_i4++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 28U, c6_point[c6_i4]);
  }
}

static void c6_track_generator(SFc6_flightControlSystemInstanceStruct
  *chartInstance, real_T c6_points[2400], real_T c6_prev_point[2], real_T
  c6_ref[2])
{
  real_T c6_cutting_dots[2400];
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_b_j;
  real_T c6_b_r;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_cnt;
  real_T c6_d;
  real_T c6_d_x;
  real_T c6_d_y;
  real_T c6_delta;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_g_x;
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
  for (c6_b_i = 0; c6_b_i < 2400; c6_b_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 24U, c6_points[c6_b_i]);
  }

  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 25U, c6_prev_point[c6_i1]);
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

  chartInstance->c6_dataWrittenToVector[19U] = true;
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 29U, c6_ref[c6_i3]);
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
          967, 11, 24U, (int32_T)sf_integer_check(chartInstance->S, 82U, 967U,
          11U, c6_b_j), 1, 1200) - 1];
        if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 4U, 9U, 0U, c6_d,
                            0.0, -1, 0U, c6_d == 0.0))) {
          c6_exitg1 = 1;
        } else {
          if (!chartInstance->c6_dataWrittenToVector[4U]) {
            sf_read_before_write_error(chartInstance->S, 0U, 82U, 1138, 1);
          }

          c6_c_y = c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S,
            82U, 1073, 11, 24U, (int32_T)sf_integer_check(chartInstance->S, 82U,
            1073U, 11U, c6_b_j), 1, 1200) + 1199] - c6_const_COG_Y;
          c6_c_x = c6_const_COG_X - c6_points[sf_eml_array_bounds_check(NULL,
            chartInstance->S, 82U, 1098, 11, 24U, (int32_T)sf_integer_check
            (chartInstance->S, 82U, 1098U, 11U, c6_b_j), 1, 1200) - 1];
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

          if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 9, 2,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c6_covrtInstance, 4U, 9U, 2U,
                              c6_delta, 0.26179938779914941, -1, 2U, c6_delta <
                              0.26179938779914941))) {
            c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S,
              82U, 1335, 19, MAX_uint32_T, (int32_T)sf_integer_check
              (chartInstance->S, 82U, 1335U, 19U, c6_cnt), 1, 1200) - 1] =
              c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 82U,
              1357, 11, 24U, (int32_T)sf_integer_check(chartInstance->S, 82U,
              1357U, 11U, c6_b_j), 1, 1200) - 1];
            c6_cutting_dots[sf_eml_array_bounds_check(NULL, chartInstance->S,
              82U, 1382, 19, MAX_uint32_T, (int32_T)sf_integer_check
              (chartInstance->S, 82U, 1382U, 19U, c6_cnt), 1, 1200) + 1199] =
              c6_points[sf_eml_array_bounds_check(NULL, chartInstance->S, 82U,
              1404, 11, 24U, (int32_T)sf_integer_check(chartInstance->S, 82U,
              1404U, 11U, c6_b_j), 1, 1200) + 1199];
            c6_cnt++;
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
                       (chartInstance->c6_covrtInstance, 4U, 9U, 3U, c6_cnt,
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
            1497, 29, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
            82U, 1497U, 29U, (real_T)(c6_e_i + 1)), 1, 2400) - 1] = rtNaN;
        }

        c6_e_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c6_mean(chartInstance, c6_cutting_dots, c6_ref);
      chartInstance->c6_dataWrittenToVector[19U] = true;
      for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
        covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 29U, c6_ref[c6_i5]);
      }

      c6_pre_cnt = c6_cnt;
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 9, 0, 0);
}

static real_T c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_arc, const char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_arc), &c6_thisId);
  sf_mex_destroy(&c6_b_arc);
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

static uint8_T c6_g_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_flightControlSystem, const
  char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_flightControlSystem), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_flightControlSystem);
  return c6_y;
}

static uint8_T c6_h_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
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

static uint32_T c6_i_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_is_c6_flightControlSystem, const char_T
  *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  uint32_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_c6_flightControlSystem), &c6_thisId);
  sf_mex_destroy(&c6_b_is_c6_flightControlSystem);
  return c6_y;
}

static uint32_T c6_j_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
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

static void c6_k_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_b_dataWrittenToVector, const char_T
  *c6_identifier, boolean_T c6_y[20])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_dataWrittenToVector),
                        &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_dataWrittenToVector);
}

static void c6_l_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[20])
{
  int32_T c6_b_i;
  boolean_T c6_bv[20];
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv, 1, 11, 0U, 1, 0U, 1, 20);
  for (c6_b_i = 0; c6_b_i < 20; c6_b_i++) {
    c6_y[c6_b_i] = c6_bv[c6_b_i];
  }

  sf_mex_destroy(&c6_u);
}

static const mxArray *c6_m_emlrt_marshallIn
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  sf_mex_assign(&c6_y, c6_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), true);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_n_emlrt_marshallIn
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
  real_T c6_d1;
  real_T c6_d2;
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

   case 101U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &chartInstance->c6_temp, 0,
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

   case 80U:
    sf_mex_assign(c6_mxData, sf_mex_create("mxData",
      *chartInstance->c6_wieghtMeanPoint, 0, 0U, 1U, 0U, 2, 1, 2), false);
    break;

   case 109U:
    c6_d1 = *chartInstance->c6_arc;
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &c6_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 111U:
    c6_d2 = *chartInstance->c6_seg;
    sf_mex_assign(c6_mxData, sf_mex_create("mxData", &c6_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
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
  chartInstance->c6_wieghtMeanPoint = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c6_arc = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c6_seg = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c6_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1706224182U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3204849275U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1101594827U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1426410784U);
}

mxArray *sf_c6_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
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
    "eNrNls9Kw0AQxjealhb/VPBQegsexUNPoicDghi12GJRxENY0k26tN1IMrX21kfrI/kI7iaxNms"
    "goQk2C8PyLcxmfvlmQpBidBBfhzyG+whV+V7jsYPCVYm0wqMR7eG5ujrXeMD8nYhz37OMAd8Zng"
    "QaTz8NZrvB/Rfo9/5qwv3K2v316DxcX1e58vU3XeS31/LVhPzdtfwjrrBnBXX/vJ+t1Y/ugvr1l"
    "PoPYvWH2poCUOaYdIIdEnFsn+csE8+exCO0R+yu61OgLltxbJ1nuVl/+cQpiR/9TH40JD+EnlHi"
    "DKFDMOu6lEFBPDU9V/6il8kPJcajIFpYP+Wt3/iTn1R/VfJDaOo/UEZKwoFON55zwCPyaNs3Y+w"
    "UOOc5efTXTH2lxnhUBGTyXor6l71MftQlP4QWDOGEo/L4gS4zzUlF4hEahgRwYRxaTo7w+d0UDk"
    "3i0IJ5N7EF9IOY1rlpjyn/GF+7DDx3/DT3uWnF8J38C19L4muFfMlghfZhTr7FfZB/m8LXlPiaI"
    "R8jMxM8bI1MhzDi4eDfphiudiG+pXEdS1xCDzDgF48CENZ3n4kFrhfz6xsMYX4Z"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sV3XJ22BxdIUBCICR0GtJWE";
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
  const char* encStrCodegen [32] = {
    "eNrtWltvG0UUXqdO1FtKWsqlEhJWpCilikJoJS5RKWmcBFwcktZOWsSDmeyetYfsziwzs04iIdE",
    "nxAt/gCce4YXf0Dde+QH8CB555MzuOrXH67vbWIKVNtbMnnPmfOc2t1iZwraFzxV8v16wrBn8PY",
    "/vlBU/00k70/TG/VlrMWn/hEws9HeJIL60uj6M+PAIJPdCRTkrMJenklHmggBmI23AheokTVI/9",
    "Cg73AqZreXJxzVq10o1HnrOOvISZ4d5JygtCNUuytmgAmy1BeComuBhtbblkeqpxkId5WtgH8rQ",
    "7wZBgiqFgVZLboeeooEHm8dgF5hUBDWWz3UrKaIgr447wtRIZalByP3Ao4Sloq0RWYIADaxgL3D",
    "w706oEJRJZteIUOtQI3WQRXoYyeQMTJlU4ocDyojighJv0/fymrFdt10P9dnmDnhdDIK6rQsghw",
    "GnTHX2f2kLkW4ycuDBBhyE1c7SSvBtqJ2/T+EIREe7uXleB0GqsMM6DhoZZPM48tZplLSTKerDP",
    "hH3bfSfBKdj9GLkyBJBP0EZOTqRQQSyIMuC1tG8HaWFfkFHZq+UCf3Y2bIXWSRtsw7dvHAqbctm",
    "eeJ5siNZmQdFqIMXSd0ginQni6Wm00lJnTJHA+vw7pwNIaPo+IQsz5lDU91VNwiiuvMFFpZWSju",
    "Uivt5DN6NYrH9cztZgSkQLrEhrQoIQiWgzSLzdpbmUKl9j4SolYrUSyOOI6QXlSXdkG0ccXGINu",
    "lSRJ5D0B7tSOjLKvoSM2FPYtJ0I9O+7EVnE7sGji4w1INtTBukTbGJ1KXtPuZdnaqTDZC2oEGKV",
    "0PMOixDmzqgTgLYY4eMH7Etwf1SUuNj8wJgtBHBKKuuY/0SJ1s4epor9Hy2Yj2fzy73MZ81+Mzf",
    "m01yMilyrKZfTf9hE/2FqVb6aWPcqUaffhL+tSb+WWO8rMGv6ebw/V799c9rl/+49N0PDG7t//6",
    "bid/UI9OmR8ZqjP/m7GDrgCtJ+61GwT1NoHpb3Graz5r0yqbIf6NJ/lzSlvt3njy4fXv92Cnsre",
    "cL+Ucrn6oHjzcjebXL3fV9xdC30Z/TlR+jLYpTYRecZIGi2ySMp23TnzM97HEh6Y+fvz8ZiX/tq",
    "zXTj2n2Otdir3MWEXZL/J6Z/taDNTOe0/SfNfw9G9U0pTDJK9THumLk49nhWeoLzyUDj24LcHe5",
    "jEp9W305MzzPhosvCdUJ8Ue5L3+8YvhDt48oVGtqGwjb1cvWMeE5vzYS/9OHffkj04InY9GxxdO",
    "o+hfa+NP0nzH8MROt54uUwYTgsG4NneeKHMKO6+qN5RjzfEQ8a1/2FVfZFjxZS4EfTIT+zx725Y",
    "8Lhj90W2OIM9yaHH9YH/WVJ9MGHt1WNYh2WOPBkRsRRzz+bg8cOQNHLsr3CtG7AqjY71dcj2Ixx",
    "g2dEtwrnUh02njwzb8UfDcMfDdifOnAxhqHI+J7+vnasOtxxMfgqKIEsQ8rVWAgSLS2GQ+ulbH4",
    "rReuVw1cuu0QRR4LqhSwMt8HW3HR5q9h91WD8ln/800EX+Y/iK+f85Lpl8xnvWS+UfENem40afT",
    "d1ouWQT83wThGPc8b2G7Z7vQZU7/sYOdtryftn/HlB9/gJFUqFZzW25HkRPY+2xQimcIsP+4rw3",
    "HzVU/Su/eoaLX3lpPjsdbeIrej2b6kolsjo7cIrKpqHeJotge+mQ75Okj9+zXTfd4/zrTGrW7fJ",
    "bmaAPfjeZ8ojxysSjcQtE4U3FyU7k4AbCcy9PoJWnpxaXHBOWHEp/ZCdN6p7zcWVldX31u5s/jO",
    "/L1FjziUVfUecPHuu+RejsqcAy7ub52l3EGodJtxldOH3jnKcrimz0VXgK7Hj3KRxOVcQ6FcQyO",
    "kVCAY8ZZlg3bZocTjVbm8x7SsWMUN8AAJl20BSJa0bnbXOKZCRVCzOKIivblIUaPJMhztgotbl1",
    "bju9/S1gYlVcalorZcXLp9B0Xb0fdQQATTOf2uB1i+eLGf9fXbRp3R7VN7rdqOWI3x68unHRHd0",
    "FjD7q/0LYo4o/np6fRgdaBhl3unV2z5GvWclNuW5HMRiJv2NRn/zx51K9tlfhgkr3+ZGgzntaR9",
    "LbpfQIQF57jM9Y3ZNgma1/tT3fU/P6L+mT73FdeNuLoeXR2nbJaG1GMq4XvSQ495Q4/56D5OEL0",
    "nrXhYjiqY2fH/WRhaDafXuZR9X7aHH+aStj43q3DXHWbcbJ9+uWqMe7Vp3Iqt//0Ci+AI8fFBwv",
    "dj5sXE90rmxeZnv/Gddh5gE88OPazJlUBAnYayEpyeqw8b373O++YMPfRr5tikrUf/BdQKGgM=",
    ""
  };

  static char newstr [2325] = "";
  newstr[0] = '\0';
  for (i = 0; i < 32; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c6_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c6_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(4175197311U));
  ssSetChecksum1(S,(197594133U));
  ssSetChecksum2(S,(1701742204U));
  ssSetChecksum3(S,(2846774826U));
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
