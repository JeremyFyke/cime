/*
** $Id: f_wrappers.c,v 1.20 2007-02-27 20:26:41 rosinski Exp $
** 
** Fortran wrappers for timing library routines
*/

#include <string.h>
#include "private.h" /* MAX_CHARS, bool */
#include "gptl.h"    /* function prototypes */

#if ( defined FORTRANCAPS )

#define gptlinitialize GPTLINITIALIZE
#define gptlfinalize GPTLFINALIZE
#define gptlpr GPTLPR
#define gptlreset GPTLRESET
#define gptlstamp GPTLSTAMP
#define gptlstart GPTLSTART
#define gptlstop GPTLSTOP
#define gptlsetoption GPTLSETOPTION
#define gptlenable GPTLENABLE
#define gptldisable GPTLDISABLE
#define gptlsetutr GPTLSETUTR
#define gptlquery GPTLQUERY
#define gptlquerycounters GPTLQUERYCOUNTERS
#define gptlget_nregions GPTLGET_NREGIONS
#define gptlget_regionname GPTLGET_REGIONNAME
#define gptlget_memusage GPTLGET_MEMUSAGE
#define gptlprint_memusage GPTLPRINT_MEMUSAGE
#define gptl_papiprinttable GPTL_PAPIPRINTTABLE
#define gptl_papiname2id GPTL_PAPINAME2ID

#elif ( defined FORTRANUNDERSCORE )

#define gptlinitialize gptlinitialize_
#define gptlfinalize gptlfinalize_
#define gptlpr gptlpr_
#define gptlreset gptlreset_
#define gptlstamp gptlstamp_
#define gptlstart gptlstart_
#define gptlstop gptlstop_
#define gptlsetoption gptlsetoption_
#define gptlenable gptlenable_
#define gptldisable gptldisable_
#define gptlsetutr gptlsetutr_
#define gptlquery gptlquery_
#define gptlquerycounters gptlquerycounters_
#define gptlget_nregions gptlget_nregions_
#define gptlget_regionname gptlget_regionname_
#define gptlget_memusage gptlget_memusage_
#define gptlprint_memusage gptlprint_memusage_
#define gptl_papiprinttable gptl_papiprinttable_
#define gptl_papiname2id gptl_papiname2id_

#elif ( defined FORTRANDOUBLEUNDERSCORE )

#define gptlinitialize gptlinitialize_
#define gptlfinalize gptlfinalize_
#define gptlpr gptlpr_
#define gptlreset gptlreset_
#define gptlstamp gptlstamp_
#define gptlstart gptlstart_
#define gptlstop gptlstop_
#define gptlsetoption gptlsetoption_
#define gptlenable gptlenable_
#define gptldisable gptldisable_
#define gptlsetutr gptlsetutr_
#define gptlquery gptlquery_
#define gptlquerycounters gptlquerycounters_
#define gptlget_nregions gptlget_nregions__
#define gptlget_regionname gptlget_regionname__
#define gptlget_memusage gptlget_memusage__
#define gptlprint_memusage gptlprint_memusage__
#define gptl_papiprinttable gptl_papiprinttable__
#define gptl_papiname2id gptl_papiname2id__

#endif

int gptlinitialize ()
{
  return GPTLinitialize ();
}

int gptlfinalize ()
{
  return GPTLfinalize ();
}

int gptlpr (int *procid)
{
  return GPTLpr (*procid);
}

void gptlreset ()
{
  GPTLreset();
  return;
}

int gptlstamp (double *wall, double *usr, double *sys)
{
  return GPTLstamp (wall, usr, sys);
}

int gptlstart (char *name, int nc1)
{
  char cname[MAX_CHARS+1];
  int numchars;

  numchars = MIN (nc1, MAX_CHARS);
  strncpy (cname, name, numchars);
  cname[numchars] = '\0';
  return GPTLstart (cname);
}

int gptlstop (char *name, int nc1)
{
  char cname[MAX_CHARS+1];
  int numchars;

  numchars = MIN (nc1, MAX_CHARS);
  strncpy (cname, name, numchars);
  cname[numchars] = '\0';
  return GPTLstop (cname);
}

int gptlsetoption (int *option, int *val)
{
  return GPTLsetoption (*option, *val);
}

int gptlenable ()
{
  return GPTLenable ();
}

int gptldisable ()
{
  return GPTLdisable ();
}

int gptlsetutr (int *option)
{
  return GPTLsetutr (*option);
}

int gptlquery (const char *name, int *t, int *count, int *onflg, double *wallclock, 
	       double *usr, double *sys, long long *papicounters_out, int *maxcounters, 
	       int nc)
{
  char cname[MAX_CHARS+1];
  int numchars;

  numchars = MIN (nc, MAX_CHARS);
  strncpy (cname, name, numchars);
  cname[numchars] = '\0';
  return GPTLquery (cname, *t, count, onflg, wallclock, usr, sys, papicounters_out, *maxcounters);
}

int gptlquerycounters (const char *name, int *t, long long *papicounters_out, int nc)
{
  char cname[MAX_CHARS+1];
  int numchars;

  numchars = MIN (nc, MAX_CHARS);
  strncpy (cname, name, numchars);
  cname[numchars] = '\0';
  return GPTLquerycounters (cname, *t, papicounters_out);
}

int gptlget_nregions (int *t, int *nregions)
{
  return GPTLget_nregions (*t, nregions);
}

int gptlget_regionname (int *t, int *region, char *name, int nc)
{
  return GPTLget_regionname (*t, *region, name, nc);
}

int gptlget_memusage (int *size, int *rss, int *share, int *text, int *datastack)
{
  return GPTLget_memusage (size, rss, share, text, datastack);
}

int gptlprint_memusage (const char *str, int nc)
{
  char cname[128+1];
  int numchars = MIN (nc, 128);

  strncpy (cname, str, numchars);
  cname[numchars] = '\0';
  return GPTLprint_memusage (cname);
}

void gptl_papiprinttable ()
{
  GPTL_PAPIprinttable ();
  return;
}

int gptl_papiname2id (const char *name, int nc)
{
  char cname[16+1];
  int numchars = MIN (nc, 16);

  strncpy (cname, name, numchars);
  cname[numchars] = '\0';
  return GPTL_PAPIname2id (cname);
}
