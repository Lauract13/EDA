// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int> &v, int ini, int fin, int &suma) {

	if (ini + 1 == fin){ // Dos elementos
		if (v[ini] < v[fin]){
			suma = v[ini] + v[fin];
			
			return true;
		}
		else{
			return false;
		}
	}
	else{
		int mitad = (ini + fin) / 2;
		int sumaIzq, sumaDer;

		bool correctoIzq = resolver(v, ini, mitad, sumaIzq);
		bool correctoDer = resolver(v, mitad + 1, fin, sumaDer);

		if (sumaIzq < sumaDer){
			suma = sumaIzq + sumaDer; 
			return true;
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
	int filas, columnas; 

	std::cin >> filas >> columnas; 

	if (!std::cin)
		return false;
	bool correcto = true;
	
	for (int i = 0; i < filas; i++){

		std::vector<int> vector(columnas);

		for (int j = 0; j < columnas; j++){
			std::cin >> vector[j];
		}
		if (correcto){
			int suma;
			correcto = resolver(vector, 0, columnas - 1, suma);
		}
		
		
	}

	if (correcto){
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