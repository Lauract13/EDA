// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "bintree_eda.h"

struct resultado{
	int dragones; 
	std::string puerta;
};

template<class T>
class arbol : public bintree < T > {
	
public:
	
	arbol() : bintree<T>(){}
	arbol(arbol<T> const &l, T const& e, arbol<T> const & r) : bintree<T>(l, e, r){}
	
	resultado dragones(){
		return resolver(this->raiz);
	}

	arbol<T> leerArbol_ext(T vacio) {
		T raiz;
		std::cin >> raiz;
		if (raiz == vacio) { // es un árbol vacío
			return{};
		}
		else { // leer recursivamente los hijos
			auto iz = leerArbol_ext(vacio);
			auto dr = leerArbol_ext(vacio);
			return{ iz, raiz, dr };
		}
	}



private:
	using Link = typename bintree<T>::Link;

	resultado resolver(Link n){
		
		if (n->left == nullptr && n->right == nullptr){ // Es una puerta
			return{ 0, n->elem };
		}
		else if (n->left != nullptr && n->right == nullptr){
			resultado izq = resolver(n->left);
			if (n->elem == "Dragon"){
				izq.dragones++;
			}
			return izq;
		}
		else if (n->right != nullptr && n->left == nullptr){
			resultado der = resolver(n->right);
			if (n->elem == "Dragon"){
				der.dragones++;
			}
			return der;
		}
		else{
			resultado izq = resolver(n->left);
			resultado der = resolver(n->right);

			if (izq.dragones <= der.dragones){
				if (n->elem == "Dragon"){
					izq.dragones++;
				}
				return izq;
			}
			else{
				if (n->elem == "Dragon"){
					der.dragones++;
				}
				return der;
			}
		}
	}


};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos; 
	std::cin >> numCasos;

	if (!std::cin)
		return false;

	for (int i = 0; i < numCasos; i++){
	

		arbol<std::string> arb = arbol<std::string>().leerArbol_ext("...");

		resultado result = arb.dragones();
		
		std::cout << result.puerta << " " << result.dragones << std::endl;
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