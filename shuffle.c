/*
 * Print a random permutation of arguments.
 * Copyright © 2000-2018 Rudá Moura <ruda.moura@gmail.com>
 */

#include "shuffle.h"

void
seed(const char *entropy)
{
	unsigned i, n, fd;

	if (entropy == NULL) {
		/* Thank you the Camel Book */
		i = getpid();
		i = time(NULL) ^ (i + (i << 15));
	} else {
		fd = open(entropy, O_RDONLY, 0);
		if (fd == -1) {
			perror(entropy);
			exit(1);
		}
		n = read(fd, &i, sizeof(unsigned));
		close(fd);
		assert (n >= 0);
	}
	srandom(i);
}

void
shuffle(char *v[], int n)
{
	int i, j;
	char *s;

	for (i = n-1; i > 0; i--) {
		j = ((double)random() / RAND_MAX) * (i+1);
		s = v[j];
		v[j] = v[i];
		v[i] = s;
	}
}
