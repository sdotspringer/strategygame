CXX           := clang++
CXXFLAGS      := -Wall -Wextra -pedantic -gdwarf-4 -std=c++20 -g -fstandalone-debug
EXECNAME      := strategygame
SOURCES       := $(shell find . -name "*.cpp")


bin:
	@echo "[\033[36mINFO\033[0m] Compiling"
	@${CXX} ${CXXFLAGS} ${SOURCES} -o ${EXECNAME}

 