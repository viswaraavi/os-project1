#include <stdio.h>
#include "utils.h"
#include "/lib/rdtscp.h"

int main(int argc, char* argv[]) {
	unsigned long long start, end, diff, clock_total = 0;

       int runs = atoi(argv[1]);

	int i;
	for (i = 0; i < runs; i++) {
		start = rdtsc();
		end = rdtsc();
		diff = end - start;
		printf("%llu\n", diff);
		clock_total = clock_total + diff;

	}

	printf("AVG: %llu\n", clock_total/runs);
}
