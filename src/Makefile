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
	@$(MAKE) --no-print-directory depend
	@$(MAKE) --no-print-directory build


## -------------------------------------------------------------------------------------------------
## -- Project setup
## -------------------------------------------------------------------------------------------------
dirs :
	@printf $(YELLOW)
	@printf "[  DIR] Creating project directory\n"
	@printf $(RESET_COLOR)
	mkdir -p ../build/
	mkdir -p ../build/dep/
	mkdir -p ../build/obj/


## -------------------------------------------------------------------------------------------------
## -- Build dependencies
## -------------------------------------------------------------------------------------------------
depend :
	@printf $(YELLOW)
	@printf "[  DEP] Building dependencies\n"
	@printf $(RESET_COLOR)
	@$(MAKE) --no-print-directory $(DEP)

../build/dep/%.d : %.cpp
	if [ -d "../build/" ]; then $(CC) -MM -MT ../build/obj/$(patsubst %.cpp,%.o,$<) $^ -o $@; fi

ifneq (clean,$(filter clean,$(MAKECMDGOALS)))
ifneq (purge,$(filter purge,$(MAKECMDGOALS)))
-include $(DEP)
endif
endif


## -------------------------------------------------------------------------------------------------
## -- Link object files into executable
## -------------------------------------------------------------------------------------------------
build :
	@# Compile source files
	@printf $(YELLOW)
	@printf "[COMPL] Compiling source files\n"
	@printf $(RESET_COLOR)
	@$(MAKE) --no-print-directory $(OBJ)
	
	@# Link object files
	@printf $(YELLOW)
	@printf "[ LINK] Linking object files\n"
	@printf $(RESET_COLOR)
	$(LD) $(LD_FLAGS) $(OBJ) -o $(EXEC)

	@printf $(GREEN)
	@printf "[BUILD] Executable built\n"
	@printf $(RESET_COLOR)


## -------------------------------------------------------------------------------------------------
## -- Compile source files into object files
## -------------------------------------------------------------------------------------------------
../build/obj/%.o : %.cpp
	$(CC) $(CC_FLAGS) -c $< -o $@


## -------------------------------------------------------------------------------------------------
## -- Run executable
## -------------------------------------------------------------------------------------------------
run :
	@printf $(BLUE)
	@printf "[  RUN] Run executable\n"
	@printf $(RESET_COLOR)
	@./$(EXEC)


## -------------------------------------------------------------------------------------------------
## -- Clean up
## -------------------------------------------------------------------------------------------------
clean :
	@printf $(RED)
	@printf "[CLEAN] Removing dependencies, object files and executable\n"
	@printf $(RESET_COLOR)
	rm -rf $(DEP)
	rm -rf $(OBJ)
	rm -rf $(EXEC)

purge :
	@printf $(RED)
	@printf "[CLEAN] Removing build directory\n"
	@printf $(RESET_COLOR)
	rm -rf ../build/


