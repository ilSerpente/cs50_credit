C = clang
CFLAGS=-I.
LDLIBS += -lcs50
credit: credit.o 
	$(C) -o credit credit.o $(LDLIBS)
