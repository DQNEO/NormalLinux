#include <stdio.h>
#include <unistd.h>
int main()
{
    int i;
    int pid;
    for (i=0;i<10;i++) {
	pid = fork();
	if (pid == -1) {
	    perror("unable to fork\n");
	    return 1;
	}

	if (pid == 0) {
	    printf("I am child\n");
	    sleep(10);
	    return 0;
	}
    }

    return 0;
}
