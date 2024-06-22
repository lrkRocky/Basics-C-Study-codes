#ifndef JUEGOS_LIB_H
#define JUEGOS_LIB_H

//Declaración de funciones principales de cada juego.
	void Piedra_papel_tijera_normal();
	void Piedra_papel_tijera_AnimalWorld();
	void Juego_de_ahorcado();
	void Ecuaciones_de_coincidencia();

//Declaración de funciones utilizadas en juegos.
	//Funciones utilizadas en juego 1 y 2: Piedra papel o tijera (versión normal y versión Animal world).
	void menu_juego_1y2();
	
	//Funciones utilizadas en juego 3: Juego de ahorcado.
	void monito(int intentos);
	
	//Funciones utilizadas en juego 4: Ecuaciones de coincidencia (Juego de serie Plan del diablo).
	void Asigna_Carta(int *C_Player, int *C_igual, int carta, int limite);
	void muestra_cartas(int inicio, int fin, int *C_Player, int jugador);
	void muestra_cartas_organizadas(int inicio, int fin, int *C_Player, int *C_Player_Nuevo, int jugador);
	void sustituir_por_multiplicacion(int *C_Player, int *C_igual, int inicio, int fin, int jugador);
	void organiza_cartas(int inicio, int fin, int *C_Player, int *C_Player_Nuevo, int jugador);
	void proteccion_contra_mala_organizacion(int inicio, int fin, int *C_Player, int *C_Player_Nuevo, int jugador);
	void operador(int inicio, int fin, int *C_Player_Nuevo, double *Resultados, double *referencia, double *diferencia, int jugador);	//Declaración de funciones a desarrollar y utilizar.
	void escoge_referencia( double *referencia, int jugador);
	void muestra_reglas();
	
#endif // JUEGOS_LIB_H
	