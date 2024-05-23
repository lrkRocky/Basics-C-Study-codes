#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

/*
	*****************************************************************************
	*	Programa realizado por: lrkRocky				    *
	*		Programación estructurada 1°K				    *
	*									    *		
	*****************************************************************************
	
		Este programa es un juego de ahorcado en el que el usuario ingresa la palabra y posteriormente el mismo u otro la adivina.
*/
void monito();

void main(){
	int size = 0;
	char letra;
	char palabra[20];			//Declaración de valores iniciales y variables por utilizar.
	char adivinada[20];
	
	printf("\nBuenas tardes \n");
	printf("Este es un juego de ahorcado: \n");			//Instrucciones
	printf("Debera adivinar la palabra ingresada al principio por otra persona, ingresando letra por letra. \n");
	printf("Cuenta con 7 intentos para adivinar la palabra, de lo contrario, se completara la figura de Juanito ahorcado. \n");
	printf("Si logra adivinar la palabra completa en menos de 7 intentos, Juanito sera salvado. \n\n\n");
	printf("\t       (o_o) \n");
	printf("\t        /|\\ \n");
	printf("\t         |	\n");
	printf("\t        / \\ \n");
	int control = 1;
	while(control == 1){
		printf("Ingrese la palabra por adivinar \n");
		scanf("%s",&palabra);
		system("CLS");
		int i;
		for(i = 0; palabra[i] != '\0' ; i++ ){
			size++;									//Determina el tamaño de la palabra ingresada.
		}
		for(i = 0; i < size ; i++ ){
			adivinada[i] = '-';						//Asignación de valores a palabra que ira siendo sustituida conforme se adivinen letras.
		}
		adivinada[size] = '\0';						//Asegura que el valor de la palabra por construir termine en valor nulo, al igual que la palabra por adivinar.
		printf("\n\n\n\n \t");
		for(i = 0; i < size ; i++ ){
			printf("- ");							//Dibujo de la palabra oculta dependiente del tamaño de la misma.
		}
		printf("\n \t");
		for(i = 0; i < size ; i++ ){				//Indicación del numero de casilla o caracter para el dibujo hecho anteriormente.
			printf("%d ",(i+1));	
		}
		printf("\n");
		int intentos;
		int flag = 0;
		int No_ganador = 0;
		for(intentos = 7; intentos > 0; intentos --){
			printf("\n\n\n\n La palabra por adivinar contiene %d  letras \n", size);	//Instrucciones e información para usuario.
			printf("A usted le quedan %d de 7 intentos \n", intentos);
			monito(intentos);															//Función de dibujo de figura de ahorcado.
			printf("Ingrese la letra que cree que cotiene la palabra \n");
			scanf(" %c",&letra);
			system("CLS");
			printf("\n\n\n\n");
			for(i = 0; i < size ; i++ ){		//Estructura for que sobreescribe letra adivinada en palabra por construir en caso de ser acertada.
				if(letra == palabra[i] ){
					adivinada[i] = letra;
					flag = 1;					//Bandera que indica cuando una letra fue acertada.
				}
				else if(palabra[i] != '-'){
				}
				else{
					adivinada[i] = '-';
				}	
			}
			printf("\t%s \n", adivinada);		//Muestra palabra que esta siendo construida o adivinada.
			printf("\t");
			for(i = 0; i < size ; i++ ){
				printf("%d",(i+1));				//Indica numero de caracter para la palabra mostrada anteriormente.
			}
			printf("\n");
			for(i = 0; i < size ; i++ ){
				if( palabra[i] != adivinada[i]){
					No_ganador = 1;					//Determina si la palabra completa ya ha sido adivinada o no con una bandera.
				}
				else{}
			}
			if(No_ganador == 0){											
				printf("La palabra si contiene la letra %c. \n \t", letra);
				intentos = 0;													//Termina ciclo de iteración for para llegar a final de juego tras haber ganado.
			}
			else{
				if(flag == 1){
				printf("La palabra si contiene la letra %c, continue asi \n \t", letra);			//Estructura para indicar si la letra fue acertada o no.
				intentos++;
				}
				else{
					printf("La palabra no contiene la letra %c, hazlo mejor por Juanito :c \n \t", letra);
				}
			}
			flag = 0;
			No_ganador = 0;
		}
		for(i = 0; i < size ; i++ ){			//Estrucutra de iteración para comparar si la palabra construida adivinando es igual a la establecida inicialmente.
			if( palabra[i] != adivinada[i]){
				No_ganador = 1;					//Bandera que se activa en caso de que la palabra no haya sido adivinada completamente.
			}
			else{}
		}
		if( No_ganador == 0){
			printf("Felicidades, adivinaste la palabra y salvaste a Juanito c: \n");
			printf("\t   _______ 	\n");
			printf("\t  |/      		\n");
			printf("\t  |     		\n");
			printf("\t  |     (^_^) \n");
			printf("\t  |      \\|/ \n");
			printf("\t  |       |	\n");			//Mensajes de ganador o perdedor del juego.
			printf("\t__|__    / \\ \n");
		}
		else{
			printf("Nooooo! Se terminaron los intentos y Juanito salio ahorcado :C \n");
			printf("La palabra por adivinar era: %s \n\n\n", palabra);
			monito(0);
		}
		printf(" \n\n\n\n  Inserte 1 si desea volver a jugar, de lo contrario, inserte cualquier otro numero o letra. \n");
		scanf("%d",&control);		//Ofrece opción de repetir o salir de estructura de iteración principal del juego.
		system("CLS");
		size = 0;
		letra = '\0';				//Reestablece valores iniciales para evitar errores.
		palabra[20] = "";
		adivinada[20] = "";
	}
	printf("Fin del juego \n");
}

void monito(intentos){		//Función que dibuja el personaje dependiendo el intento en el que se encuentre el usuario.
	switch(intentos){
	case 7:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     		 \n");
		printf("\t  |   		 \n");
		printf("\t  |   		   \n");
		printf("\t  |      		 \n");
		printf("\t__|__\n");
		break;
	case 6:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (   ) \n");
		printf("\t  |   		 \n");
		printf("\t  |   		   \n");
		printf("\t  |      		 \n");
		printf("\t__|__\n");
		break;
	case 5:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (   ) \n");
		printf("\t  |       | \n");
		printf("\t  |       | \n");
		printf("\t  |         \n");
		printf("\t__|__\n");
		break;
	case 4:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (   ) \n");
		printf("\t  |       | \n");
		printf("\t  |       | \n");
		printf("\t  |         \n");
		printf("\t__|__\n");
		break;
	case 3:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (   ) \n");
		printf("\t  |       | \n");
		printf("\t  |       |  \n");
		printf("\t  |      / \\ \n");
		printf("\t__|__\n");
		break;
	case 2:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (   ) \n");
		printf("\t  |       |/ \n");
		printf("\t  |       |  \n");
		printf("\t  |      / \\ \n");
		printf("\t__|__\n");
		break;
	case 1:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (   ) \n");
		printf("\t  |      \\|/ \n");
		printf("\t  |       | \n");
		printf("\t  |      / \\ \n");
		printf("\t__|__\n");
		break;
	case 0:
		printf("\t   _______ \n");
		printf("\t  |/      | \n");
		printf("\t  |     (*_*) \n");
		printf("\t  |      \\|/ \n");
		printf("\t  |       | \n");
		printf("\t  |      / \\ \n");
		printf("\t__|__\n");
	default:
		break;
}
}
