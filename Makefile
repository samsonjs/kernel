# Builds both tutorial trees. Each one links its own `kernel` binary in place.
SUBDIRS=kernel/src user_mode/src

all clean:
	for d in $(SUBDIRS); do $(MAKE) -C $$d $@ || exit 1; done

.PHONY: all clean
