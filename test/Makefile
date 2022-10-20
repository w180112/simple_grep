############################################################
# grep makefile
############################################################

######################################
# Set variable
######################################	
CC	= gcc
INCLUDE = -I../lib/libutil
CFLAGS = $(INCLUDE) -Wall -fPIC

TARGET = test
SRC = ../src/filter.c test.c

OBJ = $(SRC:.c=.o)
	
all: $(TARGET) test
######################################
# Compile & Link
# 	Must use \tab key after new line
######################################
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -L../lib/libutil $(OBJ) -o $(TARGET) \
	-static -lutil
######################################
# Clean 
######################################
clean:
	rm -f $(OBJ) $(TARGET)