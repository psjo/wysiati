CC = cc
LIBS = -lncursesw
CFLAGS = -std=c99 -pedantic -Wall
LDFLAGS = -s ${LIBS}
SRC = wysiati.c
OBJ = ${SRC:.c=.o}

all: options wysiati

options:
	@echo wysiati build:
	@echo "CC	= ${CC}"
	@echo "CFLAGS	= ${CFLAGS}"
	@echo "LIBS	= ${LIBS}"
	@echo "SRC	= ${SRC}"

.c.o:
	@echo "CC $<"
	@${CC} -c ${CFLAGS} $<

wysiati: ${OBJ}
	@echo "CC -o $@"
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo Cleaning
	@rm -f wysiati ${OBJ}

.PHONY: all options clean

