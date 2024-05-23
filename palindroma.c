#include <stdio.h>
#include <stdlib.h>


void main(){
	char palabra[20];
	printf("Buenas tardes. \n");
	printf("Este programa indica si la palabra ingresada es palindroma o no. \n");
	printf("Presione enter para continuar. \n");
	getchar();
	while(1){
		printf("Ingresa la palabra \n");
		scanf("%s", palabra);
		system("CLS");
		int size; 
		for(size = 0 ; palabra[size] != '\0' ; size++){}
		printf("La palabra tiene %d letras. \n", size);
		int flag = 0;
		for(int i = 0 ; i < (size/2) ; i++){
			if(palabra[i] != palabra[size - i - 1] ){
				flag = 1;
			}
			else{}
		}
		if(flag == 0){
			printf("Su palabra si es palindroma \n");
		}
		else{
			printf("Su palabra no es palindroma \n");
		}
	}
}