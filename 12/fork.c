#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();

    if (pid == -1) {
	perror("unable to fork");
    }

    if (pid == 0) {
	// child proccess
	printf("I am child\n");
	sleep(10);
    } else {
	// parent proccess
	printf("I am parent\n");
	sleep(10);
    }

    return 0;
}
