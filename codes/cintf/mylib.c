#include <stdio.h>
#include <stdarg.h>

#include "mylib.h"

#define MAXFILES 16

static const char *files[MAXFILES];

static int firstFreeDescriptor = 0;

int mylib_errno = 0;

static int mylib_message(const char *format, ...)
{
  int result;
  va_list ap;
  va_start(ap, format);
  result = fprintf(stderr, "[mylib] ");
  if (result < 0) return result;
  result = vfprintf(stderr, format, ap);
  va_end(ap);
  return result;
}

int mylib_open(const char *pathname, int flags)
{
  int i;

  mylib_message("Entering mylib_open\n");
  for (i=0; i<firstFreeDescriptor; i++) if (files[i] == NULL) goto found;

  if ( firstFreeDescriptor >= MAXFILES ) {
    mylib_message("No file descriptor left\n");
    return -1;
  }
  
  i = firstFreeDescriptor;
  
  firstFreeDescriptor++;

found:
  files[i] = pathname;
  mylib_message("Assigning descriptor #%d to path %s\n", i, pathname);
  return i;
}

void mylib_close(int descriptor)
{
  mylib_message("Entering mylib_close\n");
  files[descriptor] = NULL;

  while ( (firstFreeDescriptor>0) && (files[firstFreeDescriptor-1] == NULL) )
    firstFreeDescriptor--;
}
