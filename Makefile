EXEC_SOURCE := main.cc
BUILD_DIR := build
EXEC_NAME := BST
INCLUDE_DIR := include

export EXEC_SOURCE
# export BUILD_DIR
export EXEC_NAME
export INCLUDE_DIR

all: build run

.PHONY: run
run: | make_build_dir
	@echo ---------------------
	./$(BUILD_DIR)/${EXEC_NAME}

.PHONY: build
build:| make_build_dir
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: make_build_dir
make_build_dir:
	mkdir -p $(BUILD_DIR)