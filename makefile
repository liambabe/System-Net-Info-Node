IDIR = include
ODIR = obj
CC=gcc
CFLAGS=-I$(IDIR)
SOURCES = $(shell find . -maxdepth 4 -name "*.c")

all: compile

debug:
	$(CC) -g $(CFLAGS) $(SOURCES)

rebuild: clean compile

compile:
	 $(CC) $(CFLAGS) $(SOURCES)
	
clean:
	rm -rf $(ODIR)/*.o