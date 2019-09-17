// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class lista : public queue < T > {
private:
	using Nodo = typename queue<T>::Nodo;
public:
	void invertir(){

		int numVueltas = 0;
		if (this->nelems % 2 != 0){
			numVueltas = this->nelems - 1; 
		}
		else{
			numVueltas = this->nelems;
		}
		Nodo* p = this->prim; 
		Nodo* n = this->prim->sig;
		// Pimera vuelta
		Nodo* aux = nullptr;

		for (int i = 0; i < numVueltas / 2; i++){
			if (i == 0){
				p->sig = n->sig; 
				n->sig = p;
				this->prim = n;

				n = p->sig;
				//p = p->sig;
			}
			else if (i == (numVueltas / 2) - 1 && numVueltas % 2 != 0){ // No última vuelta
				p->sig = aux;
				aux->sig = n;
				n->sig = nullptr;
				this->ult = n;

			}
			else{ // ultima vuelta
				
				aux = n->sig;
				p->sig = aux;
				n->sig = aux->sig;
				aux->sig = n;

				p = n;
				n = p->sig;
				//aux = n->sig;
				
			}
		}

	}
	void imprimir(){

		Nodo* aux = this->prim;

		while (aux != nullptr){
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}

		std::cout << std::endl;

	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int cant, num; 
	std::cin >> cant;
	if (!std::cin)
		return false;

	if (cant == 0){
		return false;
	}
	lista<int> cola;
	for (int i = 0; i < cant; i++){
		std::cin >> num;
		cola.push(num);

	}
	if (cant != 1){
		cola.invertir();
	}
	
	
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