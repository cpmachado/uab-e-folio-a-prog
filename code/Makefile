include config.mk


SRC = ${wildcard 2200909*.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN = ${SRC:.c=}

all: ${BIN}
	@echo all built

clean:
	@rm -rf ${BIN} ${OBJ} ${DEP}

lint:
	$(foreach file,${SRC}, ./res/qa-efolio ${file};)

%:
	${CC} -o $@ $< ${LDFLAGS}

2200909A: 2200909A.o
2200909B: 2200909B.o
2200909C: 2200909C.o
2200909D: 2200909D.o
