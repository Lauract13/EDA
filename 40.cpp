// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int partidos_ganados; 
	int repeticiones_racha; 
	int partidos_perdidos;
}t_info;

// P = {0 <= i <= long(v)}
t_info resolver(const std::vector<int> &resultados, int n) {

	int act = 0;

	int num_ganados_seguidos = 0;
	int perdidos = 0;
	int racha = 0; 

	t_info ret = { 0,0,0 };
	
	while (act < n) {

		if (resultados[act] > 0) { // Partido ganado

			num_ganados_seguidos++; 
			
			if (num_ganados_seguidos > ret.partidos_ganados) {
				ret.partidos_ganados = num_ganados_seguidos;
				perdidos = 0;
				racha = 0;
			}
			if (num_ganados_seguidos == ret.partidos_ganados) {
				perdidos = 0;
				racha++;
			}
			if (num_ganados_seguidos < ret.partidos_ganados) {
				perdidos++;
			}
			
		}
		else {
			perdidos++;
			num_ganados_seguidos = 0; 

		}

		act++;
	}
	ret.partidos_perdidos = perdidos; 
	ret.repeticiones_racha = racha;
	return ret;
}
      
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int partidos; 

	std::cin >> partidos; 

	if (!std::cin)
		return false;

	std::vector<int> resultados(partidos);

	for (int i = 0; i < partidos; i++) {
		std::cin >> resultados[i];
	}

	t_info sol = resolver(resultados, partidos); 

	std::cout << sol.partidos_ganados << " " << sol.repeticiones_racha << " " << sol.partidos_perdidos << std::endl;

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