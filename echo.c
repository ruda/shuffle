/*
 * Print a random permutation of arguments.
 * Copyright © 2000-2018 Rudá Moura <ruda.moura@gmail.com>
 */

#include "shuffle.h"

void
echo(char *v[], int n, int nflag, int oneflag, int eflag)
{
	int i;

	for (i=0; i < n; i++) {
		if (eflag)
			fputc('"', stdout);
		fputs(v[i], stdout);
		if (eflag)
			fputc('"', stdout);
		if (v[i+1]) {
			if (oneflag) {
				putchar('\n');
			} else {
				putchar(' ');
			}
		}
	}
	if (!nflag)      
		putchar('\n');
}
