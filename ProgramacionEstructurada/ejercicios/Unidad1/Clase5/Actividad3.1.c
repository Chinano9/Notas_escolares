// Fernando Ponce Solís 222953
// Villedo Martinez Sandoval 222534
#include<stdio.h>

int main(void){
	int num;
	printf("Ingrese el numero: ");
	scanf("%d",&num);

	if(num>0){
		printf("El numero %d es positivo\n", num);
	}else if(num == 0){
		printf("El numero es cero");
	}else{
		printf("El numero %d es negativo", num);
	}
	return 0;
}
