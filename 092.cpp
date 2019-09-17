﻿// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class cola : public queue < T > {
private:
	using Nodo = typename queue<T>::Nodo;

public:
	void invertir(){



		
		if (this->prim != nullptr){

			Nodo* n = this->prim;
			Nodo* a1 = this->prim->sig;
			Nodo* a2 = this->prim->sig;

			n->sig = nullptr;

			while (a1 != nullptr){
				
				a2 = a1->sig;
				a1->sig = n;
				n = a1;
				a1 = a2;
			}
			
		}

		std::swap(this->ult, this->prim);


	}
	void imprimir(){

		Nodo* n = this->prim;

		while (n != nullptr){

			std::cout << n->elem << " ";
			n = n->sig;
		}

		std::cout << "\n";

	}


	
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;

	if (!std::cin)
		return false;

	std::cin >> num;

	cola<int> cola;

	while (num != 0) {
		cola.push(num);
		std::cin >> num;
	}

	
	cola.invertir();

	
	cola.imprimir();

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