// Fernando Ponce Solís 222953
// Villedo Martinez Sandoval 222534
#include<stdio.h>

int main(){
	int edad;
	char sexo;

	printf("Edad: ");
	scanf("%d",&edad);

	printf("Sexo (h/m): ");
	scanf(" %c",&sexo);

	if((sexo == 'h' && edad>= 60) || (sexo == 'm' && edad >= 55)){
		printf("Puede jubilarse!! :D \n Disfrute su retiro!\n");
	}else if(sexo != 'h' && sexo != 'm'){
		printf("No te tengo contemplado en mis archivos de sexo\n");
	}else{
		printf("No puedes jubilarte, a chambearle papu\n");
	}
	return 0;
}
