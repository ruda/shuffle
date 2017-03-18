/*
 * Print a random permutation of arguments.
 * Copyright © 2000-2017 Rudá Moura <ruda.moura@gmail.com>
 */

#include <stdio.h>
#include <string.h>
#include "shuffle.h"

void
usage(void)
{
	printf("Print a random permutation of arguments.\n");
	printf("Usage: shuffle [-h|-v|-n|-1|-e] [-p <number>] [-r <file>] arguments\n");
}

void
version(void)
{
	printf("shuffle version 1.17.3\n");
	printf("Copyright (c) 2000-2017 Ruda Moura <ruda.moura@gmail.com>\n");
}

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

int
main(int argc, char *argv[])
{
	int i, ch, nflag, oneflag, eflag;
	const char *entropy = NULL;
	int p = 1;
	nflag = oneflag = eflag = 0;

	while ((ch = getopt(argc, argv, "hvn1p:r:e")) != -1)
		switch (ch) {
		case 'h':
			usage();
			return 0;
			break;
		case 'v':
			version();
			return 0;
		case 'n':
			nflag = 1;
			break;
		case '1':
			oneflag = 1;
			break;
		case 'p':
			p = atoi(optarg);
			break;
		case 'r':
			entropy = optarg;
			break;
		case 'e':
			eflag = 1;
			break;
		default:
			return 0;
			break;
		}
	argc -= optind;
	argv += optind;

	seed(entropy);

	for (i = 0; i < p; i++) {
		shuffle(argv, argc);
		echo(argv, argc, nflag, oneflag, eflag);
	}

	return 0;
}
