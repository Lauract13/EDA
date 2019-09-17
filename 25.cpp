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



bool esValida(std::vector<int> &sol, const std::vector<int> &c, int k, std::vector<int> &cantidad, int suma, const int &consumoMax, int i) {

	// Si hay tres bombillas iguales seguidas devuelve false
	if (k >= 2 && (sol[k-1] == sol[k-2] && sol[k-1] == sol[k])) { 
		return false;
	}
	// Si el consumo supera el consumo máximo devuelve false
	else if (suma > consumoMax) { 
		return false;
	}
	// Si la suma de todas las bombillas + 1 es mayor que la suma de una bombilla del mismo tipo
	else if (cantidad.size() > 1 && (cantidad[i] > (k / 2) + 1)) {
		return false;
	}
	else {
		return true;
	}
}

void asignarBombilla(int i, const std::vector<int> &c, std::vector<int> &cant, int &suma) {

	cant[i]++;
	suma = suma + c[i];
	
}

void desmarcar(std::vector<int> &cant, int i, int &suma, const std::vector<int> &c) {
	cant[i]--;
	suma = suma - c[i];

}

// función que resuelve el problema
void resolver(std::vector<int> &sol, const std::vector<int> &cons, const int &longitud, int &formas, int k, std::vector<int> &cantidad, int suma, const int &consumoMax) {



	for (int i = 0; i < cons.size(); i++) {

		sol[k] = i;
		asignarBombilla(i, cons, cantidad, suma);
		
		
		if (esValida(sol, cons,  k, cantidad,  suma, consumoMax,  i)) {
			
			if (k == longitud - 1) { // Se ha llenado el vector 
				
					formas++;
				

			}
			else {
				
					resolver(sol, cons, longitud, formas, k+1, cantidad, suma, consumoMax);
				
			}
		}
		
		desmarcar(cantidad, i, suma, cons);
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int longitud, colores, consumo, bombilla, formas = 0;

	std::cin >> longitud >> colores >> consumo;


	if (!std::cin)
		return false;
	std::vector<int> sol(longitud);
	std::vector<int> consumos(colores);
	// Vector que guarda cuantas veces ha sido usada cada bombilla
	std::vector<int> cantidad(colores);
	for (int i = 0; i < colores; i++) {
		std::cin >> consumos[i];

	}
	
	resolver(sol, consumos, longitud, formas, 0, cantidad, 0, consumo);

	
	std::cout << formas << std::endl;



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