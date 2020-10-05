#include <stdio.h>
#define i 4       
#define j 1       

int main(int argc, char *argv[]) 
{
    FILE *fp; 
    char c;
    int n;

    if (argc < 2) { 
        printf("wunzip: file1 [file2 ...]\n"); 
        return 1; 
    }

    n=0;
    while (--argc > 0) { 
        if ((fp = fopen(*++argv, "r")) == NULL){
			return 1;
		}
        while (fread(&n, i, 1, fp)) {
            fread(&c, j, 1, fp);     
									
           
			while (n > 0){ 
                printf("%c", c);
				n--;
			}
        
		}
        fclose(fp);
		
    }

    return 0; 
}