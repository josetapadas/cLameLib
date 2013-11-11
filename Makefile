all: examples

clamelib: stack.o object.o array.o
	ar -rcs lib/clamelib.a src/clamelib/stack.o src/clamelib/object.o src/clamelib/array.o
	ranlib lib/clamelib.a

stack.o:
	clang -g -O2 -Wall -Wextra -Isrc -c -o src/clamelib/stack.o src/clamelib/stack.c

object.o:
	clang -g -O2 -Wall -Wextra -Isrc -c -o src/clamelib/object.o src/clamelib/object.c

array.o:
	clang -g -O2 -Wall -Wextra -Isrc -c -o src/clamelib/array.o src/clamelib/array.c

examples: stack_example object_example array_example

stack_example: clamelib
	clang -g -O2 -Wall -Wextra -Isrc lib/clamelib.a examples/stack_example.c -o examples/stack.example

object_example: clamelib
	clang -g -O2 -Wall -Wextra -Isrc lib/clamelib.a examples/object_example.c -o examples/object.example

array_example: clamelib
	clang -g -O2 -Wall -Wextra -Isrc lib/clamelib.a examples/array_example.c -o examples/array.example

clean:
	rm -f lib/* examples/*.example src/clamelib/*.o 
	rm -rf examples/*.dSYM
