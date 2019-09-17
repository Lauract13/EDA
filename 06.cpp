// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
Complejidad: 

	O(log n) 

Coste: 

	T(n) = { 

		c	si	ini + 1 == fin

		T(n/2) + c	si ini + 1 != fin


*/

// función que resuelve el problema
char resolver(std::vector<char> &v, const int &ini, const int &fin) {

	if (ini + 1 == fin) {
		return v[ini] + 1;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[ini] - ini == v[mitad] - mitad) {
			resolver(v, mitad, fin);
		}
		else {
			resolver(v, ini, mitad);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos; 

	std::cin >> numCasos;

	

	if (!std::cin)
		return false;

	
	for (int j = 0; j < numCasos; j++) {

		char letraIni, letraFin, letra;

		std::cin >> letraIni >> letraFin;

		std::vector<char> vector(letraFin - letraIni);


		for (int i = 0; i < vector.size(); i++) {

			std::cin >> vector[i];

		
		}

		if (vector[0] != letraIni) {
			std::cout << letraIni << std::endl;
		}
		else if (vector[vector.size() - 1] != letraFin) {
			std::cout << letraFin << std::endl;
		}
		else {
			std::cout << resolver(vector, 0, vector.size() - 1) << std::endl;
		}

	}


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