#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "utils.h"
#include "/lib/rdtscp.h"

int fd1[2], fd2[2], runs, nchars;

void * start_thread(void *arg) {
		int i, k;
		char ch;	
		for (k = 0; k < runs; k++)
		for(i = 0; i < nchars; i++) {
			read(fd1[0], &ch, 1);
			write(fd2[1], &ch, 1);		
		}	
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	int i, k;
	unsigned long long start, end;
	char ch, *str;

	if ( pipe ( fd1 ) == -1 || pipe ( fd2 ) == -1 ) {
		printf("pipe failed\n"); 
		exit(1);
	}

	str = argv[1];
	nchars = strlen(argv[1]);
	runs = atoi(argv[2]);

	pthread_t *t;
	int s = pthread_create(t, NULL, start_thread, (void *)&i);
	start = rdtsc();
	for(k = 0; k < runs; k++)  
	 for(i = 0; i < nchars; i++) {
		write(fd1[1], &str[i], 1);
		read(fd2[0], &ch, 1);			
            }

	end = rdtsc();
	printf("%llu\n", (end - start) / (2 * nchars * runs));
	pthread_exit(NULL);
}
