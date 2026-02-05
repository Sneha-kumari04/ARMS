CC = gcc
CFLAGS = -Wall

SRC = main.c student.c admin.c utils.c professor.c file_ops.c login.c
OUT = arms

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

