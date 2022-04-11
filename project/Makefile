# makfile configuration

COMMON_OBJECTS  = song.o led.o stateMachines.o p2_interrupt_handler.o switches.o buzzer.o wdInterruptHandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ./h
LDFLAGS		= -L/opt/ti/msp430_gcc/include
DEPS		= song.h led.h stateMachines.h buzzer.h switches.h

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 



#additional rules for files
toy.elf: ${COMMON_OBJECTS} toyMain.o ./lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

