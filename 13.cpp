// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int> &v, int ini, int fin, int &min, int &max) {

	if (ini >= fin){
		return true; 
	}
	else if(ini + 1 == fin){ // Dos elementos
		if (v[ini] <= v[fin]){
			min = v[ini];
			max = v[fin];
			return true;
		}
		else{
			return false;
		}
	}
	else{

		int mitad = (ini + fin) / 2;

		int minIzq, maxIzq, minDer, maxDer; 

		bool correctIzq = resolver(v, ini, mitad, minIzq, maxIzq);
		
		bool correctDer = resolver(v, mitad + 1, fin, minDer, maxDer);

		if (correctIzq && correctDer){
			if (minIzq <= minDer && maxIzq <= maxDer){
				min = minIzq;
				max = maxDer;
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num; 

	std::cin >> num;

	if (!std::cin || num == 0)
		return false;

	std::vector<int> vector;

	while (num != 0){
		vector.push_back(num);
		std::cin >> num;
	}
	int min, max;
	if (resolver(vector, 0, vector.size() - 1, min, max)){
		std::cout << "SI" << std::endl;
	}
	else{
		std::cout << "NO" << std::endl;
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