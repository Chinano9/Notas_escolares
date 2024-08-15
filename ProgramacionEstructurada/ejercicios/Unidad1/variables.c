
// Fernando Ponce Solís 222953
// Villedo Martinez Sandoval 222534

#include<stdio.h>


int main(){
	int x = 0, y, z = 25;
	float a = 2.35;
	float const gravedad = 9.81;

	int *ptr;

	ptr = &x;

	printf(" El valor de la variable x es %d\n", x);
	printf(" La direccion de x es: %p\n", &x);
	printf(" La direccion del puntero ptr es: %p\n",&ptr);
	printf(" La direccion a la que apunta ptr es: %p\n", ptr);

	*ptr = 85;

	printf(" El valor de x despues de cambiar su puntero es: %d\n", x);
	
	ptr = &y;

	printf(" El valor de la variable y es %d\n", y);
	printf(" La direccion de y es: %p\n", &y);
	printf(" La direccion del puntero ptr es: %p\n",&ptr);
	printf(" La direccion a la que apunta ptr es: %p\n", ptr);

	*ptr = x + z;

	printf(" El valor de la variable y es %d\n", y);
	printf(" Ingresa un numero entero: ");

	scanf("%d", &y);
	printf(" El valor de la variable y es %d\n", y);



	// Arreglos
	
	int numeros[5] = {65, 84, 23, 66, 47};

	printf("La primer posicion del arreglo tiene: %d\n", numeros[0]);
	printf("La primer posicion del arreglo tiene: %d\n", numeros[4]);

	char letras[3] = {'a', 'b', 'c'};

	printf("La primer posicion del arreglo tiene: %d\n", letras[0]);
	printf("La primer posicion del arreglo tiene: %d\n", letras[2]);

	char direccion[] = "Ave. De las torres 25442";
	char nombres[3][20] = {"Karla", "Omar", "Luis"}; // Cada nombre puede tener hasta 19 caracteres (el último espacio es para el terminador '\0').

	printf("Direccion: %s\n", direccion);

	printf("Ingresa un nombre: ");
	scanf("%s", direccion);
	
	printf("El nombre es: %s", direccion);
	printf("Nombre 1: %s\n", nombres[0]);
	printf("Nombre 2: %s\n", nombres[1]);
	printf("Nombre 3: %s\n", nombres[2]);

	return 0;
}
