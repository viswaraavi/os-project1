#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sched.h>
#include "lib/rdtsc.h"


char** ram_acess_time (size_t arraySize, size_t strideSize) {
    unsigned long long start;
    unsigned long long end;
    unsigned long long diff;
  
    char ** plist = malloc(sizeof(char *)*arraySize);
    for ( int i =0; i < arraySize ; i++) {
        int  index =  (i/strideSize * strideSize + strideSize)%arraySize;
        plist [i] = (char * ) &plist[index];  
    }

    char ** p = plist;

    int count = arraySize/ (strideSize ) + 1;
   
    start = rdtsc();
    for ( int i = 0 ; i < 100; i ++ ) {
         for ( int j = 0; j < count ; j ++) {

             p = (char**) *p;
             }
      
     }
     end = rdtsc();
     diff = (end - start);
     double time = (double)diff / (100 *count);
     printf("count is %d and time taken is %lf\n",count,time);
     
     free(plist);
     return p; //this is done to prevent compiler not to optimise the code

}



int main(int argc, char* argv[]) {
	//Set cpu affinity
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	if (sched_setaffinity(0, sizeof(cpu_set_t), &set) == -1) {
		printf("Affinity Failed!\n");
		exit(1);
	}
	int array_sizes[15];
	int stride_sizes[5];
	array_sizes[0]=1024/8;
	stride_sizes[0]=2;
	
    	for (int i = 1 ; i < 5; i ++) {
        stride_sizes[i] = stride_sizes[i-1] * 4;
	}
    for (int i = 1 ; i < 15 ; i++) {
        array_sizes[i] = array_sizes[i-1]<<1;
    }

	for (int j = 0; j < 5; j ++) {
          for ( int i = 0 ; i < 15; i ++) {
		ram_acess_time(array_sizes[i],stride_sizes[j]);
}
}

	
}
