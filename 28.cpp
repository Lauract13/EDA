// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


using matrix = std::vector<std::vector<int>>;



// función que resuelve el problema
void resolver(const matrix &m, int &min, int contador, const int &numProductos, const int &numSupermercados, int k, std::vector<int> &supermercados, const std::vector<int> &acumulados) {

	for (int i = 0; i < numSupermercados; i++) {

		contador += m[i][k];
		supermercados[i]++;
		

		if (supermercados[i] <= 3 && contador < min) {
			if (k == numProductos - 1) {
				
				min = contador;
				
			}
			else {
			
				if (contador + acumulados[k + 1] < min) {
					resolver(m, min, contador, numProductos, numSupermercados, k + 1, supermercados, acumulados);
				}
				
			

			}
		}

		contador -= m[i][k];
		supermercados[i]--;



	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numSupermercados, numProductos;

	std::cin >> numSupermercados >> numProductos;

	

	matrix m(numSupermercados, std::vector<int>(numProductos));

	std::vector<int> supermercados(numSupermercados, 0);
	std::vector<int> productos(numProductos);
	std::vector<int> acumulados(numProductos);

	for (int i = 0; i < numSupermercados; i++) {
		for (int j = 0; j < numProductos; j++) {
			std::cin >> m[i][j];

			productos[j] = std::min(productos[j], m[i][j]);
		}
	}

	for (int i = numProductos - 2; i > -1; i--) {
		acumulados[i] += productos[i + 1];
	}
	

	int minimo = std::numeric_limits<int>::max();

	resolver(m, minimo, 0, numProductos, numSupermercados, 0, supermercados, acumulados);

	std::cout << minimo << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;

	std::cin >> numCasos; 

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}