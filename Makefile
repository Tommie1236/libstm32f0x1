# @file    Makefile
# @author  Timo Oosterom
# @brief   STM32F0x1 HAL: Makefile
# @date    feb 28 2026
# * @copyright Copyright (c) 2026 Timo Oosterom
# Licensed under the MIT License. See LICENSE file in the project root.
# * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
# are prohibited from using this code in graded assignments.

.SILENT:

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
	echo "  [AR]  $(LIB): [$(OBJS) ]"
	$(AR) rcs $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	echo "  [CC]  $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	echo "  [RM]  $(BUILD_DIR) $(LIB) compile_commands.json"
	rm -rf $(BUILD_DIR) $(LIB) compile_commands.json
