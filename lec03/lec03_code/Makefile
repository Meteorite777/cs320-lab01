PROGRAMS = args bool braces declaration hello_world hello_numbers

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -g3 -O0 -std=c17 -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wshadow -Winit-self -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean::
	rm -f $(PROGRAMS) *.o a.out
	rm -rf *.dSYM

.PHONY: clean all
	