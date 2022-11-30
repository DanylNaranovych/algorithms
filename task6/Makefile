CC = $(CLANG_PREFIX)clang++
//LAB_OPTS = -I./src src/entity.cpp src/list.cpp
C_OPTS = -std=gnu++2b -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes --undef-value-errors=yes --track-origins=no --child-silent-after-fork=no --trace-children=no --error-exitcode=1

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin 

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main.bin
all: clean prep compile check
