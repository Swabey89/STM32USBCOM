CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib -ggdb
CPPFLAGS=-DSTM32F429x \
	-I../inc/vendor/CMSIS/Device/Include \
	-I../inc/vendor/CMSIS/Include \

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

all: ../bin/STM32USBCOM.elf

../bin/STM32USBCOM.elf: main.o startup.o system_stm32f4xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o ../bin/STM32USBCOM.elf

main.o: ../src/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) ../src/main.c -c

startup.o: ../src/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) ../src/startup.c -c

system_stm32f4xx.o: ../inc/vendor/CMSIS/Device/Source/system_stm32f4xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) ../inc/vendor/CMSIS/Device/Source/system_stm32f4xx.c -c

.PHONY: clean
clean:
	rm *.o -f
	rm ../bin/*.elf -f

PROGRAMMER=openocd
PROGRAMMER_FLAGS=-f interface/stlink.cfg -f target/stm32f4x.cfg

flash: ../bin/STM32USBCOM.elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program ../bin/STM32USBCOM.elf verify reset exit"