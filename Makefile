# SOURCE
# https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html 
SUBDIR := common dimensions

.PHONY: all $(SUBDIR)

all: $(SUBDIR)

$(SUBDIR): 
	$(MAKE) -C $@ --no-print-directory

dimensions: common

