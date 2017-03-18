SHUFFLE

Shuffle prints to standard output a random permutation of the argument list.

Knuth algorithm (in fact Fisher-Yates shuffle) is used to guarantee
truly random permutations. On supported systems,
one source of entropy is /dev/random or /dev/urandom.

INSTALL

Just run 'make' and then 'make install' (possibly with sudo).
The default prefix for installation is /usr/local/.

$ make
$ sudo make install

You can also install in your home directory.

$ make
$ make PREFIX=$HOME/.local install

USAGE

$ shuffle alpha beta gamma
beta gamma alpha

$ playmidi $(shuffle *.mid)
