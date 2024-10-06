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

LD = g++
LD_FLAGS =


## -------------------------------------------------------------------------------------------------
## -- Generated files
## -------------------------------------------------------------------------------------------------
MAIN = main.cpp
SRC  = $(MAIN)
SRC += LogBook.cpp
SRC += Logger.cpp
SRC += LogSystem.cpp

DEP  = $(patsubst %.cpp,../build/dep/%.dep,$(SRC))
OBJ  = $(patsubst %.cpp,../build/obj/%.o,$(SRC))
EXEC = ../build/c-log

MODULE_FILEPATH = ../mod/c-log
MODULE_OBJ = ../build/obj/c-log.o
MAIN_OBJ = $(patsubst %.cpp,../build/obj/%.o,$(MAIN))

## -------------------------------------------------------------------------------------------------
## -- Commands + default
## -------------------------------------------------------------------------------------------------
.PHONY : all build build-module run clean

all : build


## -------------------------------------------------------------------------------------------------
## -- Build dependencies
## -------------------------------------------------------------------------------------------------
../build/dep/%.dep : %.cpp
	@printf "%b[  DEP] %b" $(YELLOW) $(RESET_COLOR)
	$(CC) -MM -MT ../build/obj/$(patsubst %.cpp,%.o,$<) $^ -o $@

# Automatically include dependencies
-include $(DEP)


## -------------------------------------------------------------------------------------------------
## -- Compile source files into object files
## -------------------------------------------------------------------------------------------------
../build/obj/%.o : %.cpp
	@printf "%b[CMPIL] %b" $(YELLOW) $(RESET_COLOR)
	$(CC) $(CC_FLAGS) $(CC_INC) -c $< -o $@

$(MODULE_OBJ) :
	@$(MAKE) --no-print-directory -C $(MODULE_FILEPATH)


## -------------------------------------------------------------------------------------------------
## -- Link object files into executable
## -------------------------------------------------------------------------------------------------
build : $(OBJ)
	@# Link object files
	@printf "%b[ LINK] %b" $(YELLOW) $(RESET_COLOR)
	$(LD) $(LD_FLAGS) $(OBJ) -o $(EXEC)

	@printf "%b[BUILD] Executable built\n%b" $(GREEN) $(RESET_COLOR)

build-module : $(MODULE_OBJ) $(MAIN_OBJ)
	@# Link object files
	@printf "%b[ LINK] %b" $(YELLOW) $(RESET_COLOR)
	$(LD) $(LD_FLAGS) $(MODULE_OBJ) $(MAIN_OBJ) -o $(EXEC)

	@printf "%b[BUILD] Executable built\n%b" $(GREEN) $(RESET_COLOR)


## -------------------------------------------------------------------------------------------------
## -- Run executable
## -------------------------------------------------------------------------------------------------
run :
	@printf "%b[  RUN] %b" $(BLUE) $(RESET_COLOR)
	./$(EXEC)


## -------------------------------------------------------------------------------------------------
## -- Clean up
## -------------------------------------------------------------------------------------------------
clean :
	@printf "%b[CLEAN] %b" $(RED) $(RESET_COLOR)
	rm -rf $(DEP)

	@printf "%b[CLEAN] %b" $(RED) $(RESET_COLOR)
	rm -rf $(OBJ)

	@printf "%b[CLEAN] %b" $(RED) $(RESET_COLOR)
	rm -rf $(EXEC)


