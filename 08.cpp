// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
 /* 
 Complejidad: 

	O(log n)

 Coste: 

	T(n) = {
	  
		c si (ini + 1 = fin v ini = fin)

		T(n/2) +  c en cualquier otro caso
 
 */

// función que resuelve el problema
int resolver(const std::vector<int> &v, const int &ini, const int &fin) {

	if (ini + 1 == fin || ini == fin) {
		return std::min(v[ini], v[fin]);
	}
	else {
		int mitad = (ini + fin) / 2;

		int izq = std::min(v[ini], v[mitad - 1]);
		int der = std::min(v[mitad], v[fin]);

		if (izq < der) {
			resolver(v, ini, mitad - 1); 
			
		}
		else {
			resolver(v, mitad, fin);
		}

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam; 

	std::cin >> tam;

	if (!std::cin)
		return false;

	std::vector<int> vector(tam);

	for (int i = 0; i < tam; i++) {

		std::cin >> vector[i];

	}
	std::cout << resolver(vector, 0, vector.size() - 1) << std::endl;


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