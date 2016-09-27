#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"
#include "/lib/rdtsc.h"

int main(int argc, char* argv[]) {
	int fd[2], nchars = strlen(argv[1]);
	char ch;
	char *str = argv[1];
	int runs = atoi(argv[2]);
	unsigned long long start, end, diff;
	int i, j;

	if(pipe(fd)==-1) {
		printf("pipe  failed\n");
		exit(1);
	}

	start = rdtsc();
	for (i = 0; i < runs; i++) {
		for (j = 0; j < nchars; j++) {
		write(fd[1], &str[1], 1);
		read(fd[0], &ch, 1);
	  }
	}
	end = rdtsc();
	diff = end - start;
	printf("%llu\n", diff / (runs * nchars));
	close(fd[0]);
	close(fd[1]);
}
