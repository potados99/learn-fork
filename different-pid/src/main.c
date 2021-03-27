#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[]) {
    int pid;

	pid = fork();
	if (pid == -1) {
		// possible errors: EAGAIN, ENOMEM.
	    perror("Failed to fork");
	    return -1;
	}

	if (pid == 0) {
		// child
		printf("Child pid: %d\n", getpid());
	} else {
		// parent
		printf("Parent pid: %d\n", getpid());
	}

	return 0;
}
