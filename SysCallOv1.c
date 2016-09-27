#include<stdio.h>

int main() {
  unsigned long long total = 0, diff;
  int i, runs;
  scanf("%d",&runs);
  printf("%i\n", runs);
  for(i = 0; i< runs; i++) {
	scanf("%llu", &diff);
	total += diff;
}
	printf("%llu\n", total / runs);
	
}
