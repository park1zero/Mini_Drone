#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#include <emmintrin.h>
#include <string.h>
#include <xmmintrin.h>
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#ifndef flightControlSystem_COMMON_INCLUDES_
#define flightControlSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "flightControlSystem_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { int8_T fau3qf03xm ; } hrtts4l5bc ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real32_T bomzmgvf4n [ 2 ] ; } orji2pbk05 ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { int8_T mkkaskumzr ; boolean_T jhr0womnye ; } imbf3wrgri ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real32_T jc2u5ap2bv [ 2 ] ; } dyc32xehtl ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { int8_T ley0an2uip ; boolean_T njk4w5jozv ; } gabr0rnvjj ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real32_T hi5gqbqjyq_kkiq3xxxve [ 16 ] ; real32_T
evstouefyu_cxarnvbvui [ 12 ] ; real32_T jjbahtdunb_bhxxfovxdy [ 9 ] ; real_T
mfeecyi5au_pbm3vprmfu [ 4 ] ; real_T jjbahtdunb_cv5hdgrwft [ 3 ] ; real32_T
oy1omazh2e_fqdqrf4qbc [ 4 ] ; real32_T cubxvhjopd_g2mlkqadfk [ 4 ] ; real32_T
ihxox5yw1a_g1smspu5ke [ 4 ] ; real_T nnthqeo0xb [ 2 ] ; real_T kos3zu1m2r ;
real_T dxefzdnlsy ; real_T pdvf1lykyc ; real_T kx3d0bih1x [ 3 ] ; real_T
op43pbwn2e [ 2 ] ; real_T nnthqeo0xb_mbvzarwird ; real_T iqci3z4uux [ 2 ] ;
real_T b5mq1a52pd [ 2 ] ; real_T jhtkvlotcj [ 4 ] ; real_T hud1xcjqn5 [ 2 ] ;
real_T myx153u3em [ 2 ] ; real_T a33lpeqllh [ 2 ] ; real_T
eqxdhit2ae_merlcviukg [ 2 ] ; real32_T p2nu5irp4m_nz4o0shxby [ 3 ] ; real32_T
jy0sasbwp4_ppxrqq0gsf [ 3 ] ; real_T b4lfjlgxec ; real_T
hd11alvebq_llw0u2ae0v ; real_T oxza4umofr_jwzvbuczlb ; real_T
dz1nt25iy5_dhmrxtyqop ; real_T cye1hflvm1_idx_1 ; real_T htv1xfy1hr_idx_0 ;
real_T htv1xfy1hr_idx_1 ; uint32_T kswcs0uqyc ; uint32_T m4frfjfc5w ;
uint32_T poo4jqfmbr ; real32_T oru2xh2cyl [ 2 ] ; real32_T h3hwnlathw ;
real32_T bwhquruhg4 [ 6 ] ; real32_T fdgbdbyfbw [ 2 ] ; real32_T ltyqf4x4fc [
8 ] ; real32_T o340jloaui [ 16 ] ; real32_T inbvjny5r3 [ 4 ] ; real32_T
h4vd5izemq [ 4 ] ; real32_T adokisptgo [ 4 ] ; real32_T mrrvozc1qc_guugdwf2m3
[ 2 ] ; real32_T bjps1hfvua_ldqodwenvz [ 2 ] ; real32_T olsfagmvoi_dhamdvybc1
[ 2 ] ; real32_T b5mq1a52pd_dypejvacrn [ 2 ] ; real32_T gfg0sju4bm_lxo5edjg3c
[ 2 ] ; real32_T bkbsc4c4gw_owjr1h1vqy [ 2 ] ; real32_T pu0o2fnvpu_bjbgfqrolh
[ 2 ] ; real32_T ipa11olwgb_nuebgmauvi [ 2 ] ; real32_T lqeik1h102_bsqwvugooi
[ 2 ] ; real32_T df5jwd0dve ; real32_T epnbjpnxkg ; real32_T ex5bgi0qio [ 3 ]
; real32_T dosvknpiqk ; real32_T li2d3qqqn4 ; real32_T prfrp52vqr ; real32_T
kgl3ocgllz [ 3 ] ; real32_T a5i4fgo1s2 [ 2 ] ; real32_T lgxyarf22c [ 2 ] ;
real32_T gfpexfdgco [ 4 ] ; real32_T admtk2rg2g ; real32_T afrb3hakg0 ;
real32_T ncs1a20tzz [ 2 ] ; real32_T i5fcxpm2jv [ 2 ] ; real32_T ju3134gk55 ;
real32_T b2bau4tlen [ 4 ] ; real32_T fghidhzki0 [ 2 ] ; real32_T d30jjhefx4 [
2 ] ; real32_T isahuy2wrl [ 2 ] ; real32_T mgetblhiok [ 4 ] ; real32_T
ccqokhpweo [ 3 ] ; real32_T htv1xfy1hr [ 16 ] ; real32_T pu4zoonf1h [ 2 ] ;
real32_T jqyrnpqdah [ 2 ] ; real32_T hwxrjq0it0 [ 4 ] ; real32_T fhx0abha5n [
2 ] ; real32_T lgxyarf22c_cl54gopm0x [ 2 ] ; real32_T ps2w1jcoib [ 2 ] ;
real32_T j4qe4nfjsv [ 4 ] ; real32_T e4lbozqvwo [ 2 ] ; real32_T drjad5hp0z [
8 ] ; real32_T hejjqm5nej ; real32_T ljo1dpaub4_lnjdk5wtww ; real32_T
jhtkvlotcj_hv2ho1zopz ; real32_T eq5jssgbid_bnlywzniup ; real32_T
hzh2xi4fxy_dapv3jlyq5 ; real32_T hwmpgermgo_ezqlmfzvpq ; real32_T
ljddwhaot1_idx_0 ; real32_T ljddwhaot1_idx_1 ; real32_T ljddwhaot1_idx_2 ;
real32_T cqw0qrp4eu_idx_1 ; real32_T cqw0qrp4eu_idx_2 ; real32_T
evtdawb55q_idx_0 ; real32_T jijx4ghl4f_idx_0 ; real32_T jijx4ghl4f_idx_1 ;
real32_T j2fzkdga4e_idx_1 ; real32_T j2fzkdga4e_idx_2 ; real32_T
jijx4ghl4f_idx_2 ; real32_T fdumptgdfz_idx_0 ; real32_T fdumptgdfz_idx_1 ;
real32_T be1lqqa2dw_idx_1 ; real32_T be1lqqa2dw_idx_2 ; real32_T
be1lqqa2dw_idx_0 ; real32_T fdumptgdfz_idx_2 ; real32_T pzfs30csun_bjvjhhzy4i
; real32_T isx1jookfr_jzx3amusab ; real32_T fmctk2xfye_fdinthrxmb ; real32_T
do1qu2mt40_al00mdgrv4 ; int32_T cff ; int32_T denIdx ; int32_T memOffset ;
int32_T i ; uint32_T bib1wyq24m_ju13rw2h0m ; uint32_T kz4bicn3ik_jz50ptvnrg ;
uint32_T ivnkv1flcv_o4f35lbcvx ; uint32_T kwzmttb3mf_nyxm0bsxsn ; uint32_T
pue0035ipm_icdfyazkhu ; uint32_T hke1v0tqxi_oyypvi4boh ; uint16_T ao41flvyb1
; int16_T iimupityvq ; uint16_T drjad5hp0z_nvsvtgkap4 ; uint16_T
bgjnlzeaxl_m3yhjduhi1 ; uint8_T ip32us3ehh ; boolean_T p1k24wzycz ; boolean_T
aoneafkd51 ; boolean_T drrbtvcsxs ; boolean_T aagcy0d5ye ; boolean_T
l2nlpva2j1_czkfpwuzm5 ; boolean_T iqocmhdfin_mdoasc5av4 ; boolean_T
hud1xcjqn5_m3ybdk4ikc ; boolean_T pu4zoonf1h_jacdjrqyev ; boolean_T
ihwj5oflkc_h522xzlxvt ; boolean_T kpsjbxclns_c0dok3111h ; boolean_T
dyul3la2fn_ctvw0tpkon ; boolean_T oaihmoohg4_pxqvlbal2i ; boolean_T
irwy2x5q4p_p5h3gwuwqg ; boolean_T flnho2rpk4_afnsueciae ; boolean_T
c1wxoegeqm_evg4t2fsev ; boolean_T ajja2uavol_ax3wx1gs5w ; dyc32xehtl
ipbtas1tys ; orji2pbk05 bm3dpymkhz ; dyc32xehtl ifzbhw4mrws ; orji2pbk05
phrpuocqmvu ; } eo4bbte2ey ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T mi4mocbazh ; real_T mtonzezz2z [ 2 ] ; real_T
ddv3ztj2wp [ 3 ] ; real_T ov3i5h53no ; real_T msqjf2c21n ; real_T bw2ribqmwm
; real_T f2ynnmexgv ; struct { void * LoggedData ; void * SignalProbe ; }
mpopad3fr1 ; real32_T b3fmbw5stg [ 2 ] ; real32_T aq2aymvaio [ 3 ] ; real32_T
dzwopklw3c ; real32_T d4fp3a2mpz [ 15 ] ; real32_T fl0vv44tbs [ 2 ] ;
real32_T as5a0ikbk1 [ 2 ] ; real32_T ncgo1wegzg ; real32_T mirtkskmtr ;
real32_T jduomia1pb [ 5 ] ; real32_T od5c00niot [ 4 ] ; real32_T dqfv1m130o [
10 ] ; real32_T meognsjf1t [ 2 ] ; real32_T gcgpru4rcb [ 2 ] ; real32_T
peklmaellz [ 2 ] ; real32_T bsetqjfri4 ; real32_T dsjbzv2lh4 [ 2 ] ; real32_T
gixvkpnpus [ 2 ] ; real32_T ow5xb5ovt0 [ 2 ] ; real32_T krs1cvkxzk [ 2 ] ;
real32_T c4kiksmhh2 ; int32_T bbkjtf4kuy ; uint32_T l3lcputuyl ; uint32_T
pjgu33zeph ; uint32_T dxm3w2i52x ; real32_T orkq4iljgu ; real32_T b1nmhkw4zo
; real32_T n0mydijbcx ; real32_T iwg03owvar ; real32_T mf2pp40f5v [ 2 ] ;
real32_T pwlp5beuqs [ 2 ] ; uint16_T gaxgdudnvc ; int8_T dq5lalhp1e ; int8_T
fpr1qi0oiw ; int8_T klyrn0mwhb ; int8_T mfifybuxty ; int8_T a1oodzfxvv ;
int8_T mgysgsd2g4 ; int8_T idn2v5d33m ; boolean_T de4yc1bkky ; boolean_T
jd3dqtmo2p ; boolean_T f1jy25gy04 ; boolean_T gdn4qfzvsk ; boolean_T
cqi2pi21ow ; boolean_T kh1khihcrt ; boolean_T iftedegxuv ; boolean_T
g4zcogq4xi ; gabr0rnvjj ipbtas1tys ; imbf3wrgri bm3dpymkhz ; gabr0rnvjj
ifzbhw4mrws ; imbf3wrgri phrpuocqmvu ; hrtts4l5bc ciy1c2o0rv ; hrtts4l5bc
jvbbqhrajh ; hrtts4l5bc clwiujjdqo ; hrtts4l5bc acfz1zxm4t ; hrtts4l5bc
ghadbep3bbv ; } dmp1xsadgu ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T b3ouxrig41 ; } k5baggiqtb ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { ZCSigState b1rw3rggh2 ; } ph1mky0ofs ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T ml4uxk3hh0_mbvzarwird [ 38400 ] ; real_T cutting_dots
[ 38400 ] ; real_T bw3qnftzvl_cl54gopm0x [ 19200 ] ; real_T MAP [ 19200 ] ;
real_T L_image [ 19200 ] ; real_T P [ 9601 ] ; real_T g21b14ifya_kkiq3xxxve [
2400 ] ; real_T cutting_dots_cxarnvbvui [ 2400 ] ; boolean_T
pbhxkyb4vt_bhxxfovxdy [ 19200 ] ; boolean_T b0s5io5xwf_pbm3vprmfu [ 19200 ] ;
boolean_T b0s5io5xwf_cv5hdgrwft [ 19200 ] ; uint8_T b_varargout_3 [ 19200 ] ;
uint8_T b_varargout_2 [ 19200 ] ; uint8_T b_varargout_1 [ 19200 ] ; int32_T
chunksSizeAndLabels [ 168 ] ; real_T gossgpok50 [ 6 ] ; real_T c5v5iogkg1 [ 2
] ; real_T tempPoint [ 2 ] ; real_T tempPoint_g2mlkqadfk [ 2 ] ; real_T
nhh54h3gzi_g1smspu5ke [ 2 ] ; boolean_T pbhxkyb4vt_fqdqrf4qbc [ 16 ] ;
int64_T i ; real_T num_dots ; real_T cnt ; real_T delta ; real_T pre_dist ;
real_T dist ; real_T scale ; real_T absxk ; real_T t ; real_T center_idx_1 ;
real_T absxk_tmp ; real_T label ; real_T rootj ; real_T b_rootj ; real_T f_i
; real32_T nhh54h3gzi_merlcviukg ; real32_T lv0qjnd4gp_nz4o0shxby ; real32_T
pygoux2qzq_ppxrqq0gsf ; real32_T ifb2ydeq5k_llw0u2ae0v ; real32_T
ai2sf0wlp1_jwzvbuczlb ; real32_T gwjciupyu3_dhmrxtyqop ; real32_T
c44smzhxdr_guugdwf2m3 ; real32_T lcgyq3fji0_ldqodwenvz ; real32_T
i5hdnuutcy_dhamdvybc1 ; real32_T ozvujebfrx_dypejvacrn ; real32_T
demikg1emv_lxo5edjg3c ; int32_T k ; int32_T j ; int32_T i_owjr1h1vqy ;
int32_T i1 ; int32_T i2 ; int32_T pbhxkyb4vt_tmp ; int32_T
pbhxkyb4vt_tmp_bjbgfqrolh ; int32_T i3 ; eo4bbte2ey otjykwnhb3s ; }
ircitwx3zdm ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { bjqsgn0csy l152eirbdu ; real_T oq44mkeutp [ 4 ] ; real_T
a5bw1phdru ; real_T lfoamd1f2p ; real_T hxay3u1okm ; real_T jeizrdeywg ;
real_T cikrffegk0 ; real_T lyvhra0vpv ; real_T mgkcj235xx ; real_T j3gb4htxva
; real_T mum4klesjh [ 2 ] ; struct { void * LoggedData ; void * SignalProbe ;
} ly3gdhhelp ; struct { void * LoggedData ; void * SignalProbe ; } l5bw5hmnrp
; real32_T cvte14aviy ; real32_T pspzcfr2mk ; real32_T m04yjeof3s ; real32_T
kqhf5drvz0 ; real32_T ov1i3orwof ; real32_T mhobc1j1zw ; real32_T eoxhemchli
; real32_T id43ygfmie ; real32_T kbn4rojwrq ; real32_T kkysf4rkgw ; real32_T
px1njyczko ; real32_T c1pfw1s3qd ; int32_T ex0cncdzgs [ 6 ] ; int32_T
f3tlra1rjy [ 6 ] ; int32_T o42whxzij4 [ 190 ] ; int8_T fb0f52aifb ; int8_T
f002cq3idt ; int8_T c2dfbmlkab ; int8_T izywhppvza ; int8_T opalvnxykh ;
int8_T ljgqi3o5y0 ; int8_T kks5zssfkj ; int8_T nxstqctwu5 ; int8_T jon223t4wn
; int8_T mh3mthgmuv ; int8_T dbqslespgw ; int8_T al4y0orboq ; int8_T
m35cewvnrb ; uint8_T kalm02qitu ; uint8_T j2wbe0krle ; uint8_T gvcrgzo4og ;
boolean_T jjrfotind4 ; dmp1xsadgu otjykwnhb3s ; } nllkaxiwhzw ;
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
real_T P_55 ; real_T P_56 ; real_T P_57 [ 4 ] ; real_T P_58 [ 4 ] ; real_T
P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ;
real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T
P_70 ; real_T P_71 ; real_T P_72 [ 4 ] ; real_T P_73 [ 2 ] ; real_T P_74 [ 2
] ; real_T P_75 [ 4 ] ; real_T P_76 [ 2 ] ; real_T P_77 [ 2 ] ; real_T P_78 ;
real_T P_79 [ 4 ] ; real_T P_80 [ 2 ] ; real_T P_81 ; real_T P_82 ; real_T
P_83 ; real_T P_84 ; real_T P_85 [ 2 ] ; real_T P_86 [ 3 ] ; real_T P_87 [ 4
] ; real_T P_88 [ 2 ] ; real_T P_89 [ 2 ] ; real_T P_90 [ 4 ] ; real_T P_91 [
2 ] ; real_T P_92 [ 2 ] ; real_T P_93 ; real_T P_94 [ 3 ] ; real_T P_95 [ 16
] ; real_T P_96 [ 8 ] ; real_T P_97 [ 8 ] ; real32_T P_98 ; real32_T P_99 ;
real32_T P_100 ; real32_T P_101 [ 2 ] ; real32_T P_102 ; real32_T P_103 ;
real32_T P_104 ; real32_T P_105 ; real32_T P_106 ; real32_T P_107 ; real32_T
P_108 ; real32_T P_109 ; real32_T P_110 ; real32_T P_111 ; real32_T P_112 [ 4
] ; real32_T P_113 [ 4 ] ; real32_T P_114 ; real32_T P_115 ; real32_T P_116 ;
real32_T P_117 [ 6 ] ; real32_T P_118 [ 6 ] ; real32_T P_119 ; real32_T P_120
[ 6 ] ; real32_T P_121 ; real32_T P_122 [ 2 ] ; real32_T P_123 [ 2 ] ;
real32_T P_124 ; real32_T P_125 [ 2 ] ; real32_T P_126 [ 2 ] ; real32_T P_127
; real32_T P_128 [ 6 ] ; real32_T P_129 [ 6 ] ; real32_T P_130 ; real32_T
P_131 ; real32_T P_132 [ 6 ] ; real32_T P_133 [ 6 ] ; real32_T P_134 ;
real32_T P_135 ; real32_T P_136 ; real32_T P_137 ; real32_T P_138 ; real32_T
P_139 ; real32_T P_140 ; real32_T P_141 ; real32_T P_142 ; real32_T P_143 ;
real32_T P_144 ; real32_T P_145 ; real32_T P_146 ; real32_T P_147 [ 2 ] ;
real32_T P_148 [ 2 ] ; real32_T P_149 ; real32_T P_150 ; real32_T P_151 ;
real32_T P_152 ; real32_T P_153 ; real32_T P_154 ; real32_T P_155 ; real32_T
P_156 ; real32_T P_157 ; real32_T P_158 ; real32_T P_159 ; real32_T P_160 ;
real32_T P_161 ; real32_T P_162 ; real32_T P_163 ; real32_T P_164 [ 4 ] ;
real32_T P_165 ; real32_T P_166 ; real32_T P_167 ; real32_T P_168 ; real32_T
P_169 [ 16 ] ; real32_T P_170 ; real32_T P_171 ; real32_T P_172 ; real32_T
P_173 [ 4 ] ; real32_T P_174 [ 2 ] ; real32_T P_175 [ 2 ] ; real32_T P_176 ;
real32_T P_177 [ 4 ] ; real32_T P_178 [ 4 ] ; real32_T P_179 [ 2 ] ; real32_T
P_180 [ 2 ] ; real32_T P_181 [ 4 ] ; real32_T P_182 ; real32_T P_183 [ 2 ] ;
real32_T P_184 [ 4 ] ; real32_T P_185 [ 2 ] ; real32_T P_186 [ 2 ] ; real32_T
P_187 ; real32_T P_188 [ 4 ] ; real32_T P_189 [ 4 ] ; real32_T P_190 [ 2 ] ;
real32_T P_191 [ 2 ] ; real32_T P_192 [ 4 ] ; real32_T P_193 ; real32_T P_194
[ 2 ] ; real32_T P_195 ; real32_T P_196 ; real32_T P_197 [ 16 ] ; real32_T
P_198 [ 8 ] ; real32_T P_199 [ 8 ] ; real32_T P_200 [ 4 ] ; real32_T P_201 [
16 ] ; real32_T P_202 [ 16 ] ; real32_T P_203 [ 8 ] ; real32_T P_204 [ 8 ] ;
real32_T P_205 [ 16 ] ; real32_T P_206 [ 4 ] ; real32_T P_207 [ 4 ] ;
uint32_T P_208 ; uint32_T P_209 ; uint32_T P_210 ; uint32_T P_211 ; uint32_T
P_212 ; uint32_T P_213 ; uint32_T P_214 ; uint32_T P_215 ; uint32_T P_216 ;
uint16_T P_217 ; uint16_T P_218 ; uint16_T P_219 ; boolean_T P_220 ;
boolean_T P_221 ; boolean_T P_222 ; boolean_T P_223 ; boolean_T P_224 ;
boolean_T P_225 ; uint8_T P_226 ; uint8_T P_227 ; uint8_T P_228 ; fpqg1jdlo0
ipbtas1tys ; je33m1dqwd bm3dpymkhz ; fpqg1jdlo0 ifzbhw4mrws ; je33m1dqwd
phrpuocqmvu ; bpvdgm2xq5 ciy1c2o0rv ; bpvdgm2xq5 jvbbqhrajh ; bpvdgm2xq5
clwiujjdqo ; bpvdgm2xq5 acfz1zxm4t ; bpvdgm2xq5 ghadbep3bbv ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct ileg2v2ld1r_ { real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ;
real_T P_11 ; real_T P_12 ; real_T P_13 ; nu4qaxumex otjykwnhb3s ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct diqjpw4041 { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 31 ] ; int32_T * vardimsAddress [
31 ] ; RTWLoggingFcnPtr loggingPtrs [ 31 ] ; sysRanDType * systemRan [ 36 ] ;
int_T systemTid [ 36 ] ; } DataMapInfo ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { ipf5ube4r0 rtm ; } lhjbdsj2rjg ;
#endif
extern struct_8SSZ93PxvPkADZcA4gG8MD rtP_Sensors ; extern real_T rtP_COG_X ;
extern real_T rtP_COG_Y ; extern real_T rtP_degree_range1 ; extern real_T
rtP_degree_range2 ; extern real_T rtP_num_threshold ; extern real_T
rtP_rotation_degree ; extern void ha1ipjbq54 ( uint8_T * o3vpgniqky ) ;
extern void gwlyno50ln ( void ) ; extern void k3yxem35zg ( void ) ; extern
void bog0frvixl ( void ) ; extern void pyvd4pdf3iTID0 ( void ) ; extern void
pyvd4pdf3iTID1 ( void ) ; extern void pyvd4pdf3iTID2 ( void ) ; extern void
flightControlSystemTID0 ( const SensorsBus * pxdb2gu5va , real32_T pikqq4svts
[ 4 ] , uint8_T * o3vpgniqky ) ; extern void flightControlSystemTID1 ( void )
; extern void flightControlSystemTID2 ( void ) ; extern void o2f5l50guo (
void ) ; extern void f4qzdbbxmw ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , int_T mdlref_TID1 , int_T mdlref_TID2 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
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
ic5jb3movn ( eo4bbte2ey * localB , dmp1xsadgu * localDW , nu4qaxumex * localP
) ; extern void bxsrqc204k ( dmp1xsadgu * localDW , nu4qaxumex * localP ) ;
extern void kegjp2lgms ( eo4bbte2ey * localB , dmp1xsadgu * localDW ,
nu4qaxumex * localP ) ; extern void lsjhvu4egy ( eo4bbte2ey * localB ,
dmp1xsadgu * localDW , nu4qaxumex * localP ) ; extern void otjykwnhb3 (
ipf5ube4r0 * const accn4cnket , const SensorsBus * fp0u5nlpgw , const real_T
ay1xsyaztb [ 2 ] , eo4bbte2ey * localB , dmp1xsadgu * localDW , nu4qaxumex *
localP , ph1mky0ofs * localZCE ) ; extern void otjykwnhb3TID2 ( eo4bbte2ey *
localB , nu4qaxumex * localP ) ;
#endif
void mr_flightControlSystem_CreateInitRestoreData ( ) ; void
mr_flightControlSystem_CopyFromInitRestoreData ( ) ; void
mr_flightControlSystem_DestroyInitRestoreData ( ) ;
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern lhjbdsj2rjg lhjbdsj2rj ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern ircitwx3zdm ksm0js2nhsy ; extern nllkaxiwhzw dqykr4eggmg ; extern
cspyln32yuv f51itwtzkqf ;
#endif
#endif
