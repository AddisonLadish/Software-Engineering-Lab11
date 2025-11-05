CXX = g++
CXXFLAGS = -Wall -std=c++11
OBJS = main.o Matrix.o

all: lab11

lab11: $(OBJS)
	$(CXX) $(CXXFLAGS) -o lab11 $(OBJS)

main.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

clean:
	rm -f *.o lab11
