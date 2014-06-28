/**
 * print_argv.c
 * 標準引数をprintするだけのプログラム
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
	fprintf(stderr, "%s: no arguments given\n", argv[0]);
	return 1;
    }

    for (i = 1; i < argc; i++) {
	printf("%s\n", argv[i]);
    }

    return 0;
}
