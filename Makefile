CC = g++
CFLAGS = -g -std=c++14
INCLUDES = cxxtest-4.4
SOURCES = solution.cpp
TESTS = tests.h
DEMO = demo.cpp

HELPERCPP = testrunner.cpp
TESTRUNNER = runner

all:
	${CC} ${CFLAGS} -I ${INCLUDES} ${SOURCES} ${DEMO} -o ${TESTRUNNER}

test:
	./cxxtest-4.4/bin/cxxtestgen --error-printer -o ${HELPERCPP} ${TESTS}
	${CC} ${CFLAGS} -I ${INCLUDES} ${SOURCES} ${HELPERCPP} -o ${TESTRUNNER}
	./${TESTRUNNER}

clean:
	rm ${HELPERCPP} ${TESTRUNNER}
