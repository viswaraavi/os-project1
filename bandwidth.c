#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "lib/rdtsc.h"


#define SAMPLES 10
#define SIZE (1*1024*1024*1024LL)

size_t array[SIZE];

unsigned long long write_memory(long long size) {
  unsigned long long start;
  unsigned long long end;
  unsigned int check=0;
  start=rdtsc();
  for (int i = 0; i < size / sizeof(size_t); i++) {
  array[i]=1;
  check++;
  }
  end=rdtsc();
  assert(!(check==0));
  unsigned long long diff;
  diff=end-start;
  return diff;
}

unsigned long long read_memory(long long size) {
  unsigned long long start;
  unsigned long long end;
  unsigned int dum=0;
  start=rdtsc();
  for (int i = 0; i < size / sizeof(size_t); i++) {

   dum+=array[i];
  
  }
  end=rdtsc();
  assert(!(dum==0));
  unsigned long long diff;
  diff=end-start;
  return diff;
}

int main()
{
memset(array,0xFF,SIZE);
unsigned long long read_avg=0;
for(int i=0;i<=SAMPLES;i++){
unsigned long long readbw=read_memory(SIZE);
read_avg=read_avg+readbw;
}
unsigned long long readbw=read_avg/100;
unsigned long long write_avg=0;
for(int i=0;i<=SAMPLES;i++){
unsigned long long writebw=write_memory(SIZE);
write_avg=write_avg+writebw;
}
unsigned long long writebw=write_avg/100;

printf("latency for ready time %llu\n latency for write time %llu\n memory bandwidth while reading %f\n memory bandwidth while writing %f \n",readbw,writebw,1024/((double)readbw/1.75e9),1024/((double)writebw/1.75e9));
}




