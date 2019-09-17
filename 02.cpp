// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


/*		c0 si n = 0,1
T(n) = 
		T(n/2) + c1 si n > 1
		
COSTE O(log n)
*/
// función que resuelve el problema
std::string resolver(int num) {

	if (num == 0){
		return  "0";
	}
	else if (num == 1){
		return "1";
	}
	else{
		return resolver(num / 2) + char('0' + num % 2);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos, num;

	std::cin >> numCasos;
	if (!std::cin)
		return false;

	for (int i = 0; i < numCasos; i++){
		std::cin >> num;
		std::cout << resolver(num) << std::endl;
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