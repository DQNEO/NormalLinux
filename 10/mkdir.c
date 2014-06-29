#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    if (argc <= 1) {
	fprintf(stderr, "no argments\n");
	return 1;
    }

    char *path;
    path = argv[1];

    if (mkdir(path, 0777) < 0) {
	perror(path);
	return 1;
    }

    return 0;
}

