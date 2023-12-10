CC = gcc
SRC = test_application.c
OUT = test_application

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $^ -o $@

clean:
	rm -f $(OUT)
