CC = g++
OPTIONS = -g
DEBUG = #-D DEBUG
LIBDIR = lib
INCLUDEDIR = include

_OBJ = tcalendario.o tvectorcalendario.o tlistacalendario.o tabbcalendario.o tavlcalendario.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad: src/main.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/main.cpp $(OBJ) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

clean:
	rm -f $(OBJ) main

#valgrind --tool=memcheck --leak-check=full ./main