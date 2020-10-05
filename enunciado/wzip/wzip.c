#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    int cont = 1;
    char curCharFile;
    for (int i = 1; i < argc; i++)
    {
        FILE *curFile = fopen(argv[i], "r");
        if (curFile == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        char curCharIterator = fgetc(curFile);
        while ((curFile = fgetc(curFile)) != EOF)
        {
            if (curCharFile == curCharIterator)
            {
                cont++;
            }
            else
            {
                
                fwrite(&cont, sizeof(int), 1, stdout);
                fwrite(&curCharIterator, sizeof(char), 1, stdout);
                curCharIterator = curCharFile;
                cont = 1;
            }
        }
        fclose(curFile);
        fwrite(&cont, sizeof(int), 1, stdout);
        fwrite(&curCharIterator, sizeof(char), 1, stdout);
        
    }
    return 0;
}