#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int
main()
{
	while (1) {
		int fd = open("./file", O_RDONLY);
		sleep(5);
		/* close(fd); */
	}
	/* not reachable */
	return 0;
}
