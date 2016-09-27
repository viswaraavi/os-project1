       #include <sys/types.h>
       #include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>
       #include "/lib/rdtsc.h"

       int main(int argc, char *argv[])
       {
	
	int fd1[2], fd2[2], i, k;
	char *str = argv[1];
	int nchars = strlen(argv[1]);
	int runs = atoi(argv[2]);
	unsigned long long start, end, diff, total; 

	char ch;
	if ( pipe ( fd1 ) == -1 || pipe ( fd2 ) == -1 )
		printf("pipe failed\n"); 
	int rc = fork();

	if(rc < 0) 
		printf("fork failed\n");
	else if(rc == 0) {
		for (k = 0; k < runs; k++)
		for(i = 0; i < nchars; i++) {
			read(fd1[0], &ch, 1);
			write(fd2[1], &ch, 1);		
		}	
     	     }
	else {
		start = rdtsc();
		for(k = 0; k < runs; k++)  
			for(i = 0; i < nchars; i++) {
				write(fd1[1], &str[i], 1);
				read(fd2[0], &ch, 1);
			
		            }
		end = rdtsc();
		//printf("%llu\n", (end - start));
		printf("%llu\n", (end - start) / (2 * nchars * runs));
         }
  }

