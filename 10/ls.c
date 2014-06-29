#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    if (argc <= 1) {
	fprintf(stderr, "no arguments\n");
	return 1;
    }

    DIR *dp;
    struct dirent *dent;
    char *path;

    path = argv[1];
    dp = opendir(path);
    if (dp == NULL) {
	perror(path);
	exit(1);
    }

    while ((dent = readdir(dp)) != NULL) {
	printf("%s  ", dent->d_name);
    }

    printf("\n");
    closedir(dp);

    return 0;
}

