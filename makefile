CC=gcc
CFLAGS=-Wall -std=c99 -lm
DEPS = integrator.h
EUL = $(DEPS)  euler.o  duffing.o
RK4 = $(DEPS) rk4.o duffing.o
AB = $(DEPS) ab2.o duffing.o

all: duffing_euler duffing_rk4 duffing_ab2

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

duffing_euler: $(EUL)
	gcc -o $@ $^ $(CFLAGS)

duffing_rk4: $(RK4)
	gcc -o $@ $^ $(CFLAGS)

duffing_ab2: $(AB)
	gcc -o $@ $^ $(CFLAGS)
