# SOURCE
# https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html 

SUBDIR := 1 2

.PHONY: all $(SUBDIR)

all: $(SUBDIR)

$(SUBDIR):
	$(MAKE) -C $@

clean:
	for to_clean in $(SUBDIR) ; do \
		$(MAKE) -C $$to_clean --no-print-directory clean; \
	done
