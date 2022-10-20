# Simple grep utility

## How to use:
1. Type git submodule update --init --recursive
2. Type make command to compile.
3. Type ./bin/grep <file> <filter string>, e.g.
    ```bash=
    the@the:~/grep$ make
    gcc -Ilib/libutil -Wall -fPIC   -c -o src/grep.o src/grep.c
    gcc -Ilib/libutil -Wall -fPIC   -c -o src/filter.o src/filter.c
    gcc -Ilib/libutil -Wall -fPIC src/grep.o src/filter.o -o bin/grep
    the@the:~/grep$ ./bin/grep ./test/test_file.dat \ is
    line found: this is a book.
    line found: here is an apple.
    the@the:~/grep$ cat test/test_file.dat 
    this is a book.
    12343567a
    here is an apple.
    the@the:~/grep$ ./bin/grep ./test/test_file.dat *\ a*p*e
    line found: here is an apple.
    the@the:~/grep$ ./bin/grep ./test/test_file.dat *\ a*p*
    line found: here is an apple.
    the@the:~/grep$ make clean
    rm -f src/grep.o src/filter.o bin/grep
    the@the:~/grep$ 
    ```
4. Type make clean to remove all binary.

## Unit test:
1. cd test && make
2. ./test
3. make clean