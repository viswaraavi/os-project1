#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "/lib/rdtsc.h"

int main(int argc, char* argv[]) {
	int runs = atoi(argv[1]);

	unsigned long long start, end, diff, total = 0;

	int i, rc;
	for (i = 0; i < runs; i++) {
		start = rdtsc();
		rc = fork();
		end = rdtsc();
		diff = end - start;
	
		if(rc > 0 ) 
			total += diff;
		else
		 return 0;
		
	}

	printf("%llu\n", total / runs);
}
