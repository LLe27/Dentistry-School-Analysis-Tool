CC	= g++
CFLAGS	= -std=c++0x
LDFLAGS = -lpthread

.PHONY : all test clean testD

all : DateFormat.o DateFormat
	
DateFormat.o : DateFormat.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	
DateFormat : DateFormat.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test: DateFormat
	./DateFormat
	
clean:
	rm -f *.o *~ DateFormat
