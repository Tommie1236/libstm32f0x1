
CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

CFLAGS = \
	-mcpu=cortex-m0 -mthumb \
	-O0 -ffreestanding -g \
	-Iinclude \
	-Wall -Wextra \

LIB = libstm32f0x1.a
SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(LIB) compile_commands.json
