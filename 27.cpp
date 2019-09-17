// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using matrix = std::vector<std::vector<int>>;

// función que resuelve el problema
void resolver(const matrix &m, const int &numFuncionarios, int k, int &min, int contador, std::vector<bool> &marcas) {

	for (int i = 0; i < numFuncionarios; i++) {

		contador += m[k][i];

		if (!marcas[i]) {
			if (k == numFuncionarios - 1) {
				if (contador < min) {
					min = contador;
				}
			}
			else {
				marcas[i] = true;
				resolver(m, numFuncionarios, k + 1, min, contador, marcas);
				marcas[i] = false;
			}
		}
		
		contador -= m[k][i];


	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numFuncionarios; 

	std::cin >> numFuncionarios;

	if (numFuncionarios == 0)
		return false;

	matrix m(numFuncionarios, std::vector<int>(numFuncionarios));

	for (int i = 0; i < numFuncionarios; i++) {
		for (int j = 0; j < numFuncionarios; j++) {
			std::cin >> m[i][j];
		}
	}
	std::vector<bool> marcas(numFuncionarios, false);

	int minimo = 10000000000;
	resolver(m, numFuncionarios, 0, minimo, 0, marcas);

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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}