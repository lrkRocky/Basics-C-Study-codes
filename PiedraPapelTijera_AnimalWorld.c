#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

/*
	*****************************************************************************
	*	Programa realizado por: lrkRocky										*
	*		Programación estructurada 1°K										*
	*																			*		
	*****************************************************************************

	Este programa es un juego de Piedra papel o tijera contra la computadora con reglas inspiradas en pelicula animal World.
		
	Detalles y reglas:
		jugador 1 es el usuario, jugador 2 computadora.
		Cada jugador tiene 4 cartas de cada tipo (piedra, papel y tijera) que se agotan en cada jugada.
		Cada jugador inicia con 3 estrellas, pierde una por ronda perdida y gana una por ronda ganada.
		En caso de empate, el jugador conserva sus estrellas sin cambios.
		Si el jugador se termina sus cartas pero tiene menos de 3 estrellas, pierde.
		Si el jugador se termina sus cartas y tiene 3 estrellas o más, gana.
		Si el jugador se queda sin estrellas antes de terminarse las cartas, pierde.
*/
void menu();

void main (){
	printf("Buenas tardes, este es un juego de piedra papel o tijera. \n");
	printf("Ambos jugadores comienzan con 3 estresllas y 4 cartas de cada tipo. \n");
	printf("Al terminarse las cartas on menos de 3 estrellas, o terminarse las estrellas, pierde. \n");
	printf("Gana al terminarse las cartas teniendo aun 3 estrellas. \n");
	srand(time(NULL));
	int vacio;
	int seleccion;
	int NoRandom;
	int control = 1;
	int cartas[7];
	int estrellas[2] ;
	int i;
	int ganador;
	for(i = 0; i <7; i++){
		cartas[i] = 4;
	}
	estrellas[1] = 3 ;
	estrellas[2] = 3 ;
	
	while(control == 1){	// control == 1									//Estructura de iteración para repetir juegos tantas veces lo desee el usuario.
		printf("La computadora escogera piedra papel o tijera de manera aleatoria. \n");
		printf("Usted intentara jugar escogiendo piedra papel o tijera de igual forma con un numero.\n");	//Instrucciones de inicio para usuario
		menu();																								//Función que despliega menú para usuario
		printf("Ingrese su eleccion con un numero de acuerdo a las opciones mostradas anteriormente. \n");
		scanf("%d",&seleccion); 
		while(seleccion < 0 || seleccion > 3){
			printf("Entrada invalida, por favor, ingrese su nuevo su eleccion  de acuerdo a las opciones mostradas anteriormente. \n");
			scanf("%d",&seleccion);																										//Lectura de seleccion de usuario.
		}
		
		if(cartas[1] == 0){			// Estructura para limitar a computadora para no generar cartas agotadas.
			while(seleccion == 1){
				printf("Las cartas de piedra estan agotadas, por favor, selecciona otro tipo de carta. \n");
				scanf("%d",&seleccion);	
			}
		}
		else{}
		if(cartas[2] == 0){
			while(seleccion == 2){
				printf("Las cartas de papel estan agotadas, por favor, selecciona otro tipo de carta. \n");
				scanf("%d",&seleccion);	
			}
		}
		else{}
		if(cartas[3] == 0){
			while(seleccion == 3){
				printf("Las cartas de tijera estan agotadas, por favor, selecciona otro tipo de carta. \n");
				scanf("%d",&seleccion);	
			}
		}
		else{}
		
		NoRandom = rand();			//Genera número random y lo asigna a la variable NoRandom
		NoRandom = NoRandom %4;		//Limita el valor random de la variable NoRandom a 3 utilizando el residuo de la división entre 4.
		if(NoRandom == 0){
			NoRandom = rand();
			NoRandom = NoRandom %4;
		}
		if(cartas[4] == 0){			// Estructura para limitar a computadora para no generar cartas agotadas.
			while(NoRandom == 1){
				NoRandom = rand();
				NoRandom = NoRandom %4;
			}
		}
		else{}
		if(cartas[5] == 0){
			while(NoRandom == 2){
				NoRandom = rand();
				NoRandom = NoRandom %4;
			}
		}
		else{}
		if(cartas[6] == 0){
			while(NoRandom == 3){
				NoRandom = rand();
				NoRandom = NoRandom %4;
			}
		}
		else{}
		printf("Numero aleatorio generado: %d \n", NoRandom);
		//while(,cartas[1],cartas[2] cartas[3])
		
		if(seleccion == NoRandom){			//Estructura if/else para los casos de empate.
			printf("Empate \n");
			switch(seleccion){
				case 1:
					printf("Usted selecciono piedra, al igual que la computadora. \n");	//Estructura switch para personalizar mensajes en caso de empate.
					cartas[1] = cartas[1] - 1; 
					cartas[4] = cartas[4] - 1; 
					break;
				case 2:
					printf("Usted selecciono papel, al igual que la computadora. \n");
					cartas[2] = cartas[2] - 1; 
					cartas[5] = cartas[5] - 1; 
					break;
				case 3:
					printf("Usted selecciono tijera, al igual que la computadora. \n");
					cartas[3] = cartas[3] - 1; 
					cartas[6] = cartas[6] - 1; 
					break;
				default:
					break;
			}
		}
		else{
			switch(seleccion){
			case 1:
				if(NoRandom == 2){
					printf("Escoges piedra y pierdes contra papel. \n");	//Estructuras de control para personalizar mensajes dependiendo el ganador.
					estrellas[1] = estrellas[1] - 1;
					estrellas[2] = estrellas[2] + 1;
					cartas[1] = cartas[1] - 1; 
					cartas[5] = cartas[5] - 1; 
				}
				else{
					printf("Escoges piedra y ganas contra tijera. \n");
					estrellas[1] = estrellas[1] + 1;
					estrellas[2] = estrellas[2] - 1;
					cartas[1] = cartas[1] - 1; 
					cartas[6] = cartas[6] - 1; 
				} 
				break;
			case 2:
				if(NoRandom == 1){
					printf("Escoges papel y ganas contra piedra. \n");
					estrellas[1] = estrellas[1] + 1;
					estrellas[2] = estrellas[2] - 1;
					cartas[2] = cartas[2] - 1; 
					cartas[4] = cartas[4] - 1; 
				}
				else{
					printf("Escoges papel y pierdes contra tijera. \n");
					estrellas[1] = estrellas[1] - 1;
					estrellas[2] = estrellas[2] + 1;
					cartas[2] = cartas[2] - 1; 
					cartas[6] = cartas[6] - 1; 
				} 
				break;
			case 3:
				if(NoRandom == 1){
					printf("Escoges tijera y pierdes contra piedra. \n");
					estrellas[1] = estrellas[1] - 1;
					estrellas[2] = estrellas[2] + 1;
					cartas[3] = cartas[3] - 1; 
					cartas[4] = cartas[4] - 1; 
				}
				else{
					printf("Escoges tijera y ganas contra papel. \n");
					estrellas[1] = estrellas[1] + 1;
					estrellas[2] = estrellas[2] - 1;
					cartas[3] = cartas[3] - 1; 
					cartas[5] = cartas[5] - 1; 
				} 
				break;	
			default:
				break;
			}
		}
		printf("Estado y posesiones de jugadores: \n\n");
		printf("Jugador 1 (usuario): %d estrellas.    Jugador 2 (computadora): %d estrellas.  \n\n",estrellas[1],estrellas[2]);
		printf("Jugador 1 (usuario): %d cartas de pierda, %d cartas de papel, %d cartas de tijera.  \n",cartas[1],cartas[2],cartas[3]);
		printf("Jugador 2 (computadora): %d cartas de pierda, %d cartas de papel, %d cartas de tijera. \n\n",cartas[4],cartas[5],cartas[6]);
		
		if(estrellas[1] == 0 ){		
			printf("Jugador 1 (usuario) se quedo sin estrellas, jugador 2 (computadora) gana. \n");
			control = 0;
		}
		else if(estrellas[2] == 0){
			printf("Jugador 2 (computadora) se quedo sin estrellas, jugador 1 (usuario) gana. \n");
			control = 0;
		}
		else if((cartas[1] == 0 && cartas[2] == 0 && cartas[3] == 0)&&(estrellas[1] <3) ){
			printf("Jugador 1 (usuario) se quedo sin cartas con menos de 3 estrellas y pierde, jugador 2 (computadora) gana. \n");
			control = 0;
		}
		else if((cartas[4] == 0 && cartas[5] == 0 && cartas[6] == 0)&&(estrellas[2] <3) ){
			printf("Jugador 2 (computadora) se quedo sin cartas con menos de 3 estrellas y pierde, jugador 1 (usuario) gana. \n");
			control = 0;
		}
		else if((cartas[1] == 0 && cartas[2] == 0 && cartas[3] == 0)&&(estrellas[1] == 3) ){
			printf("Jugador 1 (usuario) se quedo sin cartas con 3 estrellas y gana, jugador 2 (computadora) pierde. \n");
			control = 0;
		}
		else if((cartas[4] == 0 && cartas[5] == 0 && cartas[6] == 0)&&(estrellas[2] == 3) ){
			printf("Jugador 2 (computadora) se quedo sin cartas con 3 estrellas y gana, jugador 1 (usuario) pierde. \n");
			control = 0;
		}
		else{}
		printf("Ingrese cualquier numero para continuar. \n");
		scanf("%d",&vacio);
		system("CLS");
		
	}	
	printf("Fin del juego, tenga usted buen dia.\n");			//Mensaje final del programa.
}

void menu(){
	printf("1 = Piedra \n");
	printf("2 = Papel \n");			//Menú de opciones para usuario.
	printf("3 = Tijera \n");
}



/*
		cartas[]:	[1]		[2]		[3]		[4]		[5]		[6]
	jugador 1:		piedra, papel, tijera
	jugador 2:								piedra, papel, tijera.
	
	estrellas[]:	[1]		[2]		
				jugador 1, jugador 2.
	
*/

