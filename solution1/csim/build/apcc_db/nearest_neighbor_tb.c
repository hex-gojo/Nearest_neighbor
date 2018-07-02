/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_tagBITMAPFILEHEADER l_struct_OC_tagBITMAPFILEHEADER;
typedef struct l_struct_OC_tagBITMAPINFOHEADER l_struct_OC_tagBITMAPINFOHEADER;
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC_tagBITMAPFILEHEADER {
  unsigned short field0;
  unsigned int field1;
  unsigned short field2;
  unsigned short field3;
  unsigned int field4;
};

struct l_struct_OC_tagBITMAPINFOHEADER {
  unsigned int field0;
  unsigned int field1;
  unsigned int field2;
  unsigned short field3;
  unsigned short field4;
  unsigned int field5;
  unsigned int field6;
  unsigned int field7;
  unsigned int field8;
  unsigned int field9;
  unsigned int field10;
};

struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
signed int nearest_neighbor_axim(signed int *, signed int *);
void nn_soft(signed int *llvm_cbe_cam_fb, signed int *llvm_cbe_nn_fb, signed int llvm_cbe_width, signed int llvm_cbe_height);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[9] = "test.bmp";
static  char aesl_internal__OC_str1[3] = "rb";
static  char aesl_internal__OC_str2[41] = "Can't open test.bmp by binary read mode\n";
static  char aesl_internal__OC_str3[30] = "Can't allocate rd_bmp memory\n";
static  char aesl_internal__OC_str4[29] = "Can't allocate hw_nn memory\n";
static  char aesl_internal__OC_str11[21] = "\ndebug: bfSize = %u\n";
static  char aesl_internal__OC_str5[29] = "Can't allocate sw_nn memory\n";
static  char aesl_internal__OC_str6[69] = "ERROR HW and SW results mismatch x = %ld, y = %ld, HW = %d, SW = %d\n";
static  char aesl_internal__OC_str8[11] = "result.bmp";
static  char aesl_internal__OC_str9[3] = "wb";
static  char aesl_internal__OC_str10[44] = "Can't open result.bmp by binary write mode\n";
static  char aesl_internal_str[32] = "Success HW and SW results match";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_bmpfhr_count = 0;
  l_struct_OC_tagBITMAPFILEHEADER llvm_cbe_bmpfhr;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bmpihr_count = 0;
  l_struct_OC_tagBITMAPINFOHEADER llvm_cbe_bmpihr;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  signed int *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  signed short *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
   char *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  signed short *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  signed int *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
   char *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  signed int *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  signed int *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  signed int *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
   char *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  signed int *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  signed int *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_smax35_count = 0;
  unsigned int llvm_cbe_smax35;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_smax_count = 0;
  unsigned int llvm_cbe_smax;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge517_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge517_2e_us;
  unsigned int llvm_cbe_storemerge517_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  signed int *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge20_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge20_2e_us;
  unsigned int llvm_cbe_storemerge20_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_lcssa_count = 0;
  unsigned int llvm_cbe_storemerge_2e_lcssa;
  unsigned int llvm_cbe_storemerge_2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge56_2e_lcssa_count = 0;
  unsigned int llvm_cbe_storemerge56_2e_lcssa;
  unsigned int llvm_cbe_storemerge56_2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  signed int *llvm_cbe_tmp__63;
  signed int *llvm_cbe_tmp__63__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  signed int *llvm_cbe_tmp__64;
  signed int *llvm_cbe_tmp__64__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  signed int *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  signed int *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec31_count = 0;
  unsigned long long llvm_cbe__2e_rec31;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned long long llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge19_count = 0;
  unsigned int llvm_cbe_storemerge19;
  unsigned int llvm_cbe_storemerge19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_count = 0;
  unsigned int llvm_cbe_storemerge28;
  unsigned int llvm_cbe_storemerge28__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  signed int *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond24_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond25_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__101;
  } else {
    goto llvm_cbe_tmp__102;
  }

