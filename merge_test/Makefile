CC := gcc

MKFILEDIR := $(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))

SOURCEEXT :=.c
SOURCEDIR := $(MKFILEDIR)
BUILDDIR := $(MKFILEDIR)/build
INCLUDEDIR := $(MKFILEDIR)
BINARYDIR := $(MKFILEDIR)
BINARYNAME := rtiow

LDFLAGS :=
CFLAGS := -std=c99 -Wall -O3 -g
RUNFLAGS :=

HEADERS := $(wildcard $(INCLUDEDIR)/*.h)
SOURCES := $(wildcard $(SOURCEDIR)/*$(SOURCEEXT))
OBJECTS := $(addprefix $(BUILDDIR)/,$(patsubst %$(SOURCEEXT), %.o, $(SOURCES:$(SOURCEDIR)/%=%)))

$(BINARYDIR)/$(BINARYNAME): $(BUILDDIR) $(OBJECTS) Makefile
	echo $(SOURCES)
	echo $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARYNAME) $(CFLAGS) $(LDFLAGS) 

$(BUILDDIR)/%.o: $(SOURCEDIR)/%$(SOURCEEXT) $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS) -I$(INCLUDEDIR) 

$(BUILDDIR):
	@mkdir $(BUILDDIR) || true

clean:
	@rm $(wildcard $(BUILDDIR)/*) || true
	@rm $(BINARYDIR)/$(BINARYNAME) || true

run:
	$(BINARYDIR)/$(BINARYNAME) $(RUNFLAGS)

debug:
	/usr/bin/gdb --tty=/dev/pty1 $(BINARYDIR)/$(BINARYNAME)

link: $(BINARYDIR)/$(BINARYNAME)

image: $(BINARYNAME)
	./$(BINARYNAME) > image.ppm


.PHONY: run clean debug link
