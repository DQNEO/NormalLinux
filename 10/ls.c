#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

static void do_ls(char *path);

int main(int argc, char *argv[])
{
    int i;

    if (argc <= 1) {
	fprintf(stderr, "no arguments\n");
	return 1;
    }



    for (i = 1; i < argc  ; i++) {
	do_ls(argv[i]);
    }
    return 0;
}

static void do_ls(char *path)
{

    DIR *dp;
    struct dirent *dent;

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
}
