// Laura Casas Torres
// E10

/*
Complejidad: O(n!)

Coste: 

	T(n) = {
			
		c si es solución
		T(n-1) * n en el peor de los casos
		

		
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

std::string asignarColor(int i, int &a, int &r, int &v) {

	if (i == 0) {
		a++;
		return "azul";
	}
	else if (i == 1) {
		r++;
		return "rojo";
	}
	else if(i == 2){
		v++;
		return "verde";
	}
}

bool esValida(const int &numPiezas, const int &azul, const int &rojo, const int &verde,
	std::vector<std::string> &sol, int a, int r, int v, int cont) {

	if (sol[cont] == "verde" && sol[cont - 1] == "verde") { // Si hay dos piezas verdes seguidas devuelve no valido
		return false;
	}
	else if (a > azul || r > rojo || v > verde) { // Si ha colocado mas piezas de un color de las que tiene no valido
		return false;
	}
	else if ( v > a) { // Si no cumple las condiciones delvuelve no valido
		return false;
	}
	else {
		return true;
	}
}
void tratarSolucion(const std::vector<std::string> &sol) {
	
	for (int i = 0; i < sol.size(); i++) {
		std::cout << sol[i] << " ";
	}
	std::cout << std::endl;
}

void desmarcar(int i, int &a, int &r, int &v) {
	if (i == 0) {
		a--;
	}
	else if(i==1){
		r--;
	}
	else if (i == 2) {
		v--;
	}
}

// función que resuelve el problema
bool resolver(const int &numPiezas, const int &azul, const int &rojo, const int &verde,
	std::vector<std::string> &sol, int a, int r, int v, int cont){

	bool haySolucion = false;


	for (int i = 0; i < 3; i++) {

		sol[cont] = asignarColor(i, a, r, v );
		if (esValida(numPiezas, azul, rojo, verde, sol, a, r, v, cont)) {
			if (cont == numPiezas - 1) { // Se ha llenado el vector correctamente -> es solución
				if (r > (a + v)) {
					haySolucion = true;
					tratarSolucion(sol);
				}
				
			}
			else {
				if (rojo > v + a) {
					haySolucion = resolver(numPiezas, azul, rojo, verde, sol, a, r, v, cont + 1);
				}
			}
		}
		//desmarco si el color no cumple la condicion
		desmarcar(i, a, r, v);
	}
	return haySolucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPiezas, rojo, verde, azul; 

	std::cin >> numPiezas >> azul >> rojo >> verde;

	
	if (numPiezas == 0 && azul == 0 && rojo == 0 && verde == 0)
		return false;
	std::vector<std::string> sol(numPiezas);

	if (numPiezas > (rojo + verde + azul) || rojo < 1) {
		std::cout << "SIN SOLUCION" << std::endl;
	}else {
		sol[0] = "rojo"; // La primera ficha siempre es roja
		// Se inicializa el rojo a uno y la posicion del vector solución a 1
		bool solucion = resolver(numPiezas, azul, rojo, verde, sol, 0, 1, 0, 1);

		if (!solucion) {
			std::cout << "SIN SOLUCION" << std::endl;
		}
		
	}
	
	std::cout << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}