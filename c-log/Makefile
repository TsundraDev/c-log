# Modify object file to directory
OBJ = c-log.o

# Compiler
CC = g++
CC_FLAGS = --std=c++20 -O3

# Module source files
SRC  = src/LogBook.cpp
SRC += src/Logger.cpp
SRC += src/LogSystem.cpp

$(OBJ) : 
	$(CC) $(CC_FLAGS) -r $(SRC) -o $(OBJ)
