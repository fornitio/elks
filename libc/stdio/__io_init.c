#include <stdlib.h>
#include <unistd.h>

#include "_stdio.h"

static void
__stdio_close_all(void)
{
   FILE *fp;
   fflush(stdout);
   fflush(stderr);
   for (fp = __IO_list; fp; fp = fp->next)
   {
      fflush(fp);
      close(fp->fd);
      /* Note we're not de-allocating the memory */
      /* There doesn't seem to be much point :-) */
      fp->fd = -1;
   }
}

void
__io_init_vars(void)
{
#ifndef __AS386_16__
#ifndef __AS386_32__
   static int first_time = 1;
   if( !first_time ) return ;
   first_time = 0;
#endif
#endif
   if (isatty(1))
      stdout->mode |= _IOLBF;
   atexit(__stdio_close_all);
}
