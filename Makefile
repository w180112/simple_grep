############################################################
# grep makefile
############################################################

######################################
# Set variable
######################################	
CC	= gcc
INCLUDE = -Ilib/libutil
CFLAGS = $(INCLUDE) -Wall -fPIC

TARGET = bin/grep
SRC = src/grep.c src/filter.c

OBJ = $(SRC:.c=.o)
	
all: $(TARGET)
######################################
# Compile & Link
# 	Must use \tab key after new line
######################################
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
######################################
# Clean 
######################################
clean:
	rm -f $(OBJ) $(TARGET)