PROGRAM = final.elf
MAP_FILE = final.map
OBJS = $(patsubst %.c, %.o, $(wildcard *.c)) # her .c dosyasının karşılık gelen .o dosyasını içeren bir liste oluşturur

CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 # -Wall = turn on warnings
LDFLAG = -nostdlib -T stm32_ls.ld -Wl,-Map=$(MAP_FILE) # (-Wl,-Map=final.map) final.map dosyasını hafızayı incelememiz için oluşturur.


.PHONY: all clean flash
all: $(PROGRAM)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^ # $^ = main.c   $@ = main.o

$(PROGRAM): $(OBJS)
	$(CC) $(LDFLAG) -o $@ $^

	
clean:
	rm -rf *.o *.elf *.map 

flash: all
	openocd -f board/st_nucleo_f4.cfg -c "program $(PROGRAM) verify reset exit"

