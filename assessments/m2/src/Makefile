#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

TARGET = c1m2

# Compiler Flags and Defines

ifeq ($(PLATFORM),HOST)
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = -DHOST
else
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -DMSP432 -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
endif 

CPPFLAGS = -g -O0 -std=c99 -Wall $(INCLUDES)

OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

DEP = $(SOURCES:.c=.d)

%.d : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -M -o $@

PRE = $(SOURCES:.c=.i)

%.i : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -E -o $@

ASEM = $(SOURCES:.c=.asm)

%.asm : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -S -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEP) $(PRE) $(ASEM) $(TARGET).out $(TARGET).map

