CXX=g++

CFLAGS= -c
CXXFLAGS= -Wall -W -Wextra
OUTPUT= bfi
all: bfi

bfi: bfi.o
	$(CXX) $(CXXFLAGS) bfi.o -o $(OUTPUT)

bfi.o: bfi.cpp
	$(CXX) $(CFLAGS) bfi.cpp 

clean:
	rm -rf *.o 
distclean:
	rm -rf *.o $(OUTPUT)