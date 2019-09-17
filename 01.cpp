// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>

/*Ecuaciones de recurrencia ( n = b) 


		c0    si n = 0, 1
T(n) = 
		T(n/2) + c1 si n > 1
 
 
 COSTE O(log n) 
 
 */
// función que resuelve el problema
int resolver(const int &a, const int &b) {

	if (b == 0){
		return 0;
	}
	else if (b == 1){
		return a;
	}
	else{
		int a2 = a * 2;
		int b2 = b / 2;

		if (b > 1 && b % 2 == 0){
			return resolver(a2, b2);
		}
		else if (b > 1 && b % 2 != 0){
			return resolver(a2, b2) + a;
		}
	}
	


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos, a, b;
	std::cin >> numCasos;
	if (!std::cin)
		return false;

	for (int i = 0; i < numCasos; i++){
		std::cin >> a >> b;

		std::cout << resolver(a, b) << std::endl;
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