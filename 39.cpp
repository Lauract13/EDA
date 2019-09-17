// Laura Casas Torres
// E10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int ini;
	int fin; 
}t_posicion;


// P = { 0 <= i <= long(v) && long(v) >= 1 && existe i: <= i <= n: V[i] > t}
t_posicion resolver(const std::vector<int> &v,int n, int t) {
	int ini = 0; 
	int fin = 0;
	int edificios_act = 0;
	int edificios_max = 0;
	t_posicion ret;

	// I = {0 <= ini <= fin < n && ret = max p,q: 0 <= p <= q < fin: menor(p,q) && edificios_act = #e: ini <= e < fin: v[e] >= t}
	// FUNCION DE COTA:  f(fin) = n - fin, como n es constante y fin incrementa en cada iteración, en algún momento n - fin <= 0
	while (fin < n) {

		if (v[fin] >= t) {
			edificios_act++;
			
			if (edificios_act > edificios_max) {
				edificios_max = edificios_act;
				ret.ini = ini; 
				ret.fin = fin;
			}
			fin++;
		}
		else {
			edificios_act = 0;
			fin++; 
			ini = fin;
		}
		
	}

	return ret;

}
// menor(p, q) = { PT j: p <= j <= q: v[j] >= t}
// Q = {ret = max p,q: 0 <= p <= q < n: menor(p,q)}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int numCasos; 

	std::cin >> numCasos;

	if (!std::cin)
		return false;

	int n, t;

	for (int i = 0; i < numCasos; i++) {

		std::cin >> n >> t; 

		std::vector<int> edificios(n);

		for (int j = 0; j < n; j++) {
			std::cin >> edificios[j];
		}
		t_posicion sol = resolver(edificios, n, t); 

		std::cout << sol.ini << " " << sol.fin << std::endl;
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