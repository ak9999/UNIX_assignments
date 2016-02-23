// Include guards
#ifndef __PATH_ALLOC__
#define __PATH_ALLOC__

#include <errno.h>
#include <limits.h>
#include <stdio.h>

char *
path_alloc(size_t *); /* also return allocated size, if nonnull */

#include "path_alloc.c"

#endif /* end of include guard: __PATH_ALLOC__ */
