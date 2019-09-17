// Laura Casas Torres 
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int longitud;
	int num_llanos;
	std::vector<int> posiciones;

}t_info;
// función que resuelve el problema
t_info resolver(const std::vector<int> &llanos, int l, int longitud) {

	
	std::vector<int> pos_actual;
	if (longitud == 0){
		return{ 0, 0, pos_actual };
	}
	int pos = 1;
	int long_actual = 1;

	std::vector<int> pos_actual;
	t_info ret = { 0,0,pos_actual };

	while (pos < longitud) {

		if (llanos[pos] == llanos[pos - 1]){

			long_actual++;

			if (long_actual >= l){
				ret.num_llanos++;
			}
			if (long_actual > ret.longitud){
				ret.longitud = long_actual;
			}
		}

		
	}

	return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int longitud, l; 

	std::cin >> longitud >> l;

	if (!std::cin)
		return false;

	std::vector<int> llanos(longitud);

	for (int i = 0; i < longitud; i++) {
		std::cin >> llanos[i];
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