.PHONY: all program
CPP = g++
CPP_FLAGS = -std=c++17 -g
WARNINGS = -Wall -Wextra -Wmissing-include-dirs -Wfloat-equal -Wredundant-decls -Winit-self -Wshadow -Wconversion
STANDARDS = -pedantic -pedantic-errors
TESTER_NAME = program.exe

TEST_FILES = main.cpp
INCLUDE_DIRS = .
SHARED_FILES = helpers.cpp

all: program

program:
	$(CPP) $(CPP_FLAGS) $(STANDARDS) $(WARNINGS) -I $(INCLUDE_DIRS) -o $(TESTER_NAME) $(SHARED_FILES) $(TEST_FILES)