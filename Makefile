CFLAGS = -Wall -Wextra -Werror
SOURCES = my_bc.c source/*.c
TARGET = my_bc
CC = gcc

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:
	fclean

fclean:
	@rm -f $(OBJECTS) $(TARGET)