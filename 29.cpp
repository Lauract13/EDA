// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(const std::vector<int> &usos, const std::vector<int> &abrigos, const std::vector<int> &precipitaciones, int i, int k, const std::vector<int> &sol) {

	if (usos[i] > 2 + k / 3) {
		return false;
	}
	else if (precipitaciones[k] > abrigos[i]) {
		return false;
	}
	else if (k >= 1 && sol[k] == sol[k - 1]) {
		return false;
	}
	else {
		return true;
	}
}
void resolver(const std::vector<int> &precipitaciones, const std::vector<int> &abrigos, std::vector<int> &sol, std::vector<int> usos, int k, int &combinaciones) {

	for (int i = 0; i < abrigos.size(); i++) {

		//marcar
		// Aumento en uno los usos del abrigo
		usos[i]++;
		sol[k] = i;

		if (esValida(usos,  abrigos, precipitaciones, i, k, sol )) {
			if (k == precipitaciones.size() - 1) {
				if (sol[0] != sol[k]) { // Si el ultimo y el primero son distintos
					combinaciones++;
				}
			}
			else {
				resolver(precipitaciones, abrigos, sol, usos, k + 1, combinaciones);
			}

		}

		usos[i]--;
		sol[k] = -1;

	}

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	int numDias, numAbrigos; 

	std::cin >> numDias >> numAbrigos; 

	if (numDias == 0 && numAbrigos == 0)
		return false;

	std::vector<int> precipitaciones(numDias);

	for (int i = 0; i < numDias; i++) {
		std::cin >> precipitaciones[i];
	}
	std::vector<int> abrigos(numAbrigos);

	for (int i = 0; i < numAbrigos; i++) {
		std::cin >> abrigos[i];
	}

	std::vector<int> sol(numDias, -1);
	std::vector<int> usos(numAbrigos, 0);
	int combinaciones = 0;

	resolver(precipitaciones, abrigos, sol, usos, 0, combinaciones);

	if (combinaciones == 0) {
		std::cout << "Lo puedes comprar" << std::endl;
	}
	else {
		std::cout << combinaciones << std::endl;
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