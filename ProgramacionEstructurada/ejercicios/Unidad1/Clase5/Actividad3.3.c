//Villedo Martinez Sandoval 222534
//Fernando Ponce Solis 222953
#include <stdio.h>
 
int main(){
	float  cal1,cal2,cal3,promedio;
	char nombre[70];
	printf("Ingrese su nombre:");
	scanf("%69[^\n]",nombre);
	printf("Ingrese la 1ra calificacion: ");
	scanf(" %f",&cal1);
	printf("Ingrese la 2da calificacion: ");
	scanf(" %f",&cal2);
	printf("Ingrese la 3ra calificacion: ");
	scanf(" %f",&cal3);
	promedio=(cal1+cal2+cal3)/3;
	printf("El promedio es: %f",promedio);
	if (promedio>=7){ 
	    printf("\nLa calificacion es aprobatoria");
	}
	else{
	    printf("\nLa calificacion es reprobatoria");
	}
	return 0;
} 	
