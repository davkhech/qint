CC = g++
CFLAGS = -Wall -g
INCLUDES = cxxtest-4.4

all:
	ls

test:
	./cxxtest-4.4/bin/cxxtestgen --error-printer -o testrunner.cpp tests.h
	${CC} -I ${INCLUDES} solution.cpp testrunner.cpp -o runner
	./runner
