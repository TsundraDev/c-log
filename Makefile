## -------------------------------------------------------------------------------------------------
## -- Colors
## -------------------------------------------------------------------------------------------------
RED         = "\e[1;31m"
GREEN       = "\e[1;32m"
YELLOW      = "\e[1;33m"
BLUE        = "\e[1;34m"
RESET_COLOR = "\e[0m"


## -------------------------------------------------------------------------------------------------
## -- Commands
## -------------------------------------------------------------------------------------------------
.PHONY : all dirs build run clean purge

all : dirs build

dirs :
	@# Build project directory
	@printf "%b[ MAKE] Build directory\n%b" $(YELLOW) $(RESET_COLOR)
	@printf "%b[  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p build/

	@printf "%b[  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p build/dep/

	@printf "%b[  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p build/mod/

	@printf "%b[  DIR] %b" $(YELLOW) $(RESET_COLOR)
	mkdir -p build/obj/

	@printf "\n"

build :
	@# Build executable
	@printf "%b[ MAKE] Build executable\n%b" $(YELLOW) $(RESET_COLOR)
	@$(MAKE) --no-print-directory -C src build

run :
	@$(MAKE) --no-print-directory -C src run

clean :
	@$(MAKE) --no-print-directory -C src clean

purge :
	@printf "%b[CLEAN] %b" $(RED) $(RESET_COLOR)
	rm -rf build/
