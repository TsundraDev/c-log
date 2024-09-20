## -------------------------------------------------------------------------------------------------
## -- Commands
## -------------------------------------------------------------------------------------------------
.PHONY : all build run clean purge

all :
	@$(MAKE) --no-print-directory -C src all

build :
	@$(MAKE) --no-print-directory -C src build

run :
	@$(MAKE) --no-print-directory -C src run

clean :
	@$(MAKE) --no-print-directory -C src clean

purge :
	@$(MAKE) --no-print-directory -C src purge
