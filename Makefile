clamelib: list.o
	ar -rcs lib/clamelib.a src/clamelib/list.o
	ranlib lib/clamelib.a

list.o:
	clang -g -O2 -Wall -Wextra -Isrc -c -o src/clamelib/list.o src/clamelib/list.c

list_example: clamelib
	clang -g -O2 -Wall -Wextra -Isrc lib/clamelib.a examples/list_example.c -o examples/list.example

clean:
	rm -f lib/* examples/*.example src/clamelib/*.o 
	rm -rf examples/*.dSYM