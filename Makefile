
SRC=main.c parser.c
OBJ=main.o parser.o

CFLAGS=-I/usr/include/libxml2 -DDEBUG
LDFLAGS=-lxml2

BIN=xml

%.o%.c:

$(BIN):$(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

all:$(BIN)
