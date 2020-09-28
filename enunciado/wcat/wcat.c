#include <stdio.h> 
#include <stdlib.h>
#define A 1000 

int main (int argc, char *argv[]) 

{
for (int i=1; i<argc;i++) //del segundo argumento en adelante
	{
	FILE *filep = fopen(argv[i], "r");// abrir archivo almacenar en f open
	if (filep == NULL) // si el archivo esta mal escrito o es corrupto
		{
		    printf("wcat: cannot open file\n");
		    exit(1); 
		}

	else 
		{


		char buffer[A]; // array de 1000 caracters
		fgets(buffer,A,filep);// pasar caracter a buffer 

		while (!feof(filep)) // mientras no final de archivo
			{

			printf("%s", buffer); //imprimir lo que hay en el buffer con string
			fgets(buffer,A,filep); // Seguir pasando al buffer
			}
		fclose(filep);  // cerrar archivo


		}
	}
exit(0); 
} 