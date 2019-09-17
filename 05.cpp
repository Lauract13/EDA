// Laura Casas Torres
// E10


/* 
Complejidad: 

	O(log n) 
Coste: 

	T(n) = {

		c si (ini + 1 == fin v ini == fin)

		T(n/2) + c	resto de casos


*/

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>


int resolver(const std::vector<int> &c, const int &ini, const int &fin) {

	if (ini + 1 == fin || ini == fin) { // Dos o menos elementos en el vector
		return std::min(c[ini], c[fin]);
	}
	else {
		int mitad = (ini + fin) / 2;
		if (c[mitad - 1] < c[mitad]) {
			resolver(c, ini, mitad);
		}
		else {
			resolver(c, mitad, fin);
		}
	}

}
bool resuelveCaso() {

	int tam, num;
	std::cin >> tam;

	if (!std::cin)

		return false;
	std::vector<int> curva(tam);
	
	for (int i = 0; i < tam; i++) {
		std::cin >> curva[i]; 
	}

	if (tam == 1) {
		std::cout << curva[0] << std::endl;
	}
	else {
		std::cout << resolver(curva, 0, tam - 1) << std::endl;
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
