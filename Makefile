CC      = arm-none-eabi-gcc
CFLAGS  = -mcpu=cortex-m4 -mthumb -O2 -ffast-math -fno-exceptions -Wall
INCS    = -Isrc

SRCS = \
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

OBJS = $(SRCS:.c=.o)
TARGET = arcv_delta_rl_plus3.bin
LD_SCRIPT = STM32F4xx.ld

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -T$(LD_SCRIPT) -Wl,--gc-sections -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
