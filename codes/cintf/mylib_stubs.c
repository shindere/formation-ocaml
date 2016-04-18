#include "mylib.h"

#define CAML_NAME_SPACE

#include <caml/mlvalues.h> /* definition of the value type, and conversion macros */

#if 0
#include <caml/alloc.h> /* allocation functions (to create structured OCaml objects) */
#endif

#include <caml/memory.h> /* miscellaneous memory-related functions and macros (for GC interface, in-place modification of structures, etc). */

#if 0
#include <caml/fail.h> /* functions for raising exceptions */
#include <caml/callback.h> /* callback from C to OCaml */
#include <caml/custom.h> /* operations on custom blocks */
#include <caml/intext.h> /* operations for writing user-defined serialization and deserialization functions for custom blocks */
#include <caml/threads.h> /* operations for interfacing in the presence of multiple threads*/
#endif

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
