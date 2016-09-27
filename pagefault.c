#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <assert.h>
#include "lib/rdtsc.h"



int main(int argc, char* argv[]) {
	unsigned long long start, end, diff;
	struct stat mystat;
	int fd = open("/home/viswa/Desktop/os/tmp/input.txt", O_RDWR);
	if(fd<0){
	printf("error");
	exit(1);
        }
	fstat(fd,&mystat);
	unsigned int offset=20971520;
	size_t size = mystat.st_size;
	char* map =(char*) mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char c;
	start = rdtsc();
	
	for(int i=0;i<100;i++)
	{
	     c=map[(((i+1)*offset) % (size-1))];
	}
	
	end = rdtsc();
	diff = end - start;
	printf("%lf\n", (double)((diff/100)/1.75e9));

	int rc = munmap(map, size);
	assert(rc == 0);

	close(fd);
}
