TARGET = test
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
OUTPUT_DIR = bin

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, $(addsuffix /%.o, $(OUTPUT_DIR)), $(wildcard *.c))
HEADERS = $(wildcard *.h)

$(addsuffix /%.o, $(OUTPUT_DIR)): %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): build_dir $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $(addsuffix /$@, $(OUTPUT_DIR))

build_dir:
	mkdir -p $(OUTPUT_DIR)

clean:
	rm -rf $(OUTPUT_DIR)