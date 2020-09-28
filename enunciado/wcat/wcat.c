#include <stdio.h> 
#include <stdlib.h>
#define BUFFER_SIZE 1000 
 
int main (int argc, char *argv[]) 

{
for (int i=1; i<argc;i++) 
	{
	FILE *filep = fopen(argv[i], "r");
	if (filep == NULL)
		{
		    printf("wcat: cannot open file\n");
		    exit(1); 
		}

	else 
		{


		char buffer[BUFFER_SIZE]; 
		fgets(buffer,BUFFER_SIZE,filep);
			
		while (!feof(filep)) 
			{
			
			printf("%s", buffer);
			fgets(buffer,BUFFER_SIZE,filep);
			}
		fclose(filep); 
		

		}
	}
exit(0); 
}