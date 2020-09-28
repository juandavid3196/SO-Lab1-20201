#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])  // argc =numero de argumentos , argv=puntero del argumento
{
    if (argc == 1) // si es igual a 1 no hay argumentos
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 2) // hay un solo argumento
    {
        char buffer[1000]; //array de 1000 caracteres
        while (fgets(buffer, 1000, stdin)) /* un apuntador hacia otro archivo para obtener una lectura de carácter
			                              en caso de no especificar segundo argumento*/
        {
            if (strstr(buffer, argv[1]) != NULL) //busca en el buffer el argumento 1 osea la palabra 
            {
                printf("%s", buffer);
            }
        }
    }
    else
    {

        for (int i = 2; i < argc; i++) // hay 2 o mas argumentos osea que hay palabra y archivos
        {

            char *line = NULL;  //puntero liena
            size_t lenght = 0; // dende donde empieza
            ssize_t read;// linea

            FILE *fp = fopen(argv[i], "r"); //leer archivo i=2
            if (fp == NULL) // archivo  corrupto o mal escrito
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            while ((read = getline(&line, &lenght, fp)) != -1)// linea,desdeque caracter, archivo
            {

                if (strstr(line, argv[1]) != NULL)//argumento 1 en esta linea 
                {
                    printf("%s", line); // en esa linea se encuentra la palabra imprime
                }
            }
            fclose(fp);// cierra este archivo
        }
    }

    return 0;}