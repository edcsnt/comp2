include config.mk

OBJ = comp2.o
BIN = comp2

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

check: $(BIN)
	-./$(BIN)
	rm $(BIN) $(OBJ)

clean:
	rm -f $(BIN) $(OBJ)
