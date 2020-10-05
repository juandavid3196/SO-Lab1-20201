#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
	int carAct;        
    int carAnt;         
	carAnt = EOF;       
    unsigned int c; 
    FILE *fp;          
	
	

	c = 0;
	
	if (argc == 1){ 
        printf("wzip: file1 [file2 ...]\n"); 
        exit(1); 
	}
    
	for (int i = 1; i < argc; i++){ 
		fp = fopen(argv[i], "r"); 
       
        if (fp == NULL){             
            printf("wzip: cannot open file\n"); 
            exit(1); 
        }

        while ((carAct = fgetc(fp)) != EOF){ 
											 
            if (carAnt != carAct && carAnt == EOF){
                carAnt = carAct; 
                c = 1;
            }
            else if (carAnt == carAct){ 
                c++;
            }
            else if (carAnt != carAct){ 

                fwrite(&c, 4, 1, stdout);
                fwrite(&carAnt, 1, 1, stdout); 
                carAnt = carAct; 
                c = 1;
            }
        }

        fclose(fp);
    }

    fwrite(&c, 1, 4, stdout);
    fwrite(&carAnt, 1, 1, stdout);
    return 0;
}