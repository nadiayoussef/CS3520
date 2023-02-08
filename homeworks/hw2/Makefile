IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = hw2_q1.o
_OBJ2 = hw2_q2.o
_OBJ3 = hw2_q3.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: hw2_q1 hw2_q2 hw2_q3

hw2_q1: $(_OBJ1)
	$(CC) -o $ b@ $^ $(CFLAGS) $(LIBS)

hw2_q2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
hw2_q3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~
	rm -f hw2_q3
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 