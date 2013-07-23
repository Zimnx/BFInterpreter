CXX=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
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