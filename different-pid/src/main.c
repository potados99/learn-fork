#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[]) {
    int pid;

	puts("Press Ctrl-C to stop");

	pid = fork();
	if (pid == -1) {
		// possible errors: EAGAIN, ENOMEM.
	    perror("Failed to fork");
	    return -1;
	}

	if (pid == 0) {
		// child
		printf("Child pid: %d\n", getpid());
		while (1);
	} else {
		// parent
		printf("Parent pid: %d\n", getpid());
		while (1);
	}

	return 0;
}
