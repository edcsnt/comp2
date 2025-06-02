#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RST "\e[0m"

volatile sig_atomic_t done = 0;

void term(int signum)
{
	done = 1;
}

int
main(int argc, char *argv[])
{
	struct sigaction act;
	memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = term;
	sigaction(SIGTERM, &act, NULL);

	if (argc > 1) {
		fprintf(stderr,
		        "\e[1;91merr: comp1 takes no arguments"RST"\n");
		return 1;
	}
	while (1) {
		fprintf(stderr,
		        "\e[1;95mwasting one file descriptor every 5s... :("RST
		        "\n");
		open("./foo", O_RDONLY);
		/* int fd = open("./foo", O_RDONLY); */
		sleep(5);
		/* close(fd); */
	}
	/* not reachable */
	return 0;
}
