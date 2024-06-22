#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Juegos_Lib.h"

//Funciones utilizadas en juegos.

	//Funciones utilizadas en juego 1 y 2: Piedra papel o tijera (versión normal y versión Animal world).
	void menu_juego_1y2(){
		printf("1 = Piedra \n");
		printf("2 = Papel \n");			//Imprime menú de opciones para usuario.
		printf("3 = Tijera \n");
	}
	
	//Funciones utilizadas en juego 3: Juego de ahorcado.
	void monito(int intentos){		//Función que dibuja el personaje dependiendo el intento en el que se encuentre el usuario.
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
	
	//Funciones utilizadas en juego 4: Ecuaciones de coincidencia (Juego de serie Plan del diablo).
	void escoge_referencia( double *referencia, int jugador){												//Permite a usuario escoger por cual numero apostar a acercar su resultado de operación con cartas.
		int RefOpcion;
		printf("Ingrese el numero de opcion de numero para apostar: \n");
		printf("1) numero 1 \n 2) numero 20 \n");														//Imprime opciones de referencia de numero por el cual apostar a acercarse con operación.
		scanf( "%d",&RefOpcion);																		//Guarda selección de usuario con numero ingresado.
		while(RefOpcion != 1 && RefOpcion != 2){
			printf("Numero invalido, por favor ingrese numero de opción de numero para apostar: \n");	//Protege de haber ingresado opciones invalidas (diferentes de 1 o 2).
			printf("1) numero 1 \n 2) numero 20 \n");
			scanf( "%d",&RefOpcion);																	//Guarda de nuevo la selección en caso de haber tenido la anterior invalida.
		}
		if(RefOpcion == 1){
			referencia[jugador] = 1;																	//Asigna numero de referencia según la selección del usuario.
		}
		else{
			referencia[jugador] = 20;
		}
	}
	
	void Asigna_Carta(int *C_Player, int *C_igual, int carta, int limite){									//Asigna numero aleatorio de 0 a limite carta a carta indicada.  (El limite determina si puede ser con operación o solo numerica).
		int C_iguales = 0;							//Variable que almacena las cantidad de cartas repetidas. C_igual[no. de carta repetida] = repeticiones
		C_Player[carta] = (rand() % (limite+1));	//Asigna numero de carta aleaterio entre 0 y limite indicado a la carta indicada en parametros de entrada de función.
		for(int i = 0; i < 19; i++){				
			for(int ii = 0; ii < 19; ii++){
				if(C_Player[i] == C_Player[ii] ){
					C_igual[i]++;					//	Detecta y guarda si hay cartas iguales repartidas y guarda cuales y cuantas son.
				}
				else{}
			}
		}
		for(int i = 0; i < 19; i++){									//Compara con repetidas y en caso de ya haber repartido 4 cartas iguales (3 repeticiones), reparte una diferente
			if((C_igual[i] == 3)&&(C_igual[i] == C_Player[carta])){
				C_igual[i]--;	
				while(C_igual[i] == C_Player[carta]){
					C_Player[carta] = (rand() % (limite+1));			
				}						
			}
			else{}
		}
	}
	
	void muestra_cartas(int inicio, int fin, int *C_Player, int jugador){									//Muestra cartas a usuario:
		// Cartas[0-15] = 0-10, * (11), sqrt() (12), + (13), - (14), / (15) en correspondiente orden.
		const char *carta_mostrada[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "x", "sqrt()", "+", "-", "/" }; ;	//Arreglo para mostrar de que es la carta dependiendo su valor.
		int size = 7;			//Variable que indica la cantidad de cartas sorteadas para el jugador.
		int Hay_sqrt = 0;		//Variable bandera de raiz cuadrada.
		printf("Las cartas obtenidas por jugador %d son: \n", jugador);
		for(int i = inicio; i < fin; i++){							//Revisa todas las cartas sorteadas depentiendo el jugador.
			printf("%s,\t", carta_mostrada[C_Player[i]] );
			if(C_Player[i] == 12){
				Hay_sqrt = 1;										//Detecta si dentro de las cartas sorteadas hay alguna raiz cuadrada, en caso de haberlo, enciende bandera.
			}
			else{}
		}
		if(	Hay_sqrt == 1 ){
			printf("%s \n ", carta_mostrada[C_Player[fin]] );		//Si hay 8vaa carta asignada (identificado con bandera de raiz cuadrada), también la muestra.
			size++;
		}
		else{
			printf(" \n");											//salto de linea.
		}
		for(int i = 1; i < size + 1 ; i++ ){
			printf("(%d)\t", i);									//Dibujo de las casillas de cada carta para identificar más facilmente su posición.
		}
		printf(" \n");
	}
	
	void muestra_cartas_organizadas(int inicio, int fin, int *C_Player, int *C_Player_Nuevo, int jugador){	//Muestra cartas sorteadas al usuario:
		// Cartas[0-15] = 0-10, * (11), sqrt() (12), + (13), - (14), / (15) en correspondiente orden.
		const char *carta_mostrada[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "x", "sqrt()", "+", "-", "/" }; //Arreglo para mostrar de que es la carta dependiendo su valor.
		int size = 7;			//Variable que indica la cantidad de cartas sorteadas para el jugador.
		int Hay_sqrt = 0;		//Variable bandera de raiz cuadrada.
		printf("Las cartas organizadas por jugador %d son: \n", jugador);
		for(int i = inicio; i < fin; i++){								//Imprime todas las cartas que hayan sido organizadas.
			if(C_Player_Nuevo[i] == -1){
				printf("n,\t");											//En caso de tener espacios sin asignar carta organizada, imprime letra n,
			}
			else{
				printf("%s,\t", carta_mostrada[C_Player_Nuevo[i]] );	//En caso de haber asignado ya alguna carta, muestra de que es (numero u operación).
			}
		}
		if(	C_Player[fin] != -1 ){										//Si la 8va carta de las fue sorteada pero su espacio no ha sido asignado por el usuario con otra carta, muestra también el lugar de la 8va por asignar o asginada con letra n.
			if(C_Player_Nuevo[fin] == (-1)){
				printf("n \n");
			}
			else{
				printf("%s \n ", carta_mostrada[C_Player_Nuevo[fin]] );		//Si la 8va carta de las fue sorteada y su espacio no ha sido asignado por el usuario con otra o la misma carta, muestra de que es (numero u operación).
			}
			size++;
		}
		else{}
		printf(" \n");
		for(int i = 1; i < (size + 1) ; i++ ){
			printf("(%d)\t", i);							//Indica posiciones de las cartas acoplandose a la cantidad de cartas sorteadas y organizadas por el usuario.
		}
		printf(" \n");
	}
	
	void sustituir_por_multiplicacion(int *C_Player, int *C_igual, int inicio, int fin, int jugador){		//En caso de tener multiplicación, pregunta al usuario que operación (+, - o *) decide sustituir por carta numerica.
		for(int i = inicio; i < fin+1 ; i++){																							//Revusa/escanea todas las cartas asignadas al jugador en turno.
			if(C_Player[i] == 11){																										//En caso de detectar alguna carta con valor que indica multiplicación:
				int Carta_sustituida;																									//Declara variable para almacenar elección de usuario.
				if(jugador == 2 ){
					printf("La carta no. %d asignada aleatoriamente es multiplicacion \n", (i-10));										//Impresión para jugador 2.
				}
				else{
					printf("La carta no. %d asignada aleatoriamente es multiplicacion \n", i);											//Impresión para jugador 1.
				}
				printf("Es necesario sustituir alguna carta de +, - o la misma de multiplicacion por otra carta numerica. \n");			//Impresión de indicaciones dependiendo de jugador en turno.
				printf("¿Que no. de carta es la que deseas sustituir? \n");
				scanf("%d",&Carta_sustituida);	
				if(jugador == 2){
					Carta_sustituida = Carta_sustituida + 10 ;
				}
				else{}
				while( C_Player[Carta_sustituida] != 11 && C_Player[Carta_sustituida] != 13 && C_Player[Carta_sustituida] != 14 ){		//Mientras la opción de que una carta no se puede intercambiar:
					printf("El numero de carta no contiene una opcion valida. \n");
					printf("Es necesario sustituir alguna carta de +, - o la misma de multiplicacion por otra carta numerica. \n");		//Pide al usuario ingresarsu selección nuevamente hasta que esta sea valida.
					printf("¿Que no. de carta es la que deseas sustituir? \n");
					scanf("%d",&Carta_sustituida);
				}
				Asigna_Carta( C_Player, C_igual, Carta_sustituida, 10);																	//Asigna carta numerica a la posición de carta que el usuario decidio sustituir.
				muestra_cartas( inicio, fin, C_Player, jugador);																		//Muestra las cartas sorteadas ya con sustitución al usuario.
			}																
			else{}
		}
	}
	
	void organiza_cartas(int inicio, int fin, int *C_Player, int *C_Player_Nuevo, int jugador){				//Función que permite a usuario organizar las cartas sorteadas anteriormente. 
		for(int i = 0; i <31; i++){
			C_Player_Nuevo[i] = -1;						//Asigna valor de -1 a todos los espacios de cartas por organizar para identificar casillas sin carta asignada.
		}
		int posicion;									//Variable usada para referenciar posición de carta.
		int preseleccionadas[19];						//Arreglo que almacena las posiciones de cartas ya previamente seleccionadas por el usuario para organizar cartas.
		for(int i = 0; i <19; i++){
			preseleccionadas[i] = -1;
		}
		const char *carta_mostrada[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "x", "sqrt()", "+", "-", "/"} ;	//Arreglo que permite mostrar a usuario que carta es a partir de su valor.
		for(int i = inicio; i < (fin+1); i++){																						//Estructura para repetir proceso msima cantidad de veces que cantidad cartas tenga el cugador.
			if(jugador == 2){
				printf("Ingrese la posicion en la que desea tener la carta %d (%s): \n", (i-10), carta_mostrada[C_Player[i]] );
			}																														//Mensaje de indicación dependiendo el jugador y la carta en turno.
			else{
				printf("Ingrese la posicion en la que desea tener la carta %d (%s): \n", i, carta_mostrada[C_Player[i]] );
			}
			if(i == 1){
				for(int ii = 1; ii < fin; ii++){
					printf("n \t");					//Dibujo de figura sin ninguna letra asginada con n previo a asignar la primera carta.
				}
				if(C_Player[fin] != -1){
					printf("n \t");					//Complemento de figura sin letra asignada en caso de que haya 8va carta sorteada.
				}
				else{}
				printf("\n");
				for(int ii = 1; ii < fin; ii++){	//Dibujo de posiciones disponibles con numero previo a asignar la primera carta.
					printf("(%d) \t", ii);
				}
				if(C_Player[fin] != -1){
					printf("(8) \t" );				//Complemento de indicación de posiciones para cada carta o espacio en caso de que haya 8va carta sorteada.
				}
				else{}
				printf("\n");
			}
			
			scanf("%d",&posicion);																				//Se guarda posición elegida por usuario para colocar carta.
			if(C_Player[fin] != -1){
				while(posicion < 0 || posicion > 8){
					printf("La posicion indicada no es posible con sus cartas o esta fuera de rango. \n");		//Protección en caso que el usuario ingrese una posición deseada no posible
					if(jugador == 2){																			// 		dependiendo de la existencia de la 8va carta asignada y del jugador en turno.
						printf("Ingrese de nuevo una posicion valida en la que desea tener la carta %d: (%s) \n", (i-10), carta_mostrada[C_Player[i]] );
					}	
					else{
						printf("Ingrese de nuevo una posicion valida en la que desea tener la carta %d: (%s) \n", i, carta_mostrada[C_Player[i]] );
					}
					scanf("%d",&posicion);																		//El usuario vuelve ingresar la (nueva) posición deseada y evalua si es valida.
				}	
			}
			else{
				while(posicion < 0 || posicion > 7){															//Protección para elección de posición invalida para el caso en que haya solo  7 cartas.
					printf("La posicion indicada no es posible con sus cartas o esta fuera de rango. \n");
					if(jugador == 2){
						printf("Ingrese de nuevo una posicion valida en la que desea tener la carta %d: (%s) \n", (i-10), carta_mostrada[C_Player[i]] );
					}	
					else{
						printf("Ingrese de nuevo una posicion valida en la que desea tener la carta %d: (%s) \n", i, carta_mostrada[C_Player[i]] );
					}
					scanf("%d",&posicion);																		//El usuario vuelve ingresar (nueva) posición deseada y evalua si es valida.
				}
			}
			if(jugador == 2){
				posicion = posicion +10;						//Adecua la posición indicada en la que se asignará la carta en turno dependiendo el jugador en turno.
			}
			else{}
			for(int ii = inicio; ii<(fin+1); ii++){
				if(preseleccionadas[ii] == posicion){			//Detecta si la eleccion es repetida con alguna igual realizada anteriormente.
					while(preseleccionadas[ii] == posicion ){	//En caso de que se repita elección, pide ingresar una diferente.
						printf("La posicion indicada ya fue previamente seleccionada por usted, por lo que ya tiene carta nueva en dicha posicion \n");
						printf("Ingrese de nuevo una posicion diferente en la que desea tener la carta %d: (%s) \n", i, carta_mostrada[C_Player[i]]);
						scanf("%d",&posicion);
						if(jugador == 2){
							posicion = posicion +10;			//Adecua la posición indicada en la que se asignará la carta en turno dependiendo el jugador en turno.
						}
						else{}
					}
					ii = 0;
				}
				else{}
			}			
			C_Player_Nuevo[posicion] = C_Player[i];	//Asigna la carta sorteada en turno a la posición indicada del arreglo de cartas que estan siendo organizadas. C_Player[i] 1 a 7 para jugador 1, 11 a 17 para jugador 2.
			preseleccionadas[i] = posicion;			//Guarda selección realizada para que no se repita.
			if( C_Player[fin] == (-1)){				
				if(i == (fin-1)){
					i = i+3;						//En caso de no haber 8va carta, se terminan las iteraciones de asignación de cartas a nuevas posiciones en la repetición 6.
				}
				else{}							
			}
			else{}									//En caso de haber 8va carta, se repite el proceso normal para ella sin alterar variable indicadora de iteraciones.
			system("CLS");
			muestra_cartas( inicio, fin, C_Player, jugador);								//Muestra cartas inicialmente sorteadas al jugador.
			muestra_cartas_organizadas(inicio, fin, C_Player, C_Player_Nuevo, jugador);		//Muestra cartas organizadas por el jugador con o sin espacios sin ninguna carta asignada.
		}
	}
	
	void proteccion_contra_mala_organizacion(int inicio, int fin, int *C_Player, int *C_Player_Nuevo, int jugador){						//Protege de haber hecho una incorrecta organización de cartas.
		int organizado_incorrecto;
		do{																						//Estructura de iteración para revisar organizado de cartas solo una vez y en base a ello repetir o no.
			//Cartas[0-15] = 0-10, * (11), sqrt() (12), + (13), - (14), / (15) en correspondiente orden.
			organizado_incorrecto = 0;
			for( int i = inicio; i < (fin +1); i++){		//inicio, (fin+1)										//Detecta si carta +, -, x o / fue colocada corectamente.
				if((C_Player_Nuevo[i] == 11 || (C_Player_Nuevo[i] > 12 && C_Player_Nuevo[i] < 16 )) && (C_Player_Nuevo[(i-1)] <11 && C_Player_Nuevo[(i-1)] >0) && ((C_Player_Nuevo[(i+1)] <11 && C_Player_Nuevo[(i-1)] >0) || C_Player_Nuevo[(i+1)] ==12 )){}
				else{	
					if(C_Player_Nuevo[i] == 12 && (C_Player_Nuevo[(i+1)] <11 &&C_Player_Nuevo[(i+1)] >0)){}			//Detecta si carta de raiz cuadrada fue correctamente colocada.
					else{
						if(C_Player_Nuevo[i] < 11){												//Detecta si la carta es numerica.
							if(C_Player_Nuevo[i] == 0 && C_Player_Nuevo[(i-1)] == 15){			//Detecta si se acomodo una división de  otro numero entre 0.
								organizado_incorrecto = 1;
									printf("No se puede realizar una division entre 0. \n");	//Imprime señalación de error.
							}
							else{}
						}											
						else{
							organizado_incorrecto = 1;											//Si alguna carta fue colocada incorrectamente, lo indica con variable bandera.
						}
					}	
				}
			}
			if(organizado_incorrecto == 1){
				printf("Alguna carta fue incorrectamente organizada, por favor, organicelas de nuevo. \n");
				printf("(En caso de tener alguna duda, puede repetir el juego y leer las reglas sobre el organizado de cartas). \n");
				organiza_cartas(inicio, fin, C_Player, C_Player_Nuevo, jugador); 	//Función que permite a usuario organizar las cartas dadas en caso de que anteriormente no se haya realizado correctamente. (inicio, fin, arreglos)
			}
			else{}	
		}
		while(organizado_incorrecto == 1);
	}
	
	void operador(int inicio, int fin, int *C_Player_Nuevo, double *Resultados, double *referencia, double *diferencia, int jugador){	//Realiza operaciones correspondientes con cartas organizadas por usuario y muestra resultado final de ello.
		for (int i = 0; i < 31; i++) {
	        Resultados[i] = C_Player_Nuevo[i];		//Crea copia de arreglo organizado por usuario para guardar resultados de operaciones ahora con decimales(float).
	    }
	    for (int i = 0; i < 31; i++) {
	    	if(Resultados[i] == -1){
	    		Resultados[i] = 0;	//Toda posición que no contenga carta identificada con -1, se asigna valor 0 para no afectar operaciones.
			}
			else{}
			if(Resultados[i] == 11 || Resultados[i] == 12 || Resultados[i] == 13 ||Resultados[i] == 14 || Resultados[i] == 15 ){
				Resultados[i] = Resultados[i]*(-1);		//Invierte signo de identificadores de operaciones para que no se confunda con resultados de las mismas.
			}											//Se utiliza signo negativo dado que no es posible obtener esos numeros con las operaciones a exepción de la resta, que se realiza al final solo una vez.
			else{}
				//Cartas[0-15] = 0-10, * (11), sqrt() (12), + (13), - (14), / (15) en correspondiente orden.
	    }
		for(int i = inicio; i < (fin+1) ; i++){			//Detecta cartas de sqrt()
			if(Resultados[i] == -12){
				Resultados[i] = sqrt(Resultados[i+1]);	//Aplica raiz cuadrada a carta a su derecha y guarda resultado en el lugar de la carta sqrt().
				for(int ii = (i+1); ii< (fin+1) ; ii++){
					Resultados[ii] = Resultados[ii + 1];	//Recorre todas las cartas que se encuentren a la derecha de la operación realizada una posición hacia la izquierda.
				}
			}
			else{}
		}
	    for(int d = 0 ; d <2; d++ ){	// Se repite detección dado que pueden haber una operación de cada tipo.
			for(int i = inicio; i < (fin+1) ; i++){			//Detecta cartas de multiplicación o división()
				if(Resultados[i] == -11 || Resultados[i] == -15){
					if(Resultados[i] == -15){										//En caso de detectar División
						Resultados[i-1] = (Resultados[i-1])/(Resultados[i+1])  ;	//Aplica división a cartas o cantidades de sus extremos y guarda resultado en el lugar de la primera carta (la de posición menor).
						for(int ii = i; ii< (fin+1) ; ii++){
							Resultados[ii] = Resultados[ii + 2];	//Recorre todas las cartas que se encuentren a la derecha de la división realizada 2 posiciones hacia la izquierda.
						}
					}
					else{															//En caso de detectarmultiplicación
						Resultados[i-1] = (Resultados[i-1])*(Resultados[i+1])  ;	//Aplica multiplicación a cartas o cantidades de sus extremos y guarda resultado en el lugar de la primera carta (la de posición menor).
						for(int ii = i; ii< (fin+1) ; ii++){
							Resultados[ii] = Resultados[ii + 2];	//Recorre todas las cartas que se encuentren a la derecha de la multiplicación realizada 2 posiciones hacia la izquierda.
						}
					}
				}
				else{}
			}
		}
		for(int i = inicio; i < (fin+1) ; i++){			//Detecta cartas de resta
			if(Resultados[i] == -14){										//En caso de detectar resta
				Resultados[inicio] = Resultados[inicio]-(Resultados[i+1])  ;	//Aplica suma a cartas o cantidades de sus extremos y guarda resultado en el lugar de la primera carta (la de posición menor).
				for(int ii = i; ii< (fin+1) ; ii++){
					Resultados[ii] = Resultados[ii + 2];	//Recorre todas las cartas que se encuentren a la derecha de la división realizada 2 posiciones hacia la izquierda.
				}
			}
			else{}
		}
		for(int i = inicio; i < (fin+1) ; i++){			//Detecta cartas de suma
			if(Resultados[i] == -13){										//En caso de detectar suma 
				Resultados[inicio] = Resultados[inicio]+(Resultados[i+1]) ;	//Aplica suma a cartas o cantidades de sus extremos y guarda resultado en el lugar de la primera carta (la de posición menor).
				for(int ii = i; ii< (fin+1) ; ii++){
					Resultados[ii] = Resultados[ii + 2];	//Recorre todas las cartas que se encuentren a la derecha de la división realizada 2 posiciones hacia la izquierda.
				}
			}
			else{}
		}
		printf("El resultado de la operacion que realiza su acomodo de cartas es: %lf \n", Resultados[inicio]);
		printf("\n\n Presione enter para continuar \n");
		fflush(stdin);
		getchar();
		system("CLS");
		//Cartas[0-15] = 0-10, * (11), sqrt() (12), + (13), - (14), / (15) en correspondiente orden.
	}
	
	void muestra_reglas(){ 			//Se muestran reglas para mejor comprensión del juego si es que el usuario lo desea.
		printf("Las reglas de este juego estan basadas en el juego 'Ecuaciones de coincidencia'mostrado en la segunda parte del capitulo 10 de la serie Plan del diablo. \n");
		printf("El juego esta diseñado para dos jugadores \n");
		printf("Ambos jugadores seleccionan un numero al cual apostar, este puede ser 1 o 20. \n");
		printf("Ambos jugadores obtienen una serie de cartas con simbolos y numeros para realizar operaciones que los acerquen al numero por el cual apostaron. \n");
		printf("El jugador cuya operacion matematica de el resultado mas cercano (con menor diferencia) al numero por el cual aposto, gana.\n");
		printf(" \n\n");
		printf("Detalles sobre el sorteo de cartas: \n");
		printf("Para cada jugador, simepre, se asignaran 7 cartas minimo, 8 maximo. \n");
		printf("Las primeras 3 cartas siempre por defecto seran las cartas con signo +, - y / (división) \n");
		printf("La cuarta carta asignada sera numerica (las cartas numericas pueden contener un numero de 0 a 10, incluyendo los mismos numeros). \n");
		printf("La quinta y sexta carta asignada pueden contener numeros u operaciones de multiplicacion (x) o raiz cuadrada(sqrt(10)). \n");
		printf("En caso de que la quinta y sexta carta resulten en cartas de operaciones, el programa cambiara en automatico la 6ta carta por otra numerica en su lugar. \n");
		printf("En caso de obtener una carta de multiplicacion, el usuario debera sustituir dicha carta, la carta de suma (+) o la carta de resta (-) por una carta numerica en su lugar. \n");
		printf("En caso de obtener una carta de raiz cuadrada (sqrt()), el jugador obtendra otra carta numerica adicional \n");
		printf("Por ultimo, se agragara una ultima carta numerica en el lugar 7 u 8 dependiendo de si se asigno una anteriormente por tener sqrt() \n");
		printf(" \n\n");
		printf("Detalles sobre el acomodo de cartas: \n");
		printf("La carta por asignar en el momento sera indicada por la consola con su simbolo o numero y la posicion original en la que se coloco al ser sorteada.");
		printf("El acomodo de cartas se ira mostrando conforme las asigne el usuario, los espacios sin cartas asignadas se veran reflejados con la letra n. \n");
		printf("Las operaciones son realizadas respetando jerarquia de operaciones matematicas, es decir, se ejecutan primero raiz cuadrada (sqrt()), \n");
		printf("despues multiplicacion y division (x y /) de izquierda a derecha y por ultimo sumas y restas (+ y -). \n");	
		printf("La carta de raiz cuadrada(sqrt()) debera ser colocada a la izquierda del numero al que se le desee aplicar (Ej. sqrt(), 9). \n");
		printf("Las cartas de multiplicacion y division (x y /), deberan ser colocadas entre las dos cartas a las que se les desee realizar la operacion (Ej. 5 / 3) \n");
		printf("*Nota: Se debe recordar que no se puede dividir un numero entre 0 dado que el resultado es una indeterminacion.\n");
		printf("Las cartas de suma y resta (+ y -) pueden ser utilizadas entre dos numeros o resultados al igual que las de multiplicacion y division (Ej. 5 - 3) \n");
		printf("Aunque el juego cuenta con proteccion ante la mayoria de caso en los que el usuario organice incrrectamente las cartas,\n");
		printf("el acomodo incorrecto de cartas puede llevar a errores en el resultado o en el juego, por lo que si pasara por error, es necesario terminar y repetir el juego. \n");
		printf("\n\n\n Presione enter para continuar \n");
		fflush(stdin);
		getchar();
		system("CLS");
	}



//Funciones principales de cada juego.

	void Piedra_papel_tijera_normal(){
		printf("Juego de piedra papel o tijera (version normal). \n");
		printf("Usted usuario jugara contra la computadora que generara respuesta aleatoria. \n");
		printf("Piedra gana a tijera, papel gana a piedra, tijera gana a papel y mismo tipo de respuesta es empate. \n");
		int seleccion;
		int NoRandom;
		int control = 1;
		
		while(control == 1){																					//Estructura de iteración para repetir juegos tantas veces lo desee el usuario.
			printf("La computadora escogera piedra papel o tijera de manera aleatoria. \n");
			printf("Usted intentara jugar escogiendo piedra papel o tijera de igual forma con un numero.\n");	//Instrucciones de inicio para usuario
			menu_juego_1y2();																						///Función que despliega menú para usuario
			printf("Ingrese su eleccion con un numero de acuerdo a las opciones mostradas anteriormente. \n");
			scanf("%d",&seleccion);
			while(seleccion < 0 || seleccion > 3){
				printf("Entrada invalida, por favor, ingrese su nuevo su eleccion  de acuerdo a las opciones mostradas anteriormente. \n");
				scanf("%d",&seleccion);																										//Lectura de seleccion de usuario.
			}
			NoRandom = (rand()%3) + 1;			//Genera número random, lo limita a 2 con el residuo de su división entre 3, suma 1 para evitar el 0 y lo asigna a la variable NoRandom
			if(seleccion == NoRandom){			//Estructura if/else para los casos de empate.
				printf("Empate \n");
				switch(seleccion){
					case 1:
						printf("Usted selecciono piedra, al igual que la computadora. \n");	//Estructura switch para personalizar mensajes en caso de empate.
						break;
					case 2:
						printf("Usted selecciono papel, al igual que la computadora. \n");
						break;
					case 3:
						printf("Usted selecciono tijera, al igual que la computadora. \n");
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
					}
					else{
						printf("Escoges piedra y ganas contra tijera. \n");
					} 
					break;
				case 2:
					if(NoRandom == 1){
						printf("Escoges papel y ganas contra piedra. \n");
					}
					else{
						printf("Escoges papel y pierdes contra tijera. \n");
					} 
					break;
				case 3:
					if(NoRandom == 1){
						printf("Escoges tijera y pierdes contra piedra. \n");
					}
					else{
						printf("Escoges tijera y ganas contra papel. \n");
					} 
					break;	
				default:
					break;
				}
			}
			printf("Ingrese 1 en caso de querer volver a jugar, ingrese cualquier otro numero de lo contrario \n");
			scanf("%d",&control);																						//Lectura de selección de usuario para repetir juego.
			system("CLS");
		}	
		printf("Fin del juego.\n");			//Mensaje final del programa.
	}
	
	void Piedra_papel_tijera_AnimalWorld(){
		printf("Juego de Piedra papel o tijera (version Animal world) \n");
		printf("Ambos jugadores (usuario y computadora) comienzan con 3 estresllas y 4 cartas de cada tipo. \n");
		printf("Al terminarse las cartas con menos de 3 estrellas, o terminarse las estrellas, pierde. \n");
		printf("Gana al terminarse las cartas teniendo aun 3 estrellas. \n");
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
			menu_juego_1y2();																								//Función que despliega menú para usuario
			printf("Ingrese su eleccion con un numero de acuerdo a las opciones mostradas anteriormente. \n");
			scanf("%d",&seleccion); 
			while(seleccion < 0 || seleccion > 3){
				printf("Entrada invalida, por favor, ingrese su nuevo su eleccion  de acuerdo a las opciones mostradas anteriormente. \n");
				scanf("%d",&seleccion);																										//Lectura de seleccion de usuario.
			}
	
			for(int i = 1; i < 4; i ++ ){
				if(cartas[i] == 0){			// Estructura para limitar a computadora para no generar cartas agotadas.
					while(seleccion == i){
						printf("Las cartas de piedra estan agotadas, por favor, selecciona otro tipo de carta. \n");
						scanf("%d",&seleccion);	
					}
				}
				else{}
			}
			
			NoRandom = (rand()%3) + 1;			//Genera número aleatorio, lo limita a 2 con el residuo de su división entre 3, suma 1 para evitar el 0 y lo asigna a la variable NoRandom
			for(int i = 1; i < 4; i++ ){	
				if(cartas[(i+3)] == 0){					// Estructura para limitar a computadora para no generar cartas agotadas.
					while(NoRandom == i){
						NoRandom = (rand()%3) + 1;
					}
				}
				else{}
			}
			
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
			printf("\n Presione enter para continuar. \n");
			fflush(stdin);
			getchar();
			system("CLS");
		}	
		printf("Fin del juego.\n");			//Mensaje final del programa.
	}
	
	void Juego_de_ahorcado(){
		int size = 0;				//Variable para almacenar el tamaño de la palabra por adivinar.
		char letra;					//Variable que almacena temporalmente las letras ingresadas por el usuario.
		char palabra[20];			//Arreglo en el que se almacena la palabra por adivinar.
		char adivinada[20];			//Arreglo en el que se va construyendo la palabra que se esta adivinando.
		
		printf("Juego de ahorcado: \n");			//Impresión de instrucciones
		printf("Debera adivinar la palabra ingresada al principio por otra persona, ingresando letra por letra. \n");
		printf("Cuenta con 7 intentos para adivinar la palabra, de lo contrario, se completara la figura de Juanito ahorcado. \n");
		printf("Si logra adivinar la palabra completa en menos de 7 intentos, Juanito sera salvado. \n\n\n");
		printf("\t       (o_o) \n");
		printf("\t        /|\\ \n");
		printf("\t         |	\n");
		printf("\t        / \\ \n");
		int control = 1;
		while(control == 1){								//Estrucura de iteración que permite repetir el juego.
			printf("Ingrese la palabra por adivinar \n");
			scanf("%s",&palabra);							//Se guarda la palabra por adivinar ingresada por algún usuario.
			system("CLS");									//Limpia pantalla.
			int i;
			for(i = 0; palabra[i] != '\0' ; i++ ){
				size++;									//Determina el tamaño de la palabra ingresada.
			}
			for(i = 0; i < size ; i++ ){
				adivinada[i] = '-';						//Asignación de valores por defecto a palabra que iran siendo sustituidos conforme se adivinen letras.
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
			for(intentos = 7; intentos > 0; intentos --){									//Estructura de iteración que controla los intentos (posibles errores al adivinar).
				printf("\n\n\n\n La palabra por adivinar contiene %d  letras \n", size);	//Impresión de instrucciones e información para usuario.
				printf("A usted le quedan %d de 7 intentos \n", intentos);
				monito(intentos);															//Función de dibujo de figura de ahorcado dependiente del intento en el que se encuentre el usuario.
				printf("Ingrese la letra que cree que cotiene la palabra \n");
				scanf(" %c",&letra);														//Almacena letra ingresada por usuario.
				system("CLS");
				printf("\n\n\n\n");
				for(i = 0; i < size ; i++ ){		//Estructura de iteración que sobreescribe letra adivinada en palabra por construir en caso de ser acertada.
					if(letra == palabra[i] ){
						adivinada[i] = letra;
						flag = 1;					//Bandera que indica cuando una letra fue acertada.
					}
					else if(palabra[i] != '-'){}	//En caso de tener letras ya adivinadas, no sobreescribe nada.
					else{
						adivinada[i] = '-';			//En caso de no haber adivinado nada ni tener letras, se sobreescribe de nuevo -.
					}	
				}
				printf("\t%s \n", adivinada);		//Muestra palabra que esta siendo construida o adivinada.
				printf("\t");
				for(i = 0; i < size ; i++ ){
					printf("%d",(i+1));				//Indica numero de caracter para la palabra mostrada anteriormente.
				}
				printf("\n");
				for(i = 0; i < size ; i++ ){			//Determina si la palabra completa ya ha sido adivinada o no con una bandera.
					if( palabra[i] != adivinada[i]){	//Compara todas las letras de la palabra que se esta constryendo con la palabra por adivinar,
						No_ganador = 1;					//	en caso de de haber alguna diferencia, enciende una bandera que indica que no se ha ganado.
					}
					else{}
				}
				if(No_ganador == 0){												//En caso de ganar.
					printf("La palabra si contiene la letra %c. \n \t", letra);		//Indica si la letra ingresada si estaba en la palabra por adivinar.
					intentos = 0;													//Termina ciclo de iteración for para llegar a final de juego tras haber ganado.
				}
				else{																							//En caso de no ganar.
					if(flag == 1){																				//Si acerto la letra,
					printf("La palabra si contiene la letra %c, continue asi \n \t", letra);					//Indica si la letra ingresada si estaba en la palabra por adivinar.
					intentos++;																					//Evita que se resuzcan los intentos al sumar 1 a su variable.
					}
					else{																						//Si no acerto la letra
						printf("La palabra no contiene la letra %c, hazlo mejor por Juanito :c \n \t", letra);	//Indica si la letra ingresada no estaba en la palabra por adivinar.
					}
				}
				flag = 0;																						//Reestablece valores de si se acerto letra o no y de si se gano o no.
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
			palabra[20] = '\0';
			adivinada[20] = '\0';
		}
		printf("Fin del juego \n");
	}
	
	void Ecuaciones_de_coincidencia(){
		//int Cartas[16];
		int C_Player[19] ; 		//Arreglo que alamcena valores de cartas sorteados. [no. de carta], 1-8 jugador 1, 11-18 jugador 2 (sin utilizar 0 por practicidad).
		int C_Player_Nuevo[30];	//Arreglo para almacenar valores de cartas ya organizado en orden que desee usuario. Tamaño holgado.
		double Resultados[30] = {0}; //Arreglo que almacena resultados de cada operacion realizada a las cartas organizadas por el usuario. Tamaño holgado. 
		int C_igual[16];		//Arreglo que almacena la cantidad de repeticiones que se realiza por cada carta. [no. de carta] y valor = repeticiones
		double referencia[3];	//Arreglo que almacena la referencia de numero al que apuestan los jugadores.
		double diferencia[3];	//Arreglo que almacena la diferencia entre el resultado del acomodo de cartas del jugador y el numero por el que aposto acercarse.
		int carta_1;			//Declaración de variable que se utiliza para establecer valor inicial de cartas del jugador.
		int carta_8;			//Declaración de variable que se utiliza para establecer valor final de cartas del jugador.
		int jugador;			//Declaración de variable para indicar de que jugador es turno.
		double resultado_final[3];	//Arreglo que almacena el resultado final del acomodo de cartas de cada jugador.
		int organizado_incorrecto = 0;	//Variable que permite indicar si el organizado de cartas hecho por el jugador es correcto o no.
		
		for(int i = 1; i <19; i++ ){
			C_Player[i] = -1;				//Asgina valor -1 a todos los valores del arreglo C_Player para reconocer espacios sin valores de cartas sorteadas.
		}
		for(int i = 1; i <30; i++ ){
			C_Player_Nuevo[i] = -1;			//Asgina valor -1 a todos los valores del arreglo C_Player_Nuevo para reconocer espacios sin valores asignados por usuario en el acomodo de cartas.
		}
		
		printf("Juego de Ecuaciones de coincidencia. \n");
		printf("En este juego, 2 jugadores acomodaran cartas sorteadas y apostaran a un numero, el que mas se acerque al numero apostado, gana. \n");
		printf("Ingrese el numero 1 para leer las reglas del juego. Ingrese cualquier otro numero para omitirlas.\n");	//Bienvenida.
		int seleccion_reglas;
		scanf("%d",&seleccion_reglas);
		if(seleccion_reglas == 1){				//Se muestran reglas para mejor comprensión del juego si es que el usuario lo desea.
			muestra_reglas();
		}
		else{}
		
	// Jugador 1
		carta_1 = 1; 	// 1 jugador 1, 11 jugador 2
		carta_8 = 8;	// 8 jugador 1, 18 jugador 2	Se establecen valores inciales para el jugador 1.
		jugador = 1;	// no. de jugador.
		//Posición cartas en arreglo C_Player es + 10 en caso del segundo jugador.
		C_Player[1] = 13;
		C_Player[2] = 14;	//Se asignan cartas de operación en las primeras 3 cartas sorteadas.
		C_Player[3] = 15;
		Asigna_Carta( C_Player, C_igual, 4, 10);		// Asigna numero random de 0 a 10 carta a carta 4 (solo cartas numericas).
		Asigna_Carta( C_Player, C_igual, 5, 12);		// Asigna numero random de 0 a 12 carta a carta 5  (incluye cartas de opercación).
		Asigna_Carta( C_Player, C_igual, 6, 12);		// Asigna numero random de 0 a 12 carta a carta 6   (incluye cartas de opercación).
		if((C_Player[5] == 11 || C_Player[5] == 12) && (C_Player[6] == 11 || C_Player[6] == 12)){
			Asigna_Carta( C_Player, C_igual, 6, 10);		// Sustituye ultima carta sorteada por otra numerica en caso de que las ultimas 2 sorteadas hayan sido simbolo de operación
		}
		else{}
		if(C_Player[5] == 12 || C_Player[6] == 12){
			Asigna_Carta( C_Player, C_igual, 7, 10);		//Sortea carta numerica adicional en caso de tener raiz cuadrada asignada en alguna carta anterior.
		}
		else{}
		if(C_Player[7] != (-1)){							//Detecta cual es el ultimo espacio de carta sorteada (6 o 7)
			Asigna_Carta( C_Player, C_igual, 8, 10);		//	para sortear carta en el espacio 8 en caso de tener el 7 ocupado.
		}
		else{
			Asigna_Carta( C_Player, C_igual, 7, 10);		//	o para sortear carta en el espacio 7 en caso de tenerlo desocupado.
		}																												
		muestra_cartas( carta_1, carta_8, C_Player, jugador);										//Muestra cartas sorteadas al usuario:
		sustituir_por_multiplicacion(C_Player, C_igual, carta_1, carta_8, jugador);					//En caso de tener multiplicación, pregunta al usuario que operación (+, - o *) decide sustituir por carta numerica.
		escoge_referencia( referencia, jugador);													//Permite a usuario escoger por cual numero apostar a acercar su resultado de operación con cartas.
		organiza_cartas(carta_1, carta_8, C_Player, C_Player_Nuevo, jugador); 						//Función que permite a usuario organizar las cartas sorteadas anteriormente. 
		proteccion_contra_mala_organizacion(carta_1, carta_8, C_Player, C_Player_Nuevo, jugador); 	//Protege de haber hecho una incorrecta organización de cartas.
		operador( carta_1, carta_8, C_Player_Nuevo, Resultados, referencia, diferencia, jugador); 	//Realiza operaciones correspondientes con cartas organizadas por usuario y muestra resultado final de ello.
		resultado_final[jugador] = Resultados[carta_1] ;
		if(resultado_final[jugador] < 0){															
			diferencia[jugador] = referencia[jugador] + resultado_final[jugador];	//Si el resultado es negativo, lo suma respetando ley de signos para obtener diferencia entre referencia y resultado.
		}
		else{
			diferencia[jugador] = referencia[jugador] - resultado_final[jugador];	//Si el resultado es positivo, lo resta normal para obtener diferencia entre referencia y resultado.
		}
		if(diferencia[jugador] < 0 ){												//Si la diferencia entre resultado y referencia es negativa, cambia el signo para se siempre positivo.
			diferencia[jugador] = diferencia[jugador]*(-1);
		}
		else{}
		
	// Jugador 2
		carta_1 = 11; 	// 1 jugador 1, 11 jugador 2
		carta_8 = 18;	// 8 jugador 1, 18 jugador 2		Se establecen valores inciales para el jugador 2.
		jugador = 2;	// no. de jugador.
		//Posición de cartas en arreglo C_Player es + 10 en caso del segundo jugador.
		C_Player[11] = 13;
		C_Player[12] = 14;		//Se asignan cartas de operación en las primeras 3 cartas sorteadas.
		C_Player[13] = 15;
		Asigna_Carta( C_Player, C_igual, 14, 10);		// Asigna numero random de 0 a 10 a carta 4 (solo cartas numericas).
		Asigna_Carta( C_Player, C_igual, 15, 12);		// Asigna numero random de 0 a 10 a carta 5 (incluye cartas de opercación).
		Asigna_Carta( C_Player, C_igual, 16, 12);		// Asigna numero random de 0 a 10 a carta 6 (incluye cartas de opercación).
		if((C_Player[15] == 11 || C_Player[15] == 12) && (C_Player[16] == 11 || C_Player[16] == 12) ){
			Asigna_Carta( C_Player, C_igual, 16, 10);		// Sustituye ultima carta sorteada por otra numerica en caso de que las ultimas 2 sorteadas hayan sido simbolo de operación
		}
		else{}
		if(C_Player[15] == 12 || C_Player[16] == 12){
			Asigna_Carta( C_Player, C_igual, 17, 10);		//Sortea carta numerica adicional en caso de tener raiz cuadrada asignada en alguna carta anterior.
		}
		else{}
		if(C_Player[17] != (-1)){							//	para sortear carta en el espacio 8 en caso de tener el 7 ocupado.
			Asigna_Carta( C_Player, C_igual, 18, 10);		//Detecta cual es el ultimo espacio de carta sorteada (6 o 7)
		}
		else{
			Asigna_Carta( C_Player, C_igual, 17, 10);		//	o para sortear carta en el espacio 7 en caso de tenerlo desocupado.
		}
		muestra_cartas( carta_1, carta_8, C_Player, jugador);										//Muestra cartas sorteadas al usuario:
		sustituir_por_multiplicacion(C_Player, C_igual, carta_1, carta_8, jugador);					//En caso de tener multiplicación, pregunta al usuario que operación (+, - o *) decide sustituir por carta numerica.
		escoge_referencia( referencia, jugador); 													//Permite a usuario escoger por cual numero apostar a acercar su resultado de operación con cartas.
		organiza_cartas(carta_1, carta_8, C_Player, C_Player_Nuevo, jugador); 						//Función que permite a usuario organizar las cartas sorteadas anteriormente. 
		proteccion_contra_mala_organizacion(carta_1, carta_8, C_Player, C_Player_Nuevo, jugador); 	//Protege de haber hecho una incorrecta organización de cartas.
		operador( carta_1, carta_8, C_Player_Nuevo, Resultados, referencia, diferencia, jugador); 	//Realiza operaciones correspondientes con cartas organizadas por usuario y muestra resultado final de ello.
		resultado_final[jugador] = Resultados[carta_1] ;
		if(resultado_final[jugador] < 0){		
			diferencia[jugador] = referencia[jugador] + resultado_final[jugador];	//Si el resultado es negativo, lo suma respetando ley de signos para obtener diferencia entre referencia y resultado.
		}
		else{
			diferencia[jugador] = referencia[jugador] - resultado_final[jugador];	//Si el resultado es positivo, lo resta normal para obtener diferencia entre referencia y resultado.
		}
		if(diferencia[jugador] < 0 ){												//Si la diferencia entre resultado y referencia es negativa, cambia el signo para se siempre positivo.
			diferencia[jugador] = diferencia[jugador]*(-1);
		}
		else{}
		
		
		printf("El jugador 1 tuvo el resultado %lf  y aposto al numero %lf, con una diferencia de %lf .\n", resultado_final[1], referencia[1], diferencia[1]);
		printf("El jugador 2 tuvo el resultado %lf  y aposto al numero %lf, con una diferencia de %lf .\n", resultado_final[2], referencia[2], diferencia[2]);
		if(diferencia[1] < diferencia[2]){											//Muestra resultados de ambos jugadores y los datos que los justifican.
			printf("Jugador 1 gana. \n");											//Determina el ganador en base al jugador cuya diferencia entre resultado y referencia se menor.
		}
		else{
			if(diferencia[1] == diferencia[2]){
				printf("Empate, ambos tienen la misma diferencia. \n");				//se determina empate si las diferencias entre resultados y referencias son iguales.
			}
			else{
				printf("Jugador 2 gana. \n");
			}
		}
		printf("Fin del juego. \n"); 												//Mensaje final de juego.
	}


