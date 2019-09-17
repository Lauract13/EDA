// Laura Casas Torres
// E10

/*
COMPLEJIDAD: 

	O(log n)
COSTE: 

	T(n) = {

		c si (ini == fin v ini + 1 ==fin)
		T(n/2) +  c		en cualquier otro caso

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int resuelve(const std::vector<int> &v, const int &ini, const int &fin, const int &num) {

	if (ini == fin || ini + 1 == fin) {
		if (v[ini] == num + ini) {
			return v[ini];
		}
		else if (v[fin] == num + fin) {
			return v[fin];
		}
		else {
			return -1;
		}
	}
	else {
		int mitad = (ini + fin) / 2;
		
	
		if (num + mitad < v[mitad]) {
			resuelve(v, ini, mitad, num);
		}
		else {
			resuelve(v, mitad, fin, num);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos, tam, num; 

	std::cin >> numCasos;

	if (!std::cin)
		return false;

	for (int i = 0; i < numCasos; i++) {
		std::cin >> tam >> num; 

		std::vector<int> numeros(tam);

		for (int j = 0; j < tam; j++) {
			std::cin >> numeros[j];
		}

		int result = resuelve(numeros, 0, numeros.size() - 1, num);

		if (result == -1) {
			std::cout << "NO" << std::endl;
		}
		else {
			std::cout << result << std::endl;
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