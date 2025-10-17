# SOURCE
# https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html 
SUBDIR := common dimensions

.PHONY: clean all $(SUBDIR)

all: $(SUBDIR)

$(SUBDIR): 
	$(MAKE) -C $@ --no-print-directory

# Tutorial for the below structure
# https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
clean:
	for to_clean in $(SUBDIR) ; do \
		$(MAKE) -C $$to_clean --no-print-directory clean ; \
	done


dimensions: common

