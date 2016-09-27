#include <stdio.h>
#include "utils.h"
#include "/lib/rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = atoi(argv[1]);
	unsigned long long start, end, diff;
	int i;
	start = rdtsc();
	for (i = 0; i < runs; i++);
	end = rdtsc();
	diff = end - start;
	printf("AVG: %llu\n", diff/runs);
}
