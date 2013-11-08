all: examples

clamelib: stack.o
	ar -rcs lib/clamelib.a src/clamelib/stack.o
	ranlib lib/clamelib.a

stack.o:
	clang -g -O2 -Wall -Wextra -Isrc -c -o src/clamelib/stack.o src/clamelib/stack.c

examples: stack_example

stack_example: clamelib
	clang -g -O2 -Wall -Wextra -Isrc lib/clamelib.a examples/stack_example.c -o examples/stack.example

clean:
	rm -f lib/* examples/*.example src/clamelib/*.o 
	rm -rf examples/*.dSYM