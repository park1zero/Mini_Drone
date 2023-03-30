#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#ifndef flightControlSystem_COMMON_INCLUDES_
#define flightControlSystem_COMMON_INCLUDES_
#include <stdio.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "coder_posix_time.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "flightControlSystem_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "zero_crossing_types.h"
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { int8_T fau3qf03xm ; } hrtts4l5bc ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real32_T fx5e20wl0l [ 2 ] ; } orji2pbk05 ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { int8_T mkkaskumzr ; boolean_T jhr0womnye ; } imbf3wrgri ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real32_T nwh2go4n55 [ 2 ] ; } dyc32xehtl ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { int8_T ley0an2uip ; boolean_T njk4w5jozv ; } gabr0rnvjj ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { gcv4dcppet WorkingSet ; nyazh5yq1j QRManager ; ov1jwgmha0
memspace ; real_T B [ 90321 ] ; real_T b_I [ 89600 ] ; jkcbyyifjr
CholRegManager ; real_T e [ 25600 ] ; real_T temp_PI [ 19200 ] ; real_T d [
19200 ] ; int8_T b_I_mbvzarwird [ 25600 ] ; int8_T c_I [ 25600 ] ; int8_T Q [
14400 ] ; ltrtju4vjy solution ; real_T work [ 561 ] ; real_T work_cl54gopm0x
[ 561 ] ; real_T vn1 [ 561 ] ; real_T vn2 [ 561 ] ; real_T f [ 560 ] ;
ofcwsyrt4s unusedExpr ; int8_T Gamma [ 1440 ] ; real_T work_kkiq3xxxve [ 161
] ; real_T x0 [ 160 ] ; real_T y [ 160 ] ; real_T a [ 160 ] ; real_T
y_cxarnvbvui [ 160 ] ; real_T ref_const [ 120 ] ; real_T temp_ref [ 120 ] ;
real_T epsilon_r [ 120 ] ; real_T y_bhxxfovxdy [ 120 ] ; real_T a_pbm3vprmfu
[ 120 ] ; real_T nfdaslwhu3_cv5hdgrwft [ 32 ] ; edgtad0wpy options ; real_T
temp_x [ 12 ] ; real_T m0prrxrah4_fqdqrf4qbc [ 10 ] ; real_T
nheu4vekt1_g2mlkqadfk [ 10 ] ; real32_T gnquibkpb4_g1smspu5ke [ 16 ] ;
real32_T dwhcomghda_merlcviukg [ 12 ] ; real32_T jfdz03jt1m_nz4o0shxby [ 9 ]
; real_T la31d0wa4f ; real_T cmdnc1sw5x [ 2 ] ; real_T gemwakdk4n ; real_T
fmqfyj5qyn [ 3 ] ; real_T jsscz4ikcj [ 2 ] ; real_T crtlx3liql [ 2 ] ; real_T
k04inknhkl [ 4 ] ; real_T l5leu22u3x_ppxrqq0gsf [ 4 ] ; real_T
jfdz03jt1m_llw0u2ae0v [ 3 ] ; bvhqttcz4x expl_temp ; real32_T
l3upkjhcpj_jwzvbuczlb [ 4 ] ; real32_T almh1vhi0c_dhmrxtyqop [ 4 ] ; real32_T
kbaobol53s_guugdwf2m3 [ 4 ] ; real_T lkbxk4xvcr [ 2 ] ; real_T aswlkrus4a [ 2
] ; real_T cujuc5l4w4 [ 2 ] ; real_T opvv4bmqa5 [ 2 ] ; real_T
oo4kxjylim_ldqodwenvz [ 2 ] ; real32_T gdgmg3lyzy_dhamdvybc1 [ 3 ] ; real32_T
ls05pdbprn_dypejvacrn [ 3 ] ; real_T ml5yogcxp1 ; real_T bxan3ie5rd ; real_T
b5sifbodon_lxo5edjg3c ; real_T pmqbdr5cs1_owjr1h1vqy ; real_T
epsilon_r_bjbgfqrolh ; real_T b4vpalwgb1_idx_1 ; real_T b4vpalwgb1_idx_2 ;
real_T b4vpalwgb1_idx_3 ; real_T nnv52c40m3_idx_0 ; real_T nnv52c40m3_idx_1 ;
real_T tol ; real_T colSum ; real_T f_infnrm ; real_T b_colSum ; real_T
maxConstr_new ; real_T d_nuebgmauvi ; real_T tolDelta ; real_T normDelta ;
real_T s ; real_T temp ; real_T temp_tmp ; real_T tempMaxConstr ; real_T
constrViolation_basicX ; real_T c ; real_T b_c ; real_T constrViolation ;
real_T tol_bsqwvugooi ; real_T qtb ; real_T temp2 ; real_T smax ; real_T
s_lnjdk5wtww ; real_T xnorm ; real_T a_hv2ho1zopz ; real_T scale ; real_T
absxk ; real_T t ; real_T smax_bnlywzniup ; real_T s_dapv3jlyq5 ; real_T
temp_ezqlmfzvpq ; real_T obj ; real_T b_atmp ; real_T tau ; real_T
c_bjvjhhzy4i ; real_T c_c ; real_T b_s ; real_T b_temp ; real_T b_temp_tmp ;
real_T roe ; real_T absa ; real_T absb ; real_T scale_jzx3amusab ; real_T ads
; real_T bds ; real_T p_max ; real_T denomTol ; real_T phaseOneCorrectionX ;
real_T phaseOneCorrectionP ; real_T pk_corrected ; real_T c_fdinthrxmb ;
real_T workspace ; real_T c_al00mdgrv4 ; real_T denomTol_ju13rw2h0m ; real_T
alphaTemp ; real_T phaseOneCorrectionP_jz50ptvnrg ; real_T ratio ; real_T
c_o4f35lbcvx ; real_T scale_nyxm0bsxsn ; real_T absxk_icdfyazkhu ; real_T
t_oyypvi4boh ; real_T alpha1 ; real_T temp_nvsvtgkap4 ; real_T c_m3yhjduhi1 ;
real_T c_czkfpwuzm5 ; real32_T iigja3ninj [ 2 ] ; real32_T lcl1k15zft [ 6 ] ;
real32_T ihknv3fqew [ 2 ] ; real32_T ozxkzplgaw_mdoasc5av4 [ 2 ] ; real32_T
ho41tiwhb5_m3ybdk4ikc [ 2 ] ; real32_T knxkoin2rf_jacdjrqyev [ 2 ] ; real32_T
cblnjjku2z_h522xzlxvt [ 2 ] ; real32_T mm3c4nxpnx_c0dok3111h [ 2 ] ; real32_T
cmoemunv2z_ctvw0tpkon [ 2 ] ; real32_T iy1kt1wz2c_pxqvlbal2i [ 2 ] ; real32_T
horqhogtqf_p5h3gwuwqg [ 2 ] ; real32_T cau5lj2g4y_afnsueciae [ 2 ] ; real32_T
kdbqn4yen2 ; real32_T oewyb4hpkt ; real32_T lvcltlvcb2 ; real32_T jvll40ipis
[ 3 ] ; real32_T npyo0xy4z3 ; real32_T hdrw0q5w3h ; real32_T bql5vncjzu ;
real32_T jeecavgljy [ 3 ] ; real32_T aztnumgcop [ 2 ] ; real32_T c2yujdqyow [
2 ] ; real32_T hfwsxbuwzs [ 4 ] ; real32_T f1ltscvoat ; real32_T jces0qybkg ;
real32_T ndy0vigekn [ 2 ] ; real32_T kradmmk3k2 [ 2 ] ; real32_T nwa53khrtx ;
real32_T lbn03hfkye [ 4 ] ; real32_T paymkuktx2 [ 2 ] ; real32_T ey5yvwomte [
2 ] ; real32_T jskkkllmvx [ 2 ] ; real32_T fkcsesa2rl [ 4 ] ; real32_T
jzvlajwp0e [ 3 ] ; real32_T nxzgmcxp2c [ 16 ] ; real32_T fhoe32siei [ 2 ] ;
real32_T h4l5x0xnby [ 2 ] ; real32_T l3upkjhcpj [ 4 ] ; real32_T cau5lj2g4y [
2 ] ; real32_T jiywlwgprx [ 2 ] ; real32_T hse0iniodn [ 2 ] ; real32_T
c3u1mb1nsw [ 4 ] ; real32_T fpn5su0bht [ 2 ] ; real32_T jgucqrzqio [ 8 ] ;
real32_T ebaaxyxnyj [ 8 ] ; real32_T d0zwmdv0aj [ 16 ] ; real32_T ktfzqoiio4
[ 4 ] ; real32_T gvji0ewqkz [ 4 ] ; real32_T emggr4xs4n [ 4 ] ; real32_T
na4bohncmr ; real32_T close_x ; real32_T close_y ; real32_T
d5hucejpxh_evg4t2fsev ; real32_T hdnzauffra_ax3wx1gs5w ; real32_T
o3syt3j40h_as0qznsxlv ; real32_T o1lc5nh5zk_ifotjnizh4 ; real32_T
fpn5su0bht_idx_0 ; real32_T fpn5su0bht_idx_1 ; real32_T fpn5su0bht_idx_2 ;
real32_T fpa5hclvjq_idx_1 ; real32_T fpa5hclvjq_idx_2 ; real32_T
bzfrsxsgu2_idx_0 ; real32_T bzfrsxsgu2_idx_1 ; real32_T jfj5y4wnot_idx_1 ;
real32_T jfj5y4wnot_idx_2 ; real32_T bzfrsxsgu2_idx_2 ; real32_T
bk4rxj1pbk_idx_1 ; real32_T kpv4qlt1uc_idx_1 ; real32_T kpv4qlt1uc_idx_2 ;
real32_T bk4rxj1pbk_idx_2 ; real32_T l3upkjhcpj_ltu3syw14q ; real32_T
kdclx4fqk4_ojunzewo4f ; real32_T fqtb2q5dhp_o2tow3gxzm ; real32_T
jhsfld5pu1_ipgns4eet5 ; real32_T iu5u1ztrlk_fkr0r45bcn ; int32_T cff ;
int32_T denIdx ; int32_T memOffset ; int32_T i ; int32_T temp_PI_tmp ;
int32_T colPos ; int32_T b_idx_row ; int32_T i_izlwqhinl5 ; int32_T
i_fft32lqtda ; int32_T PROBTYPE_ORIG ; int32_T nVar ; int32_T mConstr ;
int32_T idxStartIneq ; int32_T idxEndIneq ; int32_T idxStartIneq_tmp ;
int32_T activeSetChangeID ; int32_T nVar_gxhmnjv5xa ; int32_T
localActiveConstrIdx ; int32_T globalActiveConstrIdx ; int32_T TYPE ; int32_T
Qk0 ; int32_T iyend ; int32_T i_covwwkkf2n ; int32_T jjA ; int32_T d_ix ;
int32_T e_tmp ; int32_T nVar_o32uf0f2k4 ; int32_T idx ; int32_T d_lmeaga4sr3
; int32_T iac ; int32_T jBcol ; int32_T iAcol ; int32_T br ; int32_T ar ;
int32_T h ; int32_T l ; int32_T mWConstr_tmp_tmp ; int32_T iQR0 ; int32_T
idx_mvr1suhnoo ; int32_T ia ; int32_T itau ; int32_T lastc ; int32_T
f_mjmkwwa5je ; int32_T coltop ; int32_T c_ia ; int32_T jA ; int32_T
i_cnk35bhqvj ; int32_T b ; int32_T idxStartIneq_fme3ifz5tm ; int32_T
idxEndIneq_p43y5eooqm ; int32_T idxStartIneq_tmp_e13kp1af4b ; int32_T idx_row
; int32_T idx_col ; int32_T iy0_tmp ; int32_T mTotalWorkingEq_tmp_tmp ;
int32_T TYPE_tmp ; int32_T TYPE_tmp_o4akcuk44c ; int32_T totalRank ; int32_T
b_hh0jorglq2 ; int32_T ix ; int32_T minmn ; int32_T nfxd ; int32_T
i_l5yj2lrthv ; int32_T minmn_h255b31ynd ; int32_T ii ; int32_T nmi ; int32_T
mmi ; int32_T pvt ; int32_T itemp ; int32_T idxmax ; int32_T i_mert0vuy2i ;
int32_T knt ; int32_T c_mcke2mvmgq ; int32_T scalarLB ; int32_T vectorUB ;
int32_T vectorUB_tmp ; int32_T kend ; int32_T k ; int32_T
idxStartIneq_h34q0rd5y0 ; int32_T idxEndIneq_csvudntq5v ; int32_T
i_klmngopk1n ; int32_T idxStartIneq_tmp_pcqitb31bm ; int32_T nVar_pxv1dlndn0
; int32_T nullStartIdx ; int32_T nVars ; int32_T A_maxDiag_idx ; int32_T
k_p4u43j1tg5 ; int32_T b_A_maxDiag_idx ; int32_T b_order ; int32_T lastColC ;
int32_T br_appanwio2d ; int32_T ar_jdc3mylhw0 ; int32_T h_ekaxkojgre ;
int32_T i_olzclp30in ; int32_T b_ar ; int32_T e_ix ; int32_T
vectorUB_bbahwrwppi ; int32_T subRows ; int32_T LD_diagOffset ; int32_T
W_diagOffset ; int32_T offsetColK ; int32_T FMat_offset ; int32_T
k_ao3bw4rxqa ; int32_T b_idx ; int32_T ix_g2zhzn021n ; int32_T iac_ex1giwvd5a
; int32_T d_fi0130k5dq ; int32_T b_ix ; int32_T e_h22x25zmds ; int32_T
ar_eikkpx0qsf ; int32_T b_chiskqqvhf ; int32_T idx_axzrpos33g ; int32_T
scalarLB_daul3jxkyn ; int32_T vectorUB_af2thr01pj ; int32_T minmn_pbbtpb1rfa
; int32_T i_msq3zq0e5q ; int32_T ii_o3vthkjscz ; int32_T mmi_nhwg0qilgg ;
int32_T b_lukfkbsu1g ; int32_T i_pe3k2xoqfh ; int32_T lastv ; int32_T
lastc_ptgtsmqbea ; int32_T d_fts4uyq0ss ; int32_T coltop_ieb43zpzad ; int32_T
b_ia ; int32_T jA_oxmcy3hihv ; int32_T i_kkejeebp3v ; int32_T k_ieu0h5zwzh ;
int32_T idxRotGCol ; int32_T QRk0 ; int32_T b_n ; int32_T e_k ; int32_T
temp_tmp_occ0bygi5g ; int32_T b_temp_tmp_m4t0acbuzi ; int32_T k_cuicvykoli ;
int32_T d_fbjryyzszc ; int32_T ia_hcid3xt4ul ; int32_T b_iy ; int32_T
b_m44y1ux0fn ; int32_T ia_adswhasjnz ; int32_T k_kbaaiuavyx ; int32_T
d_pcrreipf50 ; int32_T ia_bp2fpdopsx ; int32_T b_chpeguaxzo ; int32_T
k_nbxe2teimf ; int32_T LD_diagOffset_ijsndrapq0 ; int32_T subMatrixDim ;
int32_T lastDiag ; int32_T b_k ; int32_T jA_myehykrizd ; int32_T b_jgiszipbhz
; int32_T ijA ; int32_T idx_evksky1jli ; int32_T b_mvxbpuuaod ; int32_T
ix0_tmp ; int32_T idx_m0xhdjns4u ; int32_T b_ixlast ; int32_T
scalarLB_jgstdh5dqy ; int32_T vectorUB_fo3oqwgntj ; int32_T ix_a5dhqtkgkb ;
int32_T b_glbbddhyxk ; int32_T b_iy_nr53svjpx4 ; int32_T c_d3eqbmfocd ;
int32_T d_naew030a0s ; int32_T i_cgyowummyi ; int32_T k_fxly3hgnbl ; int32_T
d_pm0wd15uoc ; int32_T ia_p2whnu1ymc ; int32_T k_njhishb51z ; int32_T
d_ktmj3zgz1y ; int32_T ia_n3mxoohuju ; uint32_T pwoehsu5l0 ; uint32_T
mz4zmu520c ; uint32_T jzmlqcojs2 ; uint32_T ef5jpxj5a3_oyhcjzyii5 ; uint32_T
o2r5wsgoa2_ggqm4nyunq ; uint32_T gdfrkrdmai_cqp4bgasty ; uint32_T
n1jcqflmid_cjesfvi0we ; uint32_T i5dskatkch_m1w4njeeya ; uint32_T
f2bgfnbomc_jp1ecvjvsf ; ZCEventType zcEvent ; uint16_T mxiokbtqip ; int16_T
kfnf13abq1 ; uint16_T famo41p2gw_kndmi42lhh ; uint16_T mrkfq5tipe_mxuc1cgjcl
; int8_T i1 ; int8_T Gamma_tmp ; uint8_T ndxe1wrf0w ; boolean_T n1fnyp0fl3 ;
boolean_T mklrvnllno ; boolean_T beoa1s1ubm ; boolean_T bm4oeojoo3 ;
boolean_T rEQ0 ; boolean_T l5domdhp1h_prp1qafhdl ; boolean_T
lkbxk4xvcr_dzvni1mwtz ; boolean_T h0s1xa4s0a_g4tki034ae ; boolean_T
hvntlkjnb5_c3tm3oisdo ; boolean_T o3giufoopp_cxqpgsalap ; boolean_T
hslpiw1gp5_ifekuolqfy ; boolean_T hrjsuykfkm_dxyhn1e5lq ; boolean_T
dnw3ewtrvi_g4ktxjhu5x ; boolean_T gbhtgjclae_lgknkauzw5 ; boolean_T
hv1dvtuern_f1dz14dud1 ; boolean_T lsxmsraahg_dbmzd1yyab ; boolean_T
duty41u4nz_jr52qkp2tw ; boolean_T subProblemChanged ; boolean_T updateFval ;
boolean_T newBlocking ; boolean_T nonDegenerateWset ; boolean_T okWorkingSet
; dyc32xehtl ipbtas1tys ; orji2pbk05 bm3dpymkhz ; dyc32xehtl ifzbhw4mrws ;
orji2pbk05 phrpuocqmvu ; } eo4bbte2ey ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { kyukv4umxq hq3yrsksha ; real_T mi4mocbazh ; real_T
mtonzezz2z [ 2 ] ; real_T ddv3ztj2wp [ 3 ] ; real_T bw2ribqmwm ; real_T
f2ynnmexgv ; real_T mxh1shgtae ; struct { void * AQHandles ; } puq03cpvbg ;
real32_T b3fmbw5stg [ 2 ] ; real32_T aq2aymvaio [ 3 ] ; real32_T dzwopklw3c ;
real32_T d4fp3a2mpz [ 15 ] ; real32_T fl0vv44tbs [ 2 ] ; real32_T as5a0ikbk1
[ 2 ] ; real32_T ncgo1wegzg ; real32_T mirtkskmtr ; real32_T jduomia1pb [ 5 ]
; real32_T od5c00niot [ 4 ] ; real32_T dqfv1m130o [ 10 ] ; real32_T
meognsjf1t [ 2 ] ; real32_T gcgpru4rcb [ 2 ] ; real32_T peklmaellz [ 2 ] ;
real32_T bsetqjfri4 ; real32_T dsjbzv2lh4 [ 2 ] ; real32_T gixvkpnpus [ 2 ] ;
real32_T ow5xb5ovt0 [ 2 ] ; real32_T krs1cvkxzk [ 2 ] ; real32_T c4kiksmhh2 ;
int32_T bbkjtf4kuy ; uint32_T l3lcputuyl ; uint32_T pjgu33zeph ; uint32_T
dxm3w2i52x ; real32_T orkq4iljgu ; real32_T b1nmhkw4zo ; real32_T n0mydijbcx
; real32_T iwg03owvar ; real32_T mf2pp40f5v [ 2 ] ; real32_T pwlp5beuqs [ 2 ]
; real32_T epa52s1rno ; real32_T hzslycglry ; real32_T aulr5ajjs0 ; real32_T
bxx1qp4vj4 ; uint16_T gaxgdudnvc ; int8_T dq5lalhp1e ; int8_T fpr1qi0oiw ;
int8_T klyrn0mwhb ; int8_T mfifybuxty ; int8_T a1oodzfxvv ; int8_T mgysgsd2g4
; int8_T idn2v5d33m ; int8_T l1rfy2ptxy ; boolean_T de4yc1bkky ; boolean_T
jd3dqtmo2p ; boolean_T f1jy25gy04 ; boolean_T gdn4qfzvsk ; boolean_T
k4ziqru4qd ; boolean_T a1bh1mexmu ; boolean_T erjq1mwcrc ; boolean_T
cqi2pi21ow ; boolean_T kh1khihcrt ; boolean_T iftedegxuv ; boolean_T
g4zcogq4xi ; gabr0rnvjj ipbtas1tys ; imbf3wrgri bm3dpymkhz ; gabr0rnvjj
ifzbhw4mrws ; imbf3wrgri phrpuocqmvu ; hrtts4l5bc ciy1c2o0rv ; hrtts4l5bc
jvbbqhrajh ; hrtts4l5bc clwiujjdqo ; hrtts4l5bc acfz1zxm4t ; hrtts4l5bc
ghadbep3bbv ; } dmp1xsadgu ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T b3ouxrig41 ; real_T pmyk44zbli ; } k5baggiqtb ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { ZCSigState b1rw3rggh2 ; ZCSigState j5kztqwkpa ; } ph1mky0ofs
;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T landingDots [ 38400 ] ; real_T i1lmeqimid_mbvzarwird
[ 38400 ] ; real_T pxeif1fbso_cl54gopm0x [ 19200 ] ; real_T
fikdflw4dv_kkiq3xxxve [ 19200 ] ; real_T L [ 19200 ] ; real_T P [ 9601 ] ;
real_T beaob0p0vg_cxarnvbvui [ 2400 ] ; real_T cutting_dots [ 2400 ] ; real_T
cutting_dots_bhxxfovxdy [ 2400 ] ; real_T cutting_dots_pbm3vprmfu [ 2400 ] ;
boolean_T fd3rrijpnz_cv5hdgrwft [ 19200 ] ; boolean_T glqyipdsp0_fqdqrf4qbc [
19200 ] ; boolean_T kgslz4vfm1_g2mlkqadfk [ 19200 ] ; boolean_T
ogroidm0iq_g1smspu5ke [ 3600 ] ; int32_T chunksSizeAndLabels [ 168 ] ; real_T
ctiwh0b1mh_merlcviukg [ 6 ] ; real_T ndqel51t5k_nz4o0shxby [ 4 ] ; real_T
nkzwvpgixu_ppxrqq0gsf [ 4 ] ; coderTimespec b_timespec ; coderTimespec
b_timespec_jwzvbuczlb ; real_T c35qj3wvdc [ 2 ] ; real_T akxhlqbcgs [ 2 ] ;
real_T lwq4zd1jpf [ 2 ] ; real_T center [ 2 ] ; boolean_T
kgslz4vfm1_llw0u2ae0v [ 16 ] ; int32_T counts [ 2 ] ; real_T msobbfyue1 ;
real_T h4ftxu0r5x [ 19200 ] ; real_T num_dots ; real_T dist ; real_T scale ;
real_T absxk ; real_T t ; real_T absxk_tmp ; real_T prev_theta ; real_T cnt ;
real_T plus_degree ; real_T pre_cnt ; real_T delta ; real_T delta_tmp ;
real_T delta_tmp_dhmrxtyqop ; real_T P_idx_1_tmp ; real_T tstart_tv_sec ;
real_T tstart_tv_nsec ; int64_T i ; real32_T nkzwvpgixu_guugdwf2m3 ; real32_T
enu2i2tnb1_ldqodwenvz ; int32_T b ; int32_T d ; int32_T xpageoffset ; int32_T
ky ; int32_T ku ; int32_T j ; int32_T nhCols ; int32_T i1 ; eo4bbte2ey
otjykwnhb3s ; } ircitwx3zdm ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { boolean_T hl34rmozzp [ 30929 ] ; boolean_T my54orxad4 [
30929 ] ; kyukv4umxq jpew5kksh3 ; real_T oq44mkeutp [ 8 ] ; real_T idkr2rlgq2
; real_T d0oosu3eno ; real_T o3dgrmabdz ; real_T oqbrk4g3dg ; real_T
duvnxnbg1i ; real_T mx4idkqrdn ; real_T jygvx1tqyy ; real_T punu1gak5h ;
real_T mdjfrpxwg4 [ 2 ] ; real_T lcmsgvnwk5 ; struct { void * AQHandles ; }
puq03cpvbg ; struct { void * AQHandles ; } ehurgiqcu1 ; real32_T cvte14aviy ;
real32_T ov1i3orwof ; real32_T mhobc1j1zw ; int32_T ex0cncdzgs [ 6 ] ;
int32_T f3tlra1rjy [ 6 ] ; int32_T o42whxzij4 [ 130 ] ; bjqsgn0csy l152eirbdu
; int8_T fb0f52aifb ; int8_T f002cq3idt ; int8_T ljgqi3o5y0 ; int8_T
kks5zssfkj ; uint8_T baddwxorq2 ; uint8_T hxwn30vi3o ; uint8_T gptufoudya ;
uint8_T meb5oyxx0i ; boolean_T jjrfotind4 ; boolean_T eo2hqy0qfu ; boolean_T
l31vpsvpgf ; dmp1xsadgu otjykwnhb3s ; } nllkaxiwhzw ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { k5baggiqtb otjykwnhb3s ; } h5liyesltnn ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { ph1mky0ofs otjykwnhb3s ; } cspyln32yuv ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct bpvdgm2xq5_ { uint8_T P_0 ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct je33m1dqwd_ { real32_T P_0 ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct fpqg1jdlo0_ { real32_T P_0 ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct nu4qaxumex_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real32_T P_6 [ 2 ] ; real32_T P_7 [ 2 ] ; real32_T
P_8 ; real32_T P_9 ; real32_T P_10 ; real32_T P_11 ; real32_T P_12 ; real32_T
P_13 ; real32_T P_14 ; real32_T P_15 ; real32_T P_16 [ 2 ] ; real32_T P_17 ;
real32_T P_18 ; real32_T P_19 ; real32_T P_20 [ 2 ] ; real32_T P_21 ;
real32_T P_22 ; real32_T P_23 ; real32_T P_24 ; real32_T P_25 ; real32_T P_26
; real32_T P_27 ; real32_T P_28 ; real32_T P_29 ; real32_T P_30 ; real32_T
P_31 ; real32_T P_32 ; real32_T P_33 ; real32_T P_34 ; real32_T P_35 ;
real32_T P_36 ; real32_T P_37 ; real32_T P_38 ; real32_T P_39 ; real32_T P_40
; real32_T P_41 ; real32_T P_42 ; real32_T P_43 ; real32_T P_44 ; real32_T
P_45 ; uint32_T P_46 ; uint32_T P_47 ; uint32_T P_48 ; uint32_T P_49 ;
uint32_T P_50 ; uint16_T P_51 ; uint16_T P_52 ; real_T P_53 ; real_T P_54 ;
real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T
P_60 [ 4 ] ; real_T P_61 [ 4 ] ; real_T P_62 ; real_T P_63 ; real_T P_64 ;
real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T
P_70 [ 4 ] ; real_T P_71 [ 2 ] ; real_T P_72 [ 2 ] ; real_T P_73 [ 4 ] ;
real_T P_74 [ 2 ] ; real_T P_75 [ 2 ] ; real_T P_76 ; real_T P_77 [ 4 ] ;
real_T P_78 [ 2 ] ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ;
real_T P_83 [ 2 ] ; real_T P_84 [ 3 ] ; real_T P_85 [ 4 ] ; real_T P_86 [ 2 ]
; real_T P_87 [ 2 ] ; real_T P_88 [ 4 ] ; real_T P_89 [ 2 ] ; real_T P_90 [ 2
] ; real_T P_91 ; real_T P_92 [ 3 ] ; real_T P_93 [ 16 ] ; real_T P_94 [ 8 ]
; real_T P_95 [ 8 ] ; real32_T P_96 ; real32_T P_97 ; real32_T P_98 ;
real32_T P_99 [ 2 ] ; real32_T P_100 ; real32_T P_101 ; real32_T P_102 ;
real32_T P_103 ; real32_T P_104 ; real32_T P_105 ; real32_T P_106 ; real32_T
P_107 ; real32_T P_108 ; real32_T P_109 ; real32_T P_110 [ 4 ] ; real32_T
P_111 [ 4 ] ; real32_T P_112 ; real32_T P_113 ; real32_T P_114 ; real32_T
P_115 [ 6 ] ; real32_T P_116 [ 6 ] ; real32_T P_117 ; real32_T P_118 [ 6 ] ;
real32_T P_119 ; real32_T P_120 [ 2 ] ; real32_T P_121 [ 2 ] ; real32_T P_122
; real32_T P_123 [ 2 ] ; real32_T P_124 [ 2 ] ; real32_T P_125 ; real32_T
P_126 [ 6 ] ; real32_T P_127 [ 6 ] ; real32_T P_128 ; real32_T P_129 ;
real32_T P_130 [ 6 ] ; real32_T P_131 [ 6 ] ; real32_T P_132 ; real32_T P_133
; real32_T P_134 ; real32_T P_135 ; real32_T P_136 ; real32_T P_137 ;
real32_T P_138 ; real32_T P_139 ; real32_T P_140 ; real32_T P_141 ; real32_T
P_142 ; real32_T P_143 ; real32_T P_144 ; real32_T P_145 [ 2 ] ; real32_T
P_146 [ 2 ] ; real32_T P_147 ; real32_T P_148 ; real32_T P_149 ; real32_T
P_150 ; real32_T P_151 ; real32_T P_152 ; real32_T P_153 ; real32_T P_154 ;
real32_T P_155 ; real32_T P_156 ; real32_T P_157 ; real32_T P_158 ; real32_T
P_159 ; real32_T P_160 [ 4 ] ; real32_T P_161 ; real32_T P_162 ; real32_T
P_163 ; real32_T P_164 ; real32_T P_165 ; real32_T P_166 [ 16 ] ; real32_T
P_167 ; real32_T P_168 ; real32_T P_169 ; real32_T P_170 ; real32_T P_171 [ 4
] ; real32_T P_172 [ 2 ] ; real32_T P_173 [ 2 ] ; real32_T P_174 ; real32_T
P_175 [ 4 ] ; real32_T P_176 [ 4 ] ; real32_T P_177 [ 2 ] ; real32_T P_178 [
2 ] ; real32_T P_179 [ 4 ] ; real32_T P_180 ; real32_T P_181 [ 2 ] ; real32_T
P_182 [ 4 ] ; real32_T P_183 [ 2 ] ; real32_T P_184 [ 2 ] ; real32_T P_185 ;
real32_T P_186 [ 4 ] ; real32_T P_187 [ 4 ] ; real32_T P_188 [ 2 ] ; real32_T
P_189 [ 2 ] ; real32_T P_190 [ 4 ] ; real32_T P_191 ; real32_T P_192 [ 2 ] ;
real32_T P_193 ; real32_T P_194 ; real32_T P_195 [ 16 ] ; real32_T P_196 [ 8
] ; real32_T P_197 [ 8 ] ; real32_T P_198 [ 4 ] ; real32_T P_199 [ 16 ] ;
real32_T P_200 [ 16 ] ; real32_T P_201 [ 8 ] ; real32_T P_202 [ 8 ] ;
real32_T P_203 [ 16 ] ; real32_T P_204 [ 4 ] ; real32_T P_205 [ 4 ] ;
uint32_T P_206 ; uint32_T P_207 ; uint32_T P_208 ; uint32_T P_209 ; uint32_T
P_210 ; uint32_T P_211 ; uint32_T P_212 ; uint32_T P_213 ; uint32_T P_214 ;
uint16_T P_215 ; uint16_T P_216 ; uint16_T P_217 ; boolean_T P_218 ;
boolean_T P_219 ; boolean_T P_220 ; boolean_T P_221 ; boolean_T P_222 ;
boolean_T P_223 ; int8_T P_224 ; int8_T P_225 ; int8_T P_226 ; int8_T P_227 ;
int8_T P_228 ; int8_T P_229 ; int8_T P_230 ; int8_T P_231 ; uint8_T P_232 ;
uint8_T P_233 ; uint8_T P_234 ; fpqg1jdlo0 ipbtas1tys ; je33m1dqwd bm3dpymkhz
; fpqg1jdlo0 ifzbhw4mrws ; je33m1dqwd phrpuocqmvu ; bpvdgm2xq5 ciy1c2o0rv ;
bpvdgm2xq5 jvbbqhrajh ; bpvdgm2xq5 clwiujjdqo ; bpvdgm2xq5 acfz1zxm4t ;
bpvdgm2xq5 ghadbep3bbv ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct ileg2v2ld1r_ { real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ;
real_T P_19 ; real_T P_20 ; real_T P_21 ; nu4qaxumex otjykwnhb3s ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct diqjpw4041 { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 29 ] ; int32_T * vardimsAddress [
29 ] ; RTWLoggingFcnPtr loggingPtrs [ 29 ] ; sysRanDType * systemRan [ 45 ] ;
int_T systemTid [ 45 ] ; } DataMapInfo ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { ipf5ube4r0 rtm ; } lhjbdsj2rjg ;
#endif
extern struct_8SSZ93PxvPkADZcA4gG8MD rtP_Sensors ; extern real_T rtP_COG_X ;
extern real_T rtP_COG_Y ; extern real_T rtP_ROI_Size ; extern real_T
rtP_degree_range1 ; extern real_T rtP_degree_range2 ; extern real_T
rtP_degree_range3 ; extern real_T rtP_num_threshold ; extern real_T
rtP_prev_degree_range ; extern real_T rtP_prev_degree_range2 ; extern real_T
rtP_radius ; extern real_T rtP_radius2 ; extern real_T rtP_rotation_degree ;
extern real_T rtP_rotation_degree2 ; extern real_T rtP_straight_threshold ;
extern void dw0zngvhyq ( void ) ; extern void ha1ipjbq54 ( uint8_T *
o3vpgniqky ) ; extern void gwlyno50ln ( void ) ; extern void m0l5se3ogg (
void ) ; extern void k3yxem35zg ( void ) ; extern void bog0frvixl ( void ) ;
extern void pyvd4pdf3iTID0 ( void ) ; extern void pyvd4pdf3iTID1 ( void ) ;
extern void flightControlSystemTID0 ( const CommandBus * iarztl0jur , const
SensorsBus * pxdb2gu5va , real32_T pikqq4svts [ 4 ] , uint8_T * o3vpgniqky )
; extern void flightControlSystemTID1 ( void ) ; extern void
flightControlSystemTID2 ( void ) ; extern void o2f5l50guo ( void ) ; extern
void f4qzdbbxmw ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , int_T mdlref_TID2 , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_flightControlSystem_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray *
mr_flightControlSystem_GetDWork ( ) ; extern void
mr_flightControlSystem_SetDWork ( const mxArray * ssDW ) ; extern void
mr_flightControlSystem_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_flightControlSystem_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * flightControlSystem_GetCAPIStaticMap (
void ) ;
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern void ghadbep3bb ( uint8_T * hfpztkhwej , bpvdgm2xq5 * localP ) ;
extern void jfkq2sjtgw ( const real32_T duqg5o24fi [ 4 ] , boolean_T
pfxu5bb25d ) ; extern void gcledvfwzt ( orji2pbk05 * localB , je33m1dqwd *
localP ) ; extern void alfdzl2fz1 ( orji2pbk05 * localB , imbf3wrgri *
localDW , je33m1dqwd * localP ) ; extern void phrpuocqmv ( ipf5ube4r0 * const
accn4cnket , boolean_T hjrswm4ob0 , const real32_T ndqlqfbq0n [ 2 ] ,
real32_T pp4ryk1bnn , const real32_T crftt4mdlv [ 2 ] , const real32_T
pc1pu0u41d [ 2 ] , real32_T kemszrfmdj , real32_T k3tun14l4o , orji2pbk05 *
localB , imbf3wrgri * localDW , je33m1dqwd * localP ) ; extern void
e0j2slboh1 ( dyc32xehtl * localB , fpqg1jdlo0 * localP ) ; extern void
ng2z3yysbc ( dyc32xehtl * localB , gabr0rnvjj * localDW , fpqg1jdlo0 * localP
) ; extern void ifzbhw4mrw ( ipf5ube4r0 * const accn4cnket , boolean_T
ny1m4yhfkt , const real32_T izmwj1ddpc [ 2 ] , const real32_T fppyei0jac [ 2
] , real32_T fjag4trd4p , const real32_T fn1cyjs1o0 [ 2 ] , dyc32xehtl *
localB , gabr0rnvjj * localDW , fpqg1jdlo0 * localP ) ; extern void
mr51bswvyz ( ipf5ube4r0 * const accn4cnket , dmp1xsadgu * localDW ) ; extern
void ic5jb3movn ( eo4bbte2ey * localB , dmp1xsadgu * localDW , nu4qaxumex *
localP ) ; extern void bxsrqc204k ( dmp1xsadgu * localDW , nu4qaxumex *
localP ) ; extern void eyt3piuhqz ( ipf5ube4r0 * const accn4cnket ,
dmp1xsadgu * localDW ) ; extern void kegjp2lgms ( eo4bbte2ey * localB ,
dmp1xsadgu * localDW , nu4qaxumex * localP ) ; extern void lsjhvu4egy (
eo4bbte2ey * localB , dmp1xsadgu * localDW , nu4qaxumex * localP ) ; extern
void otjykwnhb3 ( ipf5ube4r0 * const accn4cnket , const CommandBus *
ipxpc4eli1 , const SensorsBus * fp0u5nlpgw , const real_T ay1xsyaztb [ 4 ] ,
eo4bbte2ey * localB , dmp1xsadgu * localDW , nu4qaxumex * localP , ph1mky0ofs
* localZCE ) ; extern void otjykwnhb3TID2 ( eo4bbte2ey * localB , nu4qaxumex
* localP ) ;
#endif
void mr_flightControlSystem_CreateInitRestoreData ( ) ; void
mr_flightControlSystem_CopyFromInitRestoreData ( ) ; void
mr_flightControlSystem_DestroyInitRestoreData ( ) ;
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern lhjbdsj2rjg lhjbdsj2rj ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern ircitwx3zdm ksm0js2nhsy ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern nllkaxiwhzw dqykr4eggmg ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern cspyln32yuv f51itwtzkqf ;
#endif
#endif
