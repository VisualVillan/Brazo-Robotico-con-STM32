CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m3 -mthumb --specs=nosys.specs
LDSCRIPT = stm32f103c8tx_flash.ld

SRC_FILES = startup_stm32f103c8tx.s f.c ./potbrazo/potbrazo.c ./servobrazo/servobrazo.c ./uartbrazo/uartbrazo.c

OUTPUT = f.elf
OUTPUT_BIN = f.bin

all: $(OUTPUT) $(OUTPUT_BIN)

$(OUTPUT): $(SRC_FILES) $(LDSCRIPT)
	$(CC) $(CFLAGS) -T $(LDSCRIPT) $(SRC_FILES) -o $@

$(OUTPUT_BIN): $(OUTPUT)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(OUTPUT) $(OUTPUT_BIN)

.PHONY: all clean