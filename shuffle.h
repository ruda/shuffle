/*
 * Print a random permutation of arguments.
 * Copyright © 2000-2018 Rudá Moura <ruda.moura@gmail.com>
 */

#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef __SHUFFLE_H
#define __SHUFFLE_H

void seed(const char *);
void shuffle(char *v[], int n);
void echo(char *v[], int n, int nflag, int oneflag, int eflag);
void usage(void);
void version(void);

#endif /* __SHUFFLE_H */