llvm_cbe_tmp__101:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct._iobuf* %%4, i64 2, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__2[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i64 @fwrite(i8* getelementptr inbounds ([41 x i8]* @aesl_internal_.str2, i64 0, i64 0), i64 40, i64 1, %%struct._iobuf* %%5), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_19_count);
  fwrite(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 41
#endif
])), 40ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_20_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__102:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast %%struct.tagBITMAPFILEHEADER* %%bmpfhr to i8*, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__5 = ( char *)(( char *)(&llvm_cbe_bmpfhr));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i64 @fread(i8* %%8, i64 2, i64 1, %%struct._iobuf* %%1) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  fread(( char *)llvm_cbe_tmp__5, 2ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.tagBITMAPFILEHEADER* %%bmpfhr, i64 0, i32 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__7 = (signed int *)(&llvm_cbe_bmpfhr.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast i32* %%10 to i8*, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__8 = ( char *)(( char *)llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i64 @fread(i8* %%11, i64 4, i64 1, %%struct._iobuf* %%1) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_26_count);
  fread(( char *)llvm_cbe_tmp__8, 4ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.tagBITMAPFILEHEADER* %%bmpfhr, i64 0, i32 2, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__10 = (signed short *)(&llvm_cbe_bmpfhr.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = bitcast i16* %%13 to i8*, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__11 = ( char *)(( char *)llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i64 @fread(i8* %%14, i64 2, i64 1, %%struct._iobuf* %%1) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  fread(( char *)llvm_cbe_tmp__11, 2ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.tagBITMAPFILEHEADER* %%bmpfhr, i64 0, i32 3, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__13 = (signed short *)(&llvm_cbe_bmpfhr.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = bitcast i16* %%16 to i8*, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__14 = ( char *)(( char *)llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i64 @fread(i8* %%17, i64 2, i64 1, %%struct._iobuf* %%1) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  fread(( char *)llvm_cbe_tmp__14, 2ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.tagBITMAPFILEHEADER* %%bmpfhr, i64 0, i32 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__16 = (signed int *)(&llvm_cbe_bmpfhr.field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = bitcast i32* %%19 to i8*, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__17 = ( char *)(( char *)llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i64 @fread(i8* %%20, i64 4, i64 1, %%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  fread(( char *)llvm_cbe_tmp__17, 4ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = bitcast %%struct.tagBITMAPINFOHEADER* %%bmpihr to i8*, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__19 = ( char *)(( char *)(&llvm_cbe_bmpihr));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i64 @fread(i8* %%22, i64 40, i64 1, %%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  fread(( char *)llvm_cbe_tmp__19, 40ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.tagBITMAPINFOHEADER* %%bmpihr, i64 0, i32 1, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__21 = (signed int *)(&llvm_cbe_bmpihr.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%24, align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__22 = (unsigned int )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.tagBITMAPINFOHEADER* %%bmpihr, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__23 = (signed int *)(&llvm_cbe_bmpihr.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__24 = (unsigned int )*llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = mul nsw i32 %%27, %%25, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__22&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = shl nsw i64 %%29, 2, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__27 = (unsigned long long )llvm_cbe_tmp__26 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call i8* @malloc(i64 %%30), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__28 = ( char *)( char *)malloc(llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__27);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = bitcast i8* %%31 to i32*, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__29 = (signed int *)((signed int *)llvm_cbe_tmp__28);
  if (((llvm_cbe_tmp__28) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__103;
  } else {
    goto llvm_cbe_tmp__104;
  }

llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__30 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct._iobuf* %%35, i64 2, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__31 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__30[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str3, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%36), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  fwrite(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_57_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__104:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call i8* @malloc(i64 65536), !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__33 = ( char *)( char *)malloc(65536ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",65536ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = bitcast i8* %%39 to i32*, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__34 = (signed int *)((signed int *)llvm_cbe_tmp__33);
  if (((llvm_cbe_tmp__33) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__105;
  } else {
    goto llvm_cbe_tmp__106;
  }

llvm_cbe_tmp__105:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__35 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds %%struct._iobuf* %%43, i64 2, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__36 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__35[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call i64 @fwrite(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str4, i64 0, i64 0), i64 28, i64 1, %%struct._iobuf* %%44), !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_72_count);
  fwrite(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])), 28ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",28ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_73_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__106:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i8* @malloc(i64 65536), !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__38 = ( char *)( char *)malloc(65536ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",65536ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = bitcast i8* %%47 to i32*, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__39 = (signed int *)((signed int *)llvm_cbe_tmp__38);
  if (((llvm_cbe_tmp__38) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__107;
  } else {
    goto llvm_cbe__2e_preheader18;
  }

llvm_cbe__2e_preheader18:
  if ((((signed int )llvm_cbe_tmp__24) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader16_2e_lr_2e_ph;
  } else {
    llvm_cbe_storemerge_2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge21;
  }

llvm_cbe__2e_preheader16_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__22) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader16_2e_lr_2e_ph_2e_split_2e_us;
  } else {
    goto llvm_cbe__2e_preheader16_2e_lr_2e_ph_2e__2e_preheader16_2e_lr_2e_ph_2e_split_crit_edge;
  }

llvm_cbe__2e_preheader16_2e_lr_2e_ph_2e__2e_preheader16_2e_lr_2e_ph_2e_split_crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%smax35 = select i1 %%52, i32 %%27, i32 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_smax35_count);
  llvm_cbe_smax35 = (unsigned int )(((((signed int )llvm_cbe_tmp__24) > ((signed int )1u))) ? ((unsigned int )llvm_cbe_tmp__24) : ((unsigned int )1u));
if (AESL_DEBUG_TRACE)
printf("\nsmax35 = 0x%X\n", llvm_cbe_smax35);
  llvm_cbe_storemerge_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_smax35;   /* for PHI node */
  llvm_cbe_storemerge56_2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e__crit_edge21;

llvm_cbe__2e_preheader16_2e_lr_2e_ph_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%smax = select i1 %%53, i32 %%27, i32 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_smax_count);
  llvm_cbe_smax = (unsigned int )(((((signed int )llvm_cbe_tmp__24) > ((signed int )1u))) ? ((unsigned int )llvm_cbe_tmp__24) : ((unsigned int )1u));
if (AESL_DEBUG_TRACE)
printf("\nsmax = 0x%X\n", llvm_cbe_smax);
  llvm_cbe_storemerge20_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge20.us = phi i32 [ 0, %%.preheader16.lr.ph.split.us ], [ %%55, %%54  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge20_2e_us_count);
  llvm_cbe_storemerge20_2e_us = (unsigned int )llvm_cbe_storemerge20_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge20.us = 0x%X",llvm_cbe_storemerge20_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = xor i32 %%storemerge20.us, -1, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__55 = (unsigned int )llvm_cbe_storemerge20_2e_us ^ 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add i32 %%27, %%72, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__55&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = mul nsw i32 %%73, %%25, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__22&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
  llvm_cbe_storemerge517_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__108;

llvm_cbe_tmp__109:
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add nsw i32 %%storemerge20.us, 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__40 = (unsigned int )((unsigned int )(llvm_cbe_storemerge20_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__40&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__40) < ((signed int )llvm_cbe_tmp__24))) {
    llvm_cbe_storemerge20_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_storemerge_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_smax;   /* for PHI node */
    llvm_cbe_storemerge56_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge21;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__108:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge517.us = phi i32 [ 0, %%.lr.ph.us ], [ %%71, %%57  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge517_2e_us_count);
  llvm_cbe_storemerge517_2e_us = (unsigned int )llvm_cbe_storemerge517_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge517.us = 0x%X",llvm_cbe_storemerge517_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__54);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = call i32 @fgetc(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__41 = (unsigned int )fgetc((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = call i32 @fgetc(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__42 = (unsigned int )fgetc((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = call i32 @fgetc(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__43 = (unsigned int )fgetc((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = and i32 %%58, 255, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__44 = (unsigned int )llvm_cbe_tmp__41 & 255u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = shl i32 %%59, 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__45 = (unsigned int )llvm_cbe_tmp__42 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = and i32 %%62, 65280, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__46 = (unsigned int )llvm_cbe_tmp__45 & 65280u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = shl i32 %%60, 16, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__47 = (unsigned int )llvm_cbe_tmp__43 << 16u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = and i32 %%64, 16711680, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__48 = (unsigned int )llvm_cbe_tmp__47 & 16711680u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = or i32 %%63, %%61, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__49 = (unsigned int )llvm_cbe_tmp__46 | llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = or i32 %%66, %%65, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__50 = (unsigned int )llvm_cbe_tmp__49 | llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add nsw i32 %%74, %%storemerge517.us, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_tmp__57&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge517_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = sext i32 %%68 to i64, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__52 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds i32* %%32, i64 %%69, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__53 = (signed int *)(&llvm_cbe_tmp__29[(((signed long long )llvm_cbe_tmp__52))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__52));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%67, i32* %%70, align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_127_count);
  *llvm_cbe_tmp__53 = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add nsw i32 %%storemerge517.us, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_storemerge517_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
  if (((llvm_cbe_tmp__54&4294967295U) == (llvm_cbe_tmp__22&4294967295U))) {
    goto llvm_cbe_tmp__109;
  } else {
    llvm_cbe_storemerge517_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    goto llvm_cbe_tmp__108;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe_tmp__107:
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__58 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds %%struct._iobuf* %%76, i64 2, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__59 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__58[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = call i64 @fwrite(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str5, i64 0, i64 0), i64 28, i64 1, %%struct._iobuf* %%77), !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
  fwrite(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])), 28ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",28ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__60);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe__2e__crit_edge21:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.lcssa = phi i32 [ 0, %%.preheader18 ], [ %%smax35, %%.preheader16.lr.ph..preheader16.lr.ph.split_crit_edge ], [ %%smax, %%54  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge_2e_lcssa_count);
  llvm_cbe_storemerge_2e_lcssa = (unsigned int )llvm_cbe_storemerge_2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge.lcssa = 0x%X",llvm_cbe_storemerge_2e_lcssa);
printf("\n = 0x%X",0u);
printf("\nsmax35 = 0x%X",llvm_cbe_smax35);
printf("\nsmax = 0x%X",llvm_cbe_smax);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge56.lcssa = phi i32 [ undef, %%.preheader18 ], [ 0, %%.preheader16.lr.ph..preheader16.lr.ph.split_crit_edge ], [ %%25, %%54  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge56_2e_lcssa_count);
  llvm_cbe_storemerge56_2e_lcssa = (unsigned int )llvm_cbe_storemerge56_2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge56.lcssa = 0x%X",llvm_cbe_storemerge56_2e_lcssa);
printf("\n = 0x%X",((unsigned int )/*UNDEF*/0));
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = call i32 @nearest_neighbor_axim(i32* %%32, i32* %%40) nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_148_count);
  nearest_neighbor_axim((signed int *)llvm_cbe_tmp__29, (signed int *)llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @nn_soft(i32* %%32, i32* %%48, i32 %%25, i32 %%27), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_149_count);
  nn_soft((signed int *)llvm_cbe_tmp__29, (signed int *)llvm_cbe_tmp__39, llvm_cbe_tmp__22, llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__22);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__24);
}
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__63__PHI_TEMPORARY = (signed int *)llvm_cbe_tmp__34;   /* for PHI node */
  llvm_cbe_tmp__64__PHI_TEMPORARY = (signed int *)llvm_cbe_tmp__39;   /* for PHI node */
  goto llvm_cbe_tmp__110;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__110:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ %%97, %%96 ], [ 0, %%._crit_edge21  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",llvm_cbe_tmp__71);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = phi i32* [ %%86, %%96 ], [ %%40, %%._crit_edge21  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__63 = (signed int *)llvm_cbe_tmp__63__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = phi i32* [ %%85, %%96 ], [ %%48, %%._crit_edge21  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__64 = (signed int *)llvm_cbe_tmp__64__PHI_TEMPORARY;
  if ((((signed int )llvm_cbe_storemerge17) < ((signed int )128u))) {
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__111;
  }

llvm_cbe_tmp__112:
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = add nsw i32 %%storemerge17, 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__71 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__71&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__71;   /* for PHI node */
  llvm_cbe_tmp__63__PHI_TEMPORARY = (signed int *)llvm_cbe_tmp__66;   /* for PHI node */
  llvm_cbe_tmp__64__PHI_TEMPORARY = (signed int *)llvm_cbe_tmp__65;   /* for PHI node */
  goto llvm_cbe_tmp__110;

  do {     /* Syntactic loop '.preheader10' to make GCC happy */
llvm_cbe__2e_preheader10:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec31, %%94 ], [ 0, %%81  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec31 = 0x%I64X",llvm_cbe__2e_rec31);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%95, %%94 ], [ 0, %%81  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__70);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = getelementptr i32* %%83, i64 %%.re for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__65 = (signed int *)(&llvm_cbe_tmp__64[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr i32* %%82, i64 %%.re for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__66 = (signed int *)(&llvm_cbe_tmp__63[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
  if ((((signed int )llvm_cbe_storemerge3) < ((signed int )128u))) {
    goto llvm_cbe_tmp__113;
  } else {
    goto llvm_cbe_tmp__112;
  }

llvm_cbe_tmp__114:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec31 = add i64 %%.rec, 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e_rec31_count);
  llvm_cbe__2e_rec31 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec31 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec31&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add nsw i32 %%storemerge3, 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__70 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__70&4294967295ull)));
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec31;   /* for PHI node */
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__70;   /* for PHI node */
  goto llvm_cbe__2e_preheader10;

llvm_cbe_tmp__113:
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = load i32* %%86, align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__67 = (unsigned int )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load i32* %%85, align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__68 = (unsigned int )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
  if (((llvm_cbe_tmp__67&4294967295U) == (llvm_cbe_tmp__68&4294967295U))) {
    goto llvm_cbe_tmp__114;
  } else {
    goto llvm_cbe_tmp__115;
  }

  } while (1); /* end of syntactic loop '.preheader10' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([69 x i8]* @aesl_internal_.str6, i64 0, i64 0), i32 %%storemerge56.lcssa, i32 %%storemerge.lcssa, i32 %%89, i32 %%90) nounwind, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_186_count);
  printf(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 69
#endif
])), llvm_cbe_storemerge56_2e_lcssa, llvm_cbe_storemerge_2e_lcssa, llvm_cbe_tmp__67, llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge56.lcssa = 0x%X",llvm_cbe_storemerge56_2e_lcssa);
printf("\nArgument storemerge.lcssa = 0x%X",llvm_cbe_storemerge_2e_lcssa);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__67);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__68);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__69);
}
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__116;

llvm_cbe_tmp__111:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([32 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([11 x i8]* @aesl_internal_.str8, i64 0, i64 0), i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str9, i64 0, i64 0)) nounwind, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__72 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
])), ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__72);
}
  if (((llvm_cbe_tmp__72) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__117;
  } else {
    goto llvm_cbe_tmp__118;
  }

llvm_cbe_tmp__117:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__73 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__73);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds %%struct._iobuf* %%102, i64 2, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__74 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__73[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = call i64 @fwrite(i8* getelementptr inbounds ([44 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 43, i64 1, %%struct._iobuf* %%103), !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_217_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 44
#endif
])), 43ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",43ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__75);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_218_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = call i64 @fwrite(i8* %%8, i64 2, i64 1, %%struct._iobuf* %%99) nounwind, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_220_count);
  fwrite(( char *)llvm_cbe_tmp__5, 2ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__76);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = call i64 @fwrite(i8* %%11, i64 4, i64 1, %%struct._iobuf* %%99) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_221_count);
  fwrite(( char *)llvm_cbe_tmp__8, 4ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__77);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = call i64 @fwrite(i8* %%14, i64 2, i64 1, %%struct._iobuf* %%99) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_222_count);
  fwrite(( char *)llvm_cbe_tmp__11, 2ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__78);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = call i64 @fwrite(i8* %%17, i64 2, i64 1, %%struct._iobuf* %%99) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_223_count);
  fwrite(( char *)llvm_cbe_tmp__14, 2ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__79);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = call i64 @fwrite(i8* %%20, i64 4, i64 1, %%struct._iobuf* %%99) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_224_count);
  fwrite(( char *)llvm_cbe_tmp__17, 4ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__80);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = call i64 @fwrite(i8* %%22, i64 40, i64 1, %%struct._iobuf* %%99) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_225_count);
  fwrite(( char *)llvm_cbe_tmp__19, 40ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__81);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = load i32* %%10, align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__82 = (unsigned int )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str11, i64 0, i64 0), i32 %%112) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_227_count);
  printf(( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__82);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__83);
}
  llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )64u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19 = phi i32 [ 64, %%105 ], [ %%131, %%130  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge19_count);
  llvm_cbe_storemerge19 = (unsigned int )llvm_cbe_storemerge19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%X",llvm_cbe_storemerge19);
printf("\n = 0x%X",64u);
printf("\n = 0x%X",llvm_cbe_tmp__99);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = sub nsw i32 127, %%storemerge19, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__84 = (unsigned int )((unsigned int )(127u&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge19&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__84&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = shl i32 %%114, 7, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__85 = (unsigned int )llvm_cbe_tmp__84 << 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
  llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__119;

llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%131 = add nsw i32 %%storemerge19, 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_278_count);
  llvm_cbe_tmp__99 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__99&4294967295ull)));
  if (((llvm_cbe_tmp__99&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__121;
  } else {
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__99;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28 = phi i32 [ 0, %%.preheader ], [ %%129, %%116  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge28_count);
  llvm_cbe_storemerge28 = (unsigned int )llvm_cbe_storemerge28__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28 = 0x%X",llvm_cbe_storemerge28);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__98);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = add nsw i32 %%storemerge28, %%115, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__86 = (unsigned int )((unsigned int )(llvm_cbe_storemerge28&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__85&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__86&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = sext i32 %%117 to i64, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__87 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = getelementptr inbounds i32* %%40, i64 %%118, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__88 = (signed int *)(&llvm_cbe_tmp__34[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = load i32* %%119, align 4, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__89 = (unsigned int )*llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = and i32 %%120, 255, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__90 = (unsigned int )llvm_cbe_tmp__89 & 255u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = lshr i32 %%120, 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__89&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = and i32 %%122, 255, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__92 = (unsigned int )llvm_cbe_tmp__91 & 255u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = lshr i32 %%120, 16, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__93 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__89&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__93&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = and i32 %%124, 255, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__94 = (unsigned int )llvm_cbe_tmp__93 & 255u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = call i32 @fputc(i32 %%121, %%struct._iobuf* %%99) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_265_count);
  fputc(llvm_cbe_tmp__90, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__90);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__95);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = call i32 @fputc(i32 %%123, %%struct._iobuf* %%99) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_266_count);
  fputc(llvm_cbe_tmp__92, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__92);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__96);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%128 = call i32 @fputc(i32 %%125, %%struct._iobuf* %%99) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_267_count);
  fputc(llvm_cbe_tmp__94, (l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__94);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__97);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = add nsw i32 %%storemerge28, 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__98 = (unsigned int )((unsigned int )(llvm_cbe_storemerge28&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__98&4294967295ull)));
  if (((llvm_cbe_tmp__98&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__120;
  } else {
    llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__98;   /* for PHI node */
    goto llvm_cbe_tmp__119;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__121:
if (AESL_DEBUG_TRACE)
printf("\n  %%133 = call i32 @fclose(%%struct._iobuf* %%99) nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_288_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__100);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%31), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_289_count);
  free(( char *)llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%39), !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_290_count);
  free(( char *)llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%47), !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_291_count);
  free(( char *)llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__116;

llvm_cbe_tmp__116:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 1, %%92 ], [ 0, %%132  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge4;
}


void nn_soft(signed int *llvm_cbe_cam_fb, signed int *llvm_cbe_nn_fb, signed int llvm_cbe_width, signed int llvm_cbe_height) {
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned int llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  unsigned int llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  signed int *llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  unsigned int llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  unsigned long long llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  signed int *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned int llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @nn_soft\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%17, %%.preheader..preheader.split_crit_edge  for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__134);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sdiv i32 %%storemerge3, 2, !dbg !6 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__122 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge3) / ((signed int )2u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__122));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul nsw i32 %%1, %%width, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__123 = (unsigned int )((unsigned int )(llvm_cbe_tmp__122&4294967295ull)) * ((unsigned int )(llvm_cbe_width&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__123&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i32 %%storemerge3, 7, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__124 = (unsigned int )llvm_cbe_storemerge3 << 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
  if ((((signed int )llvm_cbe_tmp__122) < ((signed int )llvm_cbe_height))) {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_split_2e_us;
  } else {
    goto llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge;
  }

llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%storemerge3, 1, !dbg !6 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__134 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__134&4294967295ull)));
  if (((llvm_cbe_tmp__134&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__135;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__134;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.preheader.split.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ %%8, %%7 ], [ 0, %%.preheader  for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__126);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sdiv i32 %%storemerge12.us, 2, !dbg !6 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__125 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge12_2e_us) / ((signed int )2u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__125));
  if ((((signed int )llvm_cbe_tmp__125) < ((signed int )llvm_cbe_width))) {
    goto llvm_cbe_tmp__136;
  } else {
    goto llvm_cbe_tmp__137;
  }

llvm_cbe_tmp__137:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge12.us, 1, !dbg !7 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__126 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__126&4294967295ull)));
  if (((llvm_cbe_tmp__126&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__126;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_split_2e_us;
  }

llvm_cbe_tmp__136:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%3, %%5, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__127 = (unsigned int )((unsigned int )(llvm_cbe_tmp__123&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__125&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__127&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_332_count);
  llvm_cbe_tmp__128 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i32* %%cam_fb, i64 %%11, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_333_count);
  llvm_cbe_tmp__129 = (signed int *)(&llvm_cbe_cam_fb[(((signed long long )llvm_cbe_tmp__128))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__128));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 4, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_334_count);
  llvm_cbe_tmp__130 = (unsigned int )*llvm_cbe_tmp__129;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge12.us, %%4, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__131 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__124&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__131&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%14 to i64, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_336_count);
  llvm_cbe_tmp__132 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i32* %%nn_fb, i64 %%15, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__133 = (signed int *)(&llvm_cbe_nn_fb[(((signed long long )llvm_cbe_tmp__132))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__132));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%13, i32* %%16, align 4, !dbg !4 for 0x%I64xth hint within @nn_soft  --> \n", ++aesl_llvm_cbe_338_count);
  *llvm_cbe_tmp__133 = llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
  goto llvm_cbe_tmp__137;

  } while (1); /* end of syntactic loop '.preheader.split.us' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__135:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @nn_soft}\n");
  return;
}

