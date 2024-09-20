## -------------------------------------------------------------------------------------------------
## -- Colors
## -------------------------------------------------------------------------------------------------
YELLOW = "\e[1;33m"
RESET_COLOR = "\e[0m"

## -------------------------------------------------------------------------------------------------
## -- Commands
## -------------------------------------------------------------------------------------------------
.PHONY : all build run clean purge

all :
	@printf $(YELLOW)
	@printf "[ MAKE] make all\n"
	@printf $(RESET_COLOR)
	@$(MAKE) --no-print-directory -C src all

build :
	@$(MAKE) --no-print-directory -C src build

run :
	@$(MAKE) --no-print-directory -C src run

clean :
	@$(MAKE) --no-print-directory -C src clean

purge :
	@$(MAKE) --no-print-directory -C src purge
