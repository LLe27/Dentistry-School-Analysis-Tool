CC	= g++
CFLAGS	= -std=c++0x
LDFLAGS = -lpthread

.PHONY : all test clean

all : main.o main

main.o : main.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	
main : main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test: main
	./main
	
clean:
	rm -f *.o *~ main
