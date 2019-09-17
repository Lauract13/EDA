// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>

// O(n)
struct datos{
	int numero;
	int potencia;
};
datos invertir(int num){

	if (num == 0){
		return{ 0, 1 };
	}
	else{
		
		datos s = invertir(num / 10);

		datos r; 
		
		r.numero = s.numero + (num % 10 * s.potencia);
		r.potencia = s.potencia * 10;

		return r;
	}
}

// función que resuelve el problema
int resolver(int num) {

	if (num < 10){
		return 9 - num;
	}
	else{
		int n = num % 10;
		int r = 9 - n;
		return resolver(num / 10) * 10 + r;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int casos, numero; 

	std::cin >> casos; 
	if (!std::cin)
		return false;

	for (int i = 0; i < casos; i++){
		std::cin >> numero;

		int sol1 = resolver(numero);
		std::cout << sol1 << std::endl;
		datos sol2 = invertir(sol1); 

		std::cout << sol2.numero << std::endl;
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