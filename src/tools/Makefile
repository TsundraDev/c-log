## -------------------------------------------------------------------------------------------------
## -- Colors
## -------------------------------------------------------------------------------------------------
RED         = "\e[1;31m"
GREEN       = "\e[1;32m"
YELLOW      = "\e[1;33m"
BLUE        = "\e[1;34m"
RESET_COLOR = "\e[0m"


## -------------------------------------------------------------------------------------------------
## -- Compiler and linker
## -------------------------------------------------------------------------------------------------
CC = g++
CC_FLAGS = --std=c++20 -Wall -Wextra -Werror
CC_INC = -I.

AR = ar
AR_FLAGS = r


## -------------------------------------------------------------------------------------------------
## -- Generated files
## -------------------------------------------------------------------------------------------------
SRC  = Log/LogBook.cpp
SRC += Log/Logger.cpp
SRC += Log/LogSystem.cpp

OBJ  = $(patsubst %.cpp,./obj/%.o,$(SRC))
MOD_OBJ = tools

## -------------------------------------------------------------------------------------------------
## -- Commands + default
## -------------------------------------------------------------------------------------------------
.PHONY : build


## -------------------------------------------------------------------------------------------------
## -- Link object files into executable
## -------------------------------------------------------------------------------------------------
build :
	@# Compile source files
	@printf "%b    [  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p obj
	@printf "%b    [  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p obj/Log

	@# Compile source files
	@printf "%b    [CMPIL] Start compiling\n%b" $(YELLOW) $(RESET_COLOR)
	@$(MAKE) --no-print-directory $(OBJ)

	@# Link object files
	@printf "%b    [ LINK] %b" $(YELLOW) $(RESET_COLOR)
	g++ -r $(OBJ) -o $(MOD_OBJ)


	@# Remove object files
	@printf "%b    [CLEAN] %b" $(RED) $(RESET_COLOR)
	rm -rf obj/


## -------------------------------------------------------------------------------------------------
## -- Compile source files into object files
## -------------------------------------------------------------------------------------------------
./obj/Log/%.o : Log/%.cpp
	@printf "%b    [CMPIL] %b" $(YELLOW) $(RESET_COLOR)
	$(CC) $(CC_FLAGS) $(CC_INC) -c $< -o $@


