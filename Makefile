## -------------------------------------------------------------------------------------------------
## -- Colors
## -------------------------------------------------------------------------------------------------
RED         = "\e[1;31m"
GREEN       = "\e[1;32m"
YELLOW      = "\e[1;33m"
BLUE        = "\e[1;34m"
RESET_COLOR = "\e[0m"


## -------------------------------------------------------------------------------------------------
## -- Project directories
## -------------------------------------------------------------------------------------------------
DIR  = ./build/
DIR += ./build/dep/
DIR += ./build/obj/


## -------------------------------------------------------------------------------------------------
## -- Commands + default
## -------------------------------------------------------------------------------------------------
.PHONY : all build run clean purge

all : $(DIR) build


## -------------------------------------------------------------------------------------------------
## -- Build project directories
## -------------------------------------------------------------------------------------------------
./% :
	@printf "%b[  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p $@


## -------------------------------------------------------------------------------------------------
## -- Build, run and clean project
## -------------------------------------------------------------------------------------------------
build : $(DIR)
	@$(MAKE) --no-print-directory -C src build

run :
	@$(MAKE) --no-print-directory -C src run

clean :
	@$(MAKE) --no-print-directory -C src clean

purge :
	@printf "%b[CLEAN] %b" $(RED) $(RESET_COLOR)
	rm -rf build/
