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

// Matriz que guarda la satisfaccion de cada juguete para cada niño
using matrix = std::vector<std::vector<int>>;

bool esValida(std::vector<int> &sol,int k, const matrix &s, std::vector<int> &cantidad, const int &pos, const int &satisfaccion, const int &i, const std::vector<std::string> &t) {

	if (k % 2 != 0 ) {

		// Un niño tiene los dos juguetes del mismo tipo
		if (t[sol[k]] == t[sol[k - 1]]) {
			return false;
		}
		// Comprueba el orden de los juguetes
		if (sol[k - 1] > sol[k]) {
			return false;
		}
		// Comprueba que cumple el minimo de satisfaccion
		if ((s[pos - 1][sol[k - 1]] + s[pos - 1][sol[k]]) < satisfaccion) {
			return false;
		}
		
	}

	if (cantidad[i] < 0) {
		return false;
	}

	return true;
}

void marcar(std::vector<int> &cantidad, int i, int k, int &posNinio) {

	cantidad[i]--;
	if (k % 2 != 0) {
		posNinio++;
	}

}

void desmarcar(std::vector<int> &cantidad, int i, int k, int &posNinio) {
	cantidad[i]++;
	if (k % 2 != 0) {
		posNinio--;
	}
}

void tratarSolucion(const std::vector<int> &sol) {
	for (int i = 0; i < sol.size(); i++) {
		std::cout << sol[i] << " ";
	}
	std::cout << std::endl;
}
// función que resuelve el problema
void resolver(std::vector<int> &sol, const matrix &s,const std::vector<std::string> &t,  std::vector<int> &c, int k,  const int &minSat, int posNinio, bool &haySol) {

	

	for (int i = 0; i < t.size(); i++) {

		sol[k] = i;
		marcar(c, i,k,  posNinio);


		if (esValida(sol, k, s, c, posNinio, minSat, i, t)) {

			if (k == sol.size() - 1) { // Se ha llenado el vector 

				haySol = true;
				tratarSolucion(sol);
			


			}
			else {

				resolver(sol, s, t, c, k+1, minSat, posNinio, haySol);

			}
		}

		desmarcar(c, i, k, posNinio);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	
	int numJuguetes, numNinios, minSatisfaccion; 

	std::cin >> numJuguetes >> numNinios >> minSatisfaccion; 


	if (!std::cin)
		return false;
	
	// Vector que guarda la cantidad de juguetes que hay de cada tipo
	std::vector<int> cantidad(numJuguetes);

	for (int i = 0; i < numJuguetes; i++) {
		std::cin >> cantidad[i];
	}
	// Vector que guarda el tipo de cada uno de los juguetes
	std::vector<std::string> tipo(numJuguetes);

	for (int i = 0; i < numJuguetes; i++) {
		std::cin >> tipo[i];
	}

	matrix satisfaccion(numNinios, std::vector<int>(numJuguetes));

	for (int i = 0; i < numNinios; i++) {
		for (int j = 0; j < numJuguetes; j++) {
			std::cin >> satisfaccion[i][j];
		}
	}
	std::vector<int> sol(numNinios * 2);

	bool solucion = false; 
	
	resolver(sol, satisfaccion, tipo, cantidad, 0, minSatisfaccion, 0, solucion);

	if (!solucion) {
		std::cout << "SIN SOLUCION" << std::endl;
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