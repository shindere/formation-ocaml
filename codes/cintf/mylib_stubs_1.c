#include "mylib.h"

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/memory.h>

CAMLprim value stub_mylib_open(value name, value flags)
{
  char *name_c;
  int flags_c;
  int fd_c;
  value fd;
  CAMLparam2(name, flags);

  name_c = String_val(name);
  flags_c = Int_val(flags);
  
  fd_c = mylib_open(name_c, flags_c);
  
  fd = Val_int(fd_c);

  CAMLreturn(fd);
}

CAMLprim value stub_mylib_close(value fd)
{
  int fd_c;
  CAMLparam1(fd);
  fd_c = Int_val(fd);
  mylib_close(fd_c);
  CAMLreturn(Val_unit);
}
