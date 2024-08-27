#include<stdio.h>
#include<string.h>
int main(){
	char cadena[30];
	printf("Ingresa tu nombre completo");
	fgets(cadena,sizeof(cadena),stdin);

	printf("\n El nombre es: %s", cadena);

	char frase[30] = "Hola papu\n como estas papu :v";

	printf("La frase original es: %s",  frase);

	size_t posicion = strcspn(frase, "\n");

	frase[posicion] = '\0';
	printf("La frase modificada es: %s",  frase);

	size_t tam = strlen(frase);
	printf("\n El tamaño de la frase es: %zu", tam);
	return 0;
}
