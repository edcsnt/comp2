/* Copyright (C) 2025 Eduardo Santos <eduardo.experimental@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

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

	if (fork()) {
		while (1) {
			sigwait(&set, &sig);
			if (sig == SIGHUP || sig == SIGINT || sig == SIGTERM)
				return 1;
		}
	}

	sigprocmask(SIG_UNBLOCK, &set, NULL);

	while (1) {
		fprintf(stderr,
		        "wasting one file descriptor every 5s... :(\n");
+		open("./file", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
		sleep(5);
	}
}
