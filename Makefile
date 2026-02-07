CC = gcc
SRC = main.c student.c admin.c utils.c professor.c login.c
OUT = arms

all:
	$(CC) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
