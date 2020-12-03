CC =gcc
AR =ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS=-Wall -g -fPIC

all: mains maind
mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
maind: $(OBJECTS_MAIN) libmyBank.so
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
libmyBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all myBankd myBanks
clean:
	rm -f *.o *.a *.so maind mains