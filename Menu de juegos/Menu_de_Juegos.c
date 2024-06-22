#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Juegos_Lib.h"

/*
	*****************************************************************************
	*	Programa realizado por: lrkRocky										*
	*		Programación estructurada 1er semestre								*
	*																			*		
	*****************************************************************************

	Este programa es un menú de juegos en el que se puede escoger cual jugar.

Lista de juegos
	1) Piedra papel o tijera (versión normal).
	2) Piedra papel o tijera (versión Animal world).
	3) Juego de ahorcado.
	4) Ecuaciones de coincidencia (Juego de serie Plan del diablo).

*/


int main(){
	srand(time(NULL)); 																	//Inicialización de generador de numero aleatorios.
	int eleccion_de_usuario = 1;														//Declaración de variable para capturar la elección el usuario.
	printf("Buenas tardes, bienvenido. \n\n\n");										//Bienvenida tradicional de códigos de estudio de Rocky (siempre hay que saludar primero).
		
	while(eleccion_de_usuario == 1){													//Estructura de control para mantener iteración del juego según lo desee el usuario.
		printf("\n \t Menu de juegos de Rocky: \n\n");
		printf("1) Piedra papel y tijera (version normal). \n");
		printf("2) Piedra papel y tijera (version Animal world). \n");
		printf("3) Juego de ahorcado. \n");
		printf("4) Ecuaciones de coincidencia (Juego de serie Plan del diablo) \n\n");		//Impresión de menú de juegos.
		printf("Ingrese el numero de juego que desee jugar: \n");
		fflush(stdin);
		scanf("%d",&eleccion_de_usuario);													//Captura de selección de usuario.
		system("CLS");																		//Limpia pantalla.
		while(eleccion_de_usuario != 1 && eleccion_de_usuario != 2 && eleccion_de_usuario != 3 && eleccion_de_usuario != 4  ){
			printf("Numero ingresado invalido, favor de ingresar de nuevo su eleccion: \n\n");
			printf("Menu de juegos de Rocky: \n\n");
			printf("1) Piedra papel y tijera (version normal). \n");
			printf("2) Piedra papel y tijera (version Animal world). \n");					//Protege la elección del usuario a solo opciones validas (1, 2, 3 o 4).
			printf("3) Juego de ahorcado. \n");
			printf("4) Ecuaciones de coincidencia (Juego de serie Plan del diablo) \n\n");
			printf("Ingrese el numero de juego que desee jugar: \n");
			fflush(stdin);
			scanf("%d",&eleccion_de_usuario);	
			system("CLS");
		}
		switch (eleccion_de_usuario){
			case 1:
				Piedra_papel_tijera_normal();
				break;
			case 2:
				Piedra_papel_tijera_AnimalWorld();				//Ejecuta la función del juego dependiendo la elección del usuario.
			case 3:
				Juego_de_ahorcado();
				break;
			case 4:
				Ecuaciones_de_coincidencia();
			default:
				break;
		}
		printf("\n\n Presione enter para continuar. \n");		//Ligera pausa para que el usuario pueda ver la pantalla final del juego en caso de haber alguna.
		fflush(stdin);											
		getchar();
		system("CLS");
		
		printf("\n\n Desea volver al menu de juegos principal? \n");
		printf("\n Ingrese 1 en caso de que asi lo desee, ingrese cualquier otro numero para finalizar el programa. \n");
		fflush(stdin);											//Vacia buffer de salida para eviar problemas en scanf
		scanf("%d",&eleccion_de_usuario);						//Permite al usuario repetir bucle principal o salir de el para finalización del dia.
		system("CLS");
	}
	printf("\n\n Fin del programa, que tenga buen dia. \n");	//Mensaje final, espero que se juegue de dia o de tarde, sino, que el usuario lo interprete como bonita noche.
	return 0;
}
//Fin de la función principal.