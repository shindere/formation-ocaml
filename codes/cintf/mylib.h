#ifndef __MYLIB__
#define __MYLIB__

int mylib_open(const char *pathname, int flags);
void mylib_close(int descriptor);

extern int mylib_errno;

#endif /* __MYLIB__ */
