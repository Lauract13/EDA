// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int buscarIz(const std::vector<int> &v, const int &ini, const int &fin, const int &altura){

	if (ini >= fin){ // Vector vacío
		return ini; 
	}
	else if (ini + 1 == fin){ // Vector de un elemento
		return ini;
	}
	else{
		int mitad = (ini + fin - 1) / 2;

		if (v[mitad] < altura){
			return buscarIz(v, mitad + 1, fin, altura);
		}
		else{
			return buscarIz(v, ini, mitad + 1, altura);
		}
	}
}

int buscarDr(const std::vector<int> &v, const int &ini, const int &fin, const int &altura){
	if (ini >= fin){
		return ini; 
	}
	else if (ini + 1 == fin){
		return ini; 
	}
	else{
		int mitad = (ini + fin - 1) / 2;

		if (altura < v[mitad]){
			return buscarDr(v,ini, mitad, altura);
		}
		else{
			return buscarDr(v, mitad + 1, fin, altura);
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num, altura; 

	std::cin >> num >> altura; 

	if (!std::cin)
		return false;

	std::vector<int> alturas(num);
	for (int i = 0; i < num; i++){
		std::cin >> alturas[i];
	}

	int izq = buscarIz(alturas, 0, num, altura);
	if (alturas[izq] != altura || izq == alturas.size()){
		std::cout << "NO EXISTE" << std::endl;
	}
	else{
		int der = buscarDr(alturas, 0, num, altura);
		if (izq == der){
			std::cout << izq << std::endl;
		}
		else{
			std::cout << izq << " " << der << std::endl;
		}
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