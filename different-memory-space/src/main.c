#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int global_count = 0;

int main(int argc, const char * argv[]) {
	int local_count = 0;
    int pid = fork();

	if (pid == -1) {
		// possible errors: EAGAIN, ENOMEM.
	    perror("Failed to fork");
	    return -1;
	}

	if (pid == 0) {
		// child
		global_count++;
		local_count++;

		printf("[Child] global count: %d(%p)\n", global_count, &global_count);
		printf("[Child] local count: %d(%p)\n", local_count, &local_count);
	} else {
		// parent
		sleep(1);

		printf("[Parent] global count: %d(%p)\n", global_count, &global_count);
		printf("[Parent] local count: %d(%p)\n", local_count, &local_count);
	}

	return 0;
}
