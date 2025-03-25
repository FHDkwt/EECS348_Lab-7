# Compiler to use
CC := gcc

# Compiler flags
CFLAGS := -Wall -g

# Targets
all: football.exe temperature.exe

# Football program
football.exe: football_main.o football.o
	$(CC) $(CFLAGS) -o football.exe football_main.o football.o

football_main.o: football_main.c football.h
	$(CC) $(CFLAGS) -c football_main.c

football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c

# Temperature program
temperature.exe: temperature_main.o temperature.o
	$(CC) $(CFLAGS) -o temperature.exe temperature_main.o temperature.o

temperature_main.o: temperature_main.c temperature.h
	$(CC) $(CFLAGS) -c temperature_main.c

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c

# Clean up
clean:
	rm -f *.o football.exe temperature.exe

.PHONY: all clean
