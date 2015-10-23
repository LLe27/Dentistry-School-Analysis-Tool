CC	= g++
CFLAGS	= -std=c++0x
LDFLAGS = -lpthread

.PHONY : all test clean

all : parsetest.o parsetest

parsetest.o : parsetest.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	
parsetest : parsetest.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test: parsetest
	./parsetest
	
clean:
	rm -f *.o *~ parsetest
