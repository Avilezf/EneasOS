#
# Makefile
#

CIRCLEHOME = ../..

OBJS	= main.o kernel.o webserver.o

LIBS	= $(CIRCLEHOME)/lib/usb/libusb.a \
	  $(CIRCLEHOME)/lib/input/libinput.a \
	  $(CIRCLEHOME)/lib/fs/libfs.a \
	  $(CIRCLEHOME)/lib/net/libnet.a \
	  $(CIRCLEHOME)/lib/sched/libsched.a \
	  $(CIRCLEHOME)/lib/libcircle.a

CONTENT	= index.h style.h ledoff.h ledon.h amstrong.h eneasintro.h eneasoslogo.h globallogo.h joshua.h medalla.h mono.h pipe.h premio.h seguridadlogo.h servidorportable.h technical.h trofeo.h urbanline.h

EXTRACLEAN = $(CONTENT)

include ../Rules.mk

%.h: %.html
	@echo "  GEN   $@"
	@$(CIRCLEHOME)/tools/converttool $< > $@

%.h: %.css
	@echo "  GEN   $@"
	@$(CIRCLEHOME)/tools/converttool $< > $@

%.h: %.png
	@echo "  GEN   $@"
	@$(CIRCLEHOME)/tools/converttool -b $< > $@

%.h: %.jpg
	@echo "  GEN   $@"
	@$(CIRCLEHOME)/tools/converttool -b $< > $@

%.h: %.jpeg
	@echo "  GEN   $@"
	@$(CIRCLEHOME)/tools/converttool -b $< > $@

webserver.o: $(CONTENT)

-include $(DEPS)
