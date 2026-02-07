CC = gcc
SRC = main.c student.c admin.c utils.c professor.c login.c

ifeq ($(OS),Windows_NT)
	OUT = arms.exe
	RM = del
	RUN = $(OUT)
else
	OUT = arms
	RM = rm -f
	RUN = ./$(OUT)
endif

all:
	$(CC) $(SRC) -o $(OUT)

run: all
	$(RUN)

clean:
	$(RM) $(OUT)
