.PHONY: all clean lint tests

include config.mk


SRC = ${wildcard 2200909*.c}
GCOV = ${SRC:.c=.c.gcov} ${SRC:.c=.gcda} ${SRC:.c=.gcno}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN = ${SRC:.c=}
TESTS = ${wildcard res/test*}

all: ${BIN}
	@echo all built

clean:
	@rm -rf ${BIN} ${OBJ} ${DEP} ${GCOV}

lint:
	$(foreach file,${SRC}, ./res/qa-efolio ${file};)

tests: ${BIN}
	for test in ${TESTS};do $${test};done
	for file in ${SRC};do gcov $${file};done

%:
	${CC} -o $@ $< ${LDFLAGS}

2200909A: 2200909A.o
2200909B: 2200909B.o
2200909C: 2200909C.o
2200909D: 2200909D.o
