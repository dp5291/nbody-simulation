CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
# Your .hpp files
DEPS = Universe.hpp CelestialBody.hpp
# Your compiled .o files
OBJECTS = Universe.o CelestialBody.o main.o

LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

.PHONY: all NBody clean lint


all: NBody.a NBody test


%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

NBody.a: Universe.o CelestialBody.o
	ar rcs $@ $^ 

NBody: main.o Universe.o CelestialBody.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: test.o Universe.o CelestialBody.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	-rm -f *.o NBody.a NBody test

lint:
	cpplint *.cpp *.hpp
