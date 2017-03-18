PREFIX=/usr/local
BINDIR=$(PREFIX)/bin
MANDIR=$(PREFIX)/share/man

CFLAGS=-Wall -Werror -pedantic
CFLAGS+=-Os
#CFLAGS+=-g

OBJS=shuffle.o main.o

all: shuffle

shuffle: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

shuffle.ps: shuffle.1
	groff -man shuffle.1 > $@

shuffle.txt: shuffle.1
	groff -tman -Tutf8 shuffle.1 > $@

shuffle.html: shuffle.1
	groff -tman -Thtml shuffle.1 > $@

test: shuffle
	./test.sh

install: shuffle shuffle.1
	test -d $(DESTDIR)$(BINDIR) || install -d $(DESTDIR)$(BINDIR)
	install -m 755 shuffle $(DESTDIR)$(BINDIR)/shuffle
	test -d $(DESTDIR)$(MANDIR)/man1 || install -d $(DESTDIR)$(MANDIR)/man1
	install -m 644 shuffle.1 $(DESTDIR)$(MANDIR)/man1/shuffle.1

uninstall:
	rm -f $(BINDIR)/shuffle
	rm -f $(MANDIR)/man1/shuffle.1

tags:
	ctags *.c *.h

clean:
	rm -f *~ $(OBJS) shuffle shuffle.ps shuffle.txt shuffle.html tags
