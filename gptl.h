/*
$Id: gptl.h,v 1.39 2008-10-09 20:50:46 rosinski Exp $
*/
#ifndef GPTL_H
#define GPTL_H

/*
** Options settable by a call to GPTLsetoption() (default in parens)
*/

typedef enum {
  GPTLwall           = 1,  /* Collect wallclock stats (true) */
  GPTLcpu            = 2,  /* Collect CPU stats (false)*/
  GPTLabort_on_error = 3,  /* Abort on failure (false) */
  GPTLoverhead       = 4,  /* Estimate overhead of underlying timing routine (true) */
  GPTLdepthlimit     = 5,  /* Print timers this depth or less in the tree (inf) */
  GPTLverbose        = 6,  /* Verbose output (false) */
  GPTLnarrowprint    = 7,  /* Print PAPI stats in 8 columns not 16 (true) */
  GPTLpercent        = 9,  /* Add a column for percent of first timer (true) */
  GPTLpersec         = 10, /* Add a PAPI column that prints "per second" stats (true) */
  GPTLmultiplex      = 11, /* Allow PAPI multiplexing (true) */
  /*
  ** These are derived counters based on PAPI counters. All default to false
  */
  GPTL_IPC           = 12, /* Instructions per cycle */
  GPTL_CI            = 13, /* Computational intensity */
  GPTL_FPC           = 14, /* FP ops per cycle */
  GPTL_FPI           = 15, /* FP ops per instruction */
  GPTL_LSTPI         = 16, /* Load-store instruction fraction */
  GPTL_DCMRT         = 17, /* L1 miss rate (fraction) */
  GPTL_LSTPDCM       = 18  /* Load-stores per L1 miss */
} Option;

/*
** Underlying wallclock timer: optimize for best granularity with least overhead
*/

typedef enum {
  GPTLgettimeofday   = 22, /* the default */
  GPTLnanotime       = 23, /* only available on x86 */
  GPTLrtc            = 24, /* real time clock (UNICOSMP only) */
  GPTLmpiwtime       = 25, /* MPI_Wtime */
  GPTLclockgettime   = 26, /* clock_gettime */
  GPTLpapitime       = 27  /* only if PAPI is available */
} Funcoption;

/*
** Function prototypes
*/

extern int GPTLsetoption (const int, const int);
extern int GPTLinitialize (void);
extern int GPTLstart (const char *);
extern int GPTLstop (const char *);
extern int GPTLstamp (double *, double *, double *);
extern int GPTLpr (const int);
extern int GPTLpr_file (const char *);
extern int GPTLpr_summary (int);
extern int GPTLreset (void);
extern int GPTLfinalize (void);
extern int GPTLget_memusage (int *, int *, int *, int *, int *);
extern int GPTLprint_memusage (const char *);
extern int GPTLenable (void);
extern int GPTLdisable (void);
extern int GPTLsetutr (const int);
extern int GPTLquery (const char *, int, int *, int *, double *, double *, double *,
		      long long *, const int);
extern int GPTLquerycounters (const char *, int, long long *);
extern int GPTLget_nregions (int, int *);
extern int GPTLget_regionname (int, int, char *, int);
extern int GPTL_PAPIlibraryinit ();
extern int GPTLevent_name_to_code (const char *, int *);
extern int GPTLevent_code_to_name (const int, char *);
#endif
