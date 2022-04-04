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
# <Harsha.Y>
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

TARGET = course1.out

CFLAGS = $(INCLUDES) -Wall -g -O0 -std=c99 -DCOURSE1 -DVERBOSE -D$(PLATFORM)
CPPFLAGS = $(INCLUDES) -DCOURSE1 -DVERBOSE -D$(PLATFORM)

MAP_FILE = $(TARGET:.out=.map)
TARGET_ASM_FILE = $(TARGET:.out=.asm)

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)



ifeq ($(PLATFORM),MSP432)

#Architectures Specific Flag
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines
LDFLAGS = -T $(LINKER_FILE) -Map=$(MAP_FILE)

CFLAGS += -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
OBJDUMP = arm-none-eabi-objdump

else  

# Compiler Flags and Defines 
LDFLAGS = -Wl,-Map=$(MAP_FILE)
CC = gcc
LD = gcc # Use gcc vs ld to link with crt, etc.
SIZE = size
OBJDUMP = objdump
endif
%.d: %.c
	$(CC) $(CPPFLAGS) -MM -MF $@ $^

%.i: %.c
	$(CC) $(CPPFLAGS) -E $^ > $@

%.asm: %.c
	$(CC) $(CPPFLAGS) -S -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^


.PHONY: all
all: build

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(DEPS) $(TARGET)

.PHONY: clean
clean:
	rm -f *.map *.out *.asm *.i *.o *.d


$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^
	$(OBJDUMP) --disassemble $@ > $(TARGET_ASM_FILE)
	$(SIZE) $(TARGET)
	

