IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = 3d_dynamic.o
_OBJ2 = 3dmatrix.o
_OBJ3 = charptr.o
_OBJ4 = struct.o
_OBJ5 = practice_1.o
_OBJ6 = practice_2.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: 3d_dynamic 3dmatrix charptr struct practice_1 practice_2

3d_dynamic: $(_OBJ1)
	$(CC) -o $ b@ $^ $(CFLAGS) $(LIBS)

3dmatrix: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
charptr: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

struct: $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

practice_1: $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

practice_2: $(_OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~
	rm -f 3d_dynamic
	rm -f 3dmatrix
	rm -f charptr
	rm -f struct
	rm -f practice_1
	rm -f practice_2
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 