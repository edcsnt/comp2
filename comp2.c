#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	sigset_t set;
	int sig;

	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);

	if (!fork()) {
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		while (1) {
			fprintf(stderr,
			        "wasting one file descriptor every 5s... "
			        ":(\n");
			/* fprintf(stderr, "no more resource leaks! :)\n"); */
			open("./file", O_RDONLY);
			/* int fd = open("./file", O_RDONLY); */
			/* close(fd); */
			sleep(5);
		}
	}

	while (1) {
		sigwait(&set, &sig);
		if (sig == SIGHUP || sig == SIGINT || sig == SIGTERM)
			return 1;
	}
	/* not reachable */
	return 0;
}
