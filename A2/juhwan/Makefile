# NOTE: All indented lines are indented with a tab character. This is required.

CC=gcc
CFLAGS=
DFLAGS=
PROGS= setBits showBits

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm -f $(PROGS) *.o ~*

