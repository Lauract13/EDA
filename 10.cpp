// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

 /*
 Complejidad:

	O(n)

 Coste:

	T(n) = {

		c si (ini == fin) || v(ini) == v(fin), donde v(i): 0 <= i < 

		T(n) +  c en cualquier otro caso

 */

 // función que resuelve el problema
int resolver(const std::vector<int> &v, const int &ini, const int &fin) {

	if (v[ini] == v[fin]) {
		return 1;
	}
	else if (ini == fin) { // Un elemento
		return 1;
	}
	else {
		int mitad = (ini + fin) / 2;
		
		int izq = resolver(v, ini, mitad);
		int der = resolver(v, mitad + 1, fin);

		if (v[mitad] == v[mitad + 1]) {
			return izq + (der - 1);
		}
		else {
			return izq + der;
		}
		
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;

	std::cin >> tam;

	if (!std::cin || tam == 0)
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