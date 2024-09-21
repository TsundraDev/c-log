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
SRC  = main.cpp

DEP  = $(patsubst %.cpp,../build/dep/%.d,$(SRC))
OBJ  = $(patsubst %.cpp,../build/obj/%.o,$(SRC))
EXEC = ../build/c-log


## -------------------------------------------------------------------------------------------------
## -- Commands + default
## -------------------------------------------------------------------------------------------------
.PHONY : all dirs depend build run clean purge

all :
	@$(MAKE) --no-print-directory dirs
	@$(MAKE) --no-print-directory build


## -------------------------------------------------------------------------------------------------
## -- Project setup
## -------------------------------------------------------------------------------------------------
dirs :
	@printf "%b%b%b" $(YELLOW) "[  DIR] " $(RESET_COLOR)
	mkdir -p ../build/

	@printf "%b%b%b" $(YELLOW) "[  DIR] " $(RESET_COLOR)
	mkdir -p ../build/dep/

	@printf "%b%b%b" $(YELLOW) "[  DIR] " $(RESET_COLOR)
	mkdir -p ../build/obj/


## -------------------------------------------------------------------------------------------------
## -- Build dependencies
## -------------------------------------------------------------------------------------------------
depend : $(DEP)

../build/dep/%.d : %.cpp
	@printf "%b%b%b" $(YELLOW) "[  DEP] " $(RESET_COLOR)
	if [ -d "../build/" ]; then $(CC) -MM -MT ../build/obj/$(patsubst %.cpp,%.o,$<) $^ -o $@; fi

-include $(DEP)


## -------------------------------------------------------------------------------------------------
## -- Link object files into executable
## -------------------------------------------------------------------------------------------------
build :
	@# Compile source files
	@printf "%b%b%b" $(YELLOW) "[CMPIL] Start compiling\n" $(RESET_COLOR)
	@$(MAKE) --no-print-directory $(OBJ)
	
	@# Link object files
	@printf "%b%b%b" $(YELLOW) "[ LINK] Start linking\n" $(RESET_COLOR)
	@printf "%b%b%b" $(YELLOW) "[ LINK] " $(RESET_COLOR)
	$(LD) $(LD_FLAGS) $(OBJ) -o $(EXEC)
	@printf "%b%b%b" $(GREEN) "[BUILD] Executable built" $(RESET_COLOR)


## -------------------------------------------------------------------------------------------------
## -- Compile source files into object files
## -------------------------------------------------------------------------------------------------
../build/obj/%.o : %.cpp
	@printf "%b%b%b" $(YELLOW) "[CMPIL] " $(RESET_COLOR)
	$(CC) $(CC_FLAGS) $(CC_INC) -c $< -o $@


## -------------------------------------------------------------------------------------------------
## -- Run executable
## -------------------------------------------------------------------------------------------------
run :
	@printf "%b%b%b" $(BLUE) "[  RUN] " $(RESET_COLOR)
	./$(EXEC)


## -------------------------------------------------------------------------------------------------
## -- Clean up
## -------------------------------------------------------------------------------------------------
clean :
	@printf "%b%b%b" $(RED) "[CLEAN] " $(RESET_COLOR)
	rm -rf $(DEP)

	@printf "%b%b%b" $(RED) "[CLEAN] " $(RESET_COLOR)
	rm -rf $(OBJ)

	@printf "%b%b%b" $(RED) "[CLEAN] " $(RESET_COLOR)
	rm -rf $(EXEC)

purge :
	@printf "%b%b%b" $(RED) "[CLEAN] " $(RESET_COLOR)
	rm -rf ../build/


