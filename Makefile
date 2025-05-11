CC        := arm-none-eabi-gcc
OBJCOPY   := arm-none-eabi-objcopy
CFLAGS    := -mcpu=cortex-m4 -mthumb -O2 -ffast-math -fno-exceptions -Wall
INCS      := -Isrc

SRCS := \
	src/hal.c \
	src/fixed_point.c \
	src/vec2.c \
	src/vec4.c \
	src/ia_fht.c \
	src/macro_actions.c \
	src/rl_policy.c \
	src/vcqbf.c \
	src/pj_fhpc.c \
	src/main.c

OBJS      := $(SRCS:.c=.o)
LD_SCRIPT := STM32F4xx.ld

TARGET_ELF := arcv_delta_rl_plus3.elf
TARGET_BIN := arcv_delta_rl_plus3.bin

all: $(TARGET_BIN)

$(TARGET_ELF): $(OBJS) $(LD_SCRIPT)
	$(CC) $(CFLAGS) -T$(LD_SCRIPT) -Wl,--gc-sections -o $@ $(OBJS)

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $< $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LD_SCRIPT):
	@echo "Auto-generating minimal STM32F4xx.ld linker script"
	@cat > $(LD_SCRIPT) << 'EOF'
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
  RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
  .text :
  {
    KEEP(*(.isr_vector))
    *(.text*)
    *(.rodata*)
    _etext = .;
  } > FLASH

  .data : AT(_etext)
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  _estack = ORIGIN(RAM) + LENGTH(RAM);
  PROVIDE(__StackTop = _estack);
}
EOF

clean:
	rm -f $(OBJS) $(TARGET_ELF) $(TARGET_BIN) $(LD_SCRIPT)
