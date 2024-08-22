//Villedo Martinez Sandoval 222534
//Fernando Ponce Solis 222953
#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	
	// Ambos estan a la misma distancia
	if (A-B == C || B-A == C || B-A == 0){
		printf("Raton C\n");
	// A esta mas cerca que B
	}else if(abs(C-B) > abs(C-A)){
		printf("Gato A\n");
	}else{
		printf("Gato B\n");
	}
	return 0;
}
